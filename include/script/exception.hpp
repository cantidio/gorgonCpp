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
#ifndef _GORGON_SCRIPT_EXCEPTION_
#define _GORGON_SCRIPT_EXCEPTION_
#include "../core/exception.hpp"

namespace Gorgon{
namespace Script
{
	/**
	 * Class that represents scripts exceptions
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	18/05/2011
	 * @version	18/05/2011
	 * @ingroup	Script
	 */
	class Exception : public Core::Exception
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/05/2011
			 * @version	18/05/2011
			 * @param	const std::string&	msg			, the exception message
			 * @param	const std::string&	file		, file where the exception occurred
			 * @param	const std::string&	function	, function where the exception occurred
			 * @param	const int&			line		, the line that occured the exception
			 */
			Exception
			(
				const std::string& pMessage,
				const std::string& pFile		= "",
				const std::string& pFunction	= "",
				const int& line					= 0
			);
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/05/2011
			 * @version	18/05/2011
			 * @param	const Exception&	pException	, some previous raised exception
			 * @param	const std::string&	msg			, the exception message
			 * @param	const std::string&	file		, file where the exception occurred
			 * @param	const std::string&	function	, function where the exception occurred
			 * @param	const int&			line		, the line that occured the exception
			 */
			Exception
			(
				const Core::Exception&	pException,
				const std::string&		pMessage,
				const std::string& 		pFile		= "",
				const std::string& 		pFunction	= "",
				const int& 				pLine		= 0
			);
	};
}}
#define raiseScriptException(pMessage) throw Gorgon::Script::Exception(pMessage,__FILE__,__FUNCTION__,__LINE__)
#define raiseScriptExceptionE(pMessage,pException) throw Gorgon::Script::Exception(pException,pMessage,__FILE__,__FUNCTION__,__LINE__)
#endif
