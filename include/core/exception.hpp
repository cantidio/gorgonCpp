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
 *  Copyright (C) 2008-2010  Gorgon Team
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
#ifndef _GORGON_EXCEPTION_
#define _GORGON_EXCEPTION_

#include <iostream>
#include <sstream>
#include "log.hpp"

namespace Gorgon{
namespace Core
{
	/**
	 * Classe para tratar excessões na GorgonCore
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	08/01/2009
	 * @version	14/02/2009
	 * @ingroup	Core
	 */
	class Exception
	{
		private:
			/**
			 * Messagem
			 * String com a mensagem gerada na excessão
			 */
			std::string	message;
			/**
			 * Módulo
			 * String com o módulo de onde ocorreu a excessão
			 */
			std::string	module;
			/**
			 * Arquivo
			 * String com o nome do arquivo que ocorreu a excessão
			 */
			std::string	file;
			/**
			 * Funcão
			 * String com o nome da funcão onde ocorreu a excessão
			 */
			std::string	function;
			/**
			 * Linha
			 * Número da linha onde ocorreu a excessão
			 */
			int		line;
		public:
			/**
			 * Método construtor da classe de Exceções
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	23/01/2009
			 * @param	const std::string&	msg			, mensagem
			 * @param	const std::string&	module		, modulo em que a excessão ocorreu
			 * @param	const std::string&	file		, arquivo em que a excessão ocorreu
			 * @param	const std::string&	function	, funcão em que a excessão ocorreu
			 * @param	const int&		line		, linha em que a excessão ocorreu
			 */
			Exception
			(
				const std::string& message	= "",
				const std::string& module	= "",
				const std::string& file		= "",
				const std::string& function	= "",
				const int& line			= 1
			);
			/**
			 * Método que retorna o que aconteceu
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	14/02/2009
			 * @return	const std::string, descrição da excessão
			 */
			std::string what() const;
			/**
			 * Método que retorna a mensagem da excessão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/02/2009
			 * @version	14/02/2009
			 * @return	const std::string
			 */
			std::string getMessage() const;
	};
}}

#ifdef _MSC_VER
	#if _MSC_VER <= 1200
		#define __FUNCTION__ "?"
	#endif
#endif

#endif

