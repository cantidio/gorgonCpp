#include <physics/shape_polygon.hpp>
#include <physics/body.hpp>
#include <chipmunk/chipmunk.h>
#include <graphic/system.hpp>

namespace Gorgon {
namespace Physics
{
	ShapePolygon::ShapePolygon
	(
		const std::vector<Core::Point>& pVerts,
		const Core::Point& pOffset,
		Body& pBody
	) : Shape(pBody)
	{
		cpVect verts[ pVerts.size() ];
		for(register int i = pVerts.size() - 1; i > -1; --i)
		{
			if(mMinimum.getX() > pVerts[i].getX())	mMinimum.setX(pVerts[i].getX());
			if(mMinimum.getY() > pVerts[i].getY())	mMinimum.setY(pVerts[i].getY());
			if(mMaximum.getX() < pVerts[i].getX())	mMaximum.setX(pVerts[i].getX());
			if(mMaximum.getY() < pVerts[i].getY())	mMaximum.setY(pVerts[i].getY());

			verts[i] = cpv(pVerts[i].getX(), pVerts[i].getY());
		}
		mShape = cpPolyShapeNew
		(
			getInternalBody(),//NULL,
			pVerts.size(),
			verts,
			cpv(pOffset.getX(), pOffset.getY())
		);
	}

	int ShapePolygon::getVerticesNumber() const
	{
		return cpPolyShapeGetNumVerts(mShape);
	}

	Core::Point ShapePolygon::getVertice(const int& pIndex) const
	{
		return Core::Point
		(
			cpPolyShapeGetVert(mShape, pIndex).x,
			cpPolyShapeGetVert(mShape, pIndex).y
		);
	}

	void ShapePolygon::draw(const Graphic::Color& pColor) const
	{
		const int border = 2;
		Graphic::Sprite poly
		(
			Graphic::Image
			(
				mMaximum.getX() - mMinimum.getX() + border + 2,
				mMaximum.getY() - mMinimum.getY() + border + 2
			),
			0, 0,
			(mMaximum - mMinimum + Core::Point(border+1,border+1)) / Core::Point(2.0f , 2.0f)
		);

poly.clear(Graphic::Color(1,0,0));

		Graphic::Image* aux = Graphic::System::get().getTargetImage();

		Graphic::System::get().setTargetImage(poly);


		if( getVerticesNumber() > 2)
		{
			for(register int i = getVerticesNumber() - 1; i > 0; --i)
			{
				Graphic::System::get().drawLine
				(
					getVertice(i)	- mMinimum + Core::Point(border,border),
					getVertice(i-1) - mMinimum + Core::Point(border,border),
					pColor, border
				);
			}

			Graphic::System::get().drawLine
			(
				getVertice(0)						- mMinimum + Core::Point(border,border),
				getVertice(getVerticesNumber()-1)	- mMinimum + Core::Point(border,border),
				pColor, border
			);
		}
		Graphic::System::get().setTargetImage(*aux);
		poly.draw (	mBody->getPosition(), mBody->getAngle() / 360.0f );
	}
}}
