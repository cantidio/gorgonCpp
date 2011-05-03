#include <physics/body.hpp>
#include <physics/shape_circle.hpp>
#include <physics/shape_box.hpp>
#include <physics/shape_polygon.hpp>
#include <physics/shape_segment.hpp>
#include <physics/space.hpp>

namespace Gorgon{
namespace Physics
{
	Body::Body(cpBody *pBody, Space& pSpace)
	{
		printf("Creating the Body: %d\n",(int)this);
		mBody	= pBody;
		mLocal	= false;
		mSpace	= &pSpace;
	}
	
	Body::Body(const float& pMass, const float& pMoment, Space& pSpace)
	{
		printf("Creating the Body: %d\n",(int)this);
		mBody	= cpBodyNew(pMass, pMoment);
		mSpace	= &pSpace;
		mLocal	= true;
	}
	
	Body::~Body()
	{
		printf("Deleting the Body: %d\n",(int)this);
		for(int i = mShapes.size() - 1; i >= 0; --i)
		{
			delete mShapes[i];
		}
		if(mLocal)
		{
			cpBodyFree(mBody);
		}
	}
	
	ShapeCircle* Body::addShapeCircle(const float& pRadius, const Point& pOffset)
	{
		ShapeCircle* circle = new ShapeCircle
		(
			pRadius,
			pOffset,
			*this
		); 
		mShapes.push_back(circle);
		mSpace->addShape(circle);
		return circle;
	}
	
	ShapeBox* Body::addShapeBox(const int& pWidth, const int& pHeight)
	{
		ShapeBox* box = new ShapeBox
		(
			pWidth,
			pHeight,
			*this
		);
		mShapes.push_back(box);
		mSpace->addShape(box);
		return box;
	}
	
	ShapePolygon* Body::addShapePolygon(const std::vector<Point>& pVerts, const Point& pOffset)
	{
		ShapePolygon* polygon = new ShapePolygon
		(
			pVerts,
			pOffset,
			*this
		);
		mShapes.push_back(polygon);
		mSpace->addShape(polygon);
		return polygon; 
	}
	
	ShapeSegment* Body::addShapeSegment
	(
		const Point& pPointA,
		const Point& pPointB,
		const float& pRadius = 0.0f
	)
	{
		ShapeSegment* segment = new ShapeSegment
		(
			pPointA,
			pPointB,
			pRadius,
			*this
		);
		mShapes.push_back(segment);
		mSpace->addShape(segment);
		return segment; 
	}
//------------------------------------------------------------------------------------------
	float Body::getMomentForCircle
	(
		const float& pMass,
		const float& pDiameter,
		const float& pInnerDiameter,
		const Point& pOffset
	)
	{
		return cpMomentForCircle
		(
			pMass,
			pDiameter,
			pInnerDiameter,
			cpv(pOffset.getX(), pOffset.getY())
		);
	}
	
	float Body::getMomentForBox
	(
		const float& pMass,
		const float& pWidth,
		const float& pHeight
	)
	{
		return cpMomentForBox
		(
			pMass,
			pWidth,
			pHeight
		);
	}
	
	float Body::getMomentForSegment
	(
		const float& pMass,
		const Point& pPointA,
		const Point& pPointB
	)
	{
		return cpMomentForSegment
		(
			pMass,
			cpv(pPointA.getX(), pPointA.getY()),
			cpv(pPointB.getX(), pPointB.getY())
		);
	}
	
	float Body::getMomentForPolygon
	(
		const float& pMass,
		const std::vector<Point>& pVerts,
		const Point& pOffset
	)
	{
		cpVect verts[ pVerts.size() ];
		for(register int i = pVerts.size() - 1; i > -1; --i)
		{
			verts[i] = cpv(pVerts[i].getX(), pVerts[i].getY());
		}
		return cpMomentForPoly
		(
			pMass,
			pVerts.size(),
			verts,
			cpv(pOffset.getX(),pOffset.getY())
		);
	}
	
	void Body::draw(Graphic::Sprite& pSprite, const int& pColor) const
	{
		for(int i = getShapeNumber() - 1; i >= 0; --i)
		{
			mShapes[i]->draw
			(
				pSprite,
				pColor
			);
		}
	}
}}
