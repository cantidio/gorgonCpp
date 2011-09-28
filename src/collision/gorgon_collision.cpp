#include "collision/gorgon_collision.hpp"

namespace Gorgon
{
	CollisionFrame Collision::notFound = CollisionFrame();


	Collision::Collision(const int& pGroup,const int& pIndex)
	{
		setGroup(pGroup);
		setIndex(pIndex);
	}

	Collision::Collision(Core::File& pFile)
	{
		load(pFile);
	}

	Collision::Collision(const std::string& pFileName)
	{
		load(pFileName);
	}

	Collision::~Collision()
	{
		mCollisions.clear();
	}

	int Collision::getGroup() const
	{
		return mGroup;
	}

	int Collision::getIndex() const
	{
		return mIndex;
	}

	void Collision::setGroup(const int& pGroup)
	{
		mGroup = pGroup;
	}

	void Collision::setIndex(const int& pIndex)
	{
		mIndex = pIndex;
	}

	std::string Collision::describe() const
	{
		std::stringstream out;
		out << "Collision Describer"		<< std::endl;
		out << "Group:                 "	<< getGroup()	<< std::endl;
		out << "Index:                 "	<< getIndex()	<< std::endl;
		out << "CollisionFrame number: "	<< getSize()	<< std::endl;

		for(int i = 0; i < getSize(); ++i)
		{
			out << mCollisions[i].describe();
		}
		return out.str();
	}

	int Collision::getSize() const
	{
		return mCollisions.size();
	}

	void Collision::add(const CollisionFrame& pCollisionFrame)
	{
		mCollisions.push_back(pCollisionFrame);
	}

	void Collision::remove(const int& pPos)
	{
		if(pPos >= 0 && pPos < (int)mCollisions.size())
		{
			mCollisions.erase(mCollisions.begin() + pPos);
		}
	}

	void Collision::save(Core::File& pFile) const
	{
		const int collisionFrameSize = getSize();
		pFile.writeInt32(getGroup());
		pFile.writeInt32(getIndex());
		pFile.writeInt32(collisionFrameSize);
		for(int i = 0; i < collisionFrameSize; ++i)
		{
			(*this)[i].save(pFile);
		}
	}

	void Collision::save(const std::string& pFileName) const
	{
		Core::File file(pFileName,std::ios::out | std::ios::binary);
		save(file);
	}

	void Collision::load(Core::File& pFile)
	{
		setGroup(pFile.readInt32());
		setIndex(pFile.readInt32());
		const int collisionFrameSize = pFile.readInt32();
		for(int i = 0; i < collisionFrameSize; ++i)
		{
			add(CollisionFrame(pFile));
		}
	}

	void Collision::load(const std::string& pFileName)
	{
		Core::File file(pFileName,std::ios::in | std::ios::binary);
		load(file);
	}

	CollisionFrame& Collision::operator[](const unsigned int& pPos)
	{
		if(pPos >= 0 && pPos < mCollisions.size())
		{
			return mCollisions[pPos];
		}
		return notFound;
	}

	const CollisionFrame& Collision::operator[](const unsigned int& pPos) const
	{
		if(pPos >= 0 && pPos < mCollisions.size())
		{
			return mCollisions[pPos];
		}
		return notFound;
	}
}
