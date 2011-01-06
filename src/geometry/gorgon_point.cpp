#include "geometry/gorgon_point.hpp"

namespace Gorgon
{
	Point::Point
	(
		const double& pX,
		const double& pY
	)
	{
		int a;
		setX(pX);
		setY(pY);
	}

	Point::Point(const double& pValue)
	{
		setX(pValue);
		setY(pValue);
	}
	
	Point::Point(const Point& pPoint)
	{
		setX(pPoint.getX());
		setY(pPoint.getY());
	}
	
	void Point::describe() const
	{
		std::cout << "x: " << getX() << std::endl;
		std::cout << "y: " << getY() << std::endl;
	}
	
	bool Point::operator == (const Point& pPoint) const
	{
		return
		(
			getX() == pPoint.getX() &&
			getY() == pPoint.getY()
		);
	}

	Point Point::operator - (const Point& pPoint) const
	{
		Point value(*this);
		value -= pPoint;
		return value;
	}

	Point Point::operator + (const Point& pPoint) const
	{
		Point value(*this);
		value += pPoint;
		return value;
	}

	Point Point::operator * (const Point& pPoint) const
	{
		Point value(*this);
		value *= pPoint;
		return value;
	}

	Point Point::operator / (const Point& pPoint) const
	{
		Point value(*this);
		value /= pPoint;
		return value;
	}

	void Point::operator -= (const Point& pPoint)
	{
		subX(pPoint.getX());
		subY(pPoint.getY());
	}

	void Point::operator += (const Point& pPoint)
	{
		addX(pPoint.getX());
		addY(pPoint.getY());
	}

	void Point::operator *= (const Point& pPoint)
	{
		mulX(pPoint.getX());
		mulY(pPoint.getY());
	}

	void Point::operator /= (const Point& pPoint)
	{
		divX(pPoint.getX());
		divY(pPoint.getY());
	}
}
