#include <script/gorgon_lua_exception.hpp>

#undef LuaException

namespace Gorgon{
namespace Script
{
	LuaException::LuaException
	(
		const std::string&	pMessage,
		const std::string&	pFile,
		const std::string&	pFunction,
		const int&			pLine
	) : Exception(pMessage,"Lua",pFile,pFunction,pLine){}
}}
