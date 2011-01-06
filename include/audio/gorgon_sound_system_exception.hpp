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
#ifndef _GORGON_SOUND_SYSTEM_EXCEPTION_
#define _GORGON_SOUND_SYSTEM_EXCEPTION_
#include "../core/gorgon_exception.hpp"

namespace Gorgon{
namespace Audio
{
	#define newSoundSystemException(message) SoundSystemException(message,__FILE__,__FUNCTION__,__LINE__)
	/**
	 * Classe que representa as exceções geradas pelo sistema sonoro
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/01/2009
	 * @version	08/01/2009
	 * @ingroup	Audio
	 */
	class SoundSystemException : public Core::Exception
	{
		public:
			/**
			 * Método construtor da classe de Exceções do sistema sonoro
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	20/05/2009
			 * @param	const std::string&	msg			, mensagem
			 * @param	const std::string&	file		, arquivo em que a excessão ocorreu
			 * @param	const std::string&	function	, funcão em que a excessão ocorreu
			 * @param	const int&			line		, linha em que a excessão ocorreu
			 */
			SoundSystemException
			(
				const std::string& message,
				const std::string& file		= "",
				const std::string& function	= "",
				const int& line				= 1
			);
	};
}}
#endif
