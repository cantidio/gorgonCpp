#include "system.hpp"
#include "mouse_base.hpp"
#include "keyboard_base.hpp"
#include "joystick_base.hpp"
#include <allegro5/allegro.h>
#include <gorgon++/input/exception.hpp>

namespace Gorgon	{
namespace Input		{
namespace Addon
{
	System::System()
	{
		if( !al_init() )
		{
			Core::logWrite(std::string("Input::Addon::System::System(): Error, couldn't start Allegro5."));
			raiseInputException("Input::Addon::System::System(): Error, couldn't start Allegro5.");
		}
		if( !al_install_keyboard() )
		{
			Core::logWrite(std::string("Input::Addon::System::System(): Error, couldn't install Allegro5's Keyboard."));
			raiseInputException("Input::Addon::System::System(): Error, couldn't install Allegro5's Keyboard.");
		}
		if( !al_install_joystick() )
		{
			Core::logWrite(std::string("Input::Addon::System::System(): Error, couldn't install Allegro5's Joystick."));
			raiseInputException("Input::Addon::System::System(): Error, couldn't install Allegro5's Joystick.");
		}
		if( !al_install_mouse() )
		{
			Core::logWrite(std::string("Input::Addon::System::System(): Error, couldn't install Allegro5's Mouse."));
			raiseInputException("Input::Addon::System::System(): Error, couldn't install Allegro5's Mouse.");
		}
		Core::logWrite(std::string("Input::Addon::System::System(): Allegro5 Input System init Sucessfull."));
	}

	System::~System()
	{
		al_uninstall_keyboard();
		al_uninstall_joystick();
		al_uninstall_mouse();
		Core::logWrite(std::string("Input::Addon::System::~System(): Sucessfull"));
	}

	void System::set()
	{
		Input::System::set(new System());
	}

	Input::KeyboardBase* System::getKeyboard() const
	{
		return new KeyboardBase();
	}


	Input::MouseBase* System::getMouse() const
	{
		return new MouseBase();
	}

	Input::JoystickBase* System::getJoystick(const int& pIndex) const
	{
		return new JoystickBase(pIndex);
	}

	int System::getJoystickNumber() const
	{
		return  al_get_num_joysticks();
	}
}}}
