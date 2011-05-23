#include "spritepack_sff.hpp"
#include <gorgon++/graphic/graphic.hpp>
#include <gorgon++/addon/image_loader/gorgon++/include/gorgon_image_loader_pcx.hpp>

namespace Gorgon{
namespace Addon
{
	SpritePackSff::SpritePackSff(){}

	SpritePackSff::SpritePackSff(const std::string& pFileName)
	{
		load(pFileName);
	}

	SpritePackSff::SpritePackSff(Core::File& pFile)
	{
		load(pFile);
	}

	void SpritePackSff::load(const std::string& pFileName)
	{
		Core::File file(pFileName,std::ios::in | std::ios::binary);
		if(file.is_open())
		{
			load(file);
			file.close();
		}
		else
		{
			raiseGraphicException("SpritePackSff::load(\""+pFileName+"\"): Error, unable to open the file for reading.");
		}
	}
	
	Graphic::Sprite SpritePackSff::loadSprite(Core::File& pFile) const
	{
		//Graphic::Image imageTmp;
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
			return Graphic::Sprite
			(
				(*this)[preIndex],
				group,
				index,
				Core::Point(xOffset,yOffset)
			);
		}
		else
		{
			/**@todo talvez utilizar outro loader, ou deixar empty*/
			Graphic::Sprite temp
			(
				Graphic::Image(pFile, ImageLoaderPcx() ),
				group,
				index,
				Core::Point(xOffset,yOffset)
			);
			if(!reusePalette)
			{
				pFile.seekg(pFile.beg + nextSubFile - 768);
				temp.setPalette(new Graphic::Palette(pFile), true);
				temp.getPalette()->inverse();
			}
			else if(getSize() > 0)
			{
				temp.setPalette( (*this)[getSize()-1].getPalette()->copy() , true);
			}
			else
			{
				temp.setPalette(NULL);
			}
			pFile.seekg(pFile.beg + nextSubFile);
			temp.updateBuffer();
			return temp;
		}
	}

	void SpritePackSff::load(Core::File& pFile)
	{
		const std::string signature	= pFile.readString(12);
		const std::string version	= pFile.readString(4);
		const int groupNumber		= pFile.readInt32();
		const int imageNumber		= pFile.readInt32();
		const int offset			= pFile.readInt32();
		const int subHeaderSize		= pFile.readInt32();
		const char paletteType		= pFile.readInt8();
		pFile.ignore(479);
/**@todo verificar o header e versão dessa porra.*/

		for(int i = 0; i < imageNumber; ++i)
		{
			add(loadSprite(pFile));
		}
	}
}}
