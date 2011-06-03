#include <script/lua_param.hpp>
#include <script/exception.hpp>

namespace Gorgon{
namespace Script
{
	LuaParam::LuaParam(){}

	LuaParam::LuaParam(const std::string& pDesc, ...)
	{
		va_list args;
		va_start(args,pDesc);

		for(unsigned int i = 0; i < pDesc.length(); ++i)
		{
			switch(pDesc[i])
			{
				case 'd':	case 'D':
				case 'i':	case 'I':
				case 'n':	case 'N':
					push((double)va_arg(args,int));
					break;
				case 's': 	case 'S':
					push(std::string(va_arg(args,char*)));
					break;
				case 'b':
				case 'B':
					push(bool(va_arg(args,char*)));
					break;
				default	:
					raiseScriptException("LuaParam::LuaParam(\""+pDesc+"\"): Error, unable to define argument type.");
			}
		}
		va_end(args);
	}

	void LuaParam::push(const double& pArg)
	{
		mArgs.push_back(LuaArgument(pArg));
	}

	void LuaParam::push(const std::string& pArg)
	{
		mArgs.push_back(LuaArgument(pArg));
	}

	void LuaParam::push(const bool& pArg)
	{
		mArgs.push_back(LuaArgument(pArg));
	}

	void LuaParam::pushAll(lua_State* pState) const
	{
		for(unsigned int i = 0; i < mArgs.size(); ++i)
		{
			mArgs[i].push(pState);
		}
	}

	int LuaParam::getSize() const
	{
		return mArgs.size();
	}
}}
