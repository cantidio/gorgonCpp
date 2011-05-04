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
#include "joystick_stick.hpp"
#include "../core/gorgon_string.hpp"

namespace Gorgon{
namespace Input
{
	/**
	 * Class that represents an Abstract Joystick
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	04/05/2011
	 * @version	04/05/2011
	 */
	class Joystick
	{
		protected:
			int mIndex;			/**<< the index of the joystick*/
			Core::String mName;	/**<< the name of the joystick*/
			int mButtonNumber;	/**<< the number of buttons available*/
			int mStickNumber;	/**<< the number of sticks available */
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
				mIndex = pIndex;
			}
			/**
			 * Method that updates the values of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 */
			virtual void update()			= 0;
			/**
			 * Method that returns if the joystick is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @return	bool
			 */
			virtual bool isOpened() const	= 0;
			/**
			 * Method that returns the number of joysticks available on system
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @return	int
			 */
			static int getJoystickNumber();
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
				return mName;
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
				return mIndex;
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
				return mButtonNumber;
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
				return mStickNumber;
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
			virtual Stick getStick(const int& pStick) const = 0;
			/**
			 * Method that returns a button
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @param	const int& pButton, the index of the button
			 * @return	float
			 */
			virtual float getButton(const int& pButton) const = 0;
	};
}}
