#include "graphic/gorgon_sprite_header.hpp"

namespace Gorgon
{
	const int			SpriteHeader::mGorgonSpriteMagicNumber	= 0x676f267;
	const std::string	SpriteHeader::mGorgonSpriteSignature	= "GSPR";
	
	SpriteHeader::SpriteHeader(){}

	SpriteHeader::SpriteHeader(Core::File& pFile)
	{
		load(pFile);
	}

	void SpriteHeader::save(Core::File& pFile)
	{
		FileHeader::save(pFile);
		pFile.writeString(mGorgonSpriteSignature);
		pFile.writeInt32(mGorgonSpriteMagicNumber);
	}

	void SpriteHeader::load(Core::File& pFile)
	{
		FileHeader::load(pFile);
		mMyGorgonSpriteSignature	= pFile.readString(mGorgonSpriteSignature.length());
		mMyGorgonSpriteMagicNumber	= pFile.readInt32();
	}

	bool SpriteHeader::isValid()
	{
		if
		(
			!FileHeader::isValid()
			|| mMyGorgonSpriteMagicNumber	!= mGorgonSpriteMagicNumber
			|| mMyGorgonSpriteSignature		!= mGorgonSpriteSignature
		)
		{
			return false;
		}
		return true;
	}

	void SpriteHeader::returnFilePosition(Core::File& pFile)
	{
		FileHeader::returnFilePosition
		(
			pFile,
			sizeof(int) * 2 + sizeof(char) * mGorgonSpriteSignature.length()
		);
	}
}
