#include "gorgon_animationpack_lua.hpp"
#include <gorgon++/script/lua.hpp>
#include <gorgon++/graphic/exception.hpp>

namespace Gorgon{
namespace Graphic
{
	AnimationPackLua::AnimationPackLua() {}
	AnimationPackLua::AnimationPackLua(const AnimationPack& pAnimationPack) : AnimationPack(pAnimationPack) {}

	AnimationPackLua::AnimationPackLua(const Core::String& pFileName)
	{
		load(pFileName);
	}

	void AnimationPackLua::save(const Core::String& pFileName)
	{
		Core::File file(pFileName,std::ios::out);
		if(file.is_open())
		{
			file << "animationpack = {\n";

			for(int i = 0; i < getSize(); ++i)
			{
				file << "\t{\n";
				file << "\t\tgroup   		= " << (*this)[i].getGroup()						<< ",\n";
				file << "\t\tindex   		= " << (*this)[i].getIndex()						<< ",\n";
				file << "\t\tlooping 		= " << ((*this)[i].getLooping() ? "true" : "false")	<< ",\n";
				file << "\t\tloopFrame		= " << (*this)[i].getLoopFrame()					<< ",\n";
				file << "\t\trepeatNumber	= " << (*this)[i].getRepeatNumber()					<< ",\n";
				file << "\t\tframes			= {\n";

				for(int j = 0; j < (*this)[i].getSize(); ++j)
				{
					AnimationFrame a = (*this)[i][j];
					file << "\t\t\t{\n";
					file << "\t\t\t\tgroup		= " << a.getGroup()					<< ",\n";
					file << "\t\t\t\tindex		= " << a.getIndex()					<< ",\n";
					file << "\t\t\t\txoffset\t	= " << a.getOffset().getX()			<< ",\n";
					file << "\t\t\t\tyoffset\t	= " << a.getOffset().getY()			<< ",\n";
					file << "\t\t\t\ttime		= "	<< a.getTime()					<< ",\n";
					file << "\t\t\t\tmirroring	= " << a.getMirroring().getType()	<< ",\n";
					file << "\t\t\t\tangle		= " << a.getAngle() 				<< "\n";
					file << "\t\t\t},\n";
				}
				file << "\t\t}\n";
				file << "\t},\n";
			}
			file << "}";
		}
		else
		{
			raiseGraphicException("AnimationPackLua::save(\""+pFileName+"\"): Error, could not open the file for writting.");
		}
	}

	void AnimationPackLua::load(const Core::String& pFileName)
	{
		try
		{
			Script::Lua script(pFileName);
			//registra algumas funções para serem executadas na recuperação dos dados do animationpack
			script.executeString("function getAnimationNumber()			return #animationpack					or 0		end");
			script.executeString("function getAnimationGroup(i)			return animationpack[i].group			or 0		end");
			script.executeString("function getAnimationIndex(i)			return animationpack[i].index			or 0		end");
			script.executeString("function getAnimationLooping(i)		return animationpack[i].looping			or false	end");
			script.executeString("function getAnimationLoopFrame(i)		return animationpack[i].loopFrame		or 0		end");
			script.executeString("function getAnimationRepeatNumber(i)	return animationpack[i].repeatNumber	or 0		end");
			script.executeString("function getFrameNumber(i)		return #animationpack[i].frames				or 0		end");
			script.executeString("function getFrameGroup(i,j)		return animationpack[i].frames[j].group		or 0		end");
			script.executeString("function getFrameIndex(i,j)		return animationpack[i].frames[j].index		or 0		end");
			script.executeString("function getFrameTime(i,j)		return animationpack[i].frames[j].time		or 0		end");
			script.executeString("function getFrameMirroring(i,j)	return animationpack[i].frames[j].mirroring	or 0		end");
			script.executeString("function getFrameAngle(i,j)		return animationpack[i].frames[j].angle		or 0		end");
			script.executeString("function getFrameXOffset(i,j)		return animationpack[i].frames[j].xoffset	or 0		end");
			script.executeString("function getFrameYOffset(i,j)		return animationpack[i].frames[j].yoffset	or 0		end");


			const int animationNumber = script.function("getAnimationNumber",Script::LuaParam(),1).getNumericValue();
			for(int i = 1; i <= animationNumber; ++i)//em lua os vetores começam em 1
			{
				Animation aux
				(
					script.function("getAnimationGroup"			, Script::LuaParam("i",i), 1).getNumericValue(),
					script.function("getAnimationIndex"			, Script::LuaParam("i",i), 1).getNumericValue(),
					script.function("getAnimationLooping"		, Script::LuaParam("i",i), 1).getBoolValue(),
					script.function("getAnimationLoopFrame"		, Script::LuaParam("i",i), 1).getNumericValue(),
					script.function("getAnimationRepeatNumber"	, Script::LuaParam("i",i), 1).getNumericValue()
				);

				const int frameNumber = script.function("getFrameNumber" , Script::LuaParam("i",i), 1).getNumericValue();
				for(int j = 1; j <= frameNumber; ++j)
				{
					aux.add
					(
						AnimationFrame
						(
							script.function("getFrameGroup"		, Script::LuaParam("ii",i,j), 1).getNumericValue(),
							script.function("getFrameIndex"		, Script::LuaParam("ii",i,j), 1).getNumericValue(),
							script.function("getFrameTime"		, Script::LuaParam("ii",i,j), 1).getNumericValue(),
							Mirroring((Mirroring::Type)script.function("getFrameMirroring" , Script::LuaParam("ii",i,j), 1).getNumericValue()),
							script.function("getFrameAngle"		, Script::LuaParam("ii",i,j), 1).getNumericValue(),
							Core::Point
							(
								script.function("getFrameXOffset"	, Script::LuaParam("ii",i,j), 1).getNumericValue(),
								script.function("getFrameYOffset"	, Script::LuaParam("ii",i,j), 1).getNumericValue()
							)
						)
					);
				}
				add(aux);
			}
		}
		catch(Core::Exception& exception)
		{
			raiseGraphicExceptionE("AnimationPackLua::load(\""+pFileName+"\"): Error while loading the animationpack script.",exception);
		}
	}
}}
