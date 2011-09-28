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
#ifndef _GORGON_LUA_PARAM_
#define _GORGON_LUA_PARAM_
#include "lua_argument.hpp"
#include <string>
#include <vector>

namespace Gorgon{
namespace Script
{
	/**
	 * Classe que representa os parametros de uma função em lua
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	13/03/2009
	 * @version	14/03/2009
	 * @ingroup	Script
	 */
	class LuaParam
	{
		private:
			/**
			 * Vetor com os parâmetros
			 */
			std::vector<LuaArgument> mArgs;
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/03/2009
			 * @version	13/03/2009
			 */
			LuaParam();
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @param	const std::string& pDesc, descrição dos parametros
			 * @param	.. outros parametros
			 */
			LuaParam(const std::string& pDesc, ...);
			/**
			 * Método para adicionar um double ao parametro
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @param	const double& pArg, argumento
			 */
			void push(const double& pArg);
			/**
			 * Método para adicionar uma string ao parametro
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @param	const std::string& pArg, argumento
			 */
			void push(const std::string& pArg);
			/**
			 * Método para adicionar um bool ao parametro
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @param	const bool& pArg, argumento
			 */
			void push(const bool& pArg);
			/**
			 * Método para mandar todos os argumentos da classe para o estado em lua
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @param	lua_State* pState, estado lua
			 */
			void pushAll(lua_State* pState) const;
			/**
			 * Método para retornar o número de argumentos
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/03/2009
			 * @version	13/03/2009
			 * @return	int
			 */
			int getSize() const;
	};
}}
#endif

