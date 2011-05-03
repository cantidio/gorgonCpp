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
#ifndef _GORGON_ANIMATIONDEF_PACK_HEADER_
#define _GORGON_ANIMATIONDEF_PACK_HEADER_
#include "../core/gorgon_file.hpp"
#include "../core/gorgon_file_header.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe com o cabeçalho dos arquivos gorgon
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	23/01/2009
	 * @version	23/01/2009
	 * @ingroup	Graphic
	 */
	class SpritePackHeader : public Core::FileHeader
	{
		private:
			/**
			 * Número do sprite da gorgon correto
			 */
			static const int mGorgonSpritePackMagicNumber;
			/**
			 * Assinatura do sprite da gorgon correta
			 */
			static const std::string mGorgonSpritePackSignature;
			/**
			 * Número do arquivo lido, pode não ser o correto
			 */
			int mMyGorgonSpritePackMagicNumber;
			/**
			 * Assinatura do arquivo lido, pode não ser a correta
			 */
			std::string	mMyGorgonSpritePackSignature;
		public:
			/**
			 * Método construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/01/2009
			 * @version	23/11/2009
			 */
			SpritePackHeader();
			/**
			 * Método construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/01/2009
			 * @version	23/11/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			SpritePackHeader(Core::File& pFile);
			/**
			 * Método para salvar o header em um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2009
			 * @version	23/11/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			static void save(Core::File& pFile);
			/**
			 * Método para carregar o header de um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2009
			 * @version	23/11/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void load(Core::File& pFile);
			/**
			 * Método para verificar a autenticidade do header lido
			 *
			 * @author		Cantidio Oliveira Fontes
			 * @since		23/11/2009
			 * @version		23/11/2009
			 * @return		bool
			 */
			bool isValid();
			/**
			 * Método para retornar a posição do ponteiro do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2009
			 * @version	23/11/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			static void returnFilePosition(Core::File& pFile);
	};
}}
#endif
