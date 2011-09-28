#include "geometry/gorgon_rectangle.hpp"

namespace Gorgon
{
	Rectangle::Rectangle
	(
		const int&			pWidth,
		const int&			pHeight,
		const Core::Point&	pPosition
	)
	{
		setWidth(pWidth);
		setHeight(pHeight);
		setPosition(pPosition);
	}
	
	std::string Rectangle::describe() const
	{
		std::stringstream out;
		out << "Rectangle Describer" << std::endl;
		out << "width:	" << getWidth() << std::endl;
		out << "height:	" << getHeight() << std::endl;
		out << "PosX:   " << getPosition().getX() << std::endl;
		out << "PosY:   " << getPosition().getY() << std::endl;
		return out.str();
	}

	void Rectangle::setWidth(const int& pWidth)
	{
		mWidth = pWidth;
	}

	void Rectangle::setHeight(const int& pHeight)
	{
		mHeight = pHeight;
	}

	void Rectangle::setPosition(const Core::Point& pPosition)
	{
		mPosition = pPosition;
	}
	
	int Rectangle::getWidth() const
	{
		return mWidth;
	}
	
	int Rectangle::getHeight() const
	{
		return mHeight;
	}

	Core::Point Rectangle::getPosition() const
	{
		return mPosition;
	}
	
	bool Rectangle::intersect
	(
		const Rectangle&	pRectangle,
		const Core::Point&	pAbsolutePosition,
		const Core::Point&	pAbsoluteRectanglePosition
	) const
	{
		if
		(
			(pAbsolutePosition.getX() + getPosition().getX()				> pAbsoluteRectanglePosition.getX() + pRectangle.getPosition().getX() + pRectangle.getWidth()	) ||
			(pAbsolutePosition.getY() + getPosition().getY()				> pAbsoluteRectanglePosition.getY() + pRectangle.getPosition().getY() + pRectangle.getHeight()	) ||
			(pAbsolutePosition.getX() + getPosition().getX() + getWidth()	< pAbsoluteRectanglePosition.getX() + pRectangle.getPosition().getX()							) ||
			(pAbsolutePosition.getY() + getPosition().getY() + getHeight()	< pAbsoluteRectanglePosition.getY() + pRectangle.getPosition().getY()							)
		)
		{
			return false;
		}
		return true;
	}
}
