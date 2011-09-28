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
#include "../../graphic/animationpack.hpp"
#include "../../core/string.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Class that represents an animationpack with a loader by a lua script
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	25/01/2011
	 * @version	29/04/2011
	 */
	class AnimationPackLua : public Graphic::AnimationPack
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	25/01/2011
			 */
			AnimationPackLua();
			/**
			 * Copy Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	25/01/2011
			 * @param	const AnimationPack& pAnimationPack, original animationpack
			 */
			AnimationPackLua(const AnimationPack& pAnimationPack);
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	25/01/2011
			 * @param	const std::string& pFileName, name of tje script that holds the animationpack data
			 */
			AnimationPackLua(const Core::String& pFileName);
			/**
			 * Method that saves the animationpack into a lua file
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	25/01/2011
			 * @param	std::string pFileName, name of the file that will store the animationpack script
			 */
			void save(const Core::String& pFileName);
			/**
			 * Method that loads the animationpack from a lua file
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/01/2011
			 * @version	25/01/2011
			 * @param	std::string pFileName, name of the script to be loaded
			 */
			void load(const Core::String& pFileName);
	};
}}
#endif
