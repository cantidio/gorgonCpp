#include <gorgon++/graphic/exception.hpp>
#include <gorgon++/graphic/image.hpp>

#include <allegro5/allegro.h>
#include <sstream>
#include "display_base.hpp"
#include "image_base.hpp"

namespace Gorgon	{
namespace Graphic	{
namespace Addon
{
	DisplayBase::DisplayBase
	(
		const std::string& pWindowTitle,
		const int& pWidth,
		const int& pHeight,
		const bool& pFullScreen,
		const bool& pResizeable
	) : Graphic::DisplayBase(pWindowTitle, pWidth, pHeight, pFullScreen, pResizeable)
	{
		al_set_new_display_flags
		(
			ALLEGRO_OPENGL
			| (pFullScreen ? ALLEGRO_FULLSCREEN_WINDOW : 0)
			| (pResizeable ? ALLEGRO_RESIZABLE         : 0)
		);

		mDisplay = al_create_display(pWidth, pHeight);

		if(mDisplay == NULL)
		{
			std::stringstream out;
			out << "Graphic::Addon::DisplayBase::DisplayBase(\"" << pWindowTitle << "\", " << pWidth << ", " << pHeight << ", ";
			out << (pFullScreen ? "true" : "false") << ", " << (pResizeable ? "true" : "false") << "): Error, could not create the display.";
			raiseGraphicException( out.str() );
		}

		setWindowTitle(pWindowTitle);
		Core::logWriteFormatted
		(
			Core::String("Gorgon::Graphic::Addon::Display::Display(\"%s\",%d,%d,%s,%s): Successful."),
			pWindowTitle.c_str(),
			pWidth,
			pHeight,
			(pFullScreen ? "true" : "false"),
			(pResizeable ? "true" : "false")
		);
		mBackBuffer = new ImageBase( al_get_backbuffer(mDisplay), false);
	}

	DisplayBase::~DisplayBase()
	{
		if( mDisplay )
		{
			al_destroy_display( mDisplay );
			delete mBackBuffer;
			Core::logWrite("Gorgon::Graphic::Addon::Display::~Display(): Successfull.");
		}
		else
		{
			Core::logWrite("Gorgon::Graphic::Addon::Display::~Display(): There isn't a display to destroy.");
		}
	}

	bool DisplayBase::toogleFullScreen()
	{
		mFullScreen = !mFullScreen;
		return al_toggle_display_flag( mDisplay, ALLEGRO_FULLSCREEN_WINDOW, mFullScreen );
	}

	//al_resize_display

	void DisplayBase::setAsTarget()
	{
	    al_set_target_bitmap(al_get_backbuffer(mDisplay));
		//al_set_target_backbuffer(mDisplay);
	}

	void DisplayBase::clear(const Color& pColor)
	{
		/*Image target = Graphic::System::getTargetImage();

		Graphic::System::setTargetImage(target);*/

		ALLEGRO_BITMAP * aux = al_get_target_bitmap();	//pega o target anterior

		al_set_target_bitmap(al_get_backbuffer(mDisplay));

		al_clear_to_color
		(
			al_map_rgba_f
			(
				pColor.getRed(),
				pColor.getGreen(),
				pColor.getBlue(),
				pColor.getAlpha()
			)
		);												//limpa com a cor desejada
		al_set_target_bitmap(aux);						//seta o target antigo
	}

	void DisplayBase::swapBuffers()
	{
		al_flip_display();
	}

	void DisplayBase::setLogo(const Image& pImage)
	{
		/**@todo implementar*/
//		al_set_display_icon(mDisplay, pImage.mImage.mDisplay);
	}

	void DisplayBase::setWindowTitle(const std::string& pWindowTitle)
	{
		mWindowTitle = pWindowTitle;
		al_set_window_title(mDisplay, mWindowTitle.c_str());
	}
}}}
