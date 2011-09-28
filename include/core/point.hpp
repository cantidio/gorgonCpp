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
#ifndef _GORGON_CORE_POINT_
#define _GORGON_CORE_POINT_
#include <string>

namespace Gorgon{
namespace Core
{
	/**
	 * Class that represents a point in the 2d space
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/11/2008
	 * @version	05/10/2010
	 * @ingroup	Geometry
	 * @todo	find a better name for it
	 */
	class Point
	{
		private:
			/**
			 * Position of the point in the x axis
			 */
			double mX;
			/**
			 * Position of the point in the y axis
			 */
			double mY;
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/11/2008
			 * @version	30/05/2011
			 */
			Point();
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/11/2008
			 * @version	05/10/2010
			 * @param	const double&	pX	, the value of the x axis of the point
			 * @param	const double&	pY	, the value of the y axis of the point
			 */
			Point(const double&	pX, const double& pY);
			/**
			 * Copy Constructor
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/10/2010
			 * @version	05/10/2010
			 * @param	const Point& pPoint, the point that will be cloned
			 */
			Point(const Point& pPoint);
			/**
			 * Method that describes the attributes of the point
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/11/2008
			 * @version	30/05/2011
			 * @returns	std::string
			 */
			std::string describe() const;
			/**
			 * Method to set the x axis of the point
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/11/2008
			 * @version	05/10/2010
			 * @param	const double& pX, position of the point in the x axis
			 */
			inline void setX(const double& pX)
			{
				mX = pX;
			}
			/**
			 * Method to add a value to the position of the x axis of the point
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	31/03/2009
			 * @version	05/10/2010
			 * @param	const double& pX, value to be added in the x axis
			 */
			inline void addX(const double& pX)
			{
				mX += pX;
			}
			/**
			 * Method to subtracts a value to the position of the x axis of the point
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	31/03/2009
			 * @version	05/10/2010
			 * @param	const double& pX, value to be subtracted by the x axis
			 */
			inline void subX(const double& pX)
			{
				mX -= pX;
			}
			/**
			 * Method to multiplies a value to the position of the x axis of the point
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	05/10/2010
			 * @param	const double& pX, value to be multiplied by the x axis
			 */
			inline void mulX(const double& pX)
			{
				mX *= pX;
			}
			/**
			 * Method to divides a value to the position of the x axis of the point
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	05/10/2010
			 * @param	const double& pX, value to be divided by the x axis
			 */
			inline void divX(const double& pX)
			{
				mX /= pX;
			}
			/**
			 * Method to set the y axis of the point
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/11/2008
			 * @version	05/10/2010
			 * @param	const double& pY, position of the point in the y axis
			 */
			inline void setY(const double& pY)
			{
				mY = pY;
			}
			/**
			 * Method to add a value to the position of the y axis of the point
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	31/03/2009
			 * @version	05/10/2010
			 * @param	const double& pY, value to be added by the y axis
			 */
			inline void addY(const double& pY)
			{
				mY += pY;
			}
			/**
			 * Method to subtracts a value to the position of the y axis of the point
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	31/03/2009
			 * @version	05/10/2010
			 * @param	const double& pY, value to be subtracted by the y axis
			 */
			inline void subY(const double& pY)
			{
				mY -= pY;
			}
			/**
			 * Method to multiplies a value to the position of the x axis of the point
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	05/10/2010
			 * @param	const double& pY, value to be multiplied by the y axis
			 */
			inline void mulY(const double& pY)
			{
				mY *= pY;
			}
			/**
			 * Method to divides a value to the position of the x axis of the point
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	05/10/2010
			 * @param	const double& pY, value to be divided by the y axis
			 */
			inline void divY(const double& pY)
			{
				mY /= pY;
			}
			/**
			 * Method to get the position of the x axis of the point
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/11/2008
			 * @version	05/10/2010
			 * @return	double
			 */
			inline double getX() const
			{
				return mX;
			}
			/**
			 * Method to get the position of the y axis of the point
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/11/2008
			 * @version	05/10/2010
			 * @return	double
			 */
			inline double getY() const
			{
				return mY;
			}
			/**
			 * Operator that returns true if the 2 points are equal
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	05/10/2010
			 * @param	const Point& p, another point the be compared
			 * @return	bool
			 */
			bool operator == (const Point& pPoint) const;
			/**
			 * Decrement operator
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	05/10/2010
			 * @param	const Point& p, point to be decremented
			 * @return	Point
			 */
			Point operator - (const Point& pPoint) const;
			/**
			 * Increment operator
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	05/10/2010
			 * @param	const Point& p, point to be incremented
			 * @return	Point
			 */
			Point operator + (const Point& pPoint) const;
			/**
			 * Multiplication operator
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	05/10/2010
			 * @param	const Point& pPoint, point to be multiplied
			 * @return	Point
			 */
			Point operator * (const Point& pPoint) const;
			/**
			 * Division operator
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	05/10/2010
			 * @param	const Point& pPoint, point to be divided
			 * @return	Point
			 */
			Point operator / (const Point& pPoint) const;
			/**
			 * Decrement operator
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	07/08/2009
			 * @param	const Point& pPoint, point to be decremented
			 */
			void operator -= (const Point& pPoint);
			/**
			 * Increment operator
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	07/08/2009
			 * @param	const Point& pPoint, point to be incremented
			 */
			void operator += (const Point& pPoint);
			/**
			 * Multiplication operator
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	07/08/2009
			 * @param	const Point& pPoint, point to be multiplied
			 */
			void operator *= (const Point& pPoint);
			/**
			 * Division operator
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	07/08/2009
			 * @version	07/08/2009
			 * @param	const Point& pPoint, point to be divided
			 */
			void operator /= (const Point& pPoint);
	};
}}
#endif

