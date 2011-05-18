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
#ifndef _GORGON_LUA_ARGUMENT_
#define	_GORGON_LUA_ARGUMENT_
extern "C"
{
	#include <lua5.1/lua.h>
	#include <lua5.1/lualib.h>
	#include <lua5.1/lauxlib.h>
}
#include <string>
#include "lua_exception.hpp"

namespace Gorgon{
namespace Script
{
	/**
	 * Classe com os valores de argumento de uma função lua
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	13/03/2009
	 * @version	14/03/2009
	 * @ingroup	Script
	 */
	class LuaArgument
	{
		public:
			/**
			 * Argument types
			 */
			enum Type
			{
				Double	= 0,	/**< receive a double value	*/
				Bool	= 1,	/**< receive a bool value	*/
				String	= 2,	/**< receive a String value	*/
				Null	= 3		/**< receive a NULL value	*/
			};
		private:
			/**
			 * Argumento double
			 */
			double mDoubleArg;
			/**
			 * Argumento booleano
			 */
			bool mBoolArg;
			/**
			 * Argumento em string
			 */
			std::string mStringArg;
			/**
			 * Tipo do argumento
			 */
			Type mMyType;
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira
			 * @since	13/03/2009
			 * @version	13/03/2009
			 */
			LuaArgument();
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @param	const double& pArg, argumento em double
			 */
			LuaArgument(const double& pArg);
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @param	const std::string& pArg, argumento em string
			 */
			LuaArgument(const std::string& pArg);
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @param	const bool& pArg, argumento em bool
			 */
			LuaArgument(const bool& pArg);
			/**
			 * Método que limpa o argumento
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/03/2009
			 * @version	14/03/2009
			 */
			void clear();
			/**
			 * Método que retorna o valor double do retorno
			 *
			 * @author	Cantidio Oliveira
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @return	double, valor double
			 */
			double getDoubleValue() const;
			/**
			 * Método que retorna o valor bool do retorno
			 *
			 * @author	Cantidio Oliveira
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @return	bool
			 */
			bool getBoolValue() const;
			/**
			 * Método que retorna o valor string do retorno
			 *
			 * @author	Cantidio Oliveira
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @return	string
			 */
			std::string getStringValue() const;
			/**
			 * Método que retorna o tipo do retorno
			 *
			 * @author	Cantidio Oliveira
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @return	Type
			 */
			LuaArgument::Type getType() const;
			/**
			 * Método que empurra o argumento para ser usado como parametro de uma função
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/03/2009
			 * @version	14/03/2009
			 * @param	lua_State* pState, estado lua
			 */
			void push(lua_State* pState) const;
	};
}}
#endif
