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
#ifndef _GORGON_MOUSE_SDL_
#define _GORGON_MOUSE_SDL_
#include <gorgon++/input/mouse_base.hpp>
#include <gorgon++/geometry/gorgon_point.hpp>
#include <SDL/SDL.h>
namespace Gorgon{
namespace Addon
{
	/**
	 * Class that represents the mouse implementation with SDL
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	10/05/2011
	 * @version	10/05/2011
	 */
	class MouseSDL : public Input::MouseBase
	{
		protected:
			Uint8	mState;					/**<< var that stores the state of the keyboard*/
			Point	mPosition;				/**<< var that stores the position of the mouse*/
			int		mButton[LAST_BUTTON];
		public:
			MouseSDL();
			/**
			 * Method that updates the values of the mouse
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	10/05/2011
			 * @version	10/05/2011
			 */
			virtual void update();
			/**
			 * Method that returns if the mouse is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	10/05/2011
			 * @version	10/05/2011
			 * @return	bool
			 */
			virtual bool isOpened() const;
			/**
			 * Method that returns the position of the mouse
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	10/05/2011
			 * @version	10/05/2011
			 * @return	Point
			 */
			virtual Point getPosition() const;
			/**
			 * Method that returns the state of a button
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	10/05/2011
			 * @version	10/05/2011
			 * @param	const Mouse::Button& pButton, the button
			 * @return	bool
			 */
			virtual bool getButton(const Input::MouseBase::Button& pButton) const;
	};
}}
#endif
