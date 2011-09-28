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
#ifndef _GORGON_INPUT_JOYSTICK_BASE_NULL_
#define _GORGON_INPUT_JOYSTICK_BASE_NULL_
#include "joystick_base.hpp"
#include "joystick_stick.hpp"

namespace Gorgon{
namespace Input
{
	/**
	 * Class that represents an null joystick
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	05/05/2010
	 * @version	05/05/2010
	 * @ingroup	Input
	 */
	class JoystickBaseNull : public JoystickBase
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/05/2011
			 * @version	05/05/2011
			 * @param	const int& pIndex, the index of the joystick
			 */
			inline JoystickBaseNull(const int& pIndex = 0) : JoystickBase(pIndex) { }
			/**
			 * Method that updates the values of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/05/2011
			 * @version	05/05/2011
			 */
			virtual void update() { }
			/**
			 * Method that returns if the joystick is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/05/2011
			 * @version	05/05/2011
			 * @return	bool
			 */
			virtual bool isOpened() const { return false; }
			/**
			 * Method that returns a stick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/05/2011
			 * @version	05/05/2011
			 * @param	const int& pStick, the index of the stick to be retrieved
			 * @return	Stick
			 */
			virtual Stick getStick(const int& pStick) const { return Stick(0); }
			/**
			 * Method that returns a button
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/05/2011
			 * @version	05/05/2011
			 * @param	const int& pButton, the index of the button
			 * @return	float
			 */
			virtual float getButton(const int& pButton) const { return 0; }
	};
}}
#endif
