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
#ifndef _GORGON_GRAPHIC_IMAGE_
#define _GORGON_GRAPHIC_IMAGE_
#include <fstream>
#include <string>
#include "../core/point.hpp"
#include "palette.hpp"
#include "mirroring.hpp"
#include "color.hpp"
#include "image_loader.hpp"
#include "image_base.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Class that represents an Image
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	20/01/2009
	 * @version	26/05/2011
	 * @todo	implementar os métodos save e load da classe
	 * @ingroup	Graphic
	 */
	class Image
	{
		protected:
			ImageBase*	mImage;			/**<< the image data*/
			Palette*	mPalette;		/**<< Pointer to the color palette, NULL if the image dont have one*/
			bool		mFreeImage;		/**<< if true the class will destroy the image as requested*/
			bool		mFreePalette;	/**<< if true the mPalette will be deleted when need by the class*/
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 */
			Image();
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	24/01/2009
			 * @param	ImageBase*		pImage		, pointer to the imageBase
			 * @param	const bool&*	FreeSource	, if true the class will free the image when needed
			 */
			Image(ImageBase* pImage, const bool& pFreeSource);
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2009
			 * @version	26/05/2011
			 * @param	const int&		pWidth	, the width of the image
			 * @param	const int&		pHeight	, the height of the image
			 * @param	const int&		pBpp	, the bits per pixel of the image
			 * @details
			 *			if this method couldn't create the image, it will return a GraphicException
			 */
			Image
			(
				const int& pWidth,
				const int& pHeight,
				const int& pBpp = 0
			);
			/**
			 * Copy Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/01/2009
			 * @version	27/05/2011
			 * @param	const Image& pImage, original image
			 */
			Image(const Image& pImage);
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	26/05/2011
			 * @param	const std::string& pFileName	, the name of the image to be loaded
			 * @param	const ImageLoader& pImageLoader , the imageLoader
			 */
			Image(const std::string& pFileName, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	26/05/2011
			 * @param	Core::File&			pFile			, the file where the image is stored
			 * @param	const ImageLoader&	pImageLoader	, the imageLoader
			 */
			Image(Core::File& pFile, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Método destrutor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	25/01/2009
			 */
			virtual ~Image();
			/**
			 * Method that recreats the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const int&		pWidth	, the width of the image
			 * @param	const int&		pHeight	, the height of the image
			 * @param	const int&		pBpp	, the bits per pixel of the image
			 * @details
			 *			if this method couldn't create the image, it will return a GraphicException
			 */
			void create
			(
				const int& pWidth,
				const int& pHeight,
				const int& pBpp = 0
			);
			/**
			 * Method that sets the ImageBase of the Image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	ImageBase *pImage		, pointer to the ImageBase
			 * @param	const bool& pFreeSource	, if true the class will free the ImageBase when needed
			 */
			void setImageBase(ImageBase* pImage, const bool& pFreeSource);
			/**
			 * Method that sets the ImageBase of the Image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const ImageBase& pImage, reference to the ImageBase that will be cloned and attached to the image
			 */
			void setImageBase(const ImageBase& pImage);
			/**
			 * Method that gets the ImageBase of the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @return	ImageBase*
			 */
			const ImageBase* getImageBase() const;
			/**
			 * Method that sets the color palette of the Image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	26/05/2011
			 * @param	Palette *pPalette			, pointer to the color palette
			 * @param	const bool& pFreeSource		, if true the class will free the palette in its destructor
			 */
			void setPalette(Palette *pPalette, const bool& pFreeSource);
			/**
			 * Method that sets the color palette of the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	02/05/2011
			 * @version	26/05/2011
			 * @param	const Palette& pPalette, reference to the palette that will be cloned and attached to the image
			 * @details
			 *			This method clones the palette into the image
			 */
			void setPalette(const Palette& pPalette);
			/**
			 * Method that returns the image internal palette
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	26/05/2011
			 * @return	Palette*
			 */
			const Palette* getPalette() const;
			/**
			 * Método para descrever a imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/01/2009
			 * @version	21/01/2008
			 * @return	const std::string
			 */
			std::string describe() const;
			/**
			 * Método para usar a paleta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	20/10/2009
			 * @todo 	implementar ou deletar?
			 */
			void usePalette() const;
			/**
			 * Method that returns the width of the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @return	int
			 */
			int getWidth() const;
			/**
			 * Method that returns the height of the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @return	int
			 */
			int getHeight() const;
			/**
			 * Method that returns the bits per pixel of the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @return	int
			 */
			int getBpp() const;
			/**
			 * Method that takes this color and makes it transparent into the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	27/05/2011
			 * @param	const Color& pColor, the color that will be converted in transparent
			 */
			void setAlphaMask(const Color& pColor);
			/**
			 * Method that returns the transparent color of the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 * @return	Color
			 */				
			Color getAlphaMask() const;
			/**
			 * Method that returns the number of colors used in the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/01/2009
			 * @version	27/05/2011
			 * @return	int
			 */
			int getColorNumber() const;
			/**
			 * Method that returns the color at the given position in the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/06/2009
			 * @version	26/05/2011
			 * @param	const Core::Point&	pPosition, the position of the pixel
			 * @return	Color
			 */
			Color getPixel(const Core::Point& pPosition) const;
			
			void lock();
			void unlock();
			void setAsTarget();
			
			/**
			 * Method that clears the image with the requested color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const Color& pColor, the color to paint the image
			 */
			void clear(const Color& pColor);
			/**
			 * Method that draws the image in the requested position into the current target Image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const Core::Point& pPosition, the position the image will be drawn
			 *
			 * @see		Graphic::setTargetImage
			 */
			void draw(const Core::Point& pPosition) const;
			/**
			 * Method that draws the image in the requested position and mirroring
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const Core::Point&	pPosition	, the position in the target Image to draw this Image
			 * @param	const Mirroring&	pMirroring	, the mirroring of the image
			 *
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */
			void draw(const Core::Point& pPosition, const Mirroring& pMirroring) const; //drawFlip
			/**
			 * Method that draws the image in the requested position, and angle
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since
			 * @param	const Core::Point&	pPosition	, the position in the target Image to draw
			 * @param	const float&		pAngle		, the angle of the image
			 * @param	conat Core::Point&	pCenter		, the center of the image	
			 *
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */	
			void draw//draw rotated
			(
				const Core::Point&	pPosition,
				const float&		pAngle,
				const Core::Point&	pCenter
			) const;
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
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */	
			void draw//draw rotated flipped
			(
				const Core::Point&	pPosition,
				const float&		pAngle,
				const Core::Point&	pCenter,
				const Mirroring&	pMirroring
			) const;
			/**
			 * Method that draws the image in the requested position and mirroring, scalling it
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/05/2011
			 * @version	26/05/2011
			 * @param	const Core::Point&	pPosition	, the position in the target Image to draw this Image
			 * @param	const int&			pWidth		, the width of the resulted image
			 * @param	const int&			pHeight		, the height of the resulted image
			 * @param	const Mirroring&	pMirroring	, the mirroring of the image
			 *
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */
			void draw
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
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */
			void draw(const Core::Point& pPosition, const Color& pTint) const;//drawTinted
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
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */
			void draw(const Core::Point& pPosition, const Color& pTint, const Mirroring& pMirroring) const;//drawTinted
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
			void draw
			(
				const Core::Point&	pPosition,
				const Color&		pTint,
				const float&		pAngle,
				const Core::Point&	pCenter
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
			void draw
			(
				const Core::Point&	pPosition,
				const Color&		pTint,
				const float&		pAngle,
				const Core::Point&	pCenter,
				const Mirroring&	pMirroring
			) const;//drawTinted rotated fliped
			/**
			 * Method that returns if the image is empty
			 *
			 * @author  Cantidio Oliveira Fontes
			 * @since   13/12/2009
			 * @version 26/05/2011
			 * @return  bool
			 */
			bool isEmpty() const;
			/**
			 * Operador de comparação
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	13/12/2009
			 * @param	const Image& pImage, imagem a se comparar
			 * @return	bool
			 */
			bool operator ==(const Image& pImage) const;
			/**
			 * Operator that receives an Image and clone it to this one
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	26/05/2011
			 * @param	const ImageAllegro& pImage, the source image
			 */
			void operator =(const Image& pImage);
			/**
			 * Method that loads the image from a file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	07/08/2009
			 * @param	const std::string&	pFileName		, the name of the image file
			 * @param	const ImageLoader&	pImageLoader	, the ImageLoader
			 */
			virtual void load(const std::string& pFileName,const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Method that loads the image from a file previously opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	07/08/2009
			 * @param	File&				pFile			, file previously opened
			 * @param	const ImageLoader&	pImageLoader	, the ImageLoader
			 */
			virtual void load(Core::File& pFile,const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Method that saves the image in a file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	const string& pSpriteName, the name of the image file
			 * @param	const ImageLoader& pImageLoader, the imageLoader
			 */
			virtual void save(const std::string& pFileName,const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Method that saves the image in a file previously opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	Core::File&			pFile			, file previously opened
			 * @param	const ImageLoader&	pImageLoader	, the ImageLoader
			 */
			virtual void save(Core::File& pFile,const ImageLoader& pImageLoader = ImageLoader::getLoader());
	};
}}
#endif
