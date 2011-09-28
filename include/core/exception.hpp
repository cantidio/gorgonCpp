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
#ifndef _GORGON_EXCEPTION_
#define _GORGON_EXCEPTION_
#include "log.hpp"
#include "string.hpp"

namespace Gorgon{
namespace Core
{
	/**
	 * Class that represents a Gorgon Exception
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	08/01/2009
	 * @version	18/05/2011
	 * @ingroup	Core
	 */
	class Exception
	{
		protected:
			std::string	mMessage;	/**<< String with the description of the exception*/
			std::string	mModule;	/**<< String that describes the module where the exception ocurred*/
			std::string	mFile;		/**<< Name of the file that the exception were raised*/
			std::string	mFunction;	/**<< the name of the function or method where the exception were raised*/
			int 		mLine;		/**<< The line that occured the exception*/
			Exception*	mPrev;		/**<< Previous exception raised*/
		public:
			/**
			 * Copy Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/05/2011
			 * @version	18/05/2011
			 * @param	const Exception& pException, the original obj
			 */
			Exception(const Exception& pException);
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	23/01/2009
			 * @param	const std::string&	msg			, the exception message
			 * @param	const std::string&	module		, the module where the exception occured
			 * @param	const std::string&	file		, file where the exception occurred
			 * @param	const std::string&	function	, function where the exception occurred
			 * @param	const int&			line		, the line that occured the exception
			 */
			Exception
			(
				const std::string& message,
				const std::string& module	= "",
				const std::string& file		= "",
				const std::string& function	= "",
				const int& line				= 1
			);
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/05/2011
			 * @version	18/05/2011
			 * @param	const Exception&	pException	, some previous raised exception
			 * @param	const std::string&	msg			, the exception message
			 * @param	const std::string&	module		, the module where the exception occured
			 * @param	const std::string&	file		, file where the exception occurred
			 * @param	const std::string&	function	, function where the exception occurred
			 * @param	const int&			line		, the line that occured the exception
			 */
			Exception
			(
				const Exception&	pException,
				const std::string&	pMessage,
				const std::string& 	pModule		= "",
				const std::string& 	pFile		= "",
				const std::string& 	pFunction	= "",
				const int& 			pLine		= 1
			);
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/05/2011
			 * @version	18/05/2011
			 */
			virtual ~Exception();
			/**
			 * Method that returns the information of the exception
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	18/05/2011
			 * @param	const int& pTabs, number of tabs
			 * @return	const std::string, descrição da excessão
			 */
			virtual std::string what(const int& pTabs = 1) const;
			/**
			 * Method that returns the message of the exception
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/02/2009
			 * @version	14/02/2009
			 * @return	std::string
			 */
			std::string getMessage() const;
			/**
			 * Method that writes the exception into the log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/05/2011
			 * @version	18/05/2011
			 */
			void writeInLog() const;
	};
}}

#ifdef _MSC_VER
	#if _MSC_VER <= 1200
		#define __FUNCTION__ "?"
	#endif
#endif

#define raiseException(pMessage)				throw Gorgon::Core::Exception(pMessage,"Core",__FILE__,__FUNCTION__,__LINE__)
#define raiseExceptionE(pException,pMessage)	throw Gorgon::Core::Exception(pMessage,pException,"Core",__FILE__,__FUNCTION__,__LINE__)

#endif

