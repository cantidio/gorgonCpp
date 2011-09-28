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
#ifndef _GORGON_INPUT_KEYBOARD_
#define _GORGON_INPUT_KEYBOARD_
#include "keyboard_key.hpp"

namespace Gorgon{
namespace Input
{
	class KeyboardBase;
	class Key;
	/**
	 * Class that represents the keyboard
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/05/2011
	 * @version	27/05/2011
	 * @ingroup	Input
	 */
	class Keyboard
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	27/05/2011
			 */
			Keyboard();
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	27/05/2011
			 */
			~Keyboard();
			/**
			 * Method that returns the "state" of the key
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	27/05/2011
			 * @param	const int& pKey, the value of the key
			 * @return	Key
			 */
			Key getKey(const int& pKey) const;
			/**
			 * Method that updates the values of the keyboard
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	27/05/2011
			 */
			void update();
			/**
			 * Method that returns if the keyboard is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	27/05/2011
			 * @return	bool
			 */
			bool isOpened() const;
		protected:
			KeyboardBase* mKeyboard;/**<< The implementation of the keyboard*/
	};
}}
#endif
