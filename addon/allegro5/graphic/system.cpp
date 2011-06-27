#include <gorgon++/graphic/exception.hpp>
#include <gorgon++/graphic/color.hpp>
#include <gorgon++/core/point.hpp>
#include <gorgon++/core/log.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "system.hpp"
#include "image_base.hpp"
#include "display_base.hpp"
#include "common.hpp"

namespace Gorgon	{
namespace Graphic	{
namespace Addon
{
	System::System()
	{
		if(!al_init())
		{
			Core::logWrite(std::string("Gorgon::Graphic::Addon::System::System(): Error, could not initialize allegro5 lib."));
			raiseGraphicException("System::System(): Error when initializing allegro5 lib.");
		}
		if(!al_init_primitives_addon())
		{
			Core::logWrite(std::string("Gorgon::Graphic::Addon::System::System(): Error, could not initialize allegro5 primitives addon."));
			raiseGraphicException("System::System(): Error when initializing allegro5 primitives addon.");
		}
		if(!al_init_image_addon())
		{
			Core::logWrite(std::string("Gorgon::Graphic::Addon::System::System(): Error, could not initialize allegro5 image I/O addon."));
			raiseGraphicException("System::System(): Error when initializing allegro5 image I/O addon.");
		}
		al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP | ALLEGRO_KEEP_INDEX | ALLEGRO_PIXEL_FORMAT_LUMINANCE_8);
		Core::logWrite(std::string("Gorgon::Graphic::Addon::System::System(): Successful."));
	}

	System::~System()
	{
		al_shutdown_primitives_addon();
		Core::logWrite(std::string("Gorgon::Graphic::Addon::System::~System(): Successful."));
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
		al_put_pixel
		(
			pPosition.getX(),
			pPosition.getY(),
			gorgonColort2AllegroColor(pColor)
		);
	}

	void System::drawLine
	(
		const Core::Point& pPointA,
		const Core::Point& pPointB,
		const Color& pColor,
		const float& pThickness
	)
	{
		al_draw_line
		(
			pPointA.getX(), pPointA.getY(),
			pPointB.getX(), pPointB.getY(),
			gorgonColort2AllegroColor(pColor),
			pThickness
		);
	}

	void System::drawTriangle
	(
		const Core::Point& pPointA,
		const Core::Point& pPointB,
		const Core::Point& pPointC,
		const Color& pColor,
		const float& pThickness
	)
	{
		al_draw_triangle
		(
			pPointA.getX(), pPointA.getY(),
			pPointB.getX(), pPointB.getY(),
			pPointC.getX(), pPointC.getY(),
			gorgonColort2AllegroColor(pColor),
			pThickness
		);
	}

	void System::drawTriangleFilled
	(
		const Core::Point& pPointA,
		const Core::Point& pPointB,
		const Core::Point& pPointC,
		const Color& pColor
	)
	{
		al_draw_filled_triangle
		(
			pPointA.getX(), pPointA.getY(),
			pPointB.getX(), pPointB.getY(),
			pPointC.getX(), pPointC.getY(),
			gorgonColort2AllegroColor(pColor)
		);
	}

	void System::drawRectangle
	(
		const Core::Point& pPointA,
		const Core::Point& pPointB,
		const Color& pColor,
		const float& pThickness
	)
	{
		al_draw_rectangle
		(
			pPointA.getX(), pPointA.getY(),
			pPointB.getX(), pPointB.getY(),
			gorgonColort2AllegroColor(pColor),
			pThickness
		);
	}

	void System::drawRectangleFilled
	(
		const Core::Point& pPointA,
		const Core::Point& pPointB,
		const Color& pColor
	)
	{
		al_draw_filled_rectangle
		(
			pPointA.getX(), pPointA.getY(),
			pPointB.getX(), pPointB.getY(),
			gorgonColort2AllegroColor(pColor)
		);
	}

	void System::drawCircle
	(
		const Core::Point& pPosition,
		const float& pRadius,
		const Color& pColor,
		const float& pThickness
	)
	{
		al_draw_circle
		(
			pPosition.getX(), pPosition.getY(),
			pRadius,
			gorgonColort2AllegroColor(pColor),
			pThickness
		);
	}

	void System::drawCircleFilled
	(
		const Core::Point& pPosition,
		const float& pRadius,
		const Color& pColor
	)
	{
		al_draw_filled_circle
		(
			pPosition.getX(), pPosition.getY(),
			pRadius,
			gorgonColort2AllegroColor(pColor)
		);
	}

	void System::drawEllipse
	(
		const Core::Point& pPosition,
		const float& pRadiusX,
		const float& pRadiusY,
		const Color& pColor,
		const float& pThickness
	)
	{
		al_draw_ellipse
		(
			pPosition.getX(), pPosition.getY(),
			pRadiusX,
			pRadiusY,
			gorgonColort2AllegroColor(pColor),
			pThickness
		);
	}

	void System::drawEllipseFilled
	(
		const Core::Point& pPosition,
		const float& pRadiusX,
		const float& pRadiusY,
		const Color& pColor
	)
	{
		al_draw_filled_ellipse
		(
			pPosition.getX(), pPosition.getY(),
			pRadiusX,
			pRadiusY,
			gorgonColort2AllegroColor(pColor)
		);
	}

}}}

