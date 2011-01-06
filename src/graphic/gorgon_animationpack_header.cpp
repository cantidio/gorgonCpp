#include "graphic/gorgon_animationpack_header.hpp"

namespace Gorgon
{
	const std::string	AnimationPackHeader::mAnimationPackSignature	= "GANM_PK";
	const float			AnimationPackHeader::mAnimationPackVersion		= 0.1;

	AnimationPackHeader::AnimationPackHeader(){}

	AnimationPackHeader::AnimationPackHeader(Core::File& pFile)
	{
		load(pFile);
	}

	void AnimationPackHeader::fill(const int& pAnimationNumber)
	{
		mAnimationNumber = pAnimationNumber;
	}

	int AnimationPackHeader::getAnimationNumber() const
	{
		return mAnimationNumber;
	}

	void AnimationPackHeader::save(Core::File& pFile)
	{
		FileHeader::save(pFile);
		pFile.writeString(mAnimationPackSignature);
		pFile.writeFloat(mAnimationPackVersion);
		pFile.writeInt32(mAnimationNumber);
	}

	void AnimationPackHeader::load(Core::File& pFile)
	{
		FileHeader::load(pFile);
		mMyAnimationPackSignature	= pFile.readString(mAnimationPackSignature.length());
		mMyAnimationPackVersion		= pFile.readFloat();
		mAnimationNumber			= pFile.readInt32();
	}

	bool AnimationPackHeader::isValid()
	{
		if(FileHeader::isValid())
		{
			for(unsigned int i = 0; i < mAnimationPackSignature.length(); ++i)
			{
				if(mAnimationPackSignature[i] != mMyAnimationPackSignature[i])
				{
					return false;
				}
			}
			if(mMyAnimationPackVersion != mAnimationPackVersion)
			{
				return false;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	long AnimationPackHeader::getSize()
	{
		return mAnimationPackSignature.length() + sizeof(float) + sizeof(int);
	}

	void AnimationPackHeader::returnFilePosition(Core::File& pFile)
	{
		FileHeader::returnFilePosition(pFile,getSize());
	}
}

