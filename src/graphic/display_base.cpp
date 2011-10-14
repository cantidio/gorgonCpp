#include <graphic/display_base.hpp>
#include <sstream>

namespace Gorgon{
namespace Graphic
{
	DisplayBase::DisplayBase
	(
		const std::string& pWindowTitle,
		const int& pWidth,
		const int& pHeight,
		const bool& pFullScreen,
		const bool& pResizeable
	)
	{
		mWidth			= pWidth;
		mHeight			= pHeight;
		mWindowTitle	= pWindowTitle;
		mFullScreen		= pFullScreen;
		mResizeable		= pResizeable;
	}

	DisplayBase::~DisplayBase()
	{

	}

}}
