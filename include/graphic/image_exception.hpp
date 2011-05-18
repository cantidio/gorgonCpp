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
#ifndef _GORGON_IMAGE_EXCEPTION_
#define _GORGON_IMAGE_EXCEPTION_
#include "../core/exception.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe para tratar de excessões de imagens
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	20/01/2009
	 * @version	23/01/2009
	 * @ingroup	Graphic
	 */
	class ImageException : public Core::Exception
	{
		public:
			/**
			 * Método construtor da classe de Exceções das imagens
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	23/01/2009
			 * @param	const std::string&	pMessage	, mensagem
			 * @param	const std::string&	pSubModule	, sub módulo
			 * @param	const std::string&	pFile		, arquivo em que a excessão ocorreu
			 * @param	const std::string&	pFunction	, funcão em que a excessão ocorreu
			 * @param	const int&			pLine		, linha em que a excessão ocorreu
			 */
			ImageException
			(
				const std::string& pMessage,
				const std::string& pSubModule	= "Base",
				const std::string& pFile		= "",
				const std::string& pFunction	= "",
				const int& line					= 1
			);
	};
}}
#define ImageException(pMessage) ImageException(pMessage,"Base",__FILE__,__FUNCTION__,__LINE__)
#endif
