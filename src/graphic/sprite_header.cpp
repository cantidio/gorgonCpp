#include <graphic/sprite_header.hpp>
#include <graphic/exception.hpp>
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
		try
		{
			load(pFile);
		}
		catch(Core::Exception& exception)
		{
			raiseGraphicExceptionE("SpriteHeader::SpriteHeader(pFile): Error while creating spriteheader.",exception);
		}
	}

	void SpriteHeader::save(Core::File& pFile)
	{
		if(pFile.is_open())
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
		else
		{
			raiseGraphicException("SpriteHeader::save(pFile): Error, the file is not opened for writting.");
		}
	}

	void SpriteHeader::load(Core::File& pFile)
	{
		if(pFile.is_open())
		{
			mPutPos = pFile.tellp();
			mGetPos = pFile.tellg();
			FileHeader::load(pFile);

			std::string signature	= pFile.readString(mGorgonSpriteSignature.length());
			int			magicNumber	= pFile.readInt32();
			int			version		= pFile.readInt32();

			/**@todo rbetornar mensagens de exception adequadas*/
			if
			(
				FileHeader::isValid()
				&& magicNumber	== mGorgonSpriteMagicNumber
				&& signature	== mGorgonSpriteSignature
				&& version		== 1
			)
			{
				setGroup		( pFile.readInt32() );
				setIndex		( pFile.readInt32() );
				mOffset.setX	( pFile.readInt32() );
				mOffset.setY	( pFile.readInt32() );
				setSizeOfData	( pFile.readInt32() );
			}
			else
			{
				raiseGraphicException("SpriteHeader::load(pFile): Error, the header is invalid, maybe this isn't a gorgon sprite");
			}
		}
		else
		{
			raiseGraphicException("SpriteHeader::load(pFile): Error, the file is not opened for reading.");
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
	void SpriteHeader::setOffset(const Core::Point& pOffset)
	{
		mOffset = pOffset;
	}
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
	Core::Point SpriteHeader::getOffset()	const
	{
		return mOffset;
	}
	int SpriteHeader::getSize()
	{
		/**@todo encontrar outra forma de se fazer isso... ou não*/
		//32 = 8 * 4(sizeof(int))
		return 32 + mGorgonSpriteSignature.length();
	}
}}
