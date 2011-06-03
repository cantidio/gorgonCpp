#ifndef _GORGON_GRAPHIC_DISPLAY_BASE_ADDON_
#define _GORGON_GRAPHIC_DISPLAY_BASE_ADDON_
#include <gorgon++/graphic/display_base.hpp>
#include <string>

struct ALLEGRO_DISPLAY;
namespace Gorgon	{
namespace Graphic	{
namespace Addon
{
	/**
	 * Class that represents a Display implementation
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/05/2011
	 * @version	03/06/2011
	 * @ingroup	Graphic::Addon
	 */
	class DisplayBase : public Graphic::DisplayBase
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
				const std::string& pWindowTitle,
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
			 *
			 */
			virtual void clear(const Color& pColor);
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
			 * @param	const Image& pImage, the image to be used as a logo
			 * @details
			 *			If the image is too big, it will be resized
			 */
			virtual void setLogo(const Image& pImage);
			/**
			 * Method that sets the window title
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	29/05/2011
			 * @param	const std::string& pWindowTitle, the new tile
			 */
			virtual void setWindowTitle(const std::string& pWindowTitle);
		protected:
			ALLEGRO_DISPLAY*	mDisplay;		/**<< the display data*/

	};
}}}
#endif

