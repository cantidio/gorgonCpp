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
#ifndef _GORGON_PHYSICS_SPACE_
#define _GORGON_PHYSICS_SPACE_
#include <chipmunk/chipmunk.h>
#include <vector>
#include "body.hpp"
#include "shape.hpp"
#include "constraint_joint_pin.hpp"
#include "constraint_joint_slide.hpp"
#include "constraint_joint_pivot.hpp"
#include "constraint_joint_groove.hpp"
#include "constraint_spring_damped.hpp"
#include "constraint_spring_damped_rotary.hpp"
#include "constraint_joint_rotary_limit.hpp"
#include "constraint_joint_ratchet.hpp"
#include "constraint_joint_gear.hpp"
#include "constraint_motor_simple.hpp"

namespace Gorgon{
namespace Physics
{
	/**
	 * Class that represents the simulated space
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	03/10/2010
	 * @version	07/10/2010
	 * @ingroup	Physics
	 */
	class Space
	{
		friend class Body;
		
		protected:
			cpSpace						*mSpace;		/**< Variable that holds the chipmunk's space */
			Body						*mStaticBody;	/**< Variable that holds the staticBody */
			std::vector<Body*> 			mBodies;		/**< Variable that stores all the bodies in the simulated space*/
			std::vector<Constraint*> 	mConstraints;	/**< Variable that stores all the constraint in the simulated space*/
			/**
			 * Method that puts a Shape into the simulated space
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	05/10/2010
			 * @param	Shape* pShape, the shape to be inserted in the space
			 */
			void addShape(Shape* pShape);
			/**
			 * Method that puts a Constraint into the simulated space
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	Constraint* pConstraint, the constraint to be inserted in the space
			 * @return	Constraint*
			 */
			Constraint* addConstraint(Constraint* pConstraint);
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 */
			Space();
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 */
			virtual ~Space();
			/**
			 * Method that returns a staticBody of infinity mass
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	Body&
			 */
			inline Body& getStaticBody()
			{
				return *mStaticBody;
			}
			/**
			 * Method that runs an step of the simulated space
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const int& pFPS, the number of the frames per second the physics engine must run
			 */
			inline void runStep(const int& pFPS)
			{
				cpSpaceStep(mSpace, 1.0f/pFPS);
			}
			/**
			 * Method that sets the number of iterations the engine do per step
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const int& pIterations, number of iterations
			 * @details	the bigger the pIterations the more accurate the engine becomes
			 */
			inline void setIterations(const int& pIterations)
			{
				mSpace->iterations = pIterations;
			}
			/**
			 * Method to set the gravity of the simulated space
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const Gorgon::Point& pPoint, the gravity value for the x, and the y axis
			 */
			inline void setGravity(const Gorgon::Point& pPoint)
			{
				mSpace->gravity.x = pPoint.getX();
				mSpace->gravity.y = pPoint.getY();
			}
			/**
			 * Method that sets the damping of the simulated space	
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pDamping, the amount of viscous damping
			 * @details	A value of 0.9 means that each body will lose 10% of its velocity per second
			 */
			inline void setDamping(const float& pDamping)
			{
				mSpace->damping = pDamping;
			}
			/**
			 * Method that returns the number of bodies in the space
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/10/2010
			 * @version	05/10/2010
			 * @return	int
			 */
			inline int getBodyNumber() const
			{
				return mBodies.size();
			}
			/**
			 * Method that puts a Body into the simulated space, and return its reference
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	05/10/2010
			 * @param	const float& pMass		, the mass of the body
			 * @param	const float& pMoment	, the moment of inertia of the body
			 * @return	Body*
			 */
			Body* addBody(const float& pMass, const float& pMoment);
			/**
			 * Method that returns the number of constraints in the space
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @return	int
			 */
			inline int getConstraintNumber() const
			{
				return mConstraints.size();
			}
			/**
			 * Method that add an ConstraintPinJoint to the space
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	06/10/2010
			 * @param	Body&			pBodyA		, the first body of the constraint
			 * @param	Body&			pBodyB		, the second body of the constraint
			 * @param	const Point&	pAnchorA 	, the anchor attached to the first body
			 * @param	const Point&	pAnchorB	, the anchor attached to the second body
			 * @return	PinJoint*
			 */	
			PinJoint* addConstraintPinJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const Point& pAnchorA,
				const Point& pAnchorB
			);
			/**
			 * Method that add and Constraint of type SlideJoint to the space
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	Body&			pBodyA	, the first body of the constraint
			 * @param	Body&			pBodyB	, the second body of the constraint
			 * @param	const Point&	pAnchorA, the anchor attached to the first body
			 * @param	const Point&	pAnchorB, the anchor attached to the second body
			 * @param	const float&	pMin	, the minimum distance between the anchors
			 * @param	const float&	pMax	, the maximum distance between the anchors
			 * @return	SlideJoint*
			 * @see		SlideJoint
			 */
			SlideJoint* addConstraintSlideJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const Point& pAnchorA,
				const Point& pAnchorB,
				const float& pMin,
				const float& pMax
			);
			/**
			 * Method that add and Constraint of type PivotJoint to the space
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	Body&			pBodyA	, the first body of the constraint
			 * @param	Body&			pBodyB	, the second body of the constraint
			 * @param	const Point&	pPivot	, the pivot point
			 * @return	PivotJoint*
			 * @see		PivotJoint
			 */
			PivotJoint* addConstraintPivotJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const Point& pPivot
			);
			/**
			 * Method that add and Constraint of type PivotJoint to the space
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	Body&			pBodyA	, the first body of the constraint
			 * @param	Body&			pBodyB	, the second body of the constraint
			 * @param	const Point&	pAnchorA, the anchor attached to the first body
			 * @param	const Point&	pAnchorB, the anchor attached to the second body
			 * @return	PivotJoint*
			 * @see		PivotJoint
			 */
			PivotJoint* addConstraintPivotJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const Point& pAnchorA,
				const Point& pAnchorB
			);
			/**
			 * Method that add and Constraint of the type GrooveJoint to the space
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	Body&			pBodyA		, the first body of the constraint
			 * @param	Body&			pBodyB		, the second body of the constraint
			 * @param	const Point&	pGrooveA 	, first point of the groove in the BodyA
			 * @param	const Point&	pGrooveB 	, second point of the groove in the BodyA
			 * @param	const Point&	pAnchorB	, the anchor attached to the second body
			 * @return	GrooveJoint*
			 * @see		GrooveJoint
			 */
			GrooveJoint* addConstraintGrooveJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const Point& pGrooveA,
				const Point& pGrooveB,
				const Point& pAnchorB
			);
			/**
			 * Method that add and Constraint of the type DampedSpring to the space
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	Body& pBodyA			, the first body to be connected
			 * @param	Body& pBodyB			, the second body to be connected
			 * @param	const Point& pAnchorA	, the anchor of the first body
			 * @param	const Point& pAnchorB	, the anchor of the second body
			 * @param	const float& pRestLength, the distance the spring wants to be
			 * @param	const float& pStiffness	, the spring constant(Young's modulus)
			 * @param	const float& pDamping	, how soft the damping of the spring
			 * @return	DampedSpring*
			 * @see		DampedSpring
			 */
			DampedSpring* addConstraintDampedSpring
			(
				Body& pBodyA,
				Body& pBodyB,
				const Point& pAnchorA,
				const Point& pAnchorB,
				const float& pRestLength,
				const float& pStiffness,
				const float& pDamping
			);
			/**
			 * Method that add and Constraint of the type DampedRotarySpring to the space
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/10/2010
			 * @version	07/10/2010
			 * @param	Body& pBodyA			, the first body to be connected
			 * @param	Body& pBodyB			, the second body to be connected
			 * @param	const float& pRestAngle , the angle of the bodies when in res
			 * @param	const float& pStiffness , the spring constant
			 * @param	const float& pDamping	, the damping of the spring
			 * @return	DampedRotarySpring*
			 * @see		DampedRotarySpring
			 */
			DampedRotarySpring* addConstraintDampedRotarySpring
			(
				Body& pBodyA,
				Body& pBodyB,
				const float& pRestAngle,
				const float& pStiffness,
				const float& pDamping
			);
			/**
			 * Method tha add a Constraint of the type RotaryLimitJoint to the space
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/10/2010
			 * @version	07/10/2010
			 * @param	Body& pBodyA		, the first body of the constraint
			 * @param	Body& pBodyB		, the second body of the constraint
			 * @param	const float& pMin	, the minimum angular limit in radians
			 * @param	const float& pMax	, the maximum angular limit in radians
			 * @return	RotaryLimitJoint*
			 * @see		RotaryLimitJoint
			 */
			RotaryLimitJoint* addConstraintRotaryLimitJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const float& pMin,
				const float& pMax
			);
			RatchetJoint* addConstraintRatchetJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const float& pPhase,
				const float& pRatchet
			);
			GearJoint* addConstraintGearJoint
			(
				Body& pBodyA,
				Body& pBodyB,
				const float& pPhase,
				const float& pRatio
			);
			SimpleMotor* addConstraintSimpleMotor
			(
				Body& pBodyA,
				Body& pBodyB,
				const float& pRate
			);
			/**
			 * Method that updates the simulated space in case of staticShapes's change
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @details
			 *			When you need to change the position of a static shape you need
			 * to call this method or the space won't update its collision detection data
			 */
			inline void updateStaticShapes()
			{
				cpSpaceRehashStatic(mSpace);
			}
			/**
			 * Method to resize the static hash of the physics engine
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float&	pDim	, the size of the hash cells
			 * @param	const int&		pCount	, the suggested minimum number of cells in the hash table
			 */
			void resizeStaticHash(const float& pDim = 100, const int& pCount = 1000);
			/**
			 * Method to resize the active hash of the physics engine
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float&	pDim	, the size of the hash cells
			 * @param	const int&		pCount	, the suggested minimum number of cells in the hash table
			 */
			void resizeActiveHash(const float& pDim = 100, const int& pCount = 1000);
			/**
			 * Method that returns a color based in a base number
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 * @param	const int& pBase, the base number
			 * @return	int
			 */
			int getColor(const int& pBase) const;
			/**
			 * Method that draws the entire space in a Gorgon::Sprite
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	04/10/2010
			 * @param	Graphic::Sprite& pSprite, sprite to be draw
			 * @details
			 * 			This method generates some colors to the shapes,
			 * based in their pointers
			 * @see		getColor
			 */
			void draw(Graphic::Sprite& pSprite) const;
	};
}}
#endif
