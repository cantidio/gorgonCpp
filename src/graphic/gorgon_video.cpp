#include "graphic/gorgon_video.hpp"
/*
 * @todo mudar o nome do método show para swapBuffers, e mudar o nome do método updateBuffer da classe Image para swapBuffers tbm
 */
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
		Core::LogRegister(std::string("Trying to open a Video Device..."));

		const int screenMode = (pFullscreen) ? GFX_AUTODETECT_FULLSCREEN : GFX_AUTODETECT_WINDOWED;
		if(pBpp == 0)
		{
			set_color_depth(24);
		}
		else
		{
			set_color_depth(pBpp);
		}
		
		if
		(
			set_gfx_mode
			(
				screenMode,
				pWidth,
				pHeight,
				0,
				0
			) !=0
		)
		{
			exit(-1);
			//throw VideoException("Unable to set video mode.");
		}
		Video::mScreen = new Image(screen);
		setWindowTitle(pWindowTitle);
		Core::LogRegister(std::string("Sucessfull."));
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
		mScreen->blitImage
		(
			*this,
			0,
			0
		);
	}
}}
