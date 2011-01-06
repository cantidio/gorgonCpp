#include <physics/shape_segment.hpp>
#include <physics/body.hpp>

namespace Gorgon{
namespace Physics
{
	ShapeSegment::ShapeSegment
	(
		const Gorgon::Point& pPointA,
		const Gorgon::Point& pPointB,
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
	
	void ShapeSegment::draw(Gorgon::Sprite& pSprite, const int& pColor) const
	{
		pSprite.drawLine
		(
			getPointA().getX(),
			getPointA().getY(),
			getPointB().getX(),
			getPointB().getY(),
			pColor
		);
	}
}}
