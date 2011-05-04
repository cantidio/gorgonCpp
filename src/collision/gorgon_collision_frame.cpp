#include "collision/gorgon_collision_frame.hpp"

namespace Gorgon
{
	Rectangle CollisionFrame::mNotFound = Rectangle(0,0);
	
	CollisionFrame::CollisionFrame()
	{
	}
	
	CollisionFrame::CollisionFrame(Core::File& pFile)
	{
		load(pFile);
	}
	
	std::string CollisionFrame::describe() const
	{
		std::stringstream out;
		out << "CollisionFrame" << std::endl;
		out << "Rectangles number: " << getSize() << std::endl;
		const int collisionSize = getSize();
		for(register int i = 0; i < collisionSize; ++i)
		{
			out << "Rectangle: "	<< (i+1)							<< std::endl;
			out << "Width: "		<< mBoxes[i].getWidth()				<< std::endl;
			out << "Height: "		<< mBoxes[i].getHeight()			<< std::endl;
			out << "OffsetX:"		<< mBoxes[i].getPosition().getX()	<< std::endl;
			out << "OffsetY:"		<< mBoxes[i].getPosition().getY()	<< std::endl;
		}
		return out.str();
	}
	
	void CollisionFrame::draw
	(
		const Point& pPosition,
		const Graphic::Color& pColor,
		Graphic::Image& pImage
	) const
	{
		const int rectangleNumber = getSize();
		for(register int i = 0; i < rectangleNumber; ++i)
		{
			//pImage.drawRectangle(pPosition, mBoxes[i], pColor);
		}
	}

	/**
	 * @todo	olhar nomeclatura correta de colide
	 */
	bool CollisionFrame::colide
	(
		const CollisionFrame&	pCollisionFrame,
		const Point&			pAbsolutePosition,
		const Point&			pAbsoluteColisionPosition
	) const
	{
		const int collisionSize = pCollisionFrame.getSize() - 1;
		for(register int i = getSize() - 1; i >= 0; --i)
		{
			for(register int j = collisionSize; j >= 0; --j)
			{
				if
				(
					mBoxes[i].intersect
					(
						pCollisionFrame.mBoxes[j],
						pAbsolutePosition,
						pAbsoluteColisionPosition
					)
				)
				{
					return true;
				}
			}
		}
		return false;
	}

	void CollisionFrame::save(Core::File& pFile) const
	{
		const int boxNumber = getSize();
		pFile.writeInt32(boxNumber);
		for(register int i = 0; i < boxNumber; ++i)
		{
			pFile.writeInt32(mBoxes[i].getWidth());
			pFile.writeInt32(mBoxes[i].getHeight());
			pFile.writeDouble(mBoxes[i].getPosition().getX());
			pFile.writeDouble(mBoxes[i].getPosition().getY());
		}
	}
	
	void CollisionFrame::load(Core::File& pFile)
	{
		int boxNumber = pFile.readInt32();
		Rectangle aux;
		for(int i = 0; i < boxNumber; ++i)
		{
			aux.setWidth(pFile.readInt32());
			aux.setHeight(pFile.readInt32());
			aux.setPosition(Point(pFile.readDouble(),pFile.readDouble()));
			add(aux);
		}
	}
	
	int CollisionFrame::getSize() const
	{
		return mBoxes.size();
	}

	void CollisionFrame::add(const Rectangle& pRectangle)
	{
		mBoxes.push_back(pRectangle);
	}

	void CollisionFrame::add(const Rectangle& pRectangle,const int& pPos)
	{
		mBoxes.insert(mBoxes.begin() + pPos,pRectangle);
	}

	Rectangle& CollisionFrame::operator[](const int& pPos)
	{
		if(pPos >= 0 && pPos < getSize())
		{
			return mBoxes[pPos];
		}
		return mNotFound;
	}
	
	const Rectangle& CollisionFrame::operator[](const int& pPos) const
	{
		if(pPos >= 0 && pPos < getSize())
		{
			return mBoxes[pPos];
		}
		return mNotFound;
	}
}
