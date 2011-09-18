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
#ifndef _GORGON_SFF_SPRITEPACK_
#define	_GORGON_SFF_SPRITEPACK_
#include "../../graphic/spritepack.hpp"

namespace Gorgon  {
namespace Graphic {
namespace Addon
{
	/**
	 * @todo verificar se tem algum ponteiro morto por aqui, as vezes dá falha de segmentação ao sair do programa que utiliza essa classe
	 */
	class SpritePackSff : public SpritePack
	{
		public:
			SpritePackSff();
			SpritePackSff(const std::string& fileName);
			SpritePackSff(Core::File& pFile);

			Graphic::Sprite loadSprite(Core::File& pFile) const;
			void load(const std::string& pSpriteName);
			void load(Core::File& pFile);
	};
}}}
#endif
