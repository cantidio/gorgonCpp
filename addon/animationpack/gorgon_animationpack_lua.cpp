#include "gorgon_animationpack_lua.hpp"
namespace Gorgon
{
	AnimationPackLua::AnimationPackLua(){}
	AnimationPackLua::AnimationPackLua(Core::File& pFile)
	{
		load(pFile);
	}
	AnimationPackLua::AnimationPackLua(const Core::String& pFileName)
	{
		load(pFileName);
	}
	void AnimationPackLua::save(const Core::String& pFileName)
	{

	}
	void AnimationPackLua::save(Core::File& pFile)
	{
		if(pFile.is_open())
		{
			pFile << "animationpack = {\n";

			for(unsigned int i = 0; i < getSize(); ++i)
			{
				pFile << "\t{\n";
				pFile << "\t\tgroup   		= " << (*this)[i].getGroup()						<< ",\n";
				pFile << "\t\tindex   		= " << (*this)[i].getIndex()						<< ",\n";
				pFile << "\t\tlooping 		= " << ((*this)[i].getLooping() ? "true" : "false")	<< ",\n";
				pFile << "\t\tloopFrame		= " << (*this)[i].getLoopFrame()					<< ",\n";
				pFile << "\t\trepeatNumber	= " << (*this)[i].getRepeatNumber()					<< ",\n";
				pFile << "\t\tframes		= {\n";

				for(unsigned int j = 0; j < (*this)[i].getSize(); ++j)
				{
					Frame a = (*this)[i][j];
					pFile << "\t\t\t{\n";
					pFile << "\t\t\t\tgroup		= " << a.getGroup()					<< ",\n";
					pFile << "\t\t\t\tindex		= " << a.getIndex()					<< ",\n";
					pFile << "\t\t\t\txoffset	= " << a.getXOffset()				<< ",\n";
					pFile << "\t\t\t\tyoffset	= " << a.getYOffset()				<< ",\n";
					pFile << "\t\t\t\ttime		= "	<< a.getTime()					<< ",\n";
					pFile << "\t\t\t\tmorroring	= " << a.getMirroring().getType()	<< ",\n";
					pFile << "\t\t\t\tangle		= " << a.getAngle() 				<< "\n";
					pFile << "\t\t\t},\n";
				}
				pFile << "\t\t}\n";
				pFile << "\t},\n";
			}
			pFile << "}";
		}
	}
	void AnimationPackLua::load(const Core::String& pFileName)
	{

	}
	void AnimationPackLua::load(Core::File& pFile)
	{

	}
}
