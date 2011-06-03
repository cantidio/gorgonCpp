#include <gorgon++/graphic/exception.hpp>
#include <gorgon++/graphic/color.hpp>
#include <gorgon++/core/point.hpp>
#include <gorgon++/core/log.hpp>
#include <allegro5/allegro.h>
#include "system.hpp"
#include "image_base.hpp"
#include "display_base.hpp"

namespace Gorgon	{
namespace Graphic	{
namespace Addon
{
	System::System()
	{
		if(!al_init())
		{
			Core::logWrite("Gorgon::Graphic::Addon::System::System(): Error, could not initialize allegro5 lib.");
			raiseGraphicException("System::System(): Error when initializing allegro5 lib.");
		}
		al_set_new_bitmap_flags(/*ALLEGRO_KEEP_INDEX | */ALLEGRO_VIDEO_BITMAP);
		//al_set_new_bitmap_format(ALLEGRO_PIXEL_FORMAT_LUMINANCE_8);
		Core::logWrite("Gorgon::Graphic::Addon::System::System(): Successful.");
	}

	System::~System()
	{
		Core::logWrite(Core::String("Gorgon::Graphic::Addon::System::~System(): Successful."));
	}

	void System::set()
	{
		Graphic::System::set( new System() );
	}

	Graphic::ImageBase* System::getImage() const
	{
		return new ImageBase();
	}

	Graphic::DisplayBase* System::getDisplay
	(
		const std::string& pWindowTitle,
		const int& pWidth,
		const int& pHeight,
		const bool& pFullScreen,
		const bool& pResizeable
	) const
	{
		return new DisplayBase( pWindowTitle, pWidth, pHeight, pFullScreen, pResizeable );
	}

	void System::drawPixel(const Core::Point& pPosition,const  Color& pColor)
	{
		al_put_pixel( pPosition.getX(), pPosition.getY(), al_map_rgba_f(pColor.getRed(), pColor.getGreen(), pColor.getBlue(), pColor.getAlpha()) );
	}
}}}

