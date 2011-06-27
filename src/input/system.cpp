#include <input/system.hpp>
#include <input/mouse_base_null.hpp>
#include <input/keyboard_base_null.hpp>
#include <input/joystick_base_null.hpp>
#include <core/log.hpp>

namespace Gorgon{
namespace Input
{
	System* System::mSingleton = NULL;
	System::System()
	{
		Core::logWrite(std::string("Input::System::System(): Successful. This is a NULL System."));
	}

	System::~System()
	{
		Core::logWrite(std::string("Input::System::~System(): Successful."));
	}

	System& System::get()
	{
		if(mSingleton == NULL)
		{
			mSingleton = new System();
		}
		return *mSingleton;
	}

	void System::set(System* pSystem)
	{
		if(mSingleton != NULL)
		{
			delete mSingleton;
		}
		mSingleton = pSystem;
	}

	void System::halt()
	{
		set(NULL);
		Core::logWrite(std::string("Input::System::halt(): Successful."));
	}

	KeyboardBase* System::getKeyboard() const
	{
		return new KeyboardBaseNull();
	}

	MouseBase* System::getMouse() const
	{
		return new MouseBaseNull();
	}

	JoystickBase* System::getJoystick(const int& pIndex) const
	{
		return new JoystickBaseNull(pIndex);
	}

	int System::getJoystickNumber() const
	{
		return 0;
	}

}}
