#include <script/lua_return.hpp>
#include <script/exception.hpp>
extern "C"
{
	#include <lua5.1/lua.h>
	#include <lua5.1/lualib.h>
	#include <lua5.1/lauxlib.h>
}

namespace Gorgon{
namespace Script
{
	LuaReturn::LuaReturn(lua_State* pState, const int& pVarNumber)
	{
		if(pState != NULL)
		{
			for(int i = 0; i < pVarNumber; ++i)
			{
				if( lua_isnumber( pState, -1 ) )
				{
					mArgs.push_back(LuaArgument((double)(lua_tonumber(pState,-1))));
				}
				else if(lua_isstring(pState,-1))
				{
					mArgs.push_back(LuaArgument(std::string(lua_tostring(pState,-1))));
				}
				else if(lua_isboolean(pState,-1))
				{
					mArgs.push_back(LuaArgument((bool)(lua_toboolean(pState,-1))));
				}
				else if(lua_isnoneornil(pState,-1))
				{
					mArgs.push_back(LuaArgument());
				}
				else
				{
					raiseScriptException("LuaReturn::LuaReturn(pState,pVarNumber): Error, unable to define argument type.");
				}
				lua_pop(pState,1);
			}
		}
		else
		{
			raiseScriptException("LuaReturn::LuaReturn(pState,pVarNumber): Error, lua state is NULL.");
		}
	}

	std::string LuaReturn::getStringValue(const int& pPos) const
	{
		return mArgs[pPos].getStringValue();
	}

	double LuaReturn::getNumericValue(const int& pPos) const
	{
		return mArgs[pPos].getDoubleValue();
	}

	bool LuaReturn::getBoolValue(const int& pPos) const
	{
		return mArgs[pPos].getBoolValue();
	}

	int LuaReturn::getSize() const
	{
		return mArgs.size();
	}
}}
