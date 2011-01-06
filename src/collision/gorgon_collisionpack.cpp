#include "collision/gorgon_collisionpack.hpp"

namespace Gorgon
{
	Collision CollisionPack::mNotFound = Collision();
	CollisionPack::CollisionPack()
	{
	}
			
	CollisionPack::CollisionPack(Core::File& pFile)
	{
		load(pFile);
	}

	CollisionPack::CollisionPack(const std::string& pFileName)
	{
		load(pFileName);
	}

	CollisionPack::~CollisionPack()
	{
		clear();
	}

	std::string CollisionPack::describe() const
	{
		std::stringstream out;
		out << "CollisionPack Describer"	<< std::endl;
		out << "Collision number: "			<< getSize() << std::endl;

		for(int i = 0; i < getSize(); ++i)
		{
			out << mCollision[i].describe();
		}
		return out.str();
	}

	int CollisionPack::getSize() const
	{
		return mCollision.size();
	}

	void CollisionPack::clear()
	{
		const int collisionSize = getSize();
		for(int i = 0; i < collisionSize; ++i)
		{
			remove(i);
		}
		mCollision.clear();
	}

	int CollisionPack::getCollisionRealIndex(const int& pGroup, const int& pIndex) const
	{
		const int collisionSize = getSize();
		for (register int i = 0; i < collisionSize; ++i)
		{
			if(mCollision[i].getGroup() == pGroup && mCollision[i].getIndex() == pIndex)
			{
				return i;
			}
		}
		return -1;
	}

	void CollisionPack::add(const Collision& pCollision)
	{
		mCollision.push_back(pCollision);
	}

	void CollisionPack::add(const Collision& pCollision,const int& pPos)
	{
		mCollision.insert(mCollision.begin() + pPos,pCollision);
	}

	void CollisionPack::remove(const unsigned int& pPos)
	{
		if(pPos >= 0 && pPos < mCollision.size())
		{
			mCollision.erase(mCollision.begin() + pPos);
		}
	}

	void CollisionPack::remove(const int& pGroup,const int& pIndex)
	{
		remove
		(
			getCollisionRealIndex(pGroup,pIndex)
		);
	}

	void CollisionPack::save(Core::File& pFile) const
	{
		const int collisionSize = getSize();
		pFile.writeInt32(collisionSize);
		
		for(int i = 0; i < collisionSize; ++i)
		{
			mCollision[i].save(pFile);
		}
	}

	void CollisionPack::save(const std::string& pFileName) const
	{
		Core::File file(pFileName,std::ios::out | std::ios::binary);
		save(file);
	}

	void CollisionPack::load(Core::File& pFile)
	{
		const int collisionSize = pFile.readInt32();
		for(int i = 0; i < collisionSize; ++i)
		{
			add(Collision(pFile));
		}
	}

	void CollisionPack::load(const std::string& pFileName)
	{
		Core::File file(pFileName,std::ios::in | std::ios::binary);
		load(file);
	}

	Collision& CollisionPack::operator [](const int& pPos)
	{
		if(pPos >= 0 && pPos < getSize())
		{
			return mCollision[pPos];
		}
		return mNotFound;
	}

	const Collision& CollisionPack::operator [](const int& pPos) const
	{
		if(pPos >= 0 && pPos < getSize())
		{
			return mCollision[pPos];
		}
		return mNotFound;
	}

	Collision& CollisionPack::operator ()(const int& pGroup,const int& pIndex)
	{
		return (*this)[getCollisionRealIndex(pGroup,pIndex)];
	}

	const Collision& CollisionPack::operator ()(const int& pGroup,const int& pIndex) const
	{
		return (*this)[getCollisionRealIndex(pGroup,pIndex)];
	}
}
