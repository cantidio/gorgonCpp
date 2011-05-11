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
#ifndef _GORGON_KEYBOARD_
#define _GORGON_KEYBOARD_
#include "keyboard_base.hpp"
#include "keyboard_handler.hpp"

namespace Gorgon{
namespace Input
{
	/**
	 * Class that represents the keyboard
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/05/2011
	 * @version	07/05/2011
	 */
	class Keyboard
	{
		protected:
			KeyboardBase* mKeyboard;/**<< The implementation of the keyboard*/
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 */
			Keyboard()
			{
				mKeyboard = KeyboardHandler::get().getKeyboard();
			}
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 */
			~Keyboard()
			{
				if(mKeyboard != NULL) delete mKeyboard;
			}
			/**
			 * Method that returns the "state" of the key
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @param	const int& pKey, the value of the key
			 * @return	Key
			 */
			inline Key getKey(const int& pKey) const
			{
				return mKeyboard->getKey(pKey);
			}
			/**
			 * Method that updates the values of the keyboard
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 */
			inline void update()
			{
				mKeyboard->update();
			}
			/**
			 * Method that returns if the keyboard is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	bool
			 */
			inline bool isOpened() const
			{
				mKeyboard->isOpened();
			}
	};
}}
#endif
