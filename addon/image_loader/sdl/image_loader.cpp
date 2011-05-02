#include "image_loader.hpp"
#include <gorgon++/gorgon.hpp>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace Gorgon
{
	Uint32 getpixel(SDL_Surface *surface, int x, int y)
	{
		int bpp = surface->format->BytesPerPixel;
		Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;/* Here p is the address to the pixel we want to retrieve */

		switch (bpp)
		{
			case 1:	return *p;
			case 2:	return *(Uint16 *)p;
			case 3:
				if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
				{
					return p[0] << 16 | p[1] << 8 | p[2];
				}
				else
				{
					return p[0] | p[1] << 8 | p[2] << 16;
				}
			case 4:
				return *(Uint32 *)p;
			default:
				return 0;/* shouldn't happen, but avoids warnings */
		} // switch
	}
	/*void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
	{
		int bpp = surface->format->BytesPerPixel;
		Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

		switch (bpp)
		{
			case 1:
				*p = pixel;
				break;
			case 2:
				*(Uint16 *)p = pixel;
				break;
			case 3:
				if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
				{
					p[0] = (pixel >> 16) & 0xff;
					p[1] = (pixel >> 8) & 0xff;
					p[2] = pixel & 0xff;
				}
				else
				{
					p[0] = pixel & 0xff;
					p[1] = (pixel >> 8) & 0xff;
					p[2] = (pixel >> 16) & 0xff;
				}
				break;
			case 4:
				*(Uint32 *)p = pixel;
				break;
			default: break;
		} // switch
	}*/
	int getPixel(SDL_Surface *surface, int x, int y)
	{
		Uint8 r=0, g=0, b=0, a=0;
		Uint32 pixel = getpixel(surface,x,y);
		switch(surface->format->BytesPerPixel)
		{
			case 1:
				return pixel;
			case 2:
			case 3:
				SDL_GetRGB
				(
					pixel,
					surface->format,
					&r,&g,&b
				);
				break;
			case 4:
				SDL_GetRGBA
				(
					pixel,
					surface->format,
					&r,&g,&b,&a
				);
				break;
		}
		//printf("r:%d,g:%d,b:%d,a:%d\n",r,g,b,a);
		return Color(r,g,b,a).get();
	}

	ImageLoaderSDL::ImageLoaderSDL()
	{
		const int flags		= IMG_INIT_JPG|IMG_INIT_PNG;
		const int initted	= IMG_Init(flags);

		if((initted&flags) != flags)
		{
		    throw ImageException("ImageLoaderSDL Error: "+Core::String(IMG_GetError()));
		}
		IMG_Quit();
	}

	void ImageLoaderSDL::load(Image& pImage, const std::string& pImageName) const
	{
		Core::File file(pImageName,std::ios::in | std::ios::binary);

		if(file.is_open())
		{
			load
			(
				pImage,
				file,
				file.getSize()
			);
		}
		else
		{
			throw ImageException("Unable to load Image: "+pImageName+".");
		}
	}

	void ImageLoaderSDL::load
	(
		Image&		pImage,
		Core::File&	pFile,
		const int&	pDataLength
	) const
	{
		SDL_RWops*			sdlFile;
		SDL_Surface*		sdlImage;
		SDL_Palette*		sdlPalette;
		Palette*			gorgonPalette;
		unsigned char*		mData		= NULL;
		size_t				mDataLength	= 0;

		try
		{
			mDataLength	= (pDataLength > 0) ? pDataLength : pFile.getSize();
			mData		= new unsigned char[mDataLength];
			if(mData == NULL)
			{
				throw ImageException("Não foi possível alocar memória.");
			}
			pFile.read((char*)mData, mDataLength);
			
			sdlFile		= SDL_RWFromMem((void*)mData, mDataLength);
			sdlImage	= IMG_Load_RW(sdlFile, 0);
			if(sdlImage == NULL) throw ImageException(IMG_GetError());
			sdlPalette	= sdlImage->format->palette;

			if(sdlImage->format->BitsPerPixel <= 8)
			{
				pImage.create(sdlImage->w, sdlImage->h, 8);
			}
			else
			{
				pImage.create(sdlImage->w, sdlImage->h);
			}

			for(register int h = 0; h < sdlImage->h; ++h)
			{
				for(register int w = 0; w < sdlImage->w; ++w)
				{
					pImage.drawPixel
					(
						w,
						h,
						getPixel(sdlImage, w, h)
					);
				}
			}

			if(sdlPalette != NULL)
			{
				gorgonPalette = new Palette();
				for(register int i = sdlPalette->ncolors - 1; i >=0; --i)
				{
					gorgonPalette->setColor
					(
						sdlPalette->colors[i].r,
						sdlPalette->colors[i].g,
						sdlPalette->colors[i].b,
						i
					);
				}
				pImage.setPalette(gorgonPalette, true);
			}
			delete mData;
			SDL_FreeRW(sdlFile);
			SDL_FreeSurface(sdlImage);
		}
		catch(Core::Exception& e)
		{
			throw ImageException(e.what());
		}
		mDataLength	= 0;
		mData		= NULL;
	}

	void ImageLoaderSDL::save(Image& pImage, Core::File& pFile) const
	{
	/*
		SDL_RWops*			sdlFile;
		SDL_Surface*		sdlImage;

		sdlImage = SDL_createSurface(0,pImage.getWidth(),pImage.getHeight(),pImage.getBpp());
		SDL_SaveBMP_RW(sdlImage,sdlFile,0);*/
		throw ImageException("SDL imageloader não possui um saver.");
	}

	void ImageLoaderSDL::save(Image& pImage, const std::string& pImageName) const
	{
		Core::File file(pImageName,std::ios::out | std::ios::binary);

		if(file.is_open())
		{
			save(pImage,file);
		}
		else
		{
			throw ImageException("Unable to save Image: "+pImageName+".");
		}
	}
	/**
	 * @todo fazer  uma verificação nos formatos aceitos
	 */
	void ImageLoaderSDL::setSaveFormat(const std::string& pSaveFormat)
	{
		mSaveFormat = pSaveFormat;
	}
}
