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
#ifndef _GORGON_PHYSICS_CONSTRAINT_JOINT_PIVOT_
#define _GORGON_PHYSICS_CONSTRAINT_JOINT_PIVOT_
#include "constraint.hpp"

namespace Gorgon{
namespace Physics{
	/**
	 * Class that represents the constraints of the type PivotJoint
	 * 
	 * @author	Cantidio Oliveira Fontes
	 * @since	06/10/2010
	 * @version	06/10/2010
	 * @ingroup	Physics
	 * @todo	make the draw method
	 */
	class PivotJoint : public Constraint
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
			PivotJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const Point& pAnchorA,
				const Point& pAnchorB
			) : Constraint(pBodyA, pBodyB)
			{
				mConstraint = cpPivotJointNew2
				(
					pBodyA.getBody(),
					pBodyB.getBody(),
					cpv(pAnchorA.getX(), pAnchorA.getY()),
					cpv(pAnchorB.getX(), pAnchorB.getY())
				);
			}
			/**
			 * Constructor
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	Body&			pBodyA		, the first body of the constraint
			 * @param	Body&			pBodyB		, the second body of the constraint
			 * @param	const Point&	pPivot		, the pivot point
			 */
			PivotJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const Point& pPivot
			) : Constraint(pBodyA, pBodyB)
			{
				mConstraint = cpPivotJointNew
				(
					pBodyA.getBody(),
					pBodyB.getBody(),
					cpv(pPivot.getX(), pPivot.getY())
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
					cpPivotJointGetAnchr1(mConstraint).x,
					cpPivotJointGetAnchr1(mConstraint).y
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
					cpPivotJointGetAnchr2(mConstraint).x,
					cpPivotJointGetAnchr2(mConstraint).y
				);
			}
	};
}}
#endif
