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
#ifndef _GORGON_ANIMATION_PACK_LUA_
#define _GORGON_ANIMATION_PACK_LUA_
#include <gorgon++/graphic/animationpack.hpp>
#include <gorgon++/core/string.hpp>
namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe que representa um animationpack com loader através de um script lua
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	25/01/2011
	 * @version	29/04/2011
	 */
	class AnimationPackLua : public Graphic::AnimationPack
	{
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	25/01/2011
			 */
			AnimationPackLua();
			/**
			 * Método construtor de cópia
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	25/01/2011
			 * @param	const AnimationPack& pAnimationPack, animationpack já criado
			 */
			AnimationPackLua(const AnimationPack& pAnimationPack);
			/**
			 * Método construtor que carrega os dados de um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	25/01/2011
			 * @param	const std::string& pFileName, nome do arquivo a ser aberto para carregar os dados
			 */
			AnimationPackLua(const Core::String& pFileName);
			/**
			 * Método para salvar o pacote de animações em um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	25/01/2011
			 * @param	std::string pFileName, nome do arquivo a ser salvo os dados do pacote de animações
			 */
			void save(const Core::String& pFileName);
			/**
			 * Método para carregar os dados do pacote de animações de um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	25/01/2011
			 * @param	std::string pFileName, nome do arquivo a ser carregado
			 */
			void load(const Core::String& pFileName);
	};
}}
#endif
