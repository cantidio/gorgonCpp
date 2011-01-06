#include "script/gorgon_lua_return.hpp"

namespace Gorgon{
namespace Script
{	
	LuaReturn::LuaReturn(lua_State* pState,const int& pVarNumber)
	{
		for(int i=0; i<pVarNumber; ++i)
		{
			if(lua_isnumber(pState,-1))
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
				throw LuaException("Unable to define argument type");
			}
			lua_pop(pState,1);
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
