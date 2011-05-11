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
#ifndef _GORGON_MOUSE_BASE_NULL_
#define _GORGON_MOUSE_BASE_NULL_

namespace Gorgon{
namespace Input
{
	/**
	 * Class that represents a mouse NULL
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	10/05/2011
	 * @version	10/05/2011
	 */
	class MouseBaseNull
	{
		public:
			/**
			 * Method that updates the values of the mouse
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	10/05/2011
			 * @version	10/05/2011
			 */
			inline void update(){ }
			/**
			 * Method that returns if the mouse is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	10/05/2011
			 * @version	10/05/2011
			 * @return	bool
			 */
			inline bool isOpened() const
			{
				return false;
			}
			/**
			 * Method that returns the position of the mouse
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	10/05/2011
			 * @version	10/05/2011
			 * @return	Point
			 */
			inline Point getPosition() const
			{
				return Point(0,0);
			}
			/**
			 * Method that returns the state of a button
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	10/05/2011
			 * @version	10/05/2011
			 * @param	const int& pButton, the button
			 * @return	bool
			 */
			inline bool getButton(const int& pButton) const
			{
				return false;
			}
	};
}}
#endif
