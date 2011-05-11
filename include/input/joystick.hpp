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
#ifndef _GORGON_JOYSTICK_
#define _GORGON_JOYSTICK_
#include "joystick_base.hpp"
#include "joystick_handler.hpp"

namespace Gorgon{
namespace Input
{
	/**
	 * Class that represents a joystick
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	04/05/2011
	 * @version	05/05/2011
	 */
	class Joystick
	{
		protected:
			JoystickBase* mJoystick;/**<< var that stores the joystickBase*/
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @param	const int& pIndex, the index of the joystick
			 */
			inline Joystick(const int& pIndex = 0)
			{
				mJoystick = JoystickHandler::get().getJoystick(pIndex);
			}
			/**
			 * Method that updates the values of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 */
			inline void update()
			{
				mJoystick->update();
			}
			/**
			 * Method that returns if the joystick is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @return	bool
			 */
			bool isOpened() const
			{
				return mJoystick->isOpened();
			}
			/**
			 * Method that returns the name of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @return	Core::String
			 */
			inline Core::String getName() const
			{
				return mJoystick->getName();
			}
			/**
			 * Method that returns the index of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @return	int
			 */
			inline int getIndex() const
			{
				return mJoystick->getIndex();
			}
			/**
			 * Method that returns the number of the buttons of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @return	int
			 */
			inline int getButtonNumber() const
			{
				return mJoystick->getButtonNumber();
			}
			/**
			 * Method that returns the number of the sticks of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @return	int
			 */
			inline int getStickNumber() const
			{
				return mJoystick->getStickNumber();
			}
			/**
			 * Method that returns a stick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @param	const int& pStick, the index of the stick to be retrieved
			 * @return	Stick
			 */
			inline Stick getStick(const int& pStick) const
			{
				return mJoystick->getStick(pStick);
			}
			/**
			 * Method that returns a button
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @param	const int& pButton, the index of the button
			 * @return	float
			 */
			inline float getButton(const int& pButton) const
			{
				return mJoystick->getButton(pButton);
			}
	};
}}
#endif
