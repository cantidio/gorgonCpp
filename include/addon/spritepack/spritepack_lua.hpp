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
#ifndef _GORGON_SPRITEPACK_LUA_
#define _GORGON_SPRITEPACK_LUA_
#include "../../graphic/spritepack.hpp"

namespace Gorgon{
namespace Addon
{
	/**
	 * Classe que representa um spritepack com loader através de um script lua
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	25/01/2011
	 * @version	28/04/2011
	 */
	class SpritePackLua : public Graphic::SpritePack
	{
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	28/04/2011
			 */
			SpritePackLua();
			/**
			 * Método Construtor
			 *
			 * @author
			 * @since	25/01/2011
			 * @version	28/04/2011
			 * @param	const SpritePack& pSpritePack
			 */
			SpritePackLua(const SpritePack& pSpritePack);
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	28/04/2011
			 * @param	const Core::String& pFileName,
			 */
			SpritePackLua(const Core::String& pFileName);
			/**
			 * Método para se salvar o spritepack em um spritepack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	28/04/2011
			 * @param	const Core::String& pFileName
			 */
			void save(const Core::String& pFileName);
			/**
			 * Método para se carregar o spritepack através de um script
			 *
			 * @author	Cantidioi Oliveira Fontes
			 * @since	25/01/2011
			 * @version	28/04/2011
			 * @param	const Core::String& pFileName, string com a localização do script
			 */
			void load(const Core::String& pFileName);
	};
}}
#endif
