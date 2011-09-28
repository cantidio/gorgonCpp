#include <graphic/animationpack.hpp>
#include <graphic/exception.hpp>
#include <sstream>

namespace Gorgon{
namespace Graphic
{
	Animation AnimationPack::mNotFound;

	AnimationPack::AnimationPack(){}

	AnimationPack::AnimationPack(Core::File& pFile)
	{
		load(pFile);
	}

	AnimationPack::AnimationPack(const std::string& pFileName)
	{
		load(pFileName);
	}

	AnimationPack::~AnimationPack()
	{
		clear();
	}

	void AnimationPack::optimize(const SpritePack& pSpritePack)
	{
		for(unsigned int i = 0; i < mAnimation.size(); ++i)
		{
			mAnimation[i].optimize(pSpritePack);
		}
	}

	std::string AnimationPack::describe()
	{
		std::stringstream out;
		out << "Gorgon::Graphic::AnimationPack"	<< std::endl;
		out << "Size: " << getSize()	<< std::endl;

		for(int i = 0; i < getSize(); i++)
		{
			out << mAnimation[i].describe();
		}
		return out.str();
	}

	void AnimationPack::clear()
	{
		mAnimation.clear();
	}

	int AnimationPack::getAnimationRealIndex(const int& pGroup, const int& pIndex)
	{
		for(int i = 0; i < getSize(); ++i)
		{
			if(mAnimation[i].getGroup() == pGroup && mAnimation[i].getIndex() == pIndex)
			{
				return i;
			}
		}
		return -1;
	}

	void AnimationPack::add(const Animation& pAnimation)
	{
		mAnimation.push_back(pAnimation);
	}
	
	void AnimationPack::add(const Animation& pAnimation,const int& pPos)
	{
		mAnimation.insert(mAnimation.begin() + pPos, pAnimation);
	}

	void AnimationPack::remove(const int& pPos)
	{
		if(pPos >= 0 && pPos < getSize())
		{
			mAnimation.erase(mAnimation.begin() + pPos);
		}
	}

	void AnimationPack::remove(const int& pGroup,const int& pIndex)
	{
		remove(getAnimationRealIndex(pGroup,pIndex));
	}

	int AnimationPack::getSize()
	{
		return mAnimation.size();
	}

	void AnimationPack::save(Core::File& pFile)
	{
		mHeader.fill(getSize());
		mHeader.save(pFile);
		for(int i = 0; i < getSize(); ++i)
		{
			mAnimation[i].save(pFile);
		}
	}

	void AnimationPack::save(const std::string& pFileName)
	{
		Core::File file(pFileName,std::ios::out | std::ios::binary);
		if(file.is_open())
		{
			try
			{
				save(file);
			}
			catch(Core::Exception& exception)
			{
				raiseGraphicExceptionE("AnimationPack::save(\""+pFileName+"\"): Error while saving the AnimationPack",exception);
			}
		}
		else
		{
			raiseGraphicException("AnimationPack::save(\""+pFileName+"\"): Error: could not open the file for writting");
		}
	}

	void AnimationPack::load(Core::File& pFile)
	{
		if(pFile.is_open())
		{
			mHeader.load(pFile);
			if(mHeader.isValid())
			{
				for(int i = 0; i < mHeader.getAnimationNumber(); ++i)
				{
					add(Animation(pFile));
				}
			}
			else
			{
				raiseGraphicException("AnimationPack::load(pFile): Error : animationpack header with incorrect format.");
			}
		}
		else
		{
			raiseGraphicException("AnimationPack::load(pFile): Error: The file passed as argument isn't opened.");
		}
	}

	void AnimationPack::load(const std::string& pFileName)
	{
		Core::File file(pFileName,std::ios::in | std::ios::binary);
		if(file.is_open())
		{
			try
			{
				load(file);
			}
			catch(Core::Exception& exception)
			{
				raiseGraphicExceptionE("AnimationPack::load(\""+pFileName+"\"): Error while loading the AnimationPack from File",exception);
			}
		}
		else
		{
			raiseGraphicException("AnimationPack::load(\""+pFileName+"\"): Error: could not open the file for reading");
		}
	}

	Animation& AnimationPack::operator [](const int& pPos)
	{
		if(pPos >= 0 && pPos < getSize())
		{
			return mAnimation[pPos];
		}
		else
		{
			return mNotFound;
		}
	}

	Animation& AnimationPack::operator ()(const int& pGroup,const int& pIndex)
	{
		return (*this)[getAnimationRealIndex(pGroup,pIndex)];
	}
}}
