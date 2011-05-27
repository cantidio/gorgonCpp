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
#ifndef _GORGON_GRAPHIC_SYSTEM_
#define _GORGON_GRAPHIC_SYSTEM_

namespace Gorgon{
namespace Graphic
{
	class ImageBase;
	class Image;
	/**
	 * Class that represents the Graphic System
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	27/05/2011
	 * @version	27/05/2011
	 */
	class System
	{
		public:
			/**
			 * Method that returns the instance of the Graphic System
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 * @return	System&
			 */
			static System& get();
			static void halt();
			/**
			 * Method that returns an instance of the current joystickBase
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 * @param	const int& pIndex, the index of the Joystick
			 * @return	JoystickBase*
			 */
			virtual ImageBase* getImage() const = 0;
			/**
			 * Method that sets the target Image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 * @param	Image& pImage, the image that will receive the next draw operations
			 */
			void setTargetImage(Image& pImage);
			Image& getTargetImage();
		protected:
			/**
			 * Protected Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 */
			System();
			/**
			 * Protected Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 */
			virtual ~System();
			/**
			 * Method that sets the GraphicSystem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 * @param	System* pSystem, pointer the graphic system
			 */
			static void set(System* pSystem);
		private:	
			static System*	mSingleton;		/**<< Singleton instance of the class*/
			bool			mInit;			/**<< True if the graphic system is running, false otherwise*/
			Image*			mTargetImage;	/**<< The targetImage, this stores the image that will receive all the draw operations*/
	};
}}
#endif
