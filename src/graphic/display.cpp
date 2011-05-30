#include <graphic/display.hpp>
#include <graphic/system.hpp>
#include <graphic/display_base.hpp>
#include <sstream>

namespace Gorgon{
namespace Graphic
{
	Display::Display
	(
		const std::string& pWindowTitle,
		const int& pWidth,
		const int& pHeight,
		const bool& pFullScreen,
		const bool& pResizeable
	)
	{
		mDisplay = System::get().getDisplay( pWindowTitle, pWidth, pHeight, pFullScreen, pResizeable );
	}

	Display::~Display()
	{
		if(mDisplay != NULL)
		{
			delete mDisplay;
		}
	}

	std::string Display::describe()
	{
		std::stringstream out;
		out << "Graphic::describe()"									<< std::endl;
		out << "Title:      " << getWindowTitle()						<< std::endl;
		out << "Width:      " << getWidth()								<< std::endl;
		out << "Height:     " << getHeight()							<< std::endl;
		out << "FullScreen: " << (isFullScreen() ? "true" : "false")	<< std::endl;
		out << "Resizeable: " << (isResizeable() ? "true" : "false")	<< std::endl;
		return out.str();
	}
	
	std::string Display::getWindowTitle() const
	{
		return mDisplay->getWindowTitle();
	}
	
	int Display::getWidth() const
	{
		return mDisplay->getWidth();
	}
	
	int Display::getHeight() const
	{
		return mDisplay->getHeight();
	}
	
	bool Display::isFullScreen() const
	{
		return mDisplay->isFullScreen();
	}
	
	bool Display::isResizeable() const
	{
		return mDisplay->isFullScreen();
	}
	
	bool Display::toogleFullScreen()
	{
		return mDisplay->toogleFullScreen();
	}
	
	void Display::setAsTarget()
	{
		mDisplay->setAsTarget();
	}
	
	void Display::clear(const Color& pColor)
	{
		mDisplay->clear(pColor);
	}
	
	void Display::swapBuffers()
	{
		mDisplay->swapBuffers();
	}
	
	void Display::setLogo(const Image& pImage)
	{
		mDisplay->setLogo(pImage);
	}
}}

