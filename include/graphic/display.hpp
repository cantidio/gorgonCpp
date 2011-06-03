#ifndef _GORGON_GRAPHIC_DISPLAY_
#define _GORGON_GRAPHIC_DISPLAY_
#include <string>

namespace Gorgon{
namespace Graphic
{
	class DisplayBase;
	class Color;
	class Image;
	/**
	 * Class that represents a Display
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	22/01/2009
	 * @version	03/06/2011
	 * @ingroup	Graphic
	 */
	class Display
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 *
			 */
			Display
			(
				const std::string& pWindowtitle,
				const int& pWidth,
				const int& pHeight,
				const bool& pFullScreen = false,
				const bool& pResizeable = false
			);
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 *
			 */
			~Display();
			/**
			 * Method that returns the information of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	std::string
			 */
			std::string describe();
			/**
			 * Method that returns the title of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	std::string
			 */
			std::string getWindowTitle() const;
			/**
			 * Method that returns the width of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	int
			 */
			int getWidth() const;
			/**
			 * Method that returns the height of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return
			 */
			int getHeight() const;
			/**
			 * Method that returns if this display is on Full Screen
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	bool
			 */
			bool isFullScreen() const;
			/**
			 * Method that returns if this display is resizeable
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	bool
			 */
			bool isResizeable() const;
			/**
			 * Method that switches the display from windowed to fullscreen and from fullscreen to windowed
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @return	bool
			 */
			bool toogleFullScreen();
			/**
			 * Method that sets the display as a target for drawing images
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 */
			void setAsTarget();
			/**
			 * Method that clears the display painting it, with some color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 *
			 */
			void clear(const Color& pColor);
			/**
			 * Method that swap the buffers of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @details
			 *			To see all the modifications you made in the display, you need to call this method
			 */
			void swapBuffers();
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
			void setLogo(const Image& pImage);
			/**
			 * Method that sets the window title
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	29/05/2011
			 * @param	const std::string& pWindowTitle, the new tile
			 */
			void setWindowTitle(const std::string& pWindowTitle);
			/**
			 * Method that returns the display backbuffer
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2011
			 * @version	03/06/2011
			 * @return	Image
			 */
			Image& getBackBuffer();
		protected:
			DisplayBase* mDisplay;	/**<< The implementation of the display*/
			Image* mBackBuffer;		/**<< The display back buffer*/
	};
}}
#endif
