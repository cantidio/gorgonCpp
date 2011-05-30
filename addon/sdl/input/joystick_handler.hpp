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
#ifndef _GORGON_SDL_JOYSTICK_HANDLER_
#define _GORGON_SDL_JOYSTICK_HANDLER_
#include <gorgon++/input/joystick_handler.hpp>

namespace Gorgon{
namespace Addon
{
	class JoystickHandlerSDL : public Input::JoystickHandler
	{
		protected:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/05/2011
			 * @version	06/05/2011
			 */
			JoystickHandlerSDL();
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/05/2010
			 * @version	06/05/2010
			 */
			~JoystickHandlerSDL();
		public:
			/**
			 * Method that sets the JoystickHandler
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/05/2011
			 * @version	06/05/2011
			 * @param Joystick* pHandler, the Handler
			 */
			static void set();
			/**
			 * Method that returns an instance of the current joystickBase
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/05/2011
			 * @version	06/05/2011
			 * @param	const int& pIndex, the index of the Joystick
			 * @return	JoystickBase*
			 */
			virtual Input::JoystickBase* getJoystick(const int& pIndex) const;
			/**
			 * Method that returns the number of joysticks available on system
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @return	int
			 */
			virtual int getJoystickNumber() const;
	};
}}
#endif
