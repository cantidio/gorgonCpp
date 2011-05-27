#include <allegro5/allegro.h>
#include <gorgon++/graphic/exception.hpp>
#include "image_base.hpp"

namespace Gorgon	{
namespace Graphic	{
namespace Addon
{
	/**
	 * Function that transforms a Mirroring into an Allegro draw Flag
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/05/2011
	 * @version	26/05/2011
	 * @param	const Mirroring& pMirroring, the mirroring obj  to transform
	 * @return	int
	 */
	inline int gorgonMirroring2AllegroMirroring(const Mirroring& pMirroring)
	{
		switch(pMirroring.getType())
		{
			case Mirroring::HFlip:	return ALLEGRO_FLIP_HORIZONTAL;
			case Mirroring::VFlip:	return ALLEGRO_FLIP_VERTICAL;
			case Mirroring::HVFlip:	return ALLEGRO_FLIP_VERTICAL|ALLEGRO_FLIP_HORIZONTAL;
			default:
				return 0;
		}
	}
	/**
	 * Function that converts a Gorgon Color to a allegro one
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/05/2011
	 * @version	26/05/2011
	 * @param	const Color& pColor, the color to be converted
	 * @return	ALLEGRO_COLOR
	 */
	inline ALLEGRO_COLOR gorgonColort2AllegroColor(const Color& pColor)
	{
		return al_map_rgba(pColor.getRed(), pColor.getGreen(), pColor.getBlue(), pColor.getAlpha());
	}
	/**
	 * Function that converts an Allegro Color to a Gorgon one
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/05/2011
	 * @version	26/05/2011
	 * @param	const ALLEGRO_COLOR& pColor, the color to be converted
	 * @return	Color
	 */
	inline Color allegroColor2GorgonColor(const ALLEGRO_COLOR& pColor)
	{
		unsigned char r, g, b, a;
		al_unmap_rgba(pColor, &r, &g, &b, &a);
		return Color(r,g,b,a);
	}
//----------------------------------------------------------------------------------------------------------------------------------------------------
	void ImageBase::create
	(
		const int&		pWidth,
		const int&		pHeight,
		const int&		pBpp
	)
	{
		if(mData != NULL)
		{
			al_destroy_bitmap(mData);
		}
		mData	= al_create_bitmap(pWidth, pHeight);
		mBpp	= (mData != NULL) ? al_get_pixel_format_bits(al_get_bitmap_format(mData)) : 0;
		mWidth	= pWidth;
		mHeight	= pHeight;
		if(mData == NULL)
		{
			raiseGraphicException("ImageBase::create(): Error, could not create the image data.");
		}
	}
		
	ImageBase::ImageBase()
	{
		mData = NULL;
	}
	
	ImageBase::ImageBase
	(
		const int&		pWidth,
		const int&		pHeight,
		const int&		pBpp
	)
	{
		mData = NULL;
		create(pWidth, pHeight, pBpp);
	}
	
	ImageBase::ImageBase(const ImageBase& pImage)
	{
		(*this) = pImage;
	}
	
	ImageBase::~ImageBase()
	{
		if(mData != NULL)
		{
			al_destroy_bitmap(mData);
		}
	}
	
	void ImageBase::applyAlphaMask()
	{
		if(mData != NULL)
		{
			al_convert_mask_to_alpha(mData, gorgonColort2AllegroColor(mAlphaMask));
		}
	}
	void ImageBase::setAsTarget()
	{
		 al_set_target_bitmap(mData);
	}
	
	void ImageBase::clear(const Color& pColor) const
	{
		//al_clear_to_color(ALLEGRO_COLOR color)
		/**@todo implementar isso? */
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
		mData			= (pImage.mData != NULL)	? al_clone_bitmap(pImage.mData)							: NULL;
		mBpp			= (mData != NULL)			? al_get_pixel_format_bits(al_get_bitmap_format(mData))	: 0;

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
		Graphic::ImageBase* out;
		out = new ImageBase(*this);
	}
}}}

