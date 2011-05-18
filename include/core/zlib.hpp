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
#ifndef _GORGON_ZLIB_
#define _GORGON_ZLIB_
#include <sstream>

namespace Gorgon{
namespace Core
{
	/**
	 * Classe Estática que provém métodos de compressão e descompressão de dados
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	21/04/2010
	 * @version	21/04/2010
	 */
	class Zlib
	{
		public:
			/**
			 * Método para comprimir um stream usando a zlib
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/04/2010
			 * @version	21/04/2010
			 * @param	std::stringstream&	pSource	, stream com a origem a ser compactada
			 * @param	std::stringstream&	pDest	, stream que irá conter a saída compactada
			 * @param	const int&			pLevel	, nível de compressão
			 * @return	int
			 */
			static int compress
			(
				std::stringstream& pSource,
				std::stringstream& pDest,
				const int& pLevel
			);
			/**
			 * Método para descomprimir um stream compactado com a zlib
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/04/2010
			 * @version	21/04/2010
			 * @param	std::stringstream& pSource	, stream compactado com a zlib
			 * @param	std::stringstream& pDest	, stream que irá conter a saída
			 * @return	int
			 */
			static int decompress(std::stringstream& pSource, std::stringstream& pDest);
			/**
			 * Método para copiar o conteúdo de um arquivo para uma stringstream
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/04/2010
			 * @version	21/04/2010
			 * @param	std::fstream&		pSource	, arquivo de origem
			 * @param	std::stringstream&	pDest	, stream de destino
			 */
			static void passBuffer(std::fstream& pSource, std::stringstream& pDest);
			/**
			 * Método para copiar o conteúdo de uma stringstream para um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/04/2010
			 * @version	21/04/2010
			 * @param	std::stringstream&	pSource	, stream de origem
			 * @param	std::fstream&		pDest	, arquivo de destino
			 */
			static void passBuffer(std::stringstream& pSource, std::fstream& pDest);
	};
}}
#endif
