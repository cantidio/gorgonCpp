#include "graphic/gorgon_animation_header.hpp"

namespace Gorgon
{
	const std::string	AnimationHeader::mAnimationSignature	= "GANM";
	const float			AnimationHeader::mAnimationVersion		= 0.101;

	AnimationHeader::AnimationHeader(){}

	AnimationHeader::AnimationHeader(Core::File& pFile)
	{
		load(pFile);
	}

	void AnimationHeader::fill(const int& pFrameNumber)
	{
		mFrameNumber = pFrameNumber;
	}

	int AnimationHeader::getFrameNumber() const
	{
		return mFrameNumber;
	}

	void AnimationHeader::save(Core::File& pFile)
	{
		FileHeader::save(pFile);
		pFile.writeString(mAnimationSignature);
		pFile.writeFloat(mAnimationVersion);
		pFile.writeInt32(mFrameNumber);
	}

	void AnimationHeader::load(Core::File& pFile)
	{
		FileHeader::load(pFile);
		mMyAnimationSignature	= pFile.readString(mAnimationSignature.length());
		mMyAnimationVersion		= pFile.readFloat();
		mFrameNumber			= pFile.readInt32();
	}

	bool AnimationHeader::isValid()
	{
		if(FileHeader::isValid())
		{
			for(unsigned int i = 0; i < mAnimationSignature.length(); ++i)
			{
				if(mAnimationSignature[i] != mMyAnimationSignature[i])
				{
					return false;
				}
			}
			if(mMyAnimationVersion != mAnimationVersion)
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

	long AnimationHeader::getSize()
	{
		return mAnimationSignature.length() + sizeof(float) + sizeof(int);
	}

	void AnimationHeader::returnFilePosition(Core::File& pFile)
	{
		FileHeader::returnFilePosition(pFile,getSize());
	}
}
