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
#ifndef _GORGON_LUA_RETURN_
#define _GORGON_LUA_RETURN_
extern "C"
{
	#include <lua5.1/lua.h>
	#include <lua5.1/lualib.h>
	#include <lua5.1/lauxlib.h>
}
#include <iostream>
#include <string>
#include <vector>
#include "lua_argument.hpp"

namespace Gorgon{
namespace Script
{
	/**
	 * Classe que representa o retorno de uma função de lua
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	01/01/2009
	 * @version	14/03/2009
	 * @ingroup	Script
	 */
	class LuaReturn
	{
		private:
			/**
			 * Vetor de valores retornados por uma função lua
			 */
			std::vector<LuaArgument> mArgs;
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	14/03/2009
			 * @param	lua_State* pState, ponteiro para o estado lua
			 * @param	const int& pVarNumber, número de váriáveis retornadas
			 */
			LuaReturn(lua_State* pState,const int& pVarNumber=1);
			/**
			 * Método que retorna o valor numérico do retorno
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	13/03/2009
			 * @param	const int& pPos, posição de retorno, default 0
			 */
			double getNumericValue(const int& pPos=0) const;
			/**
			 * Método que retorna o valor de string do retorno
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	13/03/2009
			 * @param	const int& pPos, posição de retorno, default 0
			 */
			std::string getStringValue(const int& pPos=0) const;
			/**
			 * Método que retorna o valor booleano do retorno
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	13/03/2009
			 * @param	const int& pPos, posição de retorno, default 0
			 */
			bool getBoolValue(const int& pPos=0) const;
			/**
			 * Método que retorna o número de argumentos retornados
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/03/2009
			 * @version	14/03/2009
			 * @return	int
			 */
			int getSize() const;
	};
}}
#endif
