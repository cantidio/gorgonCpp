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
#ifndef _GORGON_ANIMATION_EXCEPTION_
#define _GORGON_ANIMATION_EXCEPTION_
#include <string>
#include "../core/exception.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe que excessão de Animações
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	24/02/2009
	 * @version	20/05/2009
	 * @ingroup	Graphic
	 */
	class AnimationException : public Core::Exception
	{
		public:
			/**
			 * Método construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	20/05/2009
			 * @param	const std::string&	pMessage	, mensagem
			 * @param	const std::string&	pFile		, arquivo em que a excessão ocorreu
			 * @param	const std::string&	pFunction	, funcão em que a excessão ocorreu
			 * @param	const int&			pLine		, linha em que a excessão ocorreu
			 */
			AnimationException
			(
				const std::string&	pMessage,
				const std::string&	pFile		= "",
				const std::string&	pFunction	= "",
				const int&			pLine		= 1
			);
	};
}}
#define AnimationException(pMessage) AnimationException(pMessage,__FILE__,__FUNCTION__,__LINE__)
#endif

