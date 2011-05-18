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
#ifndef _GORGON_PHYSICS_CONSTRAINT_JOINT_ROTARY_LIMIT_
#define _GORGON_PHYSICS_CONSTRAINT_JOINT_ROTARY_LIMIT_
#include "constraint.hpp"

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents a RotaryLimitJoint
	 * 
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/10/2010
	 * @version	07/10/2010
	 * @ingroup	Physics
	 */
	class RotaryLimitJoint : public Constraint
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
			 * @param	const float& pMin	, the minimum angular limit in radians
			 * @param	const float& pMax	, the maximum angular limit in radians
			 */
			RotaryLimitJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const float& pMin,
				const float& pMax
			) : Constraint(pBodyA, pBodyB)
			{
				mConstraint = cpRotaryLimitJointNew
				(
					pBodyA.getBody(),
					pBodyB.getBody(),
					pMin,
					pMax
				);
			}
		public:
			/**
			 * Method that returns the minimum angular limit in radians
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @return	float
			 */
			inline float getMin() const
			{
				return cpRotaryLimitJointGetMin(mConstraint);
			}
			/**
			 * Method that sets the minimum angular limit in radians
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @param	const float& pMin, the minimum angular limit in radians
			 */
			inline void setMin(const float& pMin) const
			{
				cpRotaryLimitJointSetMin(mConstraint, pMin);
			}
			/**
			 * Method that returns the maximum angular limit in radians
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @return	float
			 */
			inline float getMax() const
			{
				return cpRotaryLimitJointGetMax(mConstraint);
			}
			/**
			 * Method that sets the maximum angular limit in radians
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @param	const float& pMax, the maximum angular limit in radians
			 */
			inline void setMax(const float& pMax) const
			{
				return cpRotaryLimitJointSetMax(mConstraint, pMax);
			}
	};
}}
#endif
