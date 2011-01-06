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
#ifndef _GORGON_PHYSICS_CONSTRAINT_MOTOR_SIMPLE_
#define _GORGON_PHYSICS_CONSTRAINT_MOTOR_SIMPLE_
#include "constraint.hpp"

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents a simple motor
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/10/2010
	 * @version	07/10/2010
	 * @details	
	 */
	class SimpleMotor : public Constraint
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
			 * @param	const float& pRate	, the relative angular velocity of the motor
			 */
			SimpleMotor
			(
				Body& pBodyA,
				Body& pBodyB,
				const float& pRate
			) : Constraint(pBodyA,pBodyB)
			{
				mConstraint = cpSimpleMotorNew
				(
					pBodyA.getBody(),
					pBodyB.getBody(),
					pRate
				);
			}
		public:
			/**
			 * Method that returns the relative angular velocity of the motor
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @return	float
			 */
			inline float getRate() const
			{
				return cpSimpleMotorGetRate(mConstraint);
			}
			/**
			 * Method that returns the relative angular velocity of the motor
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @param	const float& pRate, the relative angular velocity of the motor
			 */
			inline void setRate(const float& pRate)
			{
				return cpSimpleMotorSetRate(mConstraint,pRate);
			}
	};
}}
#endif

