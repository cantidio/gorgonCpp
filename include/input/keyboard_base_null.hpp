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
#ifndef _GORGON_KEYBOARD_BASE_NULL_
#define _GORGON_KEYBOARD_BASE_NULL_
#include "keyboard_base.hpp"
#include "keyboard_key.hpp"

namespace Gorgon{
namespace Input
{
	/**
	 * Class that represents an null Keyboard
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/05/2010
	 * @version	07/05/2010
	 */
	class KeyboardBaseNull : public KeyboardBase
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 */
			inline KeyboardBaseNull() { }
			/**
			 * Method that updates the values of the Keyboard
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 */
			virtual void update() { }
			/**
			 * Method that returns if the Keyboard is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	bool
			 */
			virtual bool isOpened() const { return false; }
			/**
			 * Method that returns a Key
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @param	const int& pkeyValue, the key value
			 * @return	Input::Key
			 */
			virtual Input::Key getKey(const int& pKeyValue) const
			{
				return Input::Key(pKeyValue, false);
			}
	};
}}
#endif
