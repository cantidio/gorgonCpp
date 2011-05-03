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
#ifndef _GORGON_PHYSICS_CONSTRAINT_SPRING_DAMPED_
#define _GORGON_PHYSICS_CONSTRAINT_SPRING_DAMPED_
#include "constraint.hpp"

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents a damped spring
	 * 
	 * @author	Cantidio Oliveira Fontes
	 * @since	06/10/2010
	 * @version	07/10/2010
	 * @ingroup	Physics
	 */
	class DampedSpring : public Constraint
	{
		friend class Space;
		
		protected:
			/**
			 * Constructor
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	Body& pBodyA			, the first body to be connected
			 * @param	Body& pBodyB			, the second body to be connected
			 * @param	const Point& pAnchorA	, the anchor of the first body
			 * @param	const Point& pAnchorB	, the anchor of the second body
			 * @param	const float& pRestLength, the distance the spring wants to be
			 * @param	const float& pStiffness	, the spring constant(Young's modulus)
			 * @param	const float& pDamping	, how soft the damping of the spring
			 * @see		http://en.wikipedia.org/wiki/Young's_modulus
			 */
			DampedSpring
			(
				Body& pBodyA,
				Body& pBodyB,
				const Point& pAnchorA,
				const Point& pAnchorB,
				const float& pRestLength,
				const float& pStiffness,
				const float& pDamping
			) : Constraint(pBodyA, pBodyB)
			{
				mConstraint = cpDampedSpringNew
				(
					pBodyA.getBody(),
					pBodyB.getBody(),
					cpv(pAnchorA.getX(), pAnchorA.getY()),
					cpv(pAnchorB.getX(), pAnchorB.getY()),
					pRestLength,
					pStiffness,
					pDamping
				);
			}
		public:
			/**
			 * Method that returns the anchor of the first body
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	Point
			 */
			inline Point getAnchorA() const
			{
				return Point
				(
					cpDampedSpringGetAnchr1(mConstraint).x,
					cpDampedSpringGetAnchr1(mConstraint).y
				);
			}
			/**
			 * Method that returns the anchor of the second body
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	Point
			 */
			inline Point getAnchorB() const
			{
				return Point
				(
					cpDampedSpringGetAnchr2(mConstraint).x,
					cpDampedSpringGetAnchr2(mConstraint).y
				);
			}
			/**
			 * Method that returns the length of the spring when in rest
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @return	float
			 */
			inline float getRestLength() const
			{
				return cpDampedSpringGetRestLength(mConstraint);	
			}
			/**
			 * Method that sets the length of the spring when in rest
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	const float& pRestLength, the length of the spring
			 */
			inline void setRestLength(const float& pRestLength) const
			{
				cpDampedSpringSetRestLength(mConstraint,pRestLength);	
			}
			/**
			 * Method that returns the the stiffness(spring constant(Young's modulus)) of the spring
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @return	float
			 * @see		http://en.wikipedia.org/wiki/Young's_modulus
			 */
			inline float getStiffness() const
			{
				return cpDampedSpringGetStiffness(mConstraint);
			}
			/**
			 * Method that sets the stiffness of the spring
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	const float& pStiffness, the spring constant(Young's modulus)
			 * @see		http://en.wikipedia.org/wiki/Young's_modulus
			 */
			inline void setStiffness(const float& pStiffness) const
			{
				cpDampedSpringSetStiffness(mConstraint,pStiffness);
			}
			/**
			 * Method that returns the damping of the spring
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @return	float
			 */
			inline float getDamping() const
			{
				return cpDampedSpringGetDamping(mConstraint);
			}
			/**
			 * Method that sets the damping of the spring
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	const float& pDamping, the damping of the spring
			 */
			inline void setDamping(const float& pDamping) const
			{
				cpDampedSpringSetDamping(mConstraint,pDamping);
			}

			inline void draw(Graphic::Sprite& pSprite, const int& pColor)// const
			{
				Point a = getAnchorA() + getBodyA().getPosition();
				Point b = getAnchorB() + getBodyB().getPosition();
				pSprite.drawLine(a,b,pColor);
				pSprite.drawLine(a + Point(1,0), b + Point(1,0), pColor);
				pSprite.drawLine(a - Point(1,0), b - Point(1,0), pColor);
			}
	};
}}
#endif
