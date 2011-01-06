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
#ifndef _GORGON_PHYSICS_CONSTRAINT_JOINT_RATCHET_
#define _GORGON_PHYSICS_CONSTRAINT_JOINT_RATCHET_
#include "constraint.hpp"

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents the RatchetJoint
	 * 
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/10/2010
	 * @version	07/10/2010
	 * @details
	 *
	 */
	class RatchetJoint : public Constraint
	{
		friend class Space;
		protected:
			/**
			 * Constructor
			 * 
			 * @author
			 * @since
			 * @version
			 * @param
			 * @param
			 * @param	const float& pPhase, the initial offset to use when deciding where the ratchet angles are
			 * @param	const float& pRatchet, the distance between "clicks" 
			 */
			RatchetJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const float& pPhase,
				const float& pRatchet
			) : Constraint(pBodyA, pBodyB)
			{
				mConstraint = cpRatchetJointNew
				(
					pBodyA.getBody(),
					pBodyB.getBody(),
					pPhase,
					pRatchet
				);
			}
		public:
			/**
			 * Method that returns the angle of the ratchet in radians
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @return	float
			 */
			inline float getAngle()
			{
				return cpRatchetJointGetAngle(mConstraint);
			}
			/**
			 * Method that sets the angle of the ratchet
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @param	const flaot& pAngle, the angle of the ratchet in radians
			 */
			inline void setAngle(const float& pAngle)
			{
				cpRatchetJointSetAngle(mConstraint, pAngle);
			}
			/**
			 * Method that returns the phase of the ratchet
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @return	float
			 */
			inline float getPhase()
			{
				return cpRatchetJointGetPhase(mConstraint);
			}
			/**
			 * Method that sets the phase of the ratched
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @param	const float& pPhase, the initial offset of the ratchet
			 */
			inline void setPhase(const float& pPhase)
			{
				cpRatchetJointSetPhase(mConstraint, pPhase);
			}
			/**
			 * Method that returns the distance between clicks of the ratchet 
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @return	float
			 */
			inline float getRatchet()
			{
				return cpRatchetJointGetRatchet(mConstraint);
			}
			/**
			 * Method that sets the distance between clicks of the ratched
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @param	const float& pRatched, the distance between clicks
			 */
			inline void setRatchet(const float& pRatchet)
			{
				return cpRatchetJointSetRatchet(mConstraint,pRatchet);
			}
	};
}}
#endif

