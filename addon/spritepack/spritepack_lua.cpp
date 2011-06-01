#include "spritepack_lua.hpp"
#include <gorgon++/script/lua.hpp>
#include <sstream>

namespace Gorgon{
namespace Addon
{
	SpritePackLua::SpritePackLua(){}
	SpritePackLua::SpritePackLua(const SpritePack& pSpritePack) : SpritePack(pSpritePack) {}
	SpritePackLua::SpritePackLua(const Core::String& pFileName)
	{
		load(pFileName);
	}

	void SpritePackLua::save(const Core::String& pFileName)
	{
		Core::File file(pFileName,std::ios::out);
		std::vector<Core::String> pieces;
		Core::String subfilename;
		Core::String dir;

		pieces = pFileName.explode("/");
		for(unsigned int i = 0; i < pieces.size() - 1; ++i)
		{
			dir.append(pieces[i]);
			dir.append("/");
		}
		pieces = pieces.back().explode(".");
		subfilename.append(pieces[0]);
		for(unsigned int i = 1; i < pieces.size() - 1; ++i)
		{
			subfilename.append(".");
			subfilename.append(pieces[i]);
		}

		if(file.is_open())
		{
			file << "spritepack = {\n";
			for(int i = 0; i < getSize(); ++i)
			{
				std::stringstream filename;
				filename << dir << subfilename << "_image_" << i << ".bmp";
				((Graphic::Image)(*this)[i]).save(filename.str());

				file << "\t{\n";
				file << "\t\tgroup   = " << (*this)[i].getGroup()	<< ",\n";
				file << "\t\tindex   = " << (*this)[i].getIndex()	<< ",\n";
				file << "\t\txoffset = " << (*this)[i].getOffset().getX()	<< ",\n";
				file << "\t\tyoffset = " << (*this)[i].getOffset().getY()	<< ",\n";
				file << "\t\timage   = " << "\"" << subfilename << "_image_" << i << ".bmp\"\n";
				file << "\t},\n";
			}
			file << "}";
		}
	}

	void SpritePackLua::load(const Core::String& pFileName)
	{
		Script::Lua script(pFileName);
		//registra algumas funções para serem executadas na recuperação dos dados do spritepack
		script.executeString("function getSpriteNumber()	return #spritepack				end");
		script.executeString("function getSpriteLocation(i)	return spritepack[i].image		end");
		script.executeString("function getSpriteGroup(i)	return spritepack[i].group		end");
		script.executeString("function getSpriteIndex(i)	return spritepack[i].index		end");
		script.executeString("function getSpriteXOffset(i)	return spritepack[i].xoffset	end");
		script.executeString("function getSpriteYOffset(i)	return spritepack[i].yoffset	end");
		std::vector<Core::String> pieces = pFileName.explode("/");
		Core::String dir;

		for(unsigned int i = 0; i < pieces.size() - 1; ++i)
		{
			dir.append(pieces[i]);
			dir.append("/");
		}
		const int sprites = script.function("getSpriteNumber",Script::LuaParam(),1).getNumericValue();

		for(int i = 1; i <= sprites; ++i)
		{
			std::stringstream image;
			image << dir << script.function("getSpriteLocation", Script::LuaParam("i",i),1).getStringValue();
			this->add
			(
				Graphic::Sprite
				(
					Graphic::Image( image.str() ),
					script.function("getSpriteGroup"	, Script::LuaParam("i",i), 1).getNumericValue(),
					script.function("getSpriteIndex"	, Script::LuaParam("i",i), 1).getNumericValue(),
					Core::Point
					(
						script.function("getSpriteXOffset"	, Script::LuaParam("i",i), 1).getNumericValue(),
						script.function("getSpriteYOffset"	, Script::LuaParam("i",i), 1).getNumericValue()
					)
				)
			);
		}
	}
}}
