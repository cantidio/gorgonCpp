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
#ifndef _GORGON_LOG_
#define	_GORGON_LOG_
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include "gorgon_file.hpp"
/**
 * Define para ativar logs
 */
#define	_USE_LOG_

namespace Gorgon{
namespace Core
{
	/**
	 * Classe para realizar logs
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	01/01/2009
	 * @version	26/03/2009
	 * @ingroup	Core
	 */
	class Log
	{
		private:
			/**
			 * Arquivo de log
			 */
			File mFile;
			/**
			 * Se irá usar o append no arquivo existente ou sobrescreve-lo
			 */
			bool mAppend;
		protected:
			/**
			 * Ponteiro para a instancia da classe
			 */
			static Log* mSingleton;
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const std::string& logFile, nome do arquivo de log a ser gerado
			 * @param	const bool& append, se irá sobrescrever o arquivo existente ou ir mesclando os logs
			 */
			Log(const std::string& logFile,const bool& append);
			/**
			 * Método Destrutor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 */
			virtual ~Log();
		public:
			/**
			 * Método para iniciar a instância da classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/03/2009
			 * @version	25/03/2009
			 * @param	const std::string& logFile, nome do arquivo de log a ser gerado
			 * @param	const bool& append, se irá sobrescrever o arquivo existente ou ir mesclando os logs
			 */
			static void init(const std::string& logFile = "log.txt",const bool& append = false);
			/**
			 * Método para destruir a instância da classe de log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/03/2009
			 * @version	25/03/2009
			 */
			static void halt();
			/**
			 * Método para retornar a instância da classe se a mesma tiver sido instanciada
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/03/2009
			 * @version	25/03/2009
			 * @return	Log&
			 */
			static Log& get();
			/**
			 * Método para registrar a timeStamp do sistema no log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 */
			void RegisterTimeStamp();
			/**
			 * Método para registrar uma string no log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const string& message, mensagem a ser registrada
			 */
			void Register(const std::string& message,const bool& newLine=true);
			/**
			 * Método para registrar um número inteiro no arquivo de log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const long& number, número a ser registrado
			 */
			void Register(const long& number,const bool& newLine=true);
			/**
			 * Método para registrar um número em ponto flutuante no arquivo de log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const double& number, número em ponto flutuante a ser registrado
			 */
			void Register(const double& number,const bool& newLine=true);
			/**
			 * Método para registrar um booleano no arquivo de log
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const bool& boolean, booleano a ser registrado
			 */
			void Register(const bool& boolean,const bool& newLine=true);
			/**
			 * Método para registrar uma string formatada atravez de uma losta de parametros
			 *
			 * @author	Cantidio Oliveia Fontess
			 * @since	25/03/2009
			 * @version	25/03/2009
			 * @param	const char* text	, texto com as devidas formatações
			 * @param	va_list& ap			, lista de parâmetros
			 */
			void RegisterFormated(const char* text,va_list& ap);
			/**
			 * Método para registrar uma string formatada estilo printf
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/01/2009
			 * @version	25/03/2009
			 * @param	const char* text, texto com as devidas formatações
			 * @param	... outros parametros
			 */
			void RegisterFormated(const char* text,...);
	};
	/**
	 * Função inline para registrar uma string formatada no arquivo de log
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/03/2009
	 * @version	26/03/2009
	 * @param	const std::string& str, string com o formato a ser registrada,
	 * @param	... os argumentos a serem substituídos na string formatada
	 */
	inline void LogRegister(const std::string& str, ...)
	{
		#ifdef	_USE_LOG_
		if(&Log::get())
		{
			va_list ap;
			va_start(ap,str);
			Log::get().RegisterFormated(str.c_str(),ap);
			va_end(ap);
		}
		#endif
	}
	/**
	 * Função inline para registrar um long no arquivo de log
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/03/2009
	 * @version	26/03/2009
	 * @param	const long& number, valor long a ser registrado
	 */
	inline void LogRegister(const long& number)
	{
		#ifdef	_USE_LOG_
		if(&Log::get())
		{
			Log::get().Register(number);
		}
		#endif
	}
	/**
	 * Função inline para registrar um double no arquivo de log
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/03/2009
	 * @version	26/03/2009
	 * @param	const double& number, valor double a ser registrado
	 */
	inline void LogRegister(const double& number)
	{
		#ifdef	_USE_LOG_
		if(&Log::get())
		{
			Log::get().Register(number);
		}
		#endif
	}
	/**
	 * Função inline para registrar um booleano no arquivo de log
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/03/2009
	 * @version	26/03/2009
	 * @param	const bool& boolean, valor booleano a ser registrado
	 */
	inline void LogRegister(const bool& boolean)
	{
		#ifdef	_USE_LOG_
		if(&Log::get())
		{
			Log::get().Register(boolean);
		}
		#endif
	}
}}
#endif
