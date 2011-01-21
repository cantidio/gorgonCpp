#include "gorgon_image_loader.hpp"
#include <ImageMagick/Magick++.h>
#define magickColorToGorgon(color) 255 * color / MaxRGB
#define gorgonColorToMagick(color) color * MaxRGB / 255

namespace Gorgon
{
	ImageLoaderMagick::ImageLoaderMagick(char* pRunDir )
	{
		Magick::InitializeMagick(pRunDir);
	}

	void ImageLoaderMagick::load(Image& pImage, const std::string& pImageName) const
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
	void ImageLoaderMagick::load
	(
		Image&		pImage,
		Core::File&	pFile,
		const int&	pDataLength) const
	{
		Magick::Blob	magickFile;
		Magick::Image	magickImage;
		Magick::Color	magickColor;
		Gorgon::Color	gorgonColor;
		unsigned char*	mData		= NULL;
		size_t			mDataLength	= 0;
		try
		{
			mDataLength	= (pDataLength > 0) ? pDataLength : pFile.getSize();
			mData		= new unsigned char[mDataLength];
			if(mData == NULL)
			{
				throw ImageException("Não foi possível alocar memória.");
			}
			pFile.read((char*)mData, mDataLength);
			magickFile.update(mData, mDataLength);
			magickImage.read( magickFile );

			pImage.create
			(
				magickImage.size().width(),
				magickImage.size().height()
			);
			for(unsigned int h = 0; h < magickImage.size().height(); ++h)
			{
				for(unsigned int w = 0; w < magickImage.size().width(); ++w)
				{
					magickColor = magickImage.pixelColor ( w, h );
					gorgonColor.setRed		( magickColorToGorgon( magickColor.redQuantum()		));
					gorgonColor.setGreen	( magickColorToGorgon( magickColor.greenQuantum()	));
					gorgonColor.setBlue 	( magickColorToGorgon( magickColor.blueQuantum()	));
					gorgonColor.setAlfa 	( magickColorToGorgon( magickColor.alphaQuantum()	));

					pImage.drawPixel
					(
						w,
						h,
						gorgonColor.get()
					);
				}
			}
		}
		catch(Magick::Exception &error_)
		{
		//	cout << "deu merda veio" << endl;
		}
		delete mData;
		mDataLength	= 0;
		mData		= NULL;
	}

	void ImageLoaderMagick::save(Image& pImage, Core::File& pFile) const
	{
		Magick::Geometry	magickSize;
		Magick::Image		magickImage;
		Magick::Color		magickColor;
		Magick::Blob		magickBlob;
		try
		{
			magickSize.width	( pImage.getWidth()  );
			magickSize.height	( pImage.getHeight() );
			magickImage.size	( magickSize );
			magickImage.type	( Magick::OptimizeType );
			//magickImage.type	( Magick::TrueColorType );

			magickImage.magick	( "PNG" );

			for(unsigned int h = 0; h < pImage.getHeight(); ++h)
			{
				for(unsigned int w = 0; w < pImage.getWidth(); ++w)
				{
					magickColor = Magick::Color
					(
						gorgonColorToMagick( pImage.getColor(w,h).getRed()		),
						gorgonColorToMagick( pImage.getColor(w,h).getGreen()	),
						gorgonColorToMagick( pImage.getColor(w,h).getBlue()		),
						gorgonColorToMagick( pImage.getColor(w,h).getAlfa()		)
					);
					magickImage.pixelColor (w, h, magickColor );

				}
			}
			magickImage.write(&magickBlob);
			pFile.write((char*)magickBlob.data(), magickBlob.length());
		}
		catch(Magick::Exception& e)
		{
			throw ImageException(e.what());
		}
	}

	void ImageLoaderMagick::save(Image& pImage, const std::string& pImageName) const
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
}

