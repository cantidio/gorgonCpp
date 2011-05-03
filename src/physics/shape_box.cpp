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
			Graphic::Image(mWidth,mHeight),
			0,0,//x,y
			(mWidth / 2),
			(mHeight / 2) 
		);
		box.drawRectangle(0, 0, mWidth - 1, mHeight - 1, pColor);
		pSprite.drawSpriteRoteted
		(
			box,
			mBody->getPosition().getX(),
			mBody->getPosition().getY(),
			360/256 * mBody->getAngle()
		);
	}
}} 
