#include <physics/shape_segment.hpp>
#include <physics/body.hpp>

namespace Gorgon{
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
	
	void ShapeSegment::draw(Graphic::Sprite& pSprite, const int& pColor) const
	{
		pSprite.drawLine
		(
			getPointA(),
			getPointB(),
			pColor
		);
	}
}}
