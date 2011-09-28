#include "core/point.hpp"
#include <sstream>

namespace Gorgon{
namespace Core
{
	Point::Point()
	{
		setX(0);
		setY(0);
	}

	Point::Point
	(
		const double& pX,
		const double& pY
	)
	{
		setX(pX);
		setY(pY);
	}

	Point::Point(const Point& pPoint)
	{
		setX(pPoint.getX());
		setY(pPoint.getY());
	}
	
	std::string Point::describe() const
	{
		std::stringstream out;
		out << "Gorgon::Core::Point::describe()" << std::endl;
		out << "x: " << getX() << std::endl;
		out << "y: " << getY() << std::endl;
		return out.str();
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
}}
