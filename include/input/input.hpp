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
#ifndef _GORGON_INPUT_
#define	_GORGON_INPUT_
#include "joystick_handler.hpp"
#include "joystick.hpp"
#include "keyboard_base.hpp"
#include "keyboard.hpp"
/**
 * @defgroup	Input
 *
 * @author		Cantidio Oliveira Fontes
 * @since		18/08/2008
 * @version		04/05/2011
 * @details
 * 				This module is responsable for all the input functions,
 * 				like joystick, keyboard and mouse
 */
namespace Gorgon{
namespace Input
{
	class InputHandler
	{
		protected:
			static InputHandler* mHandler;/**<< Singleton instance of the class*/
	};
}}
#endif
