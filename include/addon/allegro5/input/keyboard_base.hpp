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
#ifndef _GORGON_INPUT_ADDON_KEYBOARD_BASE_
#define _GORGON_INPUT_ADDON_KEYBOARD_BASE_
#include "../../../input/keyboard_base.hpp"

struct ALLEGRO_KEYBOARD_STATE;

namespace Gorgon	{
namespace Input		{
namespace Addon
{
	/**
	 * Class that represents the keyboard implementation with allegro5
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/05/2011
	 * @version	07/05/2011
	 */
	class KeyboardBase : public Input::KeyboardBase
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 */
			KeyboardBase();
			/**
			 * Virtual Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 */
			virtual ~KeyboardBase();
			/**
			 * Method that returns if the keyboard driver is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	bool
			 */
			virtual bool isOpened() const;
			/**
			 * Method that updates the state of the keyboard
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @details
			 * 			This method must be called every cycle of the game
			 */
			virtual void update();
			/**
			 * Method that returns the key
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	Input::Key
			 */
			virtual Input::Key getKey(const int& pKeyValue) const;
		protected:
			ALLEGRO_KEYBOARD_STATE* mState;/**<< var that stores the state of the keyboard*/
	};
}}}
#endif
