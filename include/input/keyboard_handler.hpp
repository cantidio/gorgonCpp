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
#ifndef _GORGON_KEYBOARD_HANDLER_
#define _GORGON_KEYBOARD_HANDLER_

namespace Gorgon{
namespace Input
{
	class KeyboardBase;
	/**
	 * Class that represents a JoystickHandler
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	05/05/2011
	 * @version	05/05/2011
	 */
	class KeyboardHandler
	{
		protected:
			static KeyboardHandler* mHandler;/**<< Singleton instance of the class*/
			/**
			 * Protected Constructor
			 */
			KeyboardHandler();
			/**
			 * Protected Destructor
			 */
			virtual ~KeyboardHandler();
			/**
			 * Method that sets the JoystickHandler
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/05/2010
			 * @version	05/05/2010
			 * @param Joystick& pHandler, the Handler
			 */
			static void set(KeyboardHandler& pHandler);
		public:
			/**
			 * Method that returns the KeyboardHandler
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	JoystickHandler&
			 */
			static KeyboardHandler& get();
			/**
			 * Method that returns an instance of the current KeyboardBase
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	KeyboardBase*
			 */
			virtual KeyboardBase* getKeyboard() const;
	};
}}
#endif