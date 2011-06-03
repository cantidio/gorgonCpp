#include <script/lua_argument.hpp>
#include <script/exception.hpp>

namespace Gorgon{
namespace Script
{
	LuaArgument::LuaArgument()
	{
		clear();
	}

	LuaArgument::LuaArgument(const double& pArg)
	{
		clear();
		mDoubleArg	= pArg;
		mMyType		= LuaArgument::Double;
	}

	LuaArgument::LuaArgument(const std::string& pArg)
	{
		clear();
		mStringArg	= pArg;
		mMyType		= LuaArgument::String;
	}

	LuaArgument::LuaArgument(const bool& pArg)
	{
		clear();
		mBoolArg	= pArg;
		mMyType		= LuaArgument::Boolean;
	}

	void LuaArgument::clear()
	{
		mBoolArg	= false;
		mStringArg	= "";
		mDoubleArg	= 0;
		mMyType		= LuaArgument::Null;
	}

	double LuaArgument::getDoubleValue() const
	{
		return mDoubleArg;
	}

	bool LuaArgument::getBoolValue() const
	{
		return mBoolArg;
	}

	std::string LuaArgument::getStringValue() const
	{
		return mStringArg;
	}

	LuaArgument::Type LuaArgument::getType() const
	{
		return mMyType;
	}

	void LuaArgument::push(lua_State* pState) const
	{
		switch(getType())
		{
			case LuaArgument::Double:	lua_pushnumber(pState, mDoubleArg);			break;
			case LuaArgument::String:	lua_pushstring(pState, mStringArg.c_str());	break;
			case LuaArgument::Boolean:	lua_pushboolean(pState,mBoolArg);			break;
			case LuaArgument::Null:		lua_pushnil(pState);						break;
			default:
				raiseScriptException("LuaArgument::push(pState): Error, unable to define argument type.");
		}
	}
}}
