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
#ifndef _GORGON_PHYSICS_SHAPE_SEGMENT_
#define _GORGON_PHYSICS_SHAPE_SEGMENT_
#include "shape.hpp"

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents a segment shape
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	03/10/2010
	 * @version	04/10/2010
	 * @ingroup	Physics
	 */
	class ShapeSegment : public Shape
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 * @param	const Gorgon::Point&	pPointA , the first point of the segment
			 * @param	const Gorgon::Point&	pPointB , the second point of the segment
			 * @param	const float&			pRadius , the radius of the segment
			 */
			ShapeSegment
			(
				const Gorgon::Point& pPointA,
				const Gorgon::Point& pPointB,
				const float& pRadius,
				Body& pBody
			);
			/**
			 * Method that returns the first Point of the segment
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	Gorgon::Point
			 */
			inline Gorgon::Point getPointA() const
			{
				return Gorgon::Point
				(
					cpSegmentShapeGetA(mShape).x,
					cpSegmentShapeGetA(mShape).y
				);
			}
			/**
			 * Method that returns the second Point of the segment
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	Gorgon::Point
			 */
			inline Gorgon::Point getPointB() const
			{
				return Gorgon::Point
				(
					cpSegmentShapeGetB(mShape).x,
					cpSegmentShapeGetB(mShape).y
				);
			}
			/**
			 * Method that returns the NormalPoint of the segment
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	Gorgon::Point
			 */
			inline Gorgon::Point getNormal() const
			{
				return Gorgon::Point
				(
					cpSegmentShapeGetNormal(mShape).x,
					cpSegmentShapeGetNormal(mShape).y
				);
			}
			/**
			 * Method that returns the radius of the segment
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	float
			 */
			inline float getRadius() const
			{
				return cpSegmentShapeGetRadius(mShape);
			}
			/**
			 * Method that draws the segment in the sprite with some color
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 * @param	Gorgon::Sprite&	pSprite	, the sprite the segment will be draw
			 * @param	const int&		pColor	, the color to draw the segment
			 */
			virtual void draw(Gorgon::Sprite& pSprite, const int& pColor) const;
	};
}}
#endif
