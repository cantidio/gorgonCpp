#include <input/system.hpp>
#include <input/mouse.hpp>

namespace Gorgon{
namespace Input
{
	Mouse::Mouse()
	{
		mMouse = System::get().getMouse();
	}

	Mouse::~Mouse()
	{
		if(mMouse != NULL)
		{
			delete mMouse;
		}
	}
	
	void Mouse::update()
	{
		mMouse->update();
	}
	
	bool Mouse::isOpened() const
	{
		return mMouse->isOpened();
	}
	
	Core::Point Mouse::getPosition() const
	{
		return mMouse->getPosition();
	}
	
	bool Mouse::getButton(const MouseBase::Button& pButton) const
	{
		return mMouse->getButton(pButton);
	}
}}

