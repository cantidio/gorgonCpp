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
 *  Copyright (C) 2008-2009  Gorgon Team
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
#ifndef _GORGON_ANIMATION_PACK_EXCEPTION_
#define _GORGON_ANIMATION_PACK_EXCEPTION_
#include <string>
#include "../core/gorgon_exception.hpp"

namespace Gorgon
{
	/**
	 * Classe para tratamento de excessões em pacotes de animações
	 *
	 * @author	Cantídio Oliveira Fontes
	 * @since	24/02/2009
	 * @version	24/02/2009
	 * @ingroup	Graphic
	 */
	class AnimationPackException : public Core::Exception
	{
		public:
			/**
			 * Método construtor da classe de Exceções
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	24/02/2009
			 * @param	const std::string&	pMessage	, mensagem
			 * @param	const std::string&	pFile		, arquivo em que a excessão ocorreu
			 * @param	const std::string&	pFunction	, funcão em que a excessão ocorreu
			 * @param	const int&			pLine		, linha em que a excessão ocorreu
			 */
			AnimationPackException
			(
				const std::string&	pMessage,
				const std::string&	pFile		= "",
				const std::string&	pFunction	= "",
				const int&			pLine		= 1
			);
	};
}
#define AnimationPackException(pMessage) Gorgon::AnimationPackException(pMessage,__FILE__,__FUNCTION__,__LINE__)
#endif
