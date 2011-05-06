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
#ifndef _GORGON_LOG_
#define	_GORGON_LOG_

#include <string>
#include <stdio.h>
#include <stdarg.h>
#include "gorgon_file.hpp"

#define	_USE_LOG_ /**<< Define to turn on logs */
namespace Gorgon{
namespace Core
{
	/**
	 * Class to write log files
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	01/01/2009
	 * @version	05/05/2011
	 * @ingroup	Core
	 */
	class Log
	{
		protected:
			static Log* mSingleton;	/**<< Pointer to the singleton pointer*/
			File mFile;				/**<< log file*/
			bool mAppend;			/**<< if true, the file will append to the previous log file*/

			/**
			 * Protected Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const std::string& logFile	, name of the log file to be created
			 * @param	const bool& append			, if the log will append to the previous log, or overwrite it
			 */
			Log(const std::string& logFile, const bool& append);
			/**
			 * Protected Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	05/05/2011
			 */
			virtual ~Log();
		public:
			/**
			 * Method to instanciate the Log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/03/2009
			 * @version	05/05/2011
			 * @param	const std::string& logFile	, name of the log file to be created
			 * @param	const bool& append			, if the log will append to the previous log, or overwrite it
			 */
			static void init(const std::string& logFile = "log.txt",const bool& append = false);
			/**
			 * Method that returns an instance of the class
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/03/2009
			 * @version	25/03/2009
			 * @return	Log&
			 */
			static Log& get();
			/**
			 * Method to register the timestamp in the log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 */
			void writeTimeStamp();
			/**
			 * Method to register a string in the log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const string& message	, messege to be registered
			 * @param	const bool& pNewLine	, if the message will generate a newline
			 */
			void write(const std::string& message,const bool& newLine=true,const bool& pWriteTimeStamp=true);
			/**
			 * Method that registers a number into the log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const long& number		, number to be registered
			 * @param	const bool& pNewline	, if true puts a new line after the number
			 */
			void write(const long& number,const bool& newLine=true,const bool& pWriteTimeStamp=true);
			/**
			 * Method that registers a double into the log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const double& number	, double to be registered
			 * @param	const bool& pNewline	, if true puts a new line after the double
			 */
			void write(const double& number,const bool& newLine=true,const bool& pWriteTimeStamp=true);
			/**
			 * Method that registers a boolean into the log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const bool& boolean		, boolean to be registered
			 * @param	const bool& pNewline	, if true puts a new line after the boolean
			 */
			void write(const bool& boolean,const bool& newLine=true,const bool& pWriteTimeStamp=true);
			/**
			 * Method that registers a string formatted like printf into the log
			 *
			 * @author	Cantidio Oliveia Fontess
			 * @since	25/03/2009
			 * @version	25/03/2009
			 * @param	const char* text	, formatted string like printf
			 * @param	va_list& ap			, parameters list
			 */
			void writeFormatted(const char* text,va_list& ap);
			/**
			 * Method that registers a string formatted like printf into the log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const char* text	, formatted strinf like printf
			 * @param	... 				, all parameters
			 */
			void writeFormatted(const char* text, ...);
	};
	/**
	 * Inline Function that registers a string formatted like printf into the current log
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/03/2009
	 * @version	05/05/2011
	 * @param	const std::string& str, string com o formato a ser registrada,
	 * @param	... os argumentos a serem substituídos na string formatada
	 */
	inline void logWriteFormatted(const std::string& str, ...)
	{
		#ifdef	_USE_LOG_
		va_list ap;
		va_start(ap, str);
		Log::get().writeFormatted(str.c_str(),ap);
		va_end(ap);
		#endif
	}
	/**
		 * Inline Function that writes a string into the current log
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	05/05/2011
		 * @version	05/05/2011
		 * @param	const long& number, valor long a ser registrado
		 */
		inline void logWrite(const std::string& pString, const bool& pNewline = true,const bool& pWriteTimeStamp=true)
		{
			#ifdef	_USE_LOG_
			Log::get().write(pString, pNewline, pWriteTimeStamp);
			#endif
		}
	/**
	 * Inline Function that registers a number into the current log
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/03/2009
	 * @version	05/05/2011
	 * @param	const long& number, valor long a ser registrado
	 */
	inline void logWrite(const long& number, const bool& pNewline = true,const bool& pWriteTimeStamp=true)
	{
		#ifdef	_USE_LOG_
		Log::get().write(number, pNewline, pWriteTimeStamp);
		#endif
	}
	/**
	 * Inline Function that registers a double into the current log
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/03/2009
	 * @version	05/05/2011
	 * @param	const double& number, valor double a ser registrado
	 */
	inline void logWrite(const double& number, const bool& pNewline = true,const bool& pWriteTimeStamp=true)
	{
		#ifdef	_USE_LOG_
		Log::get().write(number, pNewline, pWriteTimeStamp);
		#endif
	}
	/**
	 * Inline Function that registers a boolean into the current log
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/03/2009
	 * @version	05/05/2011
	 * @param	const bool& boolean, valor booleano a ser registrado
	 * @param
	 */
	inline void logWrite(const bool& boolean, const bool& pNewline = true,const bool& pWriteTimeStamp=true)
	{
		#ifdef	_USE_LOG_
		Log::get().write(boolean, pNewline, pWriteTimeStamp);
		#endif
	}
}}
#endif
