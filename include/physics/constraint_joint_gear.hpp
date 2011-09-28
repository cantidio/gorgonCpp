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
#ifndef _GORGON_PHYSICS_CONSTRAINT_GEAR_
#define _GORGON_PHYSICS_CONSTRAINT_GEAR_
#include "constraint.hpp"

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents a GearJoint
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/10/2010
	 * @version	07/10/2010
	 * @details	Keeps the angular velocity ratio of a pair of bodies constant
	 */
	class GearJoint : public Constraint
	{
		friend class Space;
		protected:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @param	Body& pBodyA		, the first body of the constraint
			 * @param	Body& pBodyB		, the second body of the constraint
			 * @param	const float& pPhase	, the initial angular offset of the two bodies
			 * @param	const float& pRatio	, the angular velocity
			 */
			GearJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const float& pPhase,
				const float& pRatio
			) : Constraint(pBodyA,pBodyB)
			{
				mConstraint = cpGearJointNew
				(
					pBodyA.getBody(),
					pBodyB.getBody(),
					pPhase,
					pRatio
				);
			}
		public:
			/**
			 * Method that returns the Phase of the gear
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @return	float
			 */
			inline float getPhase() const
			{
				return cpGearJointGetPhase(mConstraint);
			}
			/**
			 * Method that sets the Phase of the gear
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @param	const float& pPhase, the initial angular offset of the two bodies
			 */
			inline void setPhase(const float& pPhase)
			{
				cpGearJointSetPhase(mConstraint, pPhase);
			}
			/**
			 * Method that returns the ration of the gear
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @param	float
			 */
			inline float getRatio() const
			{
				return cpGearJointGetRatio(mConstraint);
			}
			/**
			 * Method that sets the ration of the gear
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @param	const float& pRatio, the angular speed of the bodies
			 */
			inline void setRatio(const float& pRatio)
			{
				cpGearJointSetRatio(mConstraint, pRatio);
			}
	};
}}
#endif
