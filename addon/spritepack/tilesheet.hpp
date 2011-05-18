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
#ifndef _GORGON_SPRITEPACK_TILESHEET_
#define _GORGON_SPRITEPACK_TILESHEET_
#include<gorgon++/graphic/spritepack.hpp>

namespace Gorgon{
namespace Addon
{
	/**
	 * Class that represents a tilesheet
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	23/01/2009
	 * @version	18/05/2011
	 * @details
	 * 			This class opens a tilesheet and stores it like a spritepack
	 */
	class TileSheet : public Graphic::SpritePack
	{
		public:
			/**
			 * Constructor
			 * que transforma um para de tiles em um spritePack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/01/2009
			 * @version	18/05/2011
			 * @param	const Graphic::Image&	pImageSheet	, the image that stores the tilesheet
			 * @param	const int&				pWidth		, the width of the tiles
			 * @param	const int&				pHeight		, the height of the tiles
			 * @param	const int&				pJumpPixels	, number of pixels to jump every tile
			 * @details
			 * 			This method receives an image with a tile sheet and transforms it into a spritepack
			 */
			TileSheet
			(
				const Graphic::Image&	pImageSheet,
				const int&				pWidth,
				const int&				pHeight,
				const int&				pJumpPixels	= 0
			);
	};

}}
#endif
