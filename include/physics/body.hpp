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
#ifndef _GORGON_PHYSICS_BODY_
#define _GORGON_PHYSICS_BODY_
#include <chipmunk/chipmunk.h>
#include "../graphic/graphic.hpp"
#include "shape.hpp"

namespace Gorgon{
namespace Physics
{
	class ShapeCircle;
	class ShapeBox;
	class ShapeSegment;
	class ShapePolygon;
	class Space;
	/**
	 * Variable that holds the Pi value
	 */
	const double PI  = 3.141592653589793238462643383279502884197169399;
	/**
	 * Class that represents a Body
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	03/10/2010
	 * @version	03/10/2010
	 * @ingroup	Physics
	 */
	class Body
	{
		friend class Space;
		friend class Shape;
		
		protected:
			Space*				mSpace; /**< Variable that holds a reference to the body's space */
			cpBody*				mBody;	/**< Variable that holds a chipmunk's body */
			bool				mLocal;	/**< Variable that says if the mBody is local */
			std::vector<Shape*> mShapes;/**< vector with the internal shapes*/
			/**
			 * Empty Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	cpBody *pBody, pointer to a cBody, used in the Space Class
			 */
			Body(cpBody *pBody, Space& pSpace);
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pMass		, the mass of the body
			 * @param	const float& pMoment	, the moment of inertia of the body
			 * @see		getMomentForCircle
			 * @see		getMomentForSegment
			 * @see		getMomentForPolygon
			 * @see		getMomentForBox
			 */
			Body(const float& pMass, const float& pMoment, Space& pSpace);
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 */
			virtual ~Body();
		public:
			/**
			 * Method that returns the basic cpBody of the object
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/10/2010
			 * @version	05/10/2010
			 * @return	cpBody*
			 * @todo	pensar em uma forma de não precisar utilizar esse método
			 */
			inline cpBody* getBody()
			{
				return mBody;
			}
			/**
			 * Method that returns the mass of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	float
			 */
			inline float getMass() const
			{
				return cpBodyGetMass(mBody);
			}
			/**
			 * Method that sets the mass of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pMass, the new mass of the body
			 */
			void setMass(const float& pMass)
			{
				cpBodySetMass(mBody, pMass);
			}
			/**
			 * Method that returns the moment of inertia of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	float
			 */
			inline float getMoment() const
			{
				return cpBodyGetMoment(mBody);
			}
			/**
			 * Method that sets the moment of inertia of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pMoment, the new moment of inertia of the body
			 * @see		getMomentForCircle
			 * @see		getMomentForSegment
			 * @see		getMomentForPolygon
			 * @see		getMomentForBox
			 */
			void setMoment(const float& pMoment)
			{
				cpBodySetMoment(mBody,pMoment);
			}
			/**
			 * Method that returns the angle of the body in degrees
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	int
			 */
			inline int getAngle() const
			{
				return  (180 / PI) * cpBodyGetAngle(mBody);
			}
			/**
			 * Method that sets the angle of the body in degrees
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const int& pAngle, the new angle of the body in degrees
			 */
			void setAngle(const int& pAngle)
			{
				cpBodySetAngle(mBody, (pAngle * PI) / 180);
			}
			/**
			 * Method that returns the position of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	Gorgon::Point
			 */
			inline Core::Point getPosition() const
			{
				return Core::Point
				(
					cpBodyGetPos(mBody).x,
					cpBodyGetPos(mBody).y
				);
			}
			/**
			 * Method that sets the position of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const Core::Point& pPosition, the new position of the body
			 */
			inline void setPosition(const Core::Point& pPosition)
			{
				mBody->p.x = pPosition.getX();
				mBody->p.y = pPosition.getY();
			}
			/**
			 * Method that returns the velocity of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	Core::Point
			 */
			inline Core::Point getVelocity() const
			{
				return Core::Point
				(
					cpBodyGetVel(mBody).x,
					cpBodyGetVel(mBody).y
				);
			}
			/**
			 * Method that sets the velocity of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const Core::Point& pVelocity, the new velocity of the body in the x and y axis
			 */
			inline void setVelocity(const Core::Point& pVelocity)
			{
				mBody->v.x = pVelocity.getX();
				mBody->v.y = pVelocity.getY();
			}
			/**
			 * Method that returns the angular velocity of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	float
			 * @details	this method returns the velocity which the body is rotating
			 */
			inline float getAngularVelocity() const
			{
				return cpBodyGetAngVel(mBody);
			}
			/**
			 * Method that sets the angular velocity of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pVelocity, the velocity which the body is rotating
			 */
			inline void setAngularVelocity(const float& pVelocity)
			{
				cpBodySetAngVel(mBody, pVelocity);
			}
			/**
			 * Method that returns the maximum velocity of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	float
			 */
			inline float getMaximumVelocity() const
			{
				return mBody->v_limit;
			}
			/**
			 * Method that sets the maximum velocity of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pVelocity, the maximum speed of the body
			 */
			inline void setMaximumVelocity(const float& pVelocity)
			{
				mBody->v_limit = pVelocity;
			}
			/**
			 * Method that returns the maximum angular velocity of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	float
			 */
			inline float getMaximumAngularVelocity()
			{
				return mBody->w_limit;
			}
			/**
			 * Method that sets the maximum angular velocity of the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pVelocity, the maximum speed which the body will rotate
			 */
			inline void setMaximumAngularVelocity(const float& pVelocity)
			{
				mBody->w_limit = pVelocity;
			}
			/**
			 * Method that returns the force applied on the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	Core::Point
			 */
			inline Core::Point getForce() const
			{
				return Core::Point(mBody->f.x, mBody->f.y);
			}
			/**
			 * Method that sets the force applied on the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const Point& pForce, the force applied on the Body, x and y axis
			 */
			inline void setForce(const Core::Point& pForce)
			{
				mBody->f.x = pForce.getX();
				mBody->f.y = pForce.getY();
			}
			/**
			 * Method that applies a force into the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const Core::Point& pForce	, force the be applied into the body
			 * @param	const Core::Point& pOffset	, the relative offset
			 * @details
			 *			This method applies(accumulate) the force pForce into the body at a
			 * relative offset pOffset from the center of gravity
			 */
			inline void applyForce(const Core::Point& pForce, const Core::Point& pOffset)
			{
				cpBodyApplyForce
				(
					mBody,
					cpv(pForce.getX(), pForce.getY()),
					cpv(pOffset.getX(), pOffset.getY())
				);
			}
			/**
			 * Method that applies a impulse into the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const Core::Point& pImpulse	, impulse the be applied into the body
			 * @param	const Core::Point& pOffset	, the relative offset
			 * @details
			 *			This method applies the impulse pImpulse to the body at a
			 * relative offset pOffset from the center of gravity
			 */
			inline void applyImpulse(const Core::Point& pImpulse, const Core::Point& pOffset)
			{
				cpBodyApplyImpulse
				(
					mBody,
					cpv(pImpulse.getX(), pImpulse.getY()),
					cpv(pOffset.getX(), pOffset.getY())
				);
			}
			/**
			 * Method that returns the torque applied to the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @return	float
			 */
			inline float getTorque() const
			{
				return mBody->t;
			}
			/**
			 * Method that sets the torque applied into the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pTorque, the new torque applied to the body
			 */
			inline void setTorque(const float& pTorque)
			{
				mBody->t = pTorque;
			}
			/**
			 * Method that applies a torque in the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pTorque, the torque applied into the body
			 */
			inline void applyTorque(const float& pTorque)
			{
				mBody->t += pTorque;
			}
			/**
			 * Method that zero both the forces and torques accumulated into the body
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 */
			inline void	resetForces()
			{
				cpBodyResetForces(mBody);
			}
			/**
			 * Method that returns the number of shapes in the body
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/10/2010
			 * @version	05/10/2010
			 * @return	int
			 */
			inline int getShapeNumber() const
			{
				return mShapes.size();
			}
			/**
			 * Method that returns a shape by it index
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/10/2010
			 * @version	05/10/2010
			 * @param	const int& pIndex, the index of the Shape
			 * @return	Shape&
			 */
			inline Shape& getShape(const int& pIndex)
			{
				return *mShapes[pIndex];
			}
			/**
			 * Method that add a ShapeCircle to the body, and returns an reference
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/10/2010
			 * @version	04/10/2010
			 * @param	const float& pRadius, the radius of the circle
			 * @param	const Core::Point& pOffset, the offset to the balance point
			 * @return	ShapeCircle*
			 */
			ShapeCircle* addShapeCircle(const float& pRadius, const Core::Point& pOffset);
			/**
			 * Method that add a ShapeBox to the body, and returns an reference
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/10/2010
			 * @version	04/10/2010
			 * @param	const int& pWidth, the width of the box
			 * @param	const int& pHeight, the height of the box 
			 * @return	ShapeBox*
			 */
			ShapeBox* addShapeBox(const int& pWidth, const int& pHeight);
			/**
			 * Method that add a ShapePolygon to the body, and returns an reference
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/10/2010
			 * @version	04/10/2010
			 * @param	const std::vector<Core::Point>& pVerts, the vertices of the polygon
			 * @param	const Core::Point& pOffset, the offset to the balance point
			 * @return	ShapePolygon*
			 */
			ShapePolygon* addShapePolygon
			(
				const std::vector<Core::Point>& pVerts,
				const Core::Point& pOffset=Core::Point(0,0)
			);
			/**
			 * Method that add a ShapeSegment to the body, and returns an reference
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/10/2010
			 * @version	04/10/2010
			 * @param	const Core::Point& pPointA, the first point of the Segment
			 * @param	const Core::Point& pPointB, the second point of the Segment
			 * @param	cosnt float& pRadius, the radius of the segment 
			 * @return	ShapeSegment*
			 */
			ShapeSegment* addShapeSegment
			(
				const Core::Point& pPointA,
				const Core::Point& pPointB,
				const float& pRadius
			);
			/**
			 * Method that returns the moment of inertia for circles
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pMass			, the mass of the body
			 * @param	const float& pDiameter		, the diameter of the body
			 * @param	const float& pInnerDiameter	, the inner diameter of the body (A solid circle has an inner diameter of 0)
			 * @param	const Core::Point& pOffset		, the offset of the body
			 * @see		setMoment
			 * @see		Body
			 */
			static float getMomentForCircle
			(
				const float& pMass,
				const float& pDiameter,
				const float& pInnerDiameter,
				const Core::Point& pOffset = Core::Point(0,0)
			);
			/**
			 * Method that returns the moment of inertia for boxes
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pMass		, the mass of the body
			 * @param	const Point& pWidth		, the width of the box
			 * @param	const Point& pHeight	, the height of the box
			 * @see		setMoment
			 * @see		Body
			 */
			static float getMomentForBox
			(
				const float& pMass,
				const float& pWidth,
				const float& pHeight
			);
			/**
			 * Method that returns the moment of inertia for segments
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float& pMass			, the mass of the body
			 * @param	const Core::Point& pPointA		, the first point of the segment
			 * @param	const Core::Point& pPointB		, the second point of the segment
			 * @see		setMoment
			 * @see		Body
			 */
			static float getMomentForSegment
			(
				const float& pMass,
				const Core::Point& pPointA,
				const Core::Point& pPointB
			);
			/**
			 * Method that returns the moment of inertia for polygons
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/10/2010
			 * @version	03/10/2010
			 * @param	const float&				pMass	, the mass of the body
			 * @param	const std::vector<Core::Point>&	pVerts	, the vertices of the polygon
			 * @param	const Point&				pOffset	, the offset of the body
			 * @see		setMoment
			 * @see		Body
			 */
			static float getMomentForPolygon
			(
				const float& pMass,
				const std::vector<Core::Point>& pVerts,
				const Core::Point& pOffset
			);
			/**
			 * Method to draw the body in a sprite
			 * 
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/10/2010
			 * @version	05/10/2010
			 * @param	Sprite&		pSprite , the sprite to draw to body into
			 * @param	const int&	pColor	, the color to draw the body
			 */
			void draw(Graphic::Sprite& pSprite, const int& pColor) const;
	};
}}
#endif
