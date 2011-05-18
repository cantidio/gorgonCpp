#include <physics/shape_circle.hpp>
#include <physics/body.hpp>

namespace Gorgon{
namespace Physics
{
	ShapeCircle::ShapeCircle
	(
		const float& pRadius,
		const Core::Point& pOffset,
		Body& pBody
	) : Shape(pBody)
	{
		mShape = cpCircleShapeNew
		(
			getInternalBody(),
			pRadius,
			cpv(pOffset.getX(),pOffset.getY())
		);
	}
	
	void ShapeCircle::draw(Graphic::Sprite& pSprite, const int& pColor) const
	{
		Graphic::Image a(getRadius() * 2 - 1, getRadius() * 2 - 1);
		Graphic::Sprite image
		(
			Graphic::Image
			(
				getRadius() * 2,
				getRadius() * 2
			),
			0,0,
			Core::Point( getRadius(),	getRadius() )
		);
		a.drawCircle
		(
			getRadius() - 1,
			getRadius() - 1,
			getRadius() - 1,
			pColor
		);
		a.drawLine
		(
			Core::Point(getRadius()			, getRadius() - 1),
			Core::Point(getRadius()*2 - 1	, getRadius() - 1),
			pColor
		);
		image.drawImageStretched
		(
			a,
			Core::Point(0,0),
			getRadius() * 2,
			getRadius() * 2
		);
		pSprite.drawSpriteRotated
		(
			image,
			mBody->getPosition(),
			360/256 * mBody->getAngle()
		);
	}
}}
