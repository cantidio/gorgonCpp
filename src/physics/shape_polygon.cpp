#include <physics/shape_polygon.hpp>
#include <physics/body.hpp>

namespace Gorgon{
namespace Physics
{
	ShapePolygon::ShapePolygon
	(
		const std::vector<Gorgon::Point>& pVerts,
		const Gorgon::Point& pOffset,
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
	
	void ShapePolygon::draw(Graphic::Sprite& pSprite,const int& pColor) const
	{
		Graphic::Sprite poly
		(
			Graphic::Image
			(
				mMaximum.getX() - mMinimum.getX() + 1,
				mMaximum.getY() - mMinimum.getY() + 1
			),0,0,
			(mMaximum - mMinimum)/2
		);
		if( getVerticesNumber() > 2)
		{
			for(register int i = getVerticesNumber() - 1; i > 0; --i)
			{
				poly.drawLine
				(
					getVertice(i)	- mMinimum,
					getVertice(i-1) - mMinimum,
					pColor
				);
			}
			poly.drawLine
			(
				getVertice(0)						- mMinimum,
				getVertice(getVerticesNumber()-1)	- mMinimum,
				pColor
			);
		}
		pSprite.drawSpriteRotated
		(
			poly,
			mBody->getPosition(),
			360/256 * mBody->getAngle()
		);
	}
}}
