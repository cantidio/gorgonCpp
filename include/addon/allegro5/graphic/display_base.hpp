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
#ifndef _GORGON_GRAPHIC_DISPLAY_BASE_ADDON_
#define _GORGON_GRAPHIC_DISPLAY_BASE_ADDON_
#include "../../../graphic/display_base.hpp"
#include <string>

struct ALLEGRO_DISPLAY;
namespace Gorgon	{
namespace Allegro5	{
namespace Graphic
{
	/**
	 * Class that represents a Display implementation in Allegro5
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/05/2011
	 * @version	03/06/2011
	 * @ingroup	Graphic::Allegro5
	 */
	class DisplayBase : public Gorgon::Graphic::DisplayBase
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @param	const std::string&	pWindowTitle , the title of the display's window
			 * @param	const int&			pWidth       , the width of the display
			 * @param	const int&			pHeight      , the height of the display
			 * @param	const bool&			pFullScreen  , if the display will begin in fullscreen
			 * @param	const bool&			pResizeable  , if the display is resizeable
			 */
			DisplayBase
			(
				const std::string&	pWindowTitle,
				const int&			pWidth,
				const int&			pHeight,
				const bool&			pFullScreen = false,
				const bool&			pResizeable = false
			);
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 */
			virtual ~DisplayBase();
			/**
			 * Method that switches the display from windowed to fullscreen and from fullscreen to windowed
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	bool
			 */
			virtual bool toogleFullScreen();
			/**
			 * Method that sets the display as a target for drawing images
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 */
			virtual void setAsTarget();
			/**
			 * Method that clears the display painting it, with some color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @param	Gorgon::Graphic::Color& pColor, the color the clean the display
			 */
			virtual void clear( const Gorgon::Graphic::Color& pColor );
			/**
			 * Method that swap the buffers of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @details
			 *			To see all the modifications you made in the display, you need to call this method
			 */
			virtual void swapBuffers();
			/**
			 * Method that sets the logo image of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @param	const Gorgon::Graphic::Image& pImage, the image to be used as a logo
			 * @details
			 *			If the image is too big, it will be resized
			 */
			virtual void setLogo( const Gorgon::Graphic::Image& pImage );
			/**
			 * Method that sets the window title
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	29/05/2011
			 * @param	const std::string& pWindowTitle, the new tile
			 */
			virtual void setWindowTitle( const std::string& pWindowTitle );
		protected:
			ALLEGRO_DISPLAY* mDisplay; /**<< the display data*/

	};
}}}
#endif

