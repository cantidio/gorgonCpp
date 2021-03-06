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
#ifndef _GORGON_PHYSICS_SHAPE_POLYGON_
#define _GORGON_PHYSICS_SHAPE_POLYGON_
#include "shape.hpp"

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents a polygon shape
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	03/10/2010
	 * @version	03/10/2010
	 * @ingroup	Physics
	 */
	class ShapePolygon : public Shape
	{
		protected:
			/**
			 * Variable that holds the mininum x,y position of the polygon
			 */
			Core::Point mMinimum;
			/**
			 * Variable that holds the maximum x,y position of the polygon
			 */
			Core::Point mMaximum;
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const std::vector<Gorgon::Point>&	pVerts	, vector of Points defining a convex hull with a clockwise winding
			 * @param	const Gorgon::Point&				pOffset	, offset from the body's center of gravity
			 */
			ShapePolygon
			(
				const std::vector<Core::Point>& pVerts,
				const Core::Point& pOffset,
				Body& pBody
			);
			/**
			 * Method that returns the number of vertices of the polygon
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	int
			 */
			int getVerticesNumber() const;
			/**
			 * Method that returns a vertice from the polygon
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const int& pIndex, the index of the vertice you want to get
			 * @return	Gorgon::Point
			 */
			Core::Point getVertice(const int& pIndex) const;
			/**
			 * Method that draws the polygon with some color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	11/06/2011
			 * @param	const Graphic::Color& pColor , the color to draw the polygon
			 */
			virtual void draw(const Graphic::Color& pColor) const;
	};
}}
#endif
