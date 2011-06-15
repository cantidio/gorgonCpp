#include <physics/shape.hpp>
#include <physics/body.hpp>
#include <chipmunk/chipmunk.h>

namespace Gorgon{
namespace Physics
{
	Shape::Shape(Body& pBody)
	{
		mBody = &pBody;
	}

	Shape::~Shape()
	{
		cpShapeFree(mShape);
	}

	bool Shape::isSensor() const
	{
		return mShape->sensor;
	}

	float Shape::getElasticity() const
	{
		return mShape->e;
	}

	void Shape::setElasticity(const float& pElasticity)
	{
		mShape->e = pElasticity;
	}

	float Shape::getFriction()
	{
		return mShape->u;
	}

	void Shape::setFriction(const float& pCoefficient)
	{
		mShape->u = pCoefficient;
	}

	Core::Point Shape::getSurfaceVelocity() const
	{
		return Core::Point
		(
			mShape->surface_v.x,
			mShape->surface_v.y
		);
	}

	void Shape::setGroup(const unsigned int& pGroup)
	{
		mShape->group = pGroup;
	}

	unsigned int Shape::getGroup() const
	{
		return mShape->group;
	}


	cpBody* Shape::getInternalBody() const
	{
		return mBody->mBody;
	}
}}
