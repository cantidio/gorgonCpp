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
#ifndef _GORGON_ALLEGRO5_JOYSTICK_
#define _GORGON_ALLEGRO5_JOYSTICK_
#include <gorgon++/input/joystick.hpp>

struct ALLEGRO_JOYSTICK;
struct ALLEGRO_JOYSTICK_STATE;

namespace Gorgon{
namespace Addon
//namespace Allegro5{
{
	/**
	 * Class that represents an allegro5 joystick
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	04/05/2011
	 * @version	05/05/2011
	 */
	class JoystickAllegro : public Input::JoystickBase
	{
		protected:
			ALLEGRO_JOYSTICK* mJoystick;			/**<< var that holds the allegro joystick*/
			ALLEGRO_JOYSTICK_STATE* mJoystickState;	/**<< var that holds the allegro joystick state*/
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @verion	05/05/2011
			 * @param	const int& pIndex, the index of the joystick
			 */
			JoystickAllegro(const int& pIndex = 0);
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @verion	05/05/2011
			 */
			virtual ~JoystickAllegro();
			/**
			 * Method that returns if the joystick is available
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 */
			virtual bool isOpened() const;
			/**
			 * Method that updates the values of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 */
			virtual void update();
			/**
			 * Method that returns a stick of the joystick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @param	const int& pStick, the index of the stick
			 * @return	Stick
			 */
			virtual Input::Stick getStick(const int& pStick) const;
			/**
			 * Method that returns the value of the button
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @param	const int& pButton, the index of the button
			 * @return	float
			 */
			virtual float getButton(const int& pButtonIndex) const;
	};
}}
#endif
