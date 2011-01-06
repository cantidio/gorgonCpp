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
 *  Copyright (C) 2008-2010  Gorgon Team
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
#ifndef _GORGON_PHYSICS_SHAPE_CIRCLE_
#define _GORGON_PHYSICS_SHAPE_CIRCLE_
#include "shape.hpp"

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents a circle shape
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	03/10/2010
	 * @version	04/10/2010
	 * @ingroup	Physics
	 */
	class ShapeCircle : public Shape
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 * @param	const float&			pRadius , the radius of the circle
			 * @param	const Gorgon::Point&	pOffset , the offset from the body's center of gravity
			 * @param	Body&					pBody	, the body thw Shape is attached				
			 */
			ShapeCircle
			(
				const float& pRadius,
				const Gorgon::Point& pOffset,
				Body& pBody
			);
			/**
			 * Method that returns the offset of the circle
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	Gorgon::Point
			 */
			inline Gorgon::Point getOffset() const
			{
				return Gorgon::Point
				(
					cpCircleShapeGetOffset(mShape).x,
					cpCircleShapeGetOffset(mShape).y
				);
			}
			/**
			 * Method that returns the radius of the circle
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 */
			inline float getRadius() const
			{
				return cpCircleShapeGetRadius(mShape);
			}
			/**
			 * Method that draws the circle in the sprite with some color
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 * @param	Gorgon::Sprite& pSprite , the sprite the circle will be draw
			 * @param	const int& pColor , the color to draw the circle
			 * @todo	optmize this method
			 */
			virtual void draw(Gorgon::Sprite& pSprite, const int& pColor) const;
	};
}}
#endif
