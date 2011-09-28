#include <physics/shape_segment.hpp>
#include <physics/body.hpp>
#include <chipmunk/chipmunk.h>

namespace Gorgon {
namespace Physics
{
	ShapeSegment::ShapeSegment
	(
		const Core::Point& pPointA,
		const Core::Point& pPointB,
		const float& pRadius,
		Body& pBody
	) : Shape(pBody)
	{
		mShape = cpSegmentShapeNew
		(
			getInternalBody(),//NULL,
			cpv(pPointA.getX(), pPointA.getY()),
			cpv(pPointB.getX(), pPointB.getY()),
			pRadius
		);
	}

	Core::Point ShapeSegment::getPointA() const
	{
		return Core::Point
		(
			cpSegmentShapeGetA(mShape).x,
			cpSegmentShapeGetA(mShape).y
		);
	}

	Core::Point ShapeSegment::getPointB() const
	{
		return Core::Point
		(
			cpSegmentShapeGetB(mShape).x,
			cpSegmentShapeGetB(mShape).y
		);
	}

	Core::Point ShapeSegment::getNormal() const
	{
		return Core::Point
		(
			cpSegmentShapeGetNormal(mShape).x,
			cpSegmentShapeGetNormal(mShape).y
		);
	}

	float ShapeSegment::getRadius() const
	{
		return cpSegmentShapeGetRadius(mShape);
	}

	void ShapeSegment::draw(const Graphic::Color& pColor) const
	{
		Graphic::System::get().drawLine( getPointA(), getPointB(), pColor );
	}
}}
