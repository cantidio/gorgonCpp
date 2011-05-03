#include <physics/space.hpp>

namespace Gorgon{
namespace Physics
{
	Space::Space()
	{
		printf("Creating the Space: %d\n",(int)this);
		 mSpace			= cpSpaceNew();
		 mStaticBody	= new Body(&mSpace->staticBody,*this);
		 mBodies.push_back(mStaticBody);
		 /**
		  * @todo	remover a variável mStatic body, e guardar o corpo estático na primeira posićão do vetor
		  */
	}
	
	Space::~Space()
	{
		printf("Deleting the Space: %d\n",(int)this);
		for(int i = getBodyNumber() - 1; i >= 0; --i)
		{
			delete mBodies[i];
		}
		for(int i = getConstraintNumber() - 1; i >= 0; --i)
		{
			delete mConstraints[i];
		}
		cpSpaceFree(mSpace);
	}
	
	Body* Space::addBody(const float& pMass, const float& pMoment)
	{
		Body* body = new Body(pMass, pMoment, *this);
		mBodies.push_back(body);
		cpSpaceAddBody(mSpace, body->mBody);
		return body;
	}
	
	void Space::addShape(Shape* pShape)
	{
		cpSpaceAddShape(mSpace, pShape->mShape);
	}
	
	Constraint* Space::addConstraint(Constraint* pConstraint)
	{
		mConstraints.push_back(pConstraint);
		cpSpaceAddConstraint(mSpace, pConstraint->mConstraint);
		return pConstraint;
	}
	
	PinJoint* Space::addConstraintPinJoint
	(
		Body& pBodyA,
		Body& pBodyB,
		const Point& pAnchorA,
		const Point& pAnchorB
	)
	{
		return (PinJoint*)addConstraint(new PinJoint
		(
			pBodyA,
			pBodyB,
			pAnchorA,
			pAnchorB
		));
	}
	
	SlideJoint* Space::addConstraintSlideJoint
	(
		Body& pBodyA,
		Body& pBodyB,
		const Point& pAnchorA,
		const Point& pAnchorB,
		const float& pMin,
		const float& pMax
	)
	{
		return (SlideJoint*)addConstraint(new SlideJoint
		(
			pBodyA,
			pBodyB,
			pAnchorA,
			pAnchorB,
			pMin,
			pMax
		));
	}
	
	PivotJoint* Space::addConstraintPivotJoint
	(
		Body& pBodyA,
		Body& pBodyB,
		const Point& pPivot
	)
	{
		return (PivotJoint*)addConstraint(new PivotJoint
		(
			pBodyA,
			pBodyB,
			pPivot
		));
	}
	
	PivotJoint* Space::addConstraintPivotJoint
	(
		Body& pBodyA,
		Body& pBodyB,
		const Point& pAnchorA,
		const Point& pAnchorB
	)
	{
		return (PivotJoint*)addConstraint(new PivotJoint
		(
			pBodyA,
			pBodyB,
			pAnchorA,
			pAnchorB
		));
	}
	
	GrooveJoint* Space::addConstraintGrooveJoint
	(
		Body& pBodyA,
		Body& pBodyB,
		const Point& pGrooveA,
		const Point& pGrooveB,
		const Point& pAnchorB
	)
	{
		return (GrooveJoint*)addConstraint(new GrooveJoint
		(
			pBodyA,
			pBodyB,
			pGrooveA,
			pGrooveB,
			pAnchorB
		));
	}
	
	DampedSpring* Space::addConstraintDampedSpring
	(
		Body& pBodyA,
		Body& pBodyB,
		const Point& pAnchorA,
		const Point& pAnchorB,
		const float& pRestLength,
		const float& pStiffness,
		const float& pDamping
	)
	{
		return (DampedSpring*)addConstraint(new DampedSpring
		(
			pBodyA,			pBodyB,
			pAnchorA,		pAnchorB,
			pRestLength,	pStiffness,
			pDamping
		));
	}
	
	DampedRotarySpring* Space::addConstraintDampedRotarySpring
	(
		Body& pBodyA,
		Body& pBodyB,
		const float& pRestAngle,
		const float& pStiffness,
		const float& pDamping
	)
	{
		return (DampedRotarySpring*)addConstraint(new DampedRotarySpring
		(
			pBodyA,
			pBodyB,
			pRestAngle,
			pStiffness,
			pDamping
		));
	}
	
	RotaryLimitJoint* Space::addConstraintRotaryLimitJoint
	(
		Body& pBodyA,
		Body& pBodyB,
		const float& pMin,
		const float& pMax
	)
	{
		return (RotaryLimitJoint*)addConstraint(new RotaryLimitJoint
		(
			pBodyA,
			pBodyB,
			pMin,
			pMax
		));
	}
	
	RatchetJoint* Space::addConstraintRatchetJoint
	(
		Body& pBodyA,
		Body& pBodyB,
		const float& pPhase,
		const float& pRatchet
	)
	{
		return (RatchetJoint*)addConstraint(new RatchetJoint
		(
			pBodyA,
			pBodyB,
			pPhase,
			pRatchet
		));
	}
	GearJoint* Space::addConstraintGearJoint
	(
		Body& pBodyA,
		Body& pBodyB,
		const float& pPhase,
		const float& pRatio
	)
	{
		return (GearJoint*)addConstraint(new GearJoint
		(
			pBodyA,
			pBodyB,
			pPhase,
			pRatio
		));
	}
	SimpleMotor* Space::addConstraintSimpleMotor
	(
		Body& pBodyA,
		Body& pBodyB,
		const float& pRate
	)
	{
		return (SimpleMotor*)addConstraint(new SimpleMotor
		(
			pBodyA,
			pBodyB,
			pRate
		));
	}
	void Space::resizeStaticHash(const float& pDim, const int& pCount)
	{
		cpSpaceResizeStaticHash
		(
			mSpace,
			pDim,
			pCount
		);
	}
	
	void Space::resizeActiveHash(const float& pDim, const int& pCount)
	{
		cpSpaceResizeActiveHash
		(
			mSpace,
			pDim,
			pCount
		);
	}
	
	int Space::getColor(const int& pBase) const
	{
		int val = pBase;
		val = (val+0x7ed55d16) + (val<<12);
		val = (val^0xc761c23c) ^ (val>>19);
		val = (val+0x165667b1) + (val<<5);
		val = (val+0xd3a2646c) ^ (val<<9);
		val = (val+0xfd7046c5) + (val<<3);
		val = (val^0xb55a4f09) ^ (val>>16);
		return val;
	}
	
	void Space::draw(Graphic::Sprite& pSprite) const
	{
		for(int i = mBodies.size() - 1; i >= 0; --i)
		{
			mBodies[i]->draw(pSprite,getColor((int)mBodies[i]));
		}
		for(int i = mConstraints.size() - 1; i >= 0; --i)
		{
			mConstraints[i]->draw(pSprite,getColor((int)mConstraints[i]));
		}
		mStaticBody->draw(pSprite,getColor((int)mStaticBody));
	}
}}
