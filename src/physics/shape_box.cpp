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
	
	void ShapeBox::draw(Graphic::Sprite& pSprite, const int& pColor) const
	{
		Graphic::Sprite box
		(
			Graphic::Image(mWidth, mHeight),
			0,0,
			Point(mWidth/2, mHeight/2)
		);
		box.drawRectangle( Point(0,0), Point(mWidth - 1, mHeight - 1), pColor);
		pSprite.drawSpriteRotated
		(
			box,
			mBody->getPosition(),
			360/256 * mBody->getAngle()
		);
	}
}} 
