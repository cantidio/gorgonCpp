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
#ifndef _GORGON_ANIMATION_PACK_HEADER_
#define _GORGON_ANIMATION_PACK_HEADER_
#include "../core/gorgon_file.hpp"
#include "../core/gorgon_file_header.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe com o cabeçalho dos arquivos gorgon
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	24/02/2009
	 * @version	21/06/2009
	 * @ingroup	Graphic
	 */
	class AnimationPackHeader : public Core::FileHeader
	{
		private:
			/**
			 * Assinatura de identificação do animationpack correto
			 */
			static const std::string mAnimationPackSignature;
			/**
			 * Versão do arquivo
			 */
			static const float mAnimationPackVersion;
			/**
			 * Assinatura de identificação do arquivo lido, pode não ser o correto
			 */
			std::string	mMyAnimationPackSignature;
			/**
			 * Versão do arquivo lido
			 */
			float mMyAnimationPackVersion;
			/**
			 * Número de animações no pacote
			 */
			int mAnimationNumber;
		public:
			/**
			 * Método construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	24/02/2009
			 */
			AnimationPackHeader();
			/**
			 * Método construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo aberto
			 */
			AnimationPackHeader(Core::File& pFile);
			/**
			 * Método para preencher os dados do header
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	24/02/2009
			 * @param	const int& pAnimationNumber, número de animações no pack
			 */
			void fill(const int& pAnimationNumber);
			/**
			 * Método para retornar o número de animações do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	24/02/2009
			 * @return	int
			 */
			int getAnimationNumber() const;
			/**
			 * Método para carregar o header de um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void load(Core::File& pFile);
			/**
			 * Método para salvar o header em um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void save(Core::File& pFile);
			/**
			 * Método para retornar o tamanho ocupado pelo header em bytes
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	24/02/2009
			 * @return	long
			 */
			static long getSize();
			/**
			 * Método para retornar a posição do ponteiro do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			static void returnFilePosition(Core::File& pFile);
			/**
			 * Método para verificar a autenticidade do header lido
			 *
			 * @author		Cantidio Oliveira Fontes
			 * @since		24/02/2009
			 * @version		24/02/2009
			 * @return		bool
			 */
			bool isValid();
	};
}}
#endif
