#include <graphic/animation.hpp>
#include <graphic/exception.hpp>
#include <sstream>

namespace Gorgon{
namespace Graphic
{
	AnimationFrame Animation::mNotFound = AnimationFrame();

	Animation::Animation()
	{
		mGroup			= -1;
		mIndex			= -1;
		mLooping		= false;
		mLoopFrame		= -1;
		mRepeatNumber	= -1;
	}

	Animation::Animation
	(
		const int& pGroup,
		const int& pIndex,
		const bool& pLooping,
		const int& pLoopFrame,
		const int& pRepeatNumber
	)
	{
		mGroup			= pGroup;
		mIndex			= pIndex;
		mLooping		= pLooping;
		mLoopFrame		= pLoopFrame;
		mRepeatNumber	= pRepeatNumber;
	}

	Animation::Animation(Core::File& pFile)
	{
		try
		{
			load(pFile);
		}
		catch(Core::Exception& exception)
		{
			raiseGraphicExceptionE("Animation::Animation(pFile): Error: Unable to load Animation.",exception);
		}
	}

	Animation::Animation(const std::string& pFileName)
	{
		try
		{
			load(pFileName);
		}
		catch(Core::Exception& exception)
		{
			raiseGraphicExceptionE(Core::String("Animation::Animation(\"") +pFileName+"\"): Error: Unable to load Animation.",exception);
		}
	}

	Animation::~Animation()
	{
		mFrame.clear();
	}

	void Animation::optimize(const SpritePack& pSpritePack)
	{
		for(unsigned int i = 0; i < mFrame.size(); ++i)
		{
			mFrame[i].optimize(pSpritePack);
		}
	}

	std::string Animation::describe()
	{
		std::stringstream out;
		out << "Gorgon Animation" 								<< std::endl;
		out << "Group:        " << mGroup 						<< std::endl;
		out << "Index:        " << mIndex 						<< std::endl;
		out << "Looping:      " << (mLooping ? "Yes" : "No")	<< std::endl;

		if(mLooping)
		{
			out << "LoopFrame:    " << mLoopFrame				<< std::endl;
			out << "RepeatNumber: " << mRepeatNumber			<< std::endl;
		}

		out << "FrameNumber:  " << getSize()					<< std::endl;

		for(register int i = 0; i < getSize(); ++i)
		{
			out << mFrame[i].describe();
		}
		return out.str();
	}

	int Animation::getFrameRealIndex(const int& pGroup, const int& pIndex)
	{
		for(register int i = 0; i < getSize(); ++i)
		{
			if(mFrame[i].getGroup() == pGroup && mFrame[i].getIndex() == pIndex)
			{
				return i;
			}
		}
		return -1;
	}

	void Animation::add(const AnimationFrame& pFrame)
	{
		mFrame.push_back(pFrame);
	}

	void Animation::add(const AnimationFrame& pFrame,const int& pPos)
	{
		mFrame.insert(mFrame.begin() + pPos,pFrame);
	}

	void Animation::remove(const int& pPos)
	{
		if(pPos >= 0 && pPos < (int)mFrame.size())
		{
			mFrame.erase(mFrame.begin() + pPos);
		}
	}

	void Animation::remove(const int& pGroup,const int& pIndex)
	{
		remove(getFrameRealIndex(pGroup,pIndex));
	}

	int Animation::getSize() const
	{
		return mFrame.size();
	}

	int Animation::getGroup() const
	{
		return mGroup;
	}

	int Animation::getIndex() const
	{
		return mIndex;
	}

	bool Animation::getLooping() const
	{
		return mLooping;
	}

	int Animation::getLoopFrame() const
	{
		return mLoopFrame;
	}

	int Animation::getRepeatNumber() const
	{
		return mRepeatNumber;
	}

	void Animation::setGroup(const int& pGroup)
	{
		mGroup = pGroup;
	}

	void Animation::setIndex(const int& pIndex)
	{
		mIndex = pIndex;
	}

	void Animation::setLooping(const bool& pLooping)
	{
		mLooping = pLooping;
	}

	void Animation::setLoopFrame(const int& pLoopFrame)
	{
		mLoopFrame = pLoopFrame;
	}

	void Animation::setRepeatNumber(const int& pRepeatNumber)
	{
		mRepeatNumber = pRepeatNumber;
	}

	void Animation::save(Core::File& pFile)
	{
		mHeader.fill(getSize());
		mHeader.save(pFile);
		pFile.writeInt32(getGroup());
		pFile.writeInt32(getIndex());
		pFile.writeBool(getLooping());

		if(getLooping())
		{
			pFile.writeInt32(getLoopFrame());
			pFile.writeInt32(getRepeatNumber());
		}

		for(register int i = 0; i < getSize(); ++i)
		{
			mFrame[i].save(pFile);
		}
	}

	void Animation::save(const std::string& pFileName)
	{
		Core::File file(pFileName,std::ios::out | std::ios::binary);

		if(file.is_open())
		{
			save(file);
		}
		else
		{
			raiseGraphicException("Animation::save("+pFileName+"): Error file could not be opened.");
		}
	}

	void Animation::load(Core::File& pFile)
	{
		mHeader.load(pFile);/**@todo fazer alguma coisa sobre isso*/
		if(mHeader.isValid())
		{
			try
			{
				setGroup	(pFile.readInt32());
				setIndex	(pFile.readInt32());
				setLooping	(pFile.readBool());
				if(getLooping())
				{
					setLoopFrame	(pFile.readInt32());
					setRepeatNumber	(pFile.readInt32());
				}
				else
				{
					setLoopFrame	(-1);
					setRepeatNumber	(-1);
				}
				for(int i = 0; i < mHeader.getFrameNumber(); ++i)
				{
					add(AnimationFrame(pFile));
				}
			}
			catch(Core::Exception& exception)
			{
				raiseGraphicExceptionE("Animation::load(pFile): Error while trying to load the animation from File",exception);
			}
		}
		else
		{
			raiseGraphicException("Animation::load(pFile): Error: Unable to load Animation due to incorrect format.");
		}
	}

	void Animation::load(const std::string& pFileName)
	{
		Core::File file(pFileName,std::ios::in | std::ios::binary);
		if(file.is_open())
		{
			load(file);
		}
		else
		{
			raiseGraphicException("Animation::load(\""+pFileName+"\"): Error: Unable to load Animation.");
		}
	}

	AnimationFrame& Animation::operator [](const int& pPos)
	{
		if(pPos >= 0 && pPos < (int)mFrame.size())
		{
			return mFrame[pPos];
		}
		else
		{
			return mNotFound;
		}
	}

	const AnimationFrame& Animation::operator [](const int& pPos) const
	{
		if(pPos >= 0 && pPos < (int)mFrame.size())
		{
			return mFrame[pPos];
		}
		else
		{
			return mNotFound;
		}
	}
}}
