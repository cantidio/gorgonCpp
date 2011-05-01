#include "image_loader.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

namespace Gorgon
{
	Uint32 getpixel(SDL_Surface *surface, int x, int y)
	{
		int bpp = surface->format->BytesPerPixel;
		/* Here p is the address to the pixel we want to retrieve */
		Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

		switch (bpp)
		{
			case 1:	return *p;
			case 2:	return *(Uint16 *)p;
			case 3:
				if (SDL_BYTEORDER != SDL_BIG_ENDIAN)
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
				return 0;       /* shouldn't happen, but avoids warnings */
		} // switch
	}
	
	void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
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
	}

	ImageLoaderSDL::ImageLoaderSDL()
	{
		const int flags		= IMG_INIT_JPG|IMG_INIT_PNG;
		const int initted	= IMG_Init(flags);

		if((initted&flags) != flags)
		{
		    printf("IMG_Init: Failed to init required jpg and png support!\n");
		    printf("IMG_Init: %s\n", IMG_GetError());
		    // handle error
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
		
		Gorgon::Color		gorgonColor;
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
			SDL_FreeRW(sdlFile);
			delete mData;

			pImage.create
			(
				sdlImage->w,
				sdlImage->h//,
				//sdlImage->format->BitsPerPixel //vamos ver se isso fica ou não
			);
			for(register int h = 0; h < sdlImage->h; ++h)
			{
				for(register int w = 0; w < sdlImage->w; ++w)
				{
					pImage.drawPixel
					(
						w,
						h,
						getpixel(sdlImage, w, h)
					);
				}
			}
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
		/**
		 * @todo implementar esse método
		 */
		/*Magick::Geometry	magickSize;
		Magick::Image		magickImage;
		Magick::ColorRGB	magickColor;
		Magick::Blob		magickBlob;
		try
		{
			magickSize.width	( pImage.getWidth()  );
			magickSize.height	( pImage.getHeight() );
			magickImage.size	( magickSize );
			//magickImage.type	( Magick::OptimizeType );
			//magickImage.type	( Magick::TrueColorType );

			magickImage.magick	( mSaveFormat );
			magickImage.fillColor(Magick::ColorRGB(255,0,255));

			for(unsigned int h = 0; h < pImage.getHeight(); ++h)
			{
				for(unsigned int w = 0; w < pImage.getWidth(); ++w)
				{
					magickColor.red		( pImage.getColor(w,h).getRed()		/ (double)255);
					magickColor.green	( pImage.getColor(w,h).getGreen()	/ (double)255);
					magickColor.blue	( pImage.getColor(w,h).getBlue()	/ (double)255);
					magickColor.alpha	( pImage.getColor(w,h).getAlfa()	/ (double)255);
					magickImage.pixelColor (w, h, magickColor );
				}
			}
			magickImage.write(&magickBlob);
			pFile.write((char*)magickBlob.data(), magickBlob.length());
		}
		catch(Magick::Exception& e)
		{
			throw ImageException(e.what());
		}*/
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
