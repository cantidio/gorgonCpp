#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <addon/allegro5/graphic/system.hpp>
#include <addon/allegro5/graphic/image_base.hpp>
#include <addon/allegro5/graphic/font_base.hpp>
#include <addon/allegro5/graphic/display_base.hpp>
#include <addon/allegro5/graphic/common.hpp>

namespace Gorgon	{
namespace Allegro5	{
namespace Graphic
{
	System::System()
	{
		if( !al_init() )
		{
			Gorgon::Core::logWrite(std::string("Gorgon::Allegro5::Graphic::System::System(): Error, could not initialize allegro5 lib."));
			raiseGraphicException("System::System(): Error when initializing allegro5 lib.");
		}
		if( !al_init_primitives_addon() )
		{
			Gorgon::Core::logWrite(std::string("Gorgon::Allegro5::Graphic::System::System(): Error, could not initialize allegro5 primitives addon."));
			raiseGraphicException("System::System(): Error when initializing allegro5 primitives addon.");
		}
		if( !al_init_image_addon() )
		{
			Gorgon::Core::logWrite(std::string("Gorgon::Allegro5::Graphic::System::System(): Error, could not initialize allegro5 image I/O addon."));
			raiseGraphicException("System::System(): Error when initializing allegro5 image I/O addon.");
		}
		al_init_font_addon();
		if( !al_init_ttf_addon() )
		{
			Gorgon::Core::logWrite(std::string("Gorgon::Allegro5::Graphic::System::System(): Error, could not initialize allegro5 font addon."));
			raiseGraphicException("System::System(): Error when initializing allegro5 font addon.");
		}
		/**@todo usar allegro5.1 */
		al_set_new_bitmap_flags( ALLEGRO_MEMORY_BITMAP /*| ALLEGRO_KEEP_INDEX | ALLEGRO_PIXEL_FORMAT_LUMINANCE_8*/ );
		Gorgon::Core::logWrite(std::string("Gorgon::Allegro5::Graphic::System::System(): Successful."));
	}

	System::~System()
	{
		al_shutdown_ttf_addon();
		al_shutdown_font_addon();
		al_shutdown_image_addon();
		al_shutdown_primitives_addon();
		al_uninstall_system();
		Gorgon::Core::logWrite(std::string("Gorgon::Allegro5::Graphic::System::~System(): Successful."));
	}

	void System::set()
	{
		Gorgon::Graphic::System::set( new System() );
	}

	Gorgon::Graphic::ImageBase* System::getImage() const
	{
		return new ImageBase();
	}

	Gorgon::Graphic::FontBase* System::getFont() const
	{
		return new FontBase();
	}

	Gorgon::Graphic::DisplayBase* System::getDisplay
	(
		const std::string&	pWindowTitle,
		const int&			pWidth,
		const int&			pHeight,
		const bool&			pFullScreen,
		const bool&			pResizeable
	) const
	{
		return new DisplayBase( pWindowTitle, pWidth, pHeight, pFullScreen, pResizeable );
	}

	void System::drawPixel( const Gorgon::Core::Point& pPosition,const  Gorgon::Graphic::Color& pColor )
	{
		al_put_pixel
		(
			pPosition.getX(),
			pPosition.getY(),
			gorgonColort2AllegroColor( pColor )
		);
	}

	void System::drawLine
	(
		const Gorgon::Core::Point&		pPointA,
		const Gorgon::Core::Point&		pPointB,
		const Gorgon::Graphic::Color&	pColor,
		const float&					pThickness
	)
	{
		al_draw_line
		(
			pPointA.getX(), pPointA.getY(),
			pPointB.getX(), pPointB.getY(),
			gorgonColort2AllegroColor( pColor ),
			pThickness
		);
	}

	void System::drawTriangle
	(
		const Gorgon::Core::Point&		pPointA,
		const Gorgon::Core::Point&		pPointB,
		const Gorgon::Core::Point&		pPointC,
		const Gorgon::Graphic::Color&	pColor,
		const float&					pThickness
	)
	{
		al_draw_triangle
		(
			pPointA.getX(), pPointA.getY(),
			pPointB.getX(), pPointB.getY(),
			pPointC.getX(), pPointC.getY(),
			gorgonColort2AllegroColor( pColor ),
			pThickness
		);
	}

	void System::drawTriangleFilled
	(
		const Gorgon::Core::Point&		pPointA,
		const Gorgon::Core::Point&		pPointB,
		const Gorgon::Core::Point&		pPointC,
		const Gorgon::Graphic::Color&	pColor
	)
	{
		al_draw_filled_triangle
		(
			pPointA.getX(), pPointA.getY(),
			pPointB.getX(), pPointB.getY(),
			pPointC.getX(), pPointC.getY(),
			gorgonColort2AllegroColor( pColor )
		);
	}

	void System::drawRectangle
	(
		const Gorgon::Core::Point&		pPointA,
		const Gorgon::Core::Point&		pPointB,
		const Gorgon::Graphic::Color&	pColor,
		const float&					pThickness
	)
	{
		al_draw_rectangle
		(
			pPointA.getX(), pPointA.getY(),
			pPointB.getX(), pPointB.getY(),
			gorgonColort2AllegroColor( pColor ),
			pThickness
		);
	}

	void System::drawRectangleFilled
	(
		const Gorgon::Core::Point&		pPointA,
		const Gorgon::Core::Point&		pPointB,
		const Gorgon::Graphic::Color&	pColor
	)
	{
		al_draw_filled_rectangle
		(
			pPointA.getX(), pPointA.getY(),
			pPointB.getX(), pPointB.getY(),
			gorgonColort2AllegroColor( pColor )
		);
	}

	void System::drawCircle
	(
		const Gorgon::Core::Point&		pPosition,
		const float&					pRadius,
		const Gorgon::Graphic::Color&	pColor,
		const float&					pThickness
	)
	{
		al_draw_circle
		(
			pPosition.getX(), pPosition.getY(),
			pRadius,
			gorgonColort2AllegroColor( pColor ),
			pThickness
		);
	}

	void System::drawCircleFilled
	(
		const Gorgon::Core::Point&		pPosition,
		const float&					pRadius,
		const Gorgon::Graphic::Color&	pColor
	)
	{
		al_draw_filled_circle
		(
			pPosition.getX(), pPosition.getY(),
			pRadius,
			gorgonColort2AllegroColor( pColor )
		);
	}

	void System::drawEllipse
	(
		const Gorgon::Core::Point&		pPosition,
		const float&					pRadiusX,
		const float&					pRadiusY,
		const Gorgon::Graphic::Color&	pColor,
		const float&					pThickness
	)
	{
		al_draw_ellipse
		(
			pPosition.getX(), pPosition.getY(),
			pRadiusX,
			pRadiusY,
			gorgonColort2AllegroColor( pColor ),
			pThickness
		);
	}

	void System::drawEllipseFilled
	(
		const Gorgon::Core::Point&		pPosition,
		const float&					pRadiusX,
		const float&					pRadiusY,
		const Gorgon::Graphic::Color&	pColor
	)
	{
		al_draw_filled_ellipse
		(
			pPosition.getX(), pPosition.getY(),
			pRadiusX,
			pRadiusY,
			gorgonColort2AllegroColor( pColor )
		);
	}
}}}

