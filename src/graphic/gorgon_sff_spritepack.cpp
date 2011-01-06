#include "graphic/gorgon_sff_spritepack.hpp"

namespace Gorgon
{
	SffSpritePack::SffSpritePack(){}

	SffSpritePack::SffSpritePack(const std::string& pFileName)
	{
		load(pFileName);
	}

	SffSpritePack::SffSpritePack(Core::File& pFile)
	{
		load(pFile);
	}

	void SffSpritePack::load(const std::string& pFileName)
	{
		Core::File file(pFileName,std::ios::in | std::ios::binary);
		if(file.is_open())
		{
			load(file);
		}
		else
		{
			throw SpritePackException("Unable to load SffSpritePack: "+pFileName+".");
		}
	}
	
	Sprite SffSpritePack::loadSprite(Core::File& pFile) const
	{
		Image imageTmp;
		const int nextSubFile		= pFile.readInt32();
		const int sizeOfData		= pFile.readInt32();
		const short xOffset			= pFile.readInt16();
		const short yOffset			= pFile.readInt16();
		const short group			= pFile.readInt16();
		const short index			= pFile.readInt16();
		const short preIndex		= pFile.readInt16();
		const char	reusePalette	= pFile.readInt8();
		pFile.ignore(13);//comentários inúteis

		if(sizeOfData == 0)
		{
			pFile.seekg(pFile.beg + nextSubFile);
			return Sprite
			(
				(*this)[preIndex],
				group,
				index,
				xOffset,
				yOffset
			);
		}
		else
		{
			Sprite temp
			(
				Image(pFile,ImageFormatPcx()),
				group,
				index,
				xOffset,
				yOffset
			);

			if(!reusePalette)
			{
				pFile.seekg(pFile.beg + nextSubFile - 768);
				temp.setPalette(new Palette(pFile));
				temp.getPalette()->inverse();
			}
			else if(getSize() > 0)
			{
				temp.setPalette((*this)[getSize()-1].getPalette()->copy());
			}
			else
			{
				//printf("lala\n");
				temp.setPalette(NULL);
			}
			pFile.seekg(pFile.beg + nextSubFile);
			temp.updateBuffer();
			return temp;
		}
	}

	void SffSpritePack::load(Core::File& pFile)
	{
		const std::string signature	= pFile.readString(12);
		const std::string version	= pFile.readString(4);
		const int groupNumber		= pFile.readInt32();
		const int imageNumber		= pFile.readInt32();
		const int offset			= pFile.readInt32();
		const int subHeaderSize		= pFile.readInt32();
		const char paletteType		= pFile.readInt8();
		pFile.ignore(479);

		mPalLinked		= false;
		mGlobalPalette	= NULL;
		for(int i = 0; i < imageNumber; ++i)
		{
			add(loadSprite(pFile));
		}
	}
}

