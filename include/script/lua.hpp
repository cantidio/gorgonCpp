/*
 *
 *    __     ___   _ __    __     ___     ___
 *  /'_ `\  / __`\/\`'__\/'_ `\  / __`\ /' _ `\
 * /\ \L\ \/\ \L\ \ \ \//\ \L\ \/\ \L\ \/\ \/\ \
 * \ \____ \ \____/\ \_\\ \____ \ \____/\ \_\ \_\
 *  \/___L\ \/___/  \/_/ \/___L\ \/___/  \/_/\/_/
 *    /\____/              /\____/
 *    \_/__/               \_/__/
 *
 *  Copyright (C) 2008-2011  Cantidio Oliveira Fontes
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */
#ifndef _GORGON_LUA_
#define _GORGON_LUA_
#include "lua_param.hpp"
#include "lua_return.hpp"

#include <iostream>
#include <string>
#include <vector>

struct lua_State;
struct luaL_reg;
namespace Gorgon{
namespace Script
{
	/**
	 * Class that deals with lua scripts
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	01/01/2009
	 * @version	17/10/2010
	 * @ingroup	Script
	 * @todo	find a way to get somevars like in functions, param.. maybe
	 */
	class Lua
	{
		private:
			lua_State*	mState; /**<< variable that holds the state of the lua interpreter*/
			bool		mClose; /**<< variable that tells if the lua state must be closed in the destructor*/
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @version	17/10/2010
			 * @param	const std::string& pScriptName, the name of the script to open
			 * @details
			 * 			When created by this method, the object will close
			 * the script in the destructor
			 */
			Lua( const std::string& pScriptName = "" );
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/10/2010
			 * @version	17/10/2010
			 * @param	lua_State* pState, the state of the lua interpreter
			 * @details
			 * 			When created by this method, the object will NOT close
			 * the script in the destructor
			 */
			Lua( lua_State* pState );
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @version	17/10/2010
			 */
			virtual ~Lua();
			/**
			 * Method to load a script into the lua interpreter
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @version	11/03/2009
			 * @param	const std::string& pScriptName, the name of the script
			 */
			void loadScript( const std::string& pScriptName );
			/**
			 * Método para executar um comando em lua
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/03/2009
			 * @version	12/03/2009
			 * @param	const std::string& pValue, comando a ser executado em lua
			 */
			void executeString( const std::string& pValue );
			/**
			 * Método para rodar um método de lua
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @version	13/03/2009
			 * @param	const std::string&	pFunctionName	, nome da função em lua a ser chamada
			 * @param	const LuaParam&		pParam			, parametros
			 * @param	const int&			pReturnNumber	, número de variáveis retornadas no método
			 * @return	LuaReturn, objeto de retorno
			 */
			LuaReturn function
			(
				const std::string&	pFunctionName,
				const LuaParam&		pParam			= LuaParam(),
				const int&			pReturnNumber	= 0
			);
			/**
			 * Método para registrar uma variável a ser usada em lua
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @version	11/03/2009
			 * @param	const std::string& pFunctionName, nome da função em lua
			 * @param	int (*pFunction)(lua_State*), ponteiro para a função em c
			 */
			void registerFunction( const std::string& pFunctionName,int (*pFunction)(lua_State*) );
			/**
			 * Método que retorna o valor de uma variável numérica em lua
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @version	11/03/2009
			 * @param	const std::string& pVarName, nome da variável
			 * @return	double
			 */
			double getNumericVar( const std::string& pVarName );
			/**
			 * Método que retorna o valor de uma string em lua
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/03/2009
			 * @version	11/03/2009
			 * @param	const std::string& pVarName, nome da variável
			 * @return	std::string
			 */
			std::string getStringVar( const std::string& pVarName );
			/**
			 * Método para retornar o valor de um booleano em lua
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/03/2009
			 * @version	23/03/2009
			 * @param	const std::string& pVarName,  nome da variável
			 */
			bool getBooleanVar( const std::string& pVarName );

			/**
			 * Method that register a userdata into the lua state
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/10/2010
			 * @version	17/10/2010
			 * @param	const std::string& pName	, name of the user data
			 * @param	luaL_reg pMethods[]			, array with the methods of the userdata
			 * @param	luaL_reg pMetatable[]		, array with the metatable of the userdata
			 * @return	int
			 * @example
			 * 	int UserData_getX(lua_State* L)
			 * 	{
			 * 		Script::Lua lua(L);
			 * 		UserData* inst = (UserData*)lua.getUserData("UserData1");
			 *		std::cout << inst->getX() << std::endl;
			 *		return 0;
			 * 	}
			 * 	int UserData_delete(lua_State* L)
			 * 	{
			 * 		Script::Lua lua(L);
			 * 		UserData* inst = (UserData*)lua.getUserData("UserData1");
			 * 		delete inst;
			 * 		return 0;
			 * 	}
			 *	luaL_reg methods[] =
			 *	{
			 *		{"getX",	UserData_getX},
			 *		{0,0}
			 *	};
			 *	luaL_reg metatable[] =
			 *	{
			 *		{"__gc", UserData_delete},
			 *	};
			 *	Script::Lua a;
			 *	a.registerUserData("UserData1",methods,metatable);
			 */
			int registerUserData
			(
				const std::string& pName,
				luaL_reg pMethods[],
				luaL_reg pMetatable[]
			);
			/**
			 * Method that returns the UserData into the stack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/10/2010
			 * @version	17/10/2010
			 * @param	const std::string&	pName	, the name of the userData
			 * @param	const int&			pIndex	, the index of it in the stack, default 1
			 */
			void* getUserData( const std::string& pName, const int& pIndex = 1 );
			/**
			 * Method that allocs a new userData into the lua interpreter
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/10/2010
			 * @version	17/10/2010
			 * @param	const std::string&	pName			, the name of the UserData
			 * @param	void*				pUserData		, the pointer to the UserData
			 * @param	const int&			pUserDataSize	, the size of the pointer
			 * @example
			 *	Core::File* file = new Core::File("test.txt",std::ios::in);
			 *	Script::Lua lua;
			 *	lua.registerUserData("FILE",methods,metatable);
			 *	lua.createUserData("FILE",file,sizeof(Core::File*));
			 */
			void createUserData
			(
				const std::string& pName,
				void* pUserData,
				const int& pUserDataSize
			);
	};
}}
#endif
