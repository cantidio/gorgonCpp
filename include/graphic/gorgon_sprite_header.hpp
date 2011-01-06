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
#ifndef _GORGON_SPRITE_HEADER_
#define _GORGON_SPRITE_HEADER_
#include "../core/gorgon_file.hpp"
#include "../core/gorgon_file_header.hpp"

namespace Gorgon
{
	/**
	 * Classe com o cabeçalho dos arquivos gorgon
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	23/01/2008
	 * @version	21/06/2009
	 * @ingroup	Graphic
	 */
	class SpriteHeader : public Core::FileHeader
	{
		private:
			/**
			 * Número do sprite da gorgon correto
			 */
			static const int mGorgonSpriteMagicNumber;
			/**
			 * Assinatura do sprite Gorgon correto
			 */
			static const std::string mGorgonSpriteSignature;
			/**
			 * Número do arquivo lido, pode não ser o correto
			 */
			int mMyGorgonSpriteMagicNumber;
			/**
			 * Assinatura do sprite lido, pode não ser o correto
			 */
			std::string mMyGorgonSpriteSignature;
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2008
			 * @version	23/11/2008
			 */
			SpriteHeader();
			/**
			 * Método Construtor iniciado com um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			SpriteHeader(Core::File& pFile);
			/**
			 * Método para salvar o header em um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			static void save(Core::File& pFile);
			/**
			 * Método para carregar o header de um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void load(Core::File& pFile);
			/**
			 * Método para verificar a autenticidade do header lido
			 *
			 * @author		Cantidio Oliveira Fontes
			 * @since		23/11/2008
			 * @version		23/11/2008
			 * @return		bool
			 */
			bool isValid();
			/**
			 * Método para retornar a posição do ponteiro do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			static void returnFilePosition(Core::File& pFile);
	};
}
#endif
