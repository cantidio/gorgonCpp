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
#ifndef _GORGON_FILE_HEADER_
#define _GORGON_FILE_HEADER_
#include "gorgon_file.hpp"

namespace Gorgon{
namespace Core
{
	/**
	 * Classe com o cabeçalho dos arquivos gorgon
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	23/01/2009
	 * @version	23/01/2009
	 * @ingroup	Core
	 */
	class FileHeader
	{
		private:
			/**
			 * Variável inteira estática
			 * Número dos arquivos da gorgon correto
			 */
			static const int mGorgonMagicNumber;
			/**
			 * Variável inteira
			 * Número do arquivo lido, pode não ser o correto
			 */
			int mMyGorgonMagicNumber;
		protected:
			/**
			 * Método para salvar o header em um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2009
			 * @version	23/11/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			static void save(File& pFile);
			/**
			 * Método para carregar o header de um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2009
			 * @version	23/11/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void load(File& pFile);
			/**
			 * Método para verificar a autenticidade do header lido
			 *
			 * @author		Cantidio Oliveira Fontes
			 * @since		23/11/2009
			 * @version		23/11/2009
			 * @return		bool
			 */
			bool isValid() const;
			/**
			 * Método que retornar o ponteiro do arquivo um número de posições
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2009
			 * @version	23/11/2009
			 * @param	File& pFile, arquivo já aberto
			 * @param	const int& pos, número de posições para voltar
			 */
			static void returnFilePosition(File& pFile,const int& pos);
	};
}}
#endif
