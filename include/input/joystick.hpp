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
#ifndef _GORGON_INPUT_JOYSTICK_
#define _GORGON_INPUT_JOYSTICK_
#include <string>

namespace Gorgon{
namespace Input
{
	class Stick;
	class JoystickBase;
	/**
	 * Class that represents a joystick
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	04/05/2011
	 * @version	27/05/2011
	 * @ingroup	Input
	 */
	class Joystick
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	27/05/2011
			 * @param	const int& pIndex, the index of the joystick
			 */
			Joystick(const int& pIndex = 0);
			/**
			 * Method that updates the values of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	27/05/2011
			 */
			void update();
			/**
			 * Method that returns if the joystick is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	27/05/2011
			 * @return	bool
			 */
			bool isOpened() const;
			/**
			 * Method that returns the name of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	27/05/2011
			 * @return	Core::String
			 */
			std::string getName() const;
			/**
			 * Method that returns the index of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	27/05/2011
			 * @return	int
			 */
			int getIndex() const;
			/**
			 * Method that returns the number of the buttons of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	27/05/2011
			 * @return	int
			 */
			int getButtonNumber() const;
			/**
			 * Method that returns the number of the sticks of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	27/05/2011
			 * @return	int
			 */
			int getStickNumber() const;
			/**
			 * Method that returns a stick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	27/05/2011
			 * @param	const int& pStick, the index of the stick to be retrieved
			 * @return	Stick
			 */
			Stick getStick(const int& pStick) const;
			/**
			 * Method that returns a button
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	27/05/2011
			 * @param	const int& pButton, the index of the button
			 * @return	float
			 */
			float getButton(const int& pButton) const;
		protected:
			JoystickBase* mJoystick;/**<< var that stores the joystickBase*/
	};
}}
#endif
