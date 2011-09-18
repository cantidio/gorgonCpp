/*
 *
 *    __     ___   _ __    __     ___     ___
 *  /'_ `\  / __`\/\`'__\/'_ `\  / __`\ /' _ `\
 * /\ \L\ \/\ \L\ \ \ \//\ \L\ \/\ \L\ \/\ \/\ \
 * \ \____ \ \____/\ \_\\ \____ \ \____/\ \_\ \_\
 *  \/___L\ \/___/  \/_/ \/___L\ \/___/  \/_/\/_/
 *    /\____/              /\____/
 *    \_/__/               \_/__/
 *
 *  Copyright (C) 2008-2011  Cantidio Oliveira Fontes
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */
#ifndef _GORGON_IMAGE_ALLEGRO_
#define _GORGON_IMAGE_ALLEGRO_
#include <gorgon++/graphic/image_base.hpp>

struct ALLEGRO_BITMAP;
namespace Gorgon	{
namespace Graphic	{
namespace Addon
{
	/**
	 * Class that represents the implementation of the ImageBase in Allegro5
	 *
	 * @author	Cantidio	Oliveira Fontes
	 * @since	26/05/2011
	 * @version	01/06/2011
	 * @see		Graphic::Image
	 * @ingroup	Graphic::Addon
	 */
	class ImageBase : public Graphic::ImageBase
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 */
			ImageBase();
			ImageBase( ALLEGRO_BITMAP* pImage, const bool& pFreeSource );
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const int&		pWidth	, the width of the image
			 * @param	const int&		pHeight	, the height of the image
			 * @param	const int&		pBpp	, the bits per pixel of the image
			 * @param	const Color&	pColor	, the color the fill the image
			 * @details
			 *			if this method couldn't create the image, it will return a GraphicException
			 */
			ImageBase
			(
				const int& pWidth,
				const int& pHeight,
				const int& pBpp
			);
			/**
			 * Copy Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const ImageAllegro& pImage, the source image
			 */
			ImageBase(const ImageBase& pImage);
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	01/06/2011
			 */
			virtual ~ImageBase();
			/**
			 * Method that recreats the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const int&		pWidth	, the width of the image
			 * @param	const int&		pHeight	, the height of the image
			 * @param	const int&		pBpp	, the bits per pixel of the image
			 * @param	const Color&	pColor	, the color the fill the image
			 * @details
			 *			if this method couldn't create the image, it will return a GraphicException
			 */
			virtual void create
			(
				const int&		pWidth,
				const int&		pHeight,
				const int&		pBpp
			);
			//todo ver oq fazer com isso. kkkk
			virtual void lock();
			virtual void unlock();
			virtual void applyAsTarget();
			/**
			 * Method that clears the image with the requested color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const Color& pColor, the color to paint the image
			 */
			virtual void clear(const Color& pColor) const;
			/**
			 * Method that copies a rectangular area of this image to the TargetImage
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/06/2011
			 * @version	11/06/2011
			 * @param	const Core::Point& pPosition		, the position in the destination Image
			 * @param	const Core::Point& pSourcePosition	, the position in this Image where it will get to draw
			 * @param	const int& pWidth					, the width of the cut in the image
			 * @param	const int& pHeight					, the height of the cut in the image
			 */
			virtual void blit(const Core::Point& pPosition, const Core::Point& pSourcePosition, const int& pWidth, const int& pHeight) const;
			/**
			 * Method that draws the image in the requested position into the current target Image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const Core::Point& pPosition, the position the image will be drawn
			 *
			 * @see		System::setTargetImage
			 */
			virtual void draw(const Core::Point& pPosition) const;
			/**
			 * Method that draws the image in the requested position and mirroring
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const Core::Point&	pPosition	, the position in the target Image to draw this Image
			 * @param	const Mirroring&	pMirroring	, the mirroring of the image
			 *
			 * @see		System::setTargetImage
			 * @see		Mirroring
			 */
			virtual void draw(const Core::Point& pPosition, const Mirroring& pMirroring) const; //drawFlip
			/**
			 * Method that draws the image in the requested position and angle
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since
			 * @param	const Core::Point&	pPosition	, the position in the target Image to draw
			 * @param	const float&		pAngle		, the angle of the image
			 * @param	conat Core::Point&	pCenter		, the center of the image
			 *
			 * @see		System::setTargetImage
			 * @see		Mirroring
			 */
			virtual void draw
			(
				const Core::Point&	pPosition,
				const float&		pAngle,
				const Core::Point&	pCenter
			) const;//draw rotated
			/**
			 * Method that draws the image in the requested position, mirroring and angle
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since
			 * @param	const Core::Point&	pPosition	, the position in the target Image to draw
			 * @param	const float&		pAngle		, the angle of the image
			 * @param	conat Core::Point&	pCenter		, the center of the image
			 * @param	const Mirroring&	pMirroring	, the mirroring of the image
			 *
			 * @see		System::setTargetImage
			 * @see		Mirroring
			 */
			virtual void draw
			(
				const Core::Point&	pPosition,
				const float&		pAngle,
				const Core::Point&	pCenter,
				const Mirroring&	pMirroring
			) const; //draw rotated flipped
			/**
			 * Method that draws the image in the requested position and mirroring, scalling it
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const Core::Point&			pPosition	, the position in the target Image to draw this Image
			 * @param	const int&					pWidth		, the width of the resulted image
			 * @param	const int&					pHeight		, the height of the resulted image
			 * @param	const Mirroring&	pMirroring	, the mirroring of the image
			 *
			 * @see		System::setTargetImage
			 * @see		Mirroring
			 */
			virtual void draw
			(
				const Core::Point& pPosition,
				const int& pWidth,
				const int& pHeight,
				const Mirroring& pMirroring
			) const; //drawScaled
			/**
			 * Method that draws the image and multiplies all colors in the image with the given color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Core::Point&	pPosition	, position in the target Image to draw this Image
			 * @param	const Color&		pTint		, the color that will tint the image
			 *
			 * @see		System::setTargetImage
			 * @see		Mirroring
			 */
			virtual void draw(const Core::Point& pPosition, const Color& pTint) const;//drawTinted
			/**
			 * Method that draws the image and multiplies all colors in the image with the given color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Core::Point&	pPosition	, position in the target Image to draw this Image
			 * @param	const Color&		pTint		, the color that will tint the image
			 * @param	const Mirroring&	pMirroring	, the mirroring of the image
			 *
			 * @see		System:setTargetImage
			 * @see		Mirroring
			 */
			virtual void draw
			(
				const Core::Point& pPosition,
				const Color& pTint,
				const Mirroring& pMirroring
			) const;//drawTinted
			/**
			 * Method that draws the image and multiplies all colors in the image with the given color and angle
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Core::Point&	pPosition	, position in the target Image to draw this Image
			 * @param	const Color&		pTint		, the color that will tint the image
			 * @param	const float&		pAngle		, the angle of the image
			 * @param	const Core::Point&	pCenter		, the center of the image
			 *
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */
			virtual void draw
			(
				const Core::Point& pPosition,
				const Color& pTint,
				const float& pAngle,
				const Core::Point& pCenter
			) const;//drawTinted rotated
			/**
			 * Method that draws the image and multiplies all colors in the image with the given color, angle and mirroring
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Core::Point&	pPosition	, position in the target Image to draw this Image
			 * @param	const Color&		pTint		, the color that will tint the image
			 * @param	const float&		pAngle		, the angle of the image
			 * @param	const Core::Point&	pCenter		, the center of the image
			 * @param	const Mirroring&	pMirroring	, the mirroring of the image
			 *
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */
			virtual void draw
			(
				const Core::Point&	pPosition,
				const Color&		pTint,
				const float&		pAngle,
				const Core::Point&	pCenter,
				const Mirroring&	pMirroring
			) const;//drawTinted rotated fliped
			/**
			 * Method that returns the color at the given position in the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/06/2009
			 * @version	26/05/2011
			 * @param	const Core::Point&	pPosition, the position of the pixel
			 * @return	Color
			 */
			virtual Color getPixel(const Core::Point& pPosition) const;
			/**
			 * Method that returns if the image is empty
			 *
			 * @author  Cantidio Oliveira Fontes
			 * @since   13/12/2009
			 * @version 26/05/2011
			 * @return  bool
			 * @todo	implement this method
			 */
			virtual bool isEmpty() const;
			/**
			 * Operator that receives an Image and clone it to this one
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const ImageBase& pImage, the source image
			 */
			virtual void operator =(const ImageBase& pImage);
			/**
			 * Operator that returns true if the images have the same colors
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	27/06/2011
			 * @param	const ImageBase& pImageBase, the image
			 * @return	bool
			 * @todo	implement this method
			 */
			virtual bool operator ==(const Graphic::ImageBase& pImage) const;
			/**
			 * Method that clones the image and return a pointer to the cloned image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	27/05/2011
			 * @return	Graphic::ImageBase*
			 * @details
			 *			The pointer of the ImageBase isn't deleted by this object,
			 * you must handly free it
			 */
			virtual Graphic::ImageBase* clone() const;
			/**
			 * Convert the current image to the display format, for fast drawing
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/06/2011
			 * @version	14/06/2011
			 */
			virtual void convertToDisplayFormat();
			virtual void load(Core::File& pFile, const int& pDataLength);
		protected:
			/**
			 * Method that applies the alplha mask into the Image
			 *
			 * @since	27/05/2011
			 * @version	27/05/2011
			 */
			virtual void applyAlphaMask();

			ALLEGRO_BITMAP *mData;/**<< The allegro image data*/
			bool mFreeSource;
	};
}}}
#endif

