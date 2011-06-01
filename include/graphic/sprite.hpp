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
#ifndef _GORGON_SPRITE_
#define _GORGON_SPRITE_
#include <iostream>
#include <string>
#include "image.hpp"
#include "sprite_header.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Class that represents a sprite
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	01/05/2008
	 * @version	03/05/2011
	 * @ingroup	Graphic
	 * @todo	Comentar toda a classe em ingles
	 */
	class Sprite : public Image
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	30/05/2011
			 * @version	30/05/2011
			 */
			Sprite();
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	30/05/2011
			 * @param	const Image&		pImage	, image of the sprite
			 * @param	const int&			pGroup	, group of the sprite
			 * @param	const int&			pIndex	, index of the sprite
			 * @param	const Core::Point&	pOffset	, offset of the sprite
			 */
			Sprite
			(
				const Image&		pImage,
				const int&			pGroup	= 0,
				const int&			pIndex	= 0,
				const Core::Point&	pOffset	= Core::Point(0,0)
			);
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/01/2009
			 * @param	const std::string&	pSpriteName		, name of the file that has the sprite data
			 * @param	ImageLoader*		pImageLoader	, imageLoader responsable for saving the sprites
			 */
			Sprite(const std::string& pSpriteName, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	Core::File&		pFile			, file previously opened that has the sprite data
			 * @param	ImageLoader*	pImageLoader	, imageLoader responsable for saving the sprites
			 */
			Sprite(Core::File& pFile, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Copy Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/01/2009
			 * @param	const Sprite& pSpriteOrig, Sprite original
			 */
			Sprite(const Sprite& pSpriteOrig);
			/**
			 * Method that describes the sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	23/01/2009
			 * @return	std::string
			 */
			std::string describe() const;
			/**
			 * Método para cortar as bordas transparentes do sprite respeitando seus offsets
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2009
			 * @version	03/06/2009
			 */
			void trim();
			/**
			 * Método para setar o grupo do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	24/01/2008
			 * @param	const int& pGroup, grupo do sprite
			 */
			inline void setGroup(const int& pGroup)
			{
				mGroup = pGroup;
			}
			/**
			 * Método para setar o índice do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	24/01/2008
			 * @param	const int& pIndex, índice do sprite
			 */
			inline void setIndex(const int& pIndex)
			{
				mIndex = pIndex;
			}
			/**
			 * Método para setar o offset do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/05/2011
			 * @version	03/05/2011
			 * @param	const Core::Point& pOffset, offset do sprite
			 */
			inline void setOffset(const Core::Point& pOffset)
			{
				mOffset = pOffset;
			}
			/**
			 * Método para retornar o grupo do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	21/01/2009
			 * @return	int
			 */
			inline int getGroup() const
			{
				return mGroup;
			}
			/**
			 * Método para retornar o indice do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	21/01/2009
			 * @return	int
			 */
			inline int getIndex() const
			{
				return mIndex;
			}
			/**
			 * Método para retornar o offset do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	03/05/2011
			 * @return	Core::Point
			 */
			inline Core::Point getOffset() const
			{
				return mOffset;
			}
			/**
			 * Method that draws the sprite in the requested position into the current target Image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	26/05/2011
			 * @param	const Core::Point& pPosition, the position the image will be drawn
			 *
			 * @see		Graphic::setTargetImage
			 */
			void draw(const Core::Point& pPosition) const;
			/**
			 * Method that draws the sprite in the requested position and mirroring
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	26/05/2011
			 * @param	const Core::Point&	pPosition	, the position in the target Image to draw this Image
			 * @param	const Mirroring&	pMirroring	, the mirroring of the image
			 *
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */
			void draw(const Core::Point& pPosition, const Mirroring& pMirroring) const; //drawFlip
				/**
			 * Method that draws the sprite in the requested position and angle
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	27/05/2011
			 * @param	const Core::Point&	pPosition	, the position in the target Image to draw
			 * @param	const float&		pAngle		, the angle of the image
			 *
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */	
			void draw( const Core::Point& pPosition, const float& pAngle ) const;//draw rotated
			/**
			 * Method that draws the sprite in the requested position, mirroring and angle
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	27/05/2011
			 * @param	const Core::Point&	pPosition	, the position in the target Image to draw
			 * @param	const float&		pAngle		, the angle of the image
			 * @param	const Mirroring&	pMirroring	, the mirroring of the image
			 *
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */	
			void draw//drawRotatedFlipped
			(
				const Core::Point&	pPosition,
				const float&		pAngle,
				const Mirroring&	pMirroring
			) const;
			/**
			 * Method that draws the sprite in the requested position and mirroring, scalling it
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	26/05/2011
			 * @param	const Core::Point&	pPosition	, the position in the target Image to draw this Image
			 * @param	const int&			pWidth		, the width of the resulted image
			 * @param	const int&			pHeight		, the height of the resulted image
			 * @param	const Mirroring&	pMirroring	, the mirroring of the image
			 *
			 * @see		Graphic::setTargetImage
			 * @see		Graphic::Mirroring
			 */
			void draw(const Core::Point& pPosition, const int& pWidth, const int& pHeight, const Mirroring& pMirroring) const; //drawScaled
			/**
			 * Method that draws the sprite and multiplies all colors in the image with the given color
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
			 * Method that draws the sprite and multiplies all colors in the image with the given color
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
			void draw(const Core::Point& pPosition, const Color& pTint, const Mirroring& pMirroring) const;//draw Tinted fliped
			/**
			 * Method that draws the sprite and multiplies all colors in the image with the given color and angle
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
				const float&		pAngle
			) const;//drawTinted rotated
			/**
			 * Method that draws the sprite and multiplies all colors in the image with the given color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Core::Point&	pPosition	, position in the target Image to draw this Image
			 * @param	const Color&		pTint		, the color that will tint the image
			 * @param	const float&		pAngle		, he angle of the image
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
				const Mirroring&	pMirroring
			) const;//drawTinted rotated fliped
//---------------------------------------------------------------------------------------------------------------------------------------
			/**
			 * Method that loads the sprite from a file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	const std::string&	pSpriteName		, name of the file that have the sprite data
			 * @param	ImageLoader*		pImageLoader	, imageLoader responsable for saving the sprites
			 */
			virtual void load(const std::string& pSpriteName, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Method that loads the sprite from a previously opened file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	Core::File&		pFile			, previously opened file that holds the sprite data
			 * @param	ImageLoader*	pImageLoader	, imageLoader responsable for saving the sprites
			 */
			virtual void load(Core::File& pFile, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Method that saves the sprite into a file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	const std::string&	pSpriteName		, name of the file to save the sprite
			 * @param	const ImageLoader*	pImageLoader	, the imageLoader
			 */
			virtual void save(const std::string& pSpriteName,const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Method that saves the sprite into a previously opened file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	Core::File&			pFile			, the file to save the sprite
			 * @param	const ImageLoader*	pImageLoader	, the imageLoader
			 */
			virtual void save(Core::File& pFile,const ImageLoader& pImageLoader = ImageLoader::getLoader());	
		protected:
			int mGroup;				/**<< The group of the sprite*/
			int mIndex;				/**<< The index of the sprite in its group*/
			Core::Point mOffset;	/**<< The offset of the image*/
	};
}}
#endif
