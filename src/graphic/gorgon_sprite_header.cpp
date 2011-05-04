#include <graphic/gorgon_sprite_header.hpp>
#include <graphic/gorgon_sprite_exception.hpp>
#include <iostream>

namespace Gorgon{
namespace Graphic
{
	const int			SpriteHeader::mGorgonSpriteMagicNumber	= 0x676f267;
	const std::string	SpriteHeader::mGorgonSpriteSignature	= "GSPR";
	const int			SpriteHeader::mGorgonSpriteVersion		= 1;

	SpriteHeader::SpriteHeader(){}

	SpriteHeader::SpriteHeader(Core::File& pFile)
	{
		load(pFile);
	}

	void SpriteHeader::save(Core::File& pFile)
	{
		mPutPos = pFile.tellp();
		mGetPos = pFile.tellg();
		FileHeader::save(pFile);

		pFile.writeString(mGorgonSpriteSignature);
		pFile.writeInt32(mGorgonSpriteMagicNumber);
		pFile.writeInt32(mGorgonSpriteVersion);

		//@todo escrever largura e altura da imagem?
		pFile.writeInt32(mGroup);
		pFile.writeInt32(mIndex);
		pFile.writeInt32(mOffset.getX());
		pFile.writeInt32(mOffset.getY());
		pFile.writeInt32(mSizeofData);
	}

	void SpriteHeader::load(Core::File& pFile)
	{
		mPutPos = pFile.tellp();
		mGetPos = pFile.tellg();
		FileHeader::load(pFile);

		std::string signature	= pFile.readString(mGorgonSpriteSignature.length());
		int			magicNumber	= pFile.readInt32();
		int			version		= pFile.readInt32();
		/**@todo retornar mensagens de exception adequadas*/
		if
		(
			FileHeader::isValid()
			&& magicNumber	== mGorgonSpriteMagicNumber
			&& signature	== mGorgonSpriteSignature
			&& version		== 1
		)
		{
			setGroup		(pFile.readInt32());
			setIndex		(pFile.readInt32());
			mOffset.setX	(pFile.readInt32());
			mOffset.setY	(pFile.readInt32());
			setSizeOfData	(pFile.readInt32());

			/*std::cout << "Group:    " << mGroup   << std::endl;
			std::cout << "Index:    " << mIndex   << std::endl;
			std::cout << "XOffset:  " << mXOffset << std::endl;
			std::cout << "YOffset:  " << mYOffset << std::endl;
			std::cout << "DataSize: " << mSizeofData << std::endl;*/
		}
		else
		{
			//std::cout << "Not a gorgon sprite." << std::endl;
			throw SpriteException("Not a gorgon sprite.");
		}
	}

	void SpriteHeader::returnFilePosition(Core::File& pFile)
	{
		pFile.seekg(mGetPos);
		pFile.seekp(mPutPos);
	}
	void SpriteHeader::setSizeOfData(const int& pSizeOfData)
	{
		mSizeofData = pSizeOfData;
	}
	void SpriteHeader::setGroup(const int& pGroup)
	{
		mGroup = pGroup;
	}
	void SpriteHeader::setIndex(const int& pIndex)
	{
		mIndex = pIndex;
	}
	void SpriteHeader::setOffset(const Point& pOffset)
	{
		mOffset = pOffset;
	}
//	void SpriteHeader::setYOffset(const int& pYOffset)
//	{
//		mYOffset = pYOffset;
//	}
	int SpriteHeader::getSizeOfData() const
	{
		return mSizeofData;
	}
	int SpriteHeader::getGroup()	const
	{
		return mGroup;
	}
	int SpriteHeader::getIndex()	const
	{
		return mIndex;
	}
	Point SpriteHeader::getOffset()	const
	{
		return mOffset;
	}
	int SpriteHeader::getSize()
	{
		//32 = 8 * 4(sizeof(int))
		return 32 + mGorgonSpriteSignature.length();
	}
}}
