#include <graphic/exception.hpp>
#include <addon/allegro5/graphic/image_base.hpp>
#include <addon/allegro5/graphic/common.hpp>
#include <sstream>

namespace Gorgon	{
namespace Graphic	{
namespace Addon
{
	void ImageBase::create
	(
		const int& pWidth,
		const int& pHeight,
		const int& pBpp
	)
	{
		if(mData != NULL)
		{
			if( al_get_target_bitmap() == mData )
			{
				al_set_target_bitmap(NULL);
			}
			al_destroy_bitmap(mData);
		}
		mData		= al_create_bitmap(pWidth, pHeight);
		mBpp		= (mData != NULL) ? al_get_pixel_format_bits(al_get_bitmap_format(mData)) : 0;
		mWidth		= pWidth;
		mHeight		= pHeight;
		mFreeSource	= true;

		if(mData == NULL)
		{
			raiseGraphicException("ImageBase::create(): Error, could not create the image data.");
		}
	}

	ImageBase::ImageBase()
	{
		mData		= NULL;
		mFreeSource	= true;
		mWidth		= 0;
		mHeight		= 0;
		mBpp		= 0;
	}

	ImageBase::ImageBase(ALLEGRO_BITMAP* pImage, const bool& pFreeSource)
	{
		mData		= pImage;
		mFreeSource	= pFreeSource;
		mWidth		= (mData != NULL) ? al_get_bitmap_width(mData) : 0;
		mHeight		= (mData != NULL) ? al_get_bitmap_height(mData) : 0;
		mBpp		= (mData != NULL) ? al_get_pixel_format_bits(al_get_bitmap_format(mData)) : 0;
	}

	ImageBase::ImageBase
	(
		const int& pWidth,
		const int& pHeight,
		const int& pBpp
	)
	{
		mData = NULL;
		create(pWidth, pHeight, pBpp);
	}

	ImageBase::ImageBase(const ImageBase& pImage)
	{
		mData = NULL;
		(*this) = pImage;
	}

	ImageBase::~ImageBase()
	{
		if(mFreeSource && mData != NULL)
		{
			al_destroy_bitmap(mData);
		}
		mData = NULL;
	}

	void ImageBase::applyAlphaMask()
	{
		if(mData != NULL)
		{
			al_convert_mask_to_alpha(mData, gorgonColort2AllegroColor(mAlphaMask));
		}
	}

	void ImageBase::lock()
	{
		al_lock_bitmap(mData, al_get_bitmap_format(mData), ALLEGRO_LOCK_READWRITE);
	}

	void ImageBase::unlock()
	{
		al_unlock_bitmap(mData);
	}

	void ImageBase::applyAsTarget()
	{
		al_set_target_bitmap(mData);
	}

	void ImageBase::clear(const Color& pColor) const
	{
		ALLEGRO_BITMAP* aux = al_get_target_bitmap();			//pega o target anterior
		al_set_target_bitmap(mData);							//seta como novo target
		al_clear_to_color( gorgonColort2AllegroColor(pColor) );	//limpa com a cor desejada
		al_set_target_bitmap(aux);								//seta o target antigo
	}

	void ImageBase::blit(const Core::Point& pPosition, const Core::Point& pSourcePosition, const int& pWidth, const int& pHeight) const
	{
		al_draw_bitmap_region
		(
			mData,
			pSourcePosition.getX(),	pSourcePosition.getY(),
			pWidth,					pHeight,
			pPosition.getX(),		pPosition.getY(),
			0
		);
	}

	void ImageBase::draw(const Core::Point& pPosition) const //draw
	{
		al_draw_bitmap
		(
			mData,
			pPosition.getX(),
			pPosition.getY(),
			0
		);
	}

	void ImageBase::draw(const Core::Point& pPosition, const Mirroring& pMirroring) const //drawFlip
	{
		al_draw_bitmap
		(
			mData,
			pPosition.getX(), pPosition.getY(),
			gorgonMirroring2AllegroMirroring(pMirroring)
		);
	}

	void ImageBase::draw
	(
		const Core::Point&	pPosition,
		const float&		pAngle,
		const Core::Point&	pCenter
	) const//draw rotated
	{
		al_draw_rotated_bitmap
		(
			mData,
			pCenter.getX()	, pCenter.getY(),
   			pPosition.getX(), pPosition.getY(),
   			pAngle,
   			0
   		);
	}

	void ImageBase::draw
	(
		const Core::Point&	pPosition,
		const float&		pAngle,
		const Core::Point&	pCenter,
		const Mirroring&	pMirroring
	) const //draw rotated
	{
		al_draw_rotated_bitmap
		(
			mData,
			pCenter.getX()	, pCenter.getY(),
   			pPosition.getX(), pPosition.getY(),
   			pAngle,
   			gorgonMirroring2AllegroMirroring(pMirroring)
   		);
	}

	void ImageBase::draw
	(
		const Core::Point& pPosition,
		const int& pWidth,
		const int& pHeight,
		const Mirroring& pMirroring
	) const //drawScaled
	{
		al_draw_scaled_bitmap
		(
			mData,
			0,					0,
			mWidth,				mHeight,
			pPosition.getX(),	pPosition.getY(),
			pWidth, 			pHeight,
			gorgonMirroring2AllegroMirroring(pMirroring)
		);
	}

	void ImageBase::draw(const Core::Point&	pPosition, const Color& pTint) const //draw tinted
	{
		al_draw_tinted_bitmap
		(
			mData,
			gorgonColort2AllegroColor(pTint),
			pPosition.getX(), pPosition.getY(),
			0
		);
	}

	void ImageBase::draw
	(
		const Core::Point& pPosition,
		const Color& pTint,
		const Mirroring& pMirroring
	) const //draw tinted
	{
		al_draw_tinted_bitmap
		(
			mData,
			gorgonColort2AllegroColor(pTint),
			pPosition.getX(), pPosition.getY(),
			gorgonMirroring2AllegroMirroring(pMirroring)
		);
	}

	void ImageBase::draw
	(
		const Core::Point&	pPosition,
		const Color&		pTint,
		const float&		pAngle,
		const Core::Point&	pCenter
	) const//drawTinted rotated
	{
		al_draw_tinted_rotated_bitmap
		(
			mData,
			gorgonColort2AllegroColor(pTint),
   			pCenter.getX()	, pCenter.getY(),
   			pPosition.getX(), pPosition.getY(),
   			pAngle,
   			0
   		);
	}

	void ImageBase::draw
	(
		const Core::Point&	pPosition,
		const Color&		pTint,
		const float&		pAngle,
		const Core::Point&	pCenter,
		const Mirroring&	pMirroring
	) const//drawTinted rotated fliped
	{
		al_draw_tinted_rotated_bitmap
		(
			mData,
   			gorgonColort2AllegroColor(pTint),
   			pCenter.getX()	, pCenter.getY(),
   			pPosition.getX(), pPosition.getY(),
   			pAngle,
   			gorgonMirroring2AllegroMirroring(pMirroring)
   		);
	}

	Color ImageBase::getPixel(const Core::Point& pPosition) const
	{
		return allegroColor2GorgonColor
		(
			al_get_pixel
			(
				mData,
				pPosition.getX(),
				pPosition.getY()
			)
		);
	}

	bool ImageBase::isEmpty() const
	{
		return false;
	}

	void ImageBase::operator =(const ImageBase& pImage)
	{
		if(mData != NULL)
		{
			al_destroy_bitmap(mData);
		}
		mData   = (pImage.mData != NULL) ? al_clone_bitmap(pImage.mData) : NULL;
		mBpp    = pImage.mBpp;
		mWidth  = pImage.mWidth;
		mHeight = pImage.mHeight;

		if(mData == NULL && pImage.mData != NULL)
		{
			raiseGraphicException("ImageBase::operator = () : Error, could not clone the data.");
		}
	}

	bool ImageBase::operator ==(const Graphic::ImageBase& pImage) const
	{
		return false;
	}

	Graphic::ImageBase* ImageBase::clone() const
	{
		return new ImageBase(*this);
	}

	void ImageBase::load(Core::File& pFile, const int& pDataLength)
	{
		ALLEGRO_FILE*	fake_file		= NULL;
		unsigned char*	data			= NULL;
		bool			isTarget		= false;
		char const*		extensions[]	= { ".png", ".pcx", ".bmp", ".gif",".tga", ".tif", ".tiff", ".jpg", ".jpeg", NULL };

		try
		{
			if( mData != NULL )
			{
				isTarget = ( al_get_target_bitmap() == mData ) ? true : false;
				if( mFreeSource )
				{
					al_set_target_bitmap(NULL);
					al_destroy_bitmap( mData );
				}
			}

			data = new unsigned char[pDataLength];
			pFile.read( (char*)data, pDataLength );

			fake_file = al_open_memfile( (void*)data, pDataLength, "rb" );

			for( register int i = 0; extensions[i] != NULL; ++i )
			{
				al_fseek( fake_file, 0, ALLEGRO_SEEK_SET ); //return the file position to its start
				mData = al_load_bitmap_f( fake_file, extensions[i] );
				if( mData != NULL ) //if the image could be loaded quit the loop
				{
					break;
				}
			}
			if( mData != NULL )
			{
				mBpp		= al_get_pixel_format_bits( al_get_bitmap_format( mData ) ) ;
				mWidth		= al_get_bitmap_width( mData );
				mHeight		= al_get_bitmap_height( mData );
				mFreeSource	= true;
			}
			else
			{
				std::stringstream out;
				out << "ImageBase::load(" << &pFile << ", " << pDataLength << "): Error while loading the image.";
				raiseGraphicException( out.str() );
			}

			al_fclose( fake_file );		//fecha o arquivo
			delete data;				//delata os dados

			if( isTarget ) applyAsTarget();
		}
		catch( std::exception& e )
		{
			std::stringstream out;
			out << "ImageBase::load(" << &pFile << ", " << pDataLength << "): Error in loading the image, couldn't allocate memory for image.";
			raiseGraphicException( out.str() );
		}
	}

	void ImageBase::convertToDisplayFormat()
	{
		al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);

		ALLEGRO_BITMAP* aux = al_clone_bitmap(mData);
		al_destroy_bitmap(mData);
		mData = aux;

		al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
	}

}}}

