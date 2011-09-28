#include "graphic/spritepack_header.hpp"

namespace Gorgon{
namespace Graphic
{
	const int			SpritePackHeader::mGorgonSpritePackMagicNumber	= 0x676f267f;
	const std::string	SpritePackHeader::mGorgonSpritePackSignature	= "GSPR_PK";
	
	SpritePackHeader::SpritePackHeader(){}
	
	SpritePackHeader::SpritePackHeader(Core::File& pFile)
	{
		load(pFile);
	}
	
	void SpritePackHeader::save(Core::File& pFile)
	{
		FileHeader::save(pFile);
		pFile.writeString(mGorgonSpritePackSignature);
		pFile.writeInt32(mGorgonSpritePackMagicNumber);
	}
	
	void SpritePackHeader::load(Core::File& pFile)
	{
		FileHeader::load(pFile);
		mMyGorgonSpritePackSignature	= pFile.readString(mGorgonSpritePackSignature.length());
		mMyGorgonSpritePackMagicNumber	= pFile.readInt32();
	}
	
	bool SpritePackHeader::isValid()
	{
		if
		(
			!FileHeader::isValid()
			|| mMyGorgonSpritePackMagicNumber != mGorgonSpritePackMagicNumber
			|| mMyGorgonSpritePackSignature != mGorgonSpritePackSignature
		)
		{
			return false;
		}
		return true;
	}
	
	void SpritePackHeader::returnFilePosition(Core::File& pFile)
	{
		FileHeader::returnFilePosition
		(
			pFile,
			sizeof(int) * 2 + sizeof(char) * mGorgonSpritePackSignature.length()
		);
	};
}}
