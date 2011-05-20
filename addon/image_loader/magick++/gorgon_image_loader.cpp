#include "gorgon_image_loader.hpp"
#include <ImageMagick/Magick++.h>
#include <gorgon++/graphic/image.hpp>
#include <gorgon++/graphic/exception.hpp>
// /usr/include/ImageMagick

namespace Gorgon
{
	ImageLoaderMagick::ImageLoaderMagick(char* pRunDir )
	{
		Magick::InitializeMagick(pRunDir);
	}

	void ImageLoaderMagick::load(Graphic::Image& pImage, const std::string& pImageName) const
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
			std::stringstream out;
			out << "ImageLoaderMagick::load(" << (int)&pImage << ", " << pImageName << "): Error, file could not be opened for reading.";
			raiseGraphicException(out.str());
		}
	}

	void ImageLoaderMagick::load
	(
		Graphic::Image&	pImage,
		Core::File&		pFile,
		const int&		pDataLength
	) const
	{
		Magick::Blob		magickFile;
		Magick::Image		magickImage;
		Magick::ColorRGB	magickColor;
		Graphic::Color		gorgonColor;
		unsigned char*		mData		= NULL;
		size_t				mDataLength	= 0;
		try
		{
			mDataLength	= (pDataLength > 0) ? pDataLength : pFile.getSize();
			mData		= new unsigned char[mDataLength];
			if(mData == NULL)
			{
				/**@todo, talvez esse erro lance uma exception*/
				std::stringstream out;
				out << "ImageLoaderMagick::load(" << (int)&pImage << ", " << (int)&pFile << ", " << pDataLength << "): Error, could not allocate memory.";
				raiseGraphicException(out.str());
			}
			pFile.read((char*)mData, mDataLength);
			magickFile.updateNoCopy(mData, mDataLength);
			magickImage.read( magickFile );

			pImage.create
			(
				magickImage.size().width(),
				magickImage.size().height()
			);
			for(register int h = 0; h < magickImage.size().height(); ++h)
			{
				for(register int w = 0; w < magickImage.size().width(); ++w)
				{
					magickColor = magickImage.pixelColor ( w, h );
					gorgonColor.setRed		(magickColor.red()*255);
					gorgonColor.setGreen	(magickColor.green()*255);
					gorgonColor.setBlue		(magickColor.blue()*255);
					gorgonColor.setAlpha	((magickColor.alpha() >= 0 ) ? 0 : magickColor.alpha()*255);//feito pare eliminar lixo

					pImage.drawPixel
					(
						w,
						h,
						gorgonColor.get()
					);
				}
			}
		}
		catch(Magick::Exception& e)
		{
			std::stringstream out;
			out << "ImageLoaderMagick::load(" << (int)&pImage << ", " << (int)&pFile << ", " << pDataLength << "): Error, " << e.what();
			raiseGraphicException(out.str());
		}
		catch(Core::Exception& exception)
		{
			std::stringstream out;
			out << "ImageLoaderMagick::load(" << (int)&pImage << ", " << (int)&pFile << ", " << pDataLength << "): Error while loading the image.";
			raiseGraphicExceptionE(out.str(), exception);
		}
		mDataLength	= 0;
		mData		= NULL;
	}

	void ImageLoaderMagick::save(Graphic::Image& pImage, Core::File& pFile) const
	{
		Magick::Geometry	magickSize;
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
					magickColor.alpha	( pImage.getColor(w,h).getAlpha()	/ (double)255);
					magickImage.pixelColor (w, h, magickColor );
				}
			}
			magickImage.write(&magickBlob);
			pFile.write((char*)magickBlob.data(), magickBlob.length());
		}
		catch(Magick::Exception& e)
		{
			std::stringstream out;
			out << "ImageLoaderMagick::save(" << (int)&pImage << ", " << (int)&pFile << "): Error, " << e.what();
			raiseGraphicException(out.str());
		}
	}

	void ImageLoaderMagick::save(Graphic::Image& pImage, const std::string& pImageName) const
	{
		Core::File file(pImageName,std::ios::out | std::ios::binary);

		if(file.is_open())
		{
			save(pImage,file);
		}
		else
		{
			std::stringstream out;
			out << "ImageLoaderMagick::save(" << (int)&pImage << ", \"" << pImageName << "\"): Error, could not open the file fro writting.";
			raiseGraphicException(out.str());
		}
	}
	/**
	 * @todo fazer  uma verificação nos formatos aceitos
	 */
	void ImageLoaderMagick::setSaveFormat(const std::string& pSaveFormat)
	{
		mSaveFormat = pSaveFormat;
	}
}


