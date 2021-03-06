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
#ifndef _GORGON_INPUT_ADDON_MOUSE_BASE_
#define _GORGON_INPUT_ADDON_MOUSE_BASE_
#include "../../../input/mouse_base.hpp"
#include "../../../core/point.hpp"

struct ALLEGRO_MOUSE_STATE;

namespace Gorgon	{
namespace Allegro5	{
namespace Input
{
	/**
	 * Class that represents the mouse implementation with Allegro
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	11/05/2011
	 * @version	11/05/2011
	 */
	class MouseBase : public Gorgon::Input::MouseBase
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/05/2011
			 * @version	11/05/2011
			 */
			MouseBase();
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/05/2011
			 * @version	11/05/2011
			 */
			virtual ~MouseBase();
			/**
			 * Method that updates the values of the mouse
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/05/2011
			 * @version	11/05/2011
			 */
			virtual void update();
			/**
			 * Method that returns if the mouse is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/05/2011
			 * @version	11/05/2011
			 * @return	bool
			 */
			virtual bool isOpened() const;
			/**
			 * Method that returns the position of the mouse
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/05/2011
			 * @version	11/05/2011
			 * @return	Gorgon::Core::Point
			 */
			virtual Gorgon::Core::Point getPosition() const;
			/**
			 * Method that returns the state of a button
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/05/2011
			 * @version	11/05/2011
			 * @param	const Gorgon::Input::MouseButton& pButton, the button
			 * @return	bool
			 */
			virtual bool getButton(const Gorgon::Input::MouseButton::Id& pButton) const;

		protected:
			ALLEGRO_MOUSE_STATE*	mState;												/**<< var that stores the state of the mouse*/
			Core::Point				mPosition;											/**<< var that stores the position of the mouse*/
			int						mButton[Gorgon::Input::MouseButton::LAST_BUTTON];	/**<< array of the buttons*/
	};
}}}
#endif
