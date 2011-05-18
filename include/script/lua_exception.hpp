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
#ifndef _GORGON_LUA_EXCEPTION_
#define _GORGON_LUA_EXCEPTION_
#include "../core/exception.hpp"

namespace Gorgon{
namespace Script
{
	/**
	 * Classe para tratar de excessões de scripts lua
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	14/03/2009
	 * @version	20/05/2009
	 * @ingroup	Script
	 */
	class LuaException : public Core::Exception
	{
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/03/2009
			 * @version	20/05/2009
			 * @param	const std::string& message	, mensagem gerada pela excessão
			 * @param	const std::string& file		, arquivo que ocorreu a excessão
			 * @param	const std::string& function	, função que ocorreu a excessão
			 * @param	const int& line				, linha que ocorreu a excessão
			 */
			LuaException
			(
				const std::string&	pMessage,
				const std::string&	pFile		= "",
				const std::string&	pFunction	= "",
				const int&			pLine		= 1
			);
	};
}}
#define LuaException(pMessage) Gorgon::Script::LuaException(pMessage,__FILE__,__FUNCTION__,__LINE__)
#endif
