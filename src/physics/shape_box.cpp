#include <physics/shape_box.hpp>
#include <physics/body.hpp>

namespace Gorgon{
namespace Physics
{
	ShapeBox::ShapeBox
	(
		const int& pWidth,
		const int& pHeight,
		Body& pBody
	) : Shape(pBody)
	{
		mWidth	= pWidth;
		mHeight	= pHeight;
		mShape = cpBoxShapeNew
		(
			getInternalBody(),
			mWidth,
			mHeight
		);
	}

	void ShapeBox::draw(const Graphic::Color& pColor) const
	{
		Graphic::Sprite box
		(
			Graphic::Image(mWidth, mHeight),
			0,0,
			Core::Point( mWidth/2.0f, mHeight/2.0f )
		);

		Graphic::Image* aux = Graphic::System::get().getTargetImage();
		Graphic::System::get().setTargetImage(box);

		Graphic::System::get().drawRectangle
		(
			Core::Point(0,0) + Core::Point(2,2),
			Core::Point(mWidth, mHeight) - Core::Point(2,2),
			pColor,
			2
		);
		Graphic::System::get().setTargetImage(*aux);
		box.draw( mBody->getPosition(), mBody->getAngle() / 360.0f );
	}
}}
