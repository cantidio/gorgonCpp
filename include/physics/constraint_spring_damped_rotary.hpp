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
#ifndef _GORGON_PHYSICS_CONSTRAINT_SPRING_DAMPED_ROTARY_
#define _GORGON_PHYSICS_CONSTRAINT_SPRING_DAMPED_ROTARY_

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents a damped spring rotary
	 * 
	 * @author	Cantidio Oliveira Fontes
	 * @since	06/10/2010
	 * @version	07/10/2010
	 * @details	This spring damps the rotation between 2 bodies
	 * @ingroup	Physics
	 */
	class DampedRotarySpring : public Constraint
	{
		friend class Space;
		
		protected:
			/**
			 * Constructor
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	Body& pBodyA			, the first body to be connected
			 * @param	Body& pBodyB			, the second body to be connected
			 * @param	const float& pRestAngle , the angle of the bodies when in res
			 * @param	const float& pStiffness , the spring constant
			 * @param	const float& pDamping	, the damping of the spring
			 * @see		http://en.wikipedia.org/wiki/Young's_modulus
			 */
			DampedRotarySpring
			(
				Body& pBodyA,
				Body& pBodyB,
				const float& pRestAngle,
				const float& pStiffness,
				const float& pDamping
			) : Constraint(pBodyA,pBodyB)
			{
				cpDampedRotarySpringNew
				(
					pBodyA.getBody(),
					pBodyB.getBody(),
					pRestAngle,
					pStiffness,
					pDamping
				);
			}
		public:
			/**
			 * Method that returns the angle of the spring when in rest
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @return	float
			 */
			inline float getRestAngle() const
			{
				return cpDampedRotarySpringGetRestAngle(mConstraint);
			}
			/**
			 * Method that sets the angle of the spring when in rest
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	const float& pAngle
			 */
			inline void setRestAngle(const float& pAngle) const
			{
				cpDampedRotarySpringSetRestAngle(mConstraint,pAngle);
			}
			/**
			 * Method that returns the stiffness of the spring
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @return	float
			 * @see		http://en.wikipedia.org/wiki/Young's_modulus
			 */
			inline float getStiffness() const
			{
				return cpDampedRotarySpringGetStiffness(mConstraint);
			}
			/**
			 * Method that sets the stiffness of the spring
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	const float& pStiffness, the spring constant
			 * @see		http://en.wikipedia.org/wiki/Young's_modulus
			 */
			inline void setStiffness(const float& pStiffness) const
			{
				cpDampedRotarySpringSetStiffness(mConstraint,pStiffness);
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
				return cpDampedRotarySpringGetDamping(mConstraint);
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
				cpDampedRotarySpringSetDamping(mConstraint,pDamping);
			}
	};
}}
#endif
