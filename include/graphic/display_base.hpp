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
#ifndef _GORGON_GRAPHIC_DISPLAY_BASE_
#define _GORGON_GRAPHIC_DISPLAY_BASE_
#include <string>

namespace Gorgon{
namespace Graphic
{
	class Image;
	class ImageBase;
	class Color;
	/**
	 * Class that represents a Display implementation
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/05/2011
	 * @version	11/10/2011
	 * @ingroup	Graphic
	 */
	class DisplayBase
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @param	const std::string& pWindowtitle,
			 * @param	const int&	pWidth		, the width of the display
			 * @param	const int&	pHeight		, the height of the display
			 * @param	const bool&	pFullScreen	, if the display will be fullscreen
			 * @param	const bool&	pResizeable	, if the display will be resisable
			 */
			DisplayBase
			(
				const std::string& pWindowtitle,
				const int&	pWidth,
				const int&	pHeight,
				const bool&	pFullScreen = false,
				const bool&	pResizeable = false
			);
			/**
			 * Virtual Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/10/2011
			 * @version	11/10/2011
			 */
			virtual ~DisplayBase();
			/**
			 * Method that returns the title of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	std::string
			 */
			inline std::string getWindowTitle() const
			{
				return mWindowTitle;
			}
			/**
			 * Method that returns the width of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	int
			 */
			inline int getWidth() const
			{
				return mWidth;
			}
			/**
			 * Method that returns the height of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return
			 */
			inline int getHeight() const
			{
				return mHeight;
			}
			/**
			 * Method that returns if this display is on Full Screen
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	bool
			 */
			inline bool isFullScreen() const
			{
				return mFullScreen;
			}
			/**
			 * Method that returns if this display is resizeable
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	bool
			 */
			inline bool isResizeable() const
			{
				return mResizeable;
			}
			/**
			 * Method that switches the display from windowed to fullscreen and from fullscreen to windowed
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	bool
			 */
			virtual bool toogleFullScreen() = 0;
			/**
			 * Method that sets the display as a target for drawing images
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 */
			virtual void setAsTarget() = 0;
			/**
			 * Method that clears the display painting it, with some color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 *
			 */
			virtual void clear(const Color& pColor) = 0;
			/**
			 * Method that swap the buffers of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @details
			 *			To see all the modifications you made in the display, you need to call this method
			 */
			virtual void swapBuffers() = 0;
			/**
			 * Method that sets the logo image of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @param	const Image& pImage, the image to be used as a logo
			 * @details
			 *			If the image is too big, it will be resized
			 */
			virtual void setLogo(const Image& pImage) = 0;
			/**
			 * Method that sets the window title
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	29/05/2011
			 * @param	const std::string& pWindowTitle, the new tile
			 */
			virtual void setWindowTitle(const std::string& pWindowTitle) = 0;
			/**
			 * Method that returns the current backbuffer of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2011
			 * @version	03/06/2011
			 * @return	ImageBase*
			 */
			inline virtual ImageBase* getBackBuffer()
			{
				return mBackBuffer;
			}
		protected:
			std::string		mWindowTitle;
			int				mWidth;
			int				mHeight;
			bool			mFullScreen;
			bool			mResizeable;
			ImageBase*		mBackBuffer;	/**<< the backbuffer of the display*/
	};
}}
#endif
