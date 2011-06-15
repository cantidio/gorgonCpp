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
#ifndef _GORGON_PHYSICS_SHAPE_
#define _GORGON_PHYSICS_SHAPE_
#include "../graphic/graphic.hpp"

struct cpShape;
struct cpBody;

namespace Gorgon{
namespace Physics
{
	class Body;
	/**
	 * Class that represents a Shape
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	03/10/2010
	 * @version	04/10/2010
	 * @ingroup	Physics
	 */
	class Shape
	{
		protected:

			cpShape *mShape;/**<< Variable that holds a chipmunk's shape*/
			Body* mBody;/**<< Variable that holds the reference to the body of the shape*/

			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 */
			Shape(Body& pBody);
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 * @param	const float&			pRadius , the radius of the circle
			 * @param	const Gorgon::Point&	pOffset , the offset from the body's center of gravity
			 */
			virtual ~Shape();
			/**
			 * Method to return the body internal's body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 * @return	cpBody*
			 */
			cpBody* getInternalBody() const;
		public:
			friend class Space;
			friend class Body;
			/**
			 * Method that tells if this shape is a sensor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	bool
			 */
			bool isSensor() const;
			/**
			 * Method to return the elasticity of the shape
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	float
			 */
			float getElasticity() const;
			/**
			 * Method that sets the elasticity of the shape
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pElasticity, the elasticity of the shape
			 */
			void setElasticity(const float& pElasticity);
			/**
			 * Method that returns the friction coefficient of the shape
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	float
			 */
			float getFriction();
			/**
			 * Method to set the friction coefficient of the shape
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since
			 * @version
			 */
			void setFriction(const float& pCoefficient);
			/**
			 * Method that returns the surface's velocity
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	Core::Point
			 */
			Core::Point getSurfaceVelocity() const;
			/**
			 * Method that sets the group of the shape
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	const unsigned& pGroup, the new group
			 * @details
			 * 			if shapes have the same group, they won't collide
			 */
			void setGroup(const unsigned int& pGroup);
			/**
			 * Method that returns the group of the shape
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @return	unsigned int
			 */
			unsigned int getGroup() const;
			/**
			 * Method that draws the shape in the Sprite with some color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 * @param	const Graphic::Color& pColor , the color to draw the Shape
			 * @details	Each new shape implemented, must implement this method
			 */
			virtual void draw(const Graphic::Color& pColor) const = 0;
	};
}}
#endif
