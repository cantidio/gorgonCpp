#include <physics/shape.hpp>
#include <physics/body.hpp>

namespace Gorgon{
namespace Physics
{
	Shape::Shape(Body& pBody)
	{
		printf("Creating the Shape: %d\n",(int)this);
		mBody = &pBody;
	}

	Shape::~Shape()
	{
		printf("Deleting the Shape: %d\n",(int)this);
		cpShapeFree(mShape);
	}
	
	cpBody* Shape::getInternalBody() const
	{
		return mBody->mBody;
	}
}}
