#include <physics/shape_circle.hpp>
#include <physics/body.hpp>
#include <chipmunk/chipmunk.h>

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

	Core::Point ShapeCircle::getOffset() const
	{
		return Core::Point
		(
			cpCircleShapeGetOffset(mShape).x,
			cpCircleShapeGetOffset(mShape).y
		);
	}

	float ShapeCircle::getRadius() const
	{
		return cpCircleShapeGetRadius(mShape);
	}

	void ShapeCircle::draw(const Graphic::Color& pColor) const
	{
		Graphic::Sprite image
		(
			Graphic::Image
			(
				getRadius() * 2,
				getRadius() * 2
			),
			0,0,
			Core::Point( getRadius(), getRadius() )
		);

		Graphic::Image* aux = Graphic::System::get().getTargetImage();
		Graphic::System::get().setTargetImage(image);

		Graphic::System::get().drawCircle
		(
			Core::Point( getRadius() , getRadius()),
			getRadius()-2,
			pColor,2
		);
		Graphic::System::get().drawLine
		(
			Core::Point( getRadius() , getRadius() ),
			Core::Point( getRadius() , getRadius() * 2),
			pColor,2
		);

		Graphic::System::get().setTargetImage(*aux);

		image.draw( mBody->getPosition(), mBody->getAngle()/360.0f );
	}
}}
