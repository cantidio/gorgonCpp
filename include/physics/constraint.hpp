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
#ifndef _GORGON_PHYSICS_CONSTRAINT_
#define _GORGON_PHYSICS_CONSTRAINT_
#include "body.hpp"

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents the constraints
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	06/10/2010
	 * @version	06/10/2010
	 * @ingroup	Physics
	 */
	class Constraint
	{
		friend class Space;
		protected:
			cpConstraint*	mConstraint;	/**< variable that holds the chipmunk constraint*/
			Body*			mBodyA;			/**< variable that holds the pointer to the first body linked by the constraint*/
			Body*			mBodyB;			/**< variable that holds the pointer to the second body linked by the constraint*/

			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	Body& pBodyA, the first body to be linked by the constraint
			 * @param	Body& pBodyB, the second body to be linked by the constraint
			 */
			Constraint(Body& pBodyA, Body& pBodyB)
			{
				setBodyA(pBodyA);
				setBodyB(pBodyB);
				mConstraint = NULL;
			}
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 */
			virtual ~Constraint()
			{
				cpConstraintFree(mConstraint);
			}
		public:
			/**
			 * Method that sets the first body to be linked by the constraint
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	Body& pBody, the body to be linked by the constraint
			 */
			inline void setBodyA(Body& pBody)
			{
				mBodyA = &pBody;
			}
			/**
			 * Method that returns the first body linked by the constraint
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	Body&
			 */
			inline Body& getBodyA()
			{
				return *mBodyA;
			}
			/**
			 * Method that sets the second body linked by the constraint
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	Body& pBody, the body to be linked by the constraint
			 */
			inline void setBodyB(Body& pBody)
			{
				mBodyB = &pBody;
			}
			/**
			 * Method that returns the second body linked by the constraint
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	Body&
			 */
			inline Body& getBodyB()
			{
				return *mBodyB;
			}
			/**
			 * Method that sets the max force
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	const float& pForce, the max force that the constraint can act on the bodies
			 * @details
			 * 			This Method sets the max amount of force that the constraint
			 * can use the act on the 2 bodies, its Default is INFINITY, if the constraint
			 * needs more than the amount of force to be able to hold itself together,
			 * it will fall apart.
			 */
			inline void setMaxForce(const float& pForce)
			{
				mConstraint->maxForce = pForce;
			}
			/**
			 * Method that returns the maxForce the constraint can use
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	float
			 * @see		setMaxForce
			 */
			inline float getMaxForce() const
			{
				return mConstraint->maxForce;
			}
			/**
			 * Method that sets the percentage of errors corrected each space's step
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	const float& pBias, the percentage of error correction by space step
			 * @see		Space::runStep
			 * @details
			 * 			This Method sets the percentage of erros corrected each step
			 * of the space, before clamping to a maximum speed. Can be used to make joints
			 * correct them selves smoothly instead of at a constant speed.
			 */
			inline void setBiasCoef(const float& pBias)
			{
				mConstraint->biasCoef = pBias;
			}
			/**
			 * Method that returns the percentage of errors corrected each space's step
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	float
			 */
			inline float getBiasCoef() const
			{
				return mConstraint->biasCoef;
			}
			/**
			 * Method that sets the maximum error correction speed
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	const float& pBias, the maximum error correction speed allowed
			 * @see		Space::runStep
			 * @details
			 * 			This method sets the maximum speed at which the constraint can apply
			 * error correction. Defaults to INFINITY.
			 */
			inline void setMaxBias(const float& pBias) const
			{
				mConstraint->maxBias = pBias;
			}
			/**
			 * Method that returns the maximum error correction speed allowed
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	float
			 */
			inline float getMaxBias() const
			{
				return mConstraint->maxBias;
			}
			virtual void draw(const Graphic::Color& pColor) {}
	};
}}
#endif
