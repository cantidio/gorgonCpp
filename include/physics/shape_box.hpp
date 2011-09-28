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
#ifndef _GORGON_PHYSICS_SHAPE_BOX_
#define _GORGON_PHYSICS_SHAPE_BOX_
#include "shape.hpp"

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents a Box shape
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	03/10/2010
	 * @version	04/10/2010
	 * @ingroup	Physics
	 */
	class ShapeBox : public Shape
	{
		protected:
			/**
			 * Variable that stores the width of the box
			 */
			int mWidth;
			/**
			 * Variable that stores the height of the box
			 */
			int mHeight;
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 * @param	const int& pWidth , width of the box
			 * @param	const int& pHeight , height of the box
			 * @param	Body& pBody, reference of the body of the shape
			 */
			ShapeBox(const int& pWidth, const int& pHeight, Body& pBody);
			/**
			 * Method that draws the box with some color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	11/06/2011
			 * @param	const Graphic::Color& pColor , the color to draw the box
			 */
			virtual void draw(const Graphic::Color& pColor) const;
	};
}}
#endif
