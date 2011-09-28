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
#ifndef _GORGON_PHYSICS_CONSTRAINT_JOINT_SLIDE_
#define _GORGON_PHYSICS_CONSTRAINT_JOINT_SLIDE_
#include "constraint.hpp"

namespace Gorgon{
namespace Physics{
	/**
	 * Class that represents the constraints of the type SlideJoint
	 * 
	 * @author	Cantidio Oliveira Fontes
	 * @since	06/10/2010
	 * @version	06/10/2010
	 * @ingroup	Physics
	 * @todo	make the draw method
	 */
	class SlideJoint : public Constraint
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
			 * @param	const float&	pMin		, the minimum distance between the anchors
			 * @param	const float&	pMax		, the maximum distance between the anchors
			 */
			SlideJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const Core::Point& pAnchorA,
				const Core::Point& pAnchorB,
				const float& pMin,
				const float& pMax
			) : Constraint(pBodyA, pBodyB)
			{
				mConstraint = cpSlideJointNew
				(
					pBodyA.getBody(),
					pBodyB.getBody(),
					cpv(pAnchorA.getX(), pAnchorA.getY()),
					cpv(pAnchorB.getX(), pAnchorB.getY()),
					pMin,
					pMax
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
			inline Core::Point getAnchorA() const
			{
				return Core::Point
				(
					cpSlideJointGetAnchr1(mConstraint).x,
					cpSlideJointGetAnchr1(mConstraint).y
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
			inline Core::Point getAnchorB() const
			{
				return Core::Point
				(
					cpSlideJointGetAnchr2(mConstraint).x,
					cpSlideJointGetAnchr2(mConstraint).y
				);
			}
			/**
			 * Method that returns the minimum distance between the anchors points
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	float
			 */
			inline float getMin() const
			{
				return cpSlideJointGetMin(mConstraint);
			}
			/**
			 * Method that sets the minimum distance between anchor the points
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	const float& pDistance, the minimum distance between the 2 anchors
			 */
			inline void setMin(const float& pDistance)
			{
				cpSlideJointSetMin(mConstraint, pDistance);
			}
			/**
			 * Method that returns the maximum distance between the anchors points
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	float
			 */
			inline float getMax() const
			{
				return cpSlideJointGetMax(mConstraint);
			}
			/**
			 * Method that sets the maximum distance between the anchor points
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	const float& pDistance, the max distance between the 2 anchors
			 */
			inline void setMax(const float& pDistance)
			{
				cpSlideJointSetMax(mConstraint, pDistance);
			}
	};
}}
#endif

