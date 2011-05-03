#include "graphic/gorgon_frame.hpp"
#include <sstream>

namespace Gorgon{
namespace Graphic
{
	Frame::Frame()
	{
		mGroup		= 0;
		mIndex		= 0;
		mRealIndex	= -1;
		mOffset		= Point(0,0);
		mTime		= 0;
		mMirroring	= Mirroring::Normal;
		mAngle		= 0;
	}

	Frame::Frame
	(
		const int&			pGroup,
		const int&			pIndex,
		const int&			pTime,
		const Mirroring&	pMirroring,
		const int&			pAngle,
		const Point&		pOffset
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

	Frame::Frame(Core::File& pFile)
	{
		load(pFile);
	}

	std::string Frame::describe() const
	{
		std::stringstream out;
		out << "Gorgon Frame"	<< std::endl;
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

	int Frame::getGroup() const
	{
		return mGroup;
	}

	int Frame::getIndex() const
	{
		return mIndex;
	}

	int Frame::getRealIndex() const
	{
		return mRealIndex;
	}

	Point Frame::getOffset() const
	{
		return mOffset;
	}

	int Frame::getTime() const
	{
		return mTime;
	}

	Mirroring Frame::getMirroring() const
	{
		return mMirroring;
	}

	int Frame::getAngle() const
	{
		return mAngle;
	}

	void Frame::setGroup(const int& pGroup)
	{
		mGroup = pGroup;
	}

	void Frame::setIndex(const int& pIndex)
	{
		mIndex = pIndex;
	}

	void Frame::setRealIndex(const int& pIndex)
	{
		mRealIndex = pIndex;
	}

	void Frame::setTime(const int& pTime)
	{
		mTime = pTime;
	}

	void Frame::setOffset(const Point& pOffset)
	{
		mOffset = pOffset;
	}
	void Frame::setXOffset(const int& pXOffset)
	{
		mOffset.setX(pXOffset);
	}

	void Frame::setYOffset(const int& pYOffset)
	{
		mOffset.setY(pYOffset);
	}

	void Frame::setMirroring(const Mirroring& pMirroring)
	{
		mMirroring = pMirroring;
	}

	void Frame::setAngle(const int& pAngle)
	{
		mAngle = pAngle;
	}

	void Frame::optimize(const SpritePack& pSpritePack)
	{
		mRealIndex = pSpritePack.getSpriteRealIndex(mGroup,mIndex);
	}

	void Frame::save(Core::File& pFile)
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

	void Frame::load(Core::File& pFile)
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
}}
