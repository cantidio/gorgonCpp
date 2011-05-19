#include <sstream>
#include <graphic/animation_frame.hpp>
#include <graphic/exception.hpp>

namespace Gorgon{
namespace Graphic
{
	AnimationFrame::AnimationFrame()
	{
		mGroup		= 0;
		mIndex		= 0;
		mRealIndex	= -1;
		mOffset		= Core::Point(0,0);
		mTime		= 0;
		mMirroring	= Mirroring::Normal;
		mAngle		= 0;
	}

	AnimationFrame::AnimationFrame
	(
		const int&			pGroup,
		const int&			pIndex,
		const int&			pTime,
		const Mirroring&	pMirroring,
		const int&			pAngle,
		const Core::Point&	pOffset
	)
	{
		mGroup		= pGroup;
		mIndex		= pIndex;
		mRealIndex	= -1;
		mOffset		= pOffset;
		mTime		= pTime;
		mMirroring	= pMirroring;
		mAngle		= pAngle;
	}

	AnimationFrame::AnimationFrame(Core::File& pFile)
	{
		try
		{
			load(pFile);
		}
		catch(Core::Exception& exception)
		{
			raiseGraphicExceptionE("AnimationFrame::AnimationFrame(pFile): Error while trying to load the animationFrame from File",exception);
		}
	}

	std::string AnimationFrame::describe() const
	{
		std::stringstream out;
		out << "Gorgon::Graphic::AnimationFrame"	<< std::endl;
		out << "group: "		<< mGroup			<< std::endl;
		out << "index: "		<< mIndex			<< std::endl;
		out << "realIndex: "	<< mRealIndex		<< std::endl;
		out << "xOffset: "		<< mOffset.getX()	<< std::endl;
		out << "yOffset: "		<< mOffset.getY()	<< std::endl;
		out << "Time: "			<< mTime			<< std::endl;
		out << "Mirroring: ";

		switch(mMirroring.getType())
		{
			case Mirroring::Normal:	out << "Normal";	break;
			case Mirroring::HFlip:	out << "HFlip";	break;
			case Mirroring::VFlip:	out << "VFlip";	break;
			case Mirroring::VHFlip:	out << "VHFlip";	break;
			default:				out << "Unknown";
		}
		out << std::endl;
		out << "Angle: " << mAngle << " degrees" << std::endl;
		return out.str();
	}

	int AnimationFrame::getGroup() const
	{
		return mGroup;
	}

	int AnimationFrame::getIndex() const
	{
		return mIndex;
	}

	int AnimationFrame::getRealIndex() const
	{
		return mRealIndex;
	}

	Core::Point AnimationFrame::getOffset() const
	{
		return mOffset;
	}

	int AnimationFrame::getTime() const
	{
		return mTime;
	}

	Mirroring AnimationFrame::getMirroring() const
	{
		return mMirroring;
	}

	int AnimationFrame::getAngle() const
	{
		return mAngle;
	}

	void AnimationFrame::setGroup(const int& pGroup)
	{
		mGroup = pGroup;
	}

	void AnimationFrame::setIndex(const int& pIndex)
	{
		mIndex = pIndex;
	}

	void AnimationFrame::setRealIndex(const int& pIndex)
	{
		mRealIndex = pIndex;
	}

	void AnimationFrame::setTime(const int& pTime)
	{
		mTime = pTime;
	}

	void AnimationFrame::setOffset(const Core::Point& pOffset)
	{
		mOffset = pOffset;
	}
	void AnimationFrame::setXOffset(const int& pXOffset)
	{
		mOffset.setX(pXOffset);
	}

	void AnimationFrame::setYOffset(const int& pYOffset)
	{
		mOffset.setY(pYOffset);
	}

	void AnimationFrame::setMirroring(const Mirroring& pMirroring)
	{
		mMirroring = pMirroring;
	}

	void AnimationFrame::setAngle(const int& pAngle)
	{
		mAngle = pAngle;
	}

	void AnimationFrame::optimize(const SpritePack& pSpritePack)
	{
		mRealIndex = pSpritePack.getSpriteRealIndex(mGroup,mIndex);
	}

	void AnimationFrame::save(Core::File& pFile)
	{
		try
		{
			pFile.writeInt32(getGroup());
			pFile.writeInt32(getIndex());
			pFile.writeInt32(getRealIndex());
			pFile.writeInt32(getOffset().getX());
			pFile.writeInt32(getOffset().getY());
			pFile.writeInt32(getTime());
			pFile.write((char*)&mMirroring.getType(),sizeof(Mirroring::Type));
			pFile.writeInt32(getAngle());
		}
		catch(Core::Exception& exception)
		{
			raiseGraphicExceptionE("AnimationFrame::save(pFile): Error while saving the AnimationFrame into File",exception);
		}
	}

	void AnimationFrame::load(Core::File& pFile)
	{
		try
		{
			Mirroring::Type mirroring;
			setGroup	(pFile.readInt32());
			setIndex	(pFile.readInt32());
			setRealIndex(pFile.readInt32());
			setXOffset	(pFile.readInt32());
			setYOffset	(pFile.readInt32());
			setTime		(pFile.readInt32());
			pFile.read((char*)&mirroring,sizeof(Mirroring::Type));
			setAngle	(pFile.readInt32());
			mMirroring = mirroring;
		}
		catch(Core::Exception& exception)
		{
			raiseGraphicExceptionE("AnimationFrame::load(pFile): Error while loading the AnimationFrame from File",exception);
		}
	}
}}
