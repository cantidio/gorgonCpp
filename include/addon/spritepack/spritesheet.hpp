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
#ifndef _GORGON_SPRITEPACK_SPRITESHEET_
#define	_GORGON_SPRITEPACK_SPRITESHEET_
#include "../../graphic/spritepack.hpp"

namespace Gorgon{
namespace Addon
{
	/**
	 * Class that represents a spritesheet
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	28/02/2009
	 * @version	18/05/2011
	 */
	class SpriteSheet : public Graphic::SpritePack
	{
		protected:
			/**
			 * Method that takes a sprite from the spritesheet and add in the SpritePack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	28/02/2009
			 * @version	18/05/2011
			 * @param	Graphic::Image&			pImage		, image to take the sprite off
			 * @param	const Core::Point&		pPosition	, position that this method will start to cut the sprite
			 * @param	const int&				pGroup		, group of the cutted sprite
			 * @param	const int&				pIndex		, index of the cutted sprite
			 * @param	const Graphic::Color&	pBGCol		, background color
			 * @details
			 *			This method is called to help the constructor
			 */
			int getSpriteInSpriteSheet
			(
				Graphic::Image&			pImage,
				const Core::Point&		pPosition,
				const int&				pGroup,
				const int&				pIndex,
				const Graphic::Color&	pBGCol
			);
		public:
			/**
			 * Constructor that receives an image with the spritesheet and separate the sprites by the background color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/09/2009
			 * @version	18/05/2011
			 * @param	const Graphic::Image	pImageSheet			, image that contains the spritesheet
			 * @para	const Graphic::Color&	pBackgroundColor	, color to be ignored, this color isn't the transparent color
			 */
			SpriteSheet(const Graphic::Image& pImageSheet, const Graphic::Color& pBackgroundColor);
	};
}}
#endif
