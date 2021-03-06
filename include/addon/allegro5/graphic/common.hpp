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
#ifndef _GORGON_GRAPHIC_ADDON_COMMON_
#define _GORGON_GRAPHIC_ADDON_COMMON_
#include "../../../core/point.hpp"
#include "../../../core/log.hpp"
#include "../../../graphic/color.hpp"
#include "../../../graphic/image_base.hpp"
#include "../../../graphic/font_base.hpp"
#include "../../../graphic/mirroring.hpp"
#include "../../../graphic/exception.hpp"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_memfile.h>

namespace Gorgon	{
namespace Allegro5	{
namespace Graphic
{
	/**
	 * Function that transforms a Font::Alignment into a allegro alignment flag
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	14/09/2011
	 * @version	14/09/2011
	 * @param	const Font::Alignment& pAlignment, the alignment that will be converted into an allegro's text alignment flag
	 * @return	int, allegro's text alignment flag
	 */
	inline int gorgonFontAlignment2AllegroAlignment( const Gorgon::Graphic::Font::Alignment& pAlignment )
	{
		switch( pAlignment )
		{
			case Gorgon::Graphic::Font::AlignLeft:	return ALLEGRO_ALIGN_LEFT;
			case Gorgon::Graphic::Font::AlignRight:	return ALLEGRO_ALIGN_RIGHT;
			case Gorgon::Graphic::Font::AlignCenter:	return ALLEGRO_ALIGN_CENTRE;
			default:
				return 0;
		}
	}
	/**
	 * Function that transforms a Mirroring into an Allegro draw Flag
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/05/2011
	 * @version	26/05/2011
	 * @param	const Gorgon::Graphic::Mirroring& pMirroring, the mirroring obj  to transform
	 * @return	int
	 */
	inline int gorgonMirroring2AllegroMirroring( const Gorgon::Graphic::Mirroring& pMirroring )
	{
		switch( pMirroring.getType() )
		{
			case Gorgon::Graphic::Mirroring::HFlip:	return ALLEGRO_FLIP_HORIZONTAL;
			case Gorgon::Graphic::Mirroring::VFlip:	return ALLEGRO_FLIP_VERTICAL;
			case Gorgon::Graphic::Mirroring::HVFlip:	return ALLEGRO_FLIP_VERTICAL|ALLEGRO_FLIP_HORIZONTAL;
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
	 * @param	const Gorgon::Graphic::Color& pColor, the color to be converted
	 * @return	ALLEGRO_COLOR
	 */
	inline ALLEGRO_COLOR gorgonColort2AllegroColor( const Gorgon::Graphic::Color& pColor )
	{
		return al_map_rgba_f( pColor.getRed(), pColor.getGreen(), pColor.getBlue(), pColor.getAlpha() );
	}
	/**
	 * Function that converts an Allegro Color to a Gorgon one
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/05/2011
	 * @version	26/05/2011
	 * @param	const ALLEGRO_COLOR& pColor, the color to be converted
	 * @return	Gorgon::Graphic::Color
	 */
	inline Gorgon::Graphic::Color allegroColor2GorgonColor( const ALLEGRO_COLOR& pColor )
	{
		float r, g, b, a;
		al_unmap_rgba_f( pColor, &r, &g, &b, &a );
		return Gorgon::Graphic::Color( r, g, b, a );
	}
}}}
#endif
