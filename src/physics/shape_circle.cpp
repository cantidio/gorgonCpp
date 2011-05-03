#include <physics/shape_circle.hpp>
#include <physics/body.hpp>

namespace Gorgon{
namespace Physics
{
	ShapeCircle::ShapeCircle
	(
		const float& pRadius,
		const Gorgon::Point& pOffset,
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
			0,
			0,
			getRadius(),
			getRadius()
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
			getRadius(),
			getRadius() - 1,
			getRadius() * 2 - 1,
			getRadius() - 1,
			pColor
		);
		image.drawImageStretched
		(
			a,
			0,0,//x,y
			getRadius() * 2,
			getRadius() * 2
		);
		pSprite.drawSpriteRoteted
		(
			image,
			mBody->getPosition().getX(),
			mBody->getPosition().getY(),
			360/256 * mBody->getAngle()
		);
	}
}}
