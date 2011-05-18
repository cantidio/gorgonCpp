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
#ifndef _GORGON_PHYSICS_CONSTRAINT_JOINT_PIN_
#define _GORGON_PHYSICS_CONSTRAINT_JOINT_PIN_
#include "constraint.hpp"

namespace Gorgon{
namespace Physics{
	/**
	 * Class that represents the constraints of the type PinJoint
	 * 
	 * @author	Cantidio Oliveira Fontes
	 * @since	06/10/2010
	 * @version	06/10/2010
	 * @ingroup	Physics
	 * @todo	make the draw method
	 */
	class PinJoint : public Constraint
	{
		friend class Space;
		protected:
			/**
			 * Constructor
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	Body&			pBodyA		, the first body of the constraint
			 * @param	Body&			pBodyB		, the second body of the constraint
			 * @param	const Point&	pAnchorA 	, the anchor attached to the first body
			 * @param	const Point&	pAnchorB	, the anchor attached to the second body
			 */
			PinJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const Core::Point& pAnchorA,
				const Core::Point& pAnchorB
			) : Constraint(pBodyA, pBodyB)
			{
				mConstraint = cpPinJointNew
				(
					pBodyA.getBody(),
					pBodyB.getBody(),
					cpv(pAnchorA.getX(), pAnchorA.getY()),
					cpv(pAnchorB.getX(), pAnchorB.getY())
				);
			}
		public:
			/**
			 * Method that returns the anchor of the first body
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	Core::Point
			 */
			inline Core::Point getAnchor1() const
			{
				return Core::Point
				(
					cpPinJointGetAnchr1(mConstraint).x,
					cpPinJointGetAnchr1(mConstraint).y
				);
			}
			/**
			 * Method that returns the anchor of the second body
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	Core::Point
			 */
			inline Core::Point getAnchor2() const
			{
				return Core::Point
				(
					cpPinJointGetAnchr2(mConstraint).x,
					cpPinJointGetAnchr2(mConstraint).y
				);
			}
			/**
			 * Method that returns the distance between the 2 anchors
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	float
			 */
			inline float getDistance() const
			{
				return cpPinJointGetDist(mConstraint);
			}
			/**
			 * Method that sets the distance between the 2 bodies
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	const float& pDistance, the distance between the 2 bodies
			 */
			inline void setDistance(const float& pDistance)
			{
				cpPinJointSetDist(mConstraint, pDistance);
			}
	};
}}
#endif
