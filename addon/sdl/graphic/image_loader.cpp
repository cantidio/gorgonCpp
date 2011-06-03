#include "image_loader.hpp"
#include <gorgon++/gorgon.hpp>
#include <gorgon++/graphic/exception.hpp>
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

	Graphic::Color getPixel(SDL_Surface *surface, int x, int y)
	{
		Uint8 r=0, g=0, b=0, a=255;
		Uint32 pixel = getpixel(surface,x,y);
		switch(surface->format->BytesPerPixel)
		{
			case 1:
				//return pixel;
				r = g = b = pixel;
				break;
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
		return Graphic::Color(r/255.0f , g/255.0f, b/255.0f, a/255.0f);
	}

	ImageLoaderSDL::ImageLoaderSDL()
	{
		const int flags		= IMG_INIT_JPG|IMG_INIT_PNG;
		const int initted	= IMG_Init(flags);

		if((initted&flags) != flags)
		{
			raiseGraphicException("ImageLoaderSDL::ImageLoaderSDL(): Error, " + std::string(IMG_GetError()));
		}
		IMG_Quit();
	}

	void ImageLoaderSDL::load(Graphic::Image& pImage, const std::string& pImageName) const
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
			raiseGraphicException("ImageLoaderSDL::load(pImage,\""+pImageName+"\"): Error, the file could not be opened for reading.");
		}
	}

	void ImageLoaderSDL::load
	(
		Graphic::Image&	pImage,
		Core::File&		pFile,
		const int&		pDataLength
	) const
	{
		SDL_RWops*			sdlFile			= NULL;
		SDL_Surface*		sdlImage		= NULL;
		SDL_Palette*		sdlPalette		= NULL;
		Graphic::Palette*	gorgonPalette	= NULL;
		unsigned char*		mData			= NULL;
		size_t				mDataLength		= 0;

		try
		{
			mDataLength	= (pDataLength > 0) ? pDataLength : pFile.getSize();
			mData		= new unsigned char[mDataLength];
			if(mData == NULL)
			{
				/**@todo talvez acima retorna uma exception, tem que testar manu*/
				raiseGraphicException("ImageLoaderSDL::load(pImage,pFile,pDataLength): Error, could not allocate memory.");
			}
			pFile.read((char*)mData, mDataLength);

			sdlFile		= SDL_RWFromMem((void*)mData, mDataLength);
			sdlImage	= IMG_Load_RW(sdlFile, 0);
			if(sdlImage == NULL)
			{
				raiseGraphicException(IMG_GetError());
			}
			sdlPalette	= sdlImage->format->palette;

			if(sdlImage->format->BitsPerPixel <= 8)
			{
				pImage.create(sdlImage->w, sdlImage->h, 8);
			}
			else
			{
				pImage.create(sdlImage->w, sdlImage->h);
				sdlPalette = NULL;
			}
			Graphic::Image target = Graphic::System::get().getTargetImage();
			Graphic::System::get().setTargetImage(pImage);
			//pImage.setAsTarget();
			pImage.lock();

			for(register int h = 0; h < sdlImage->h; ++h)
			{
				for(register int w = 0; w < sdlImage->w; ++w)
				{
					Graphic::System::get().drawPixel( Core::Point(w, h), getPixel(sdlImage, w, h) );
				}
			}

			pImage.unlock();
			Graphic::System::get().setTargetImage(target);
			if(sdlPalette != NULL)
			{
				gorgonPalette = new Graphic::Palette(sdlPalette->ncolors);
				for(register int i = sdlPalette->ncolors - 1; i >=0; --i)
				{
					gorgonPalette->setColor
					(
						sdlPalette->colors[i].r / 255.0f,
						sdlPalette->colors[i].g / 255.0f,
						sdlPalette->colors[i].b / 255.0f,
						i
					);
				}
				pImage.setPalette(gorgonPalette, true);
			}
			delete mData;
			SDL_FreeRW(sdlFile);
			SDL_FreeSurface(sdlImage);
		}
		catch(Core::Exception& exception)
		{
			raiseGraphicExceptionE("ImageLoaderSDL::load(pImage,pFile,pDataLength): Error, while loading the image.",exception);
		}
		mDataLength	= 0;
		mData		= NULL;
	}

	void ImageLoaderSDL::save(Graphic::Image& pImage, Core::File& pFile) const
	{
	/**
	 * @todo implementar pelo menos o método de salvar como BMP
		SDL_RWops*			sdlFile;
		SDL_Surface*		sdlImage;

		sdlImage = SDL_createSurface(0,pImage.getWidth(),pImage.getHeight(),pImage.getBpp());
		SDL_SaveBMP_RW(sdlImage,sdlFile,0);*/
		raiseGraphicException("ImageLoaderSDL::save(pImage,pFile): Error, SDL imageloader cant save images");
	}

	void ImageLoaderSDL::save(Graphic::Image& pImage, const std::string& pImageName) const
	{
		Core::File file(pImageName,std::ios::out | std::ios::binary);

		if(file.is_open())
		{
			save(pImage,file);
		}
		else
		{
			raiseGraphicException("ImageLoaderSDL::ImageLoaderSDL(pImage,\""+pImageName+"\"): Error, the file could not be opened for writting.");
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
