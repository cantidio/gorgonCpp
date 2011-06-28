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

#include <allegro5/allegro.h>
#include <allegro5/allegro_memfile.h>

#include <gorgon++/core/point.hpp>
#include <gorgon++/core/log.hpp>
#include <gorgon++/graphic/color.hpp>
#include <gorgon++/graphic/image_base.hpp>
#include <gorgon++/graphic/mirroring.hpp>
#include <gorgon++/graphic/exception.hpp>

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
		return al_map_rgba_f(pColor.getRed(), pColor.getGreen(), pColor.getBlue(), pColor.getAlpha());
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
		float r, g, b, a;
		al_unmap_rgba_f(pColor, &r, &g, &b, &a);
		return Color(r,g,b,a);
	}
}}}
#endif
