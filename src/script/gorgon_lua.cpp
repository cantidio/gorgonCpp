#include <script/gorgon_lua.hpp>

namespace Gorgon{
namespace Script
{
	Lua::Lua(const std::string& pScriptName)
	{
		mState	= lua_open();
		mClose	= true;
		luaL_openlibs(mState);
		loadScript(pScriptName);
	}
	Lua::Lua(lua_State* pState)
	{
		mState	= pState;
		mClose	= false;
	}
	Lua::~Lua()
	{
		if(mClose)
		{
			lua_close(mState);
		}
	}

	void Lua::loadScript(const std::string& pScriptName)
	{
		if(pScriptName == "")
		{
			return;
		}
		Core::LogRegister(std::string("Loading Scriptfile: ") + pScriptName);
		int status = luaL_dofile(mState, pScriptName.c_str());
		if(status != 0)//deu erro ao carregar o script
		{
			Core::Log::get().Register(std::string("Error loading the script."),true);
/*			throw new LuaException("error loading script file");
			*/
		}
	}

	void Lua::executeString(const std::string& pValue)
	{
		if(luaL_dostring(mState,pValue.c_str())!=0)
		{
			Core::Log::get().Register(std::string("Unable to execute string."),true);
			//throw LuaException("Unable to execute string.");
			//cout << "Unable to execute string." << endl;
		}
	}

	LuaReturn Lua::function
	(
		const std::string&	pFunctionName,
		const LuaParam&		pParam,
		const int&			pReturnNumber
	)
	{
		lua_getglobal(mState, pFunctionName.c_str());
		pParam.pushAll(mState);//pushing the arguments

		/* do the call (param.size() arguments, result) */
		if(lua_pcall(mState, pParam.getSize(), pReturnNumber, 0) != 0)
		{
			Core::LogRegister(std::string("error: ") + lua_tostring(mState, -1) + " when trying to call function: " + pFunctionName);
			//throw Exception("Error")
		}
		return LuaReturn(mState,pReturnNumber);
	}

	void Lua::registerFunction(const std::string& pFunctionName,int (*pFunction) (lua_State*))
	{
		lua_register
		(
			mState,
			pFunctionName.c_str(),
			pFunction
		);
	}

	double Lua::getNumericVar(const std::string& pVarName)
	{
		lua_getglobal(mState,pVarName.c_str());
		if (!lua_isnumber(mState, -1))
		{
			Core::LogRegister(std::string("Trying to get a NumericVar: ") + pVarName + " but it isn't a number");
			return -1;
		}
		return (double)lua_tonumber(mState, -1);
	}

	std::string Lua::getStringVar(const std::string& pVarName)
	{
		lua_getglobal(mState, pVarName.c_str());
		if (!lua_isstring(mState, -1))
		{
			Core::LogRegister(std::string("Trying to get a StringVar: ") + pVarName + " but it isn't a string");
			return std::string("erro");
		}
		return std::string((char*)lua_tostring(mState, -1));
	}

	bool Lua::getBooleanVar(const std::string& pVarName)
	{
		lua_getglobal(mState,pVarName.c_str());
		if (!lua_isboolean(mState,-1))
		{
			Core::LogRegister(std::string("Trying to get a BoolVar: ") + pVarName + " but it isn't a boolean");
			return false;
		}
		return (bool)lua_toboolean(mState, -1);
	}

	int Lua::registerUserData
	(
		const std::string& pName,
		luaL_reg pMethods[],
		luaL_reg pMetatable[]
	)
	{
		luaL_openlib		(mState, pName.c_str(), pMethods, 0);	/* create methods table, add it to the globals */
		luaL_newmetatable	(mState, pName.c_str());				/* create metatable for UserData, add it to the Lua register */
		luaL_openlib		(mState, 0, pMetatable, 0);				/* fill metatable */
		lua_pushliteral		(mState, "__index");
		lua_pushvalue		(mState, -3);							/* dup methods table*/
		lua_rawset			(mState, -3);							/* metatable.__index = methods */
		lua_pushliteral		(mState, "__metatable");
		lua_pushvalue		(mState, -3);							/* dup methods table*/
		lua_rawset			(mState, -3);							/* hide metatable: metatable.__metatable = methods */
		lua_pop				(mState, 1);							/* drop metatable */
		return 1;													/* return methods on the stack */
	}

	void* Lua::getUserData(const std::string& pName, const int& pIndex)
	{
		void** l_inst; //lua instance
		luaL_checktype(mState, pIndex, LUA_TUSERDATA);
		l_inst = (void**)luaL_checkudata(mState, pIndex, pName.c_str());
		if (l_inst == NULL)
		{
			luaL_typerror(mState, pIndex, pName.c_str());
		}
		if (!*l_inst)
		{
			luaL_error(mState, "null Vector");
		}
		return *l_inst;
	}

	void Lua::createUserData
	(
		const std::string& pName,
		void* pUserData,
		const int& pUserDataSize
	)
	{
		void** l_inst;
		l_inst	= (void**)lua_newuserdata(mState, pUserDataSize);	//create the userdata, of the size passed
		*l_inst	= pUserData;										//set the pointer to the userdata
		luaL_getmetatable	(mState, pName.c_str());
		lua_setmetatable	(mState, -2);
	}

}}
