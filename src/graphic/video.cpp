/*#include "graphic/video.hpp"
#include <core/string.hpp>

namespace Gorgon{
namespace Graphic
{
	Video*	Video::mSingleton	= NULL;
	Image*	Video::mScreen		= NULL;

	Video::Video
	(
		const std::string&	pWindowTitle,
		const int&			pWidth,
		const int&			pHeight,
		const bool&			pFullscreen,
		const int&			pBpp
	) : Sprite(Image(pWidth,pHeight,pBpp))
	{
		Core::logWriteFormatted
		(
			Core::String("Gorgon::Graphic::Video::Video(\"%s\",%d,%d,%s,%d): "),
			pWindowTitle.c_str(),
			pWidth,
			pHeight,
			(pFullscreen ? "true" : "false"),
			pBpp
		);
		const int screenMode = (pFullscreen) ? GFX_AUTODETECT_FULLSCREEN : GFX_AUTODETECT_WINDOWED;
		set_color_depth((pBpp == 0) ? 24 : pBpp);
		if
		(
			set_gfx_mode( screenMode, pWidth, pHeight, 0, 0 ) !=0
		)
		{
			Core::logWrite(Core::String("Error: unable to set video mode."),true,false);
		}
		//Video::mScreen = new Image(screen);
		setWindowTitle(pWindowTitle);
		Core::logWrite(Core::String("Sucessfull."),true,false);
	}

	void Video::init
	(
		const std::string&	pWindowTitle,
		const int&			pWidth,
		const int&			pHeight,
		const bool&			pFullscreen,
		const int&			pBpp
	)
	{
		if(Video::mSingleton == NULL)
		{
			Video::mSingleton = new Video
			(
				pWindowTitle,
				pWidth,
				pHeight,
				pFullscreen,
				pBpp
			);
		}
	}

	void Video::halt()
	{
		if(mSingleton == NULL)
		{
			delete mSingleton;
			mSingleton = NULL;
		}
	}

	void Video::setWindowTitle(const std::string& pWindowTitle)
	{
		set_window_title(pWindowTitle.c_str());
	}

	Video& Video::get()
	{
		Video::init();
		return *Video::mSingleton;
	}

	void Video::show()
	{
		
	}
}}*/
