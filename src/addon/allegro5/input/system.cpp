#include <addon/allegro5/input/system.hpp>
#include <addon/allegro5/input/mouse_base.hpp>
#include <addon/allegro5/input/keyboard_base.hpp>
#include <addon/allegro5/input/joystick_base.hpp>

#include <allegro5/allegro.h>
#include <input/exception.hpp>

namespace Gorgon	{
namespace Allegro5	{
namespace Input
{
	System::System()
	{
		if( !al_init() )
		{
			Gorgon::Core::logWrite(std::string("Input::Addon::System::System(): Error, couldn't start Allegro5."));
			raiseInputException("Input::Addon::System::System(): Error, couldn't start Allegro5.");
		}
		if( !al_install_keyboard() )
		{
			Gorgon::Core::logWrite(std::string("Input::Addon::System::System(): Error, couldn't install Allegro5's Keyboard."));
			raiseInputException("Input::Addon::System::System(): Error, couldn't install Allegro5's Keyboard.");
		}
		if( !al_install_joystick() )
		{
			Gorgon::Core::logWrite(std::string("Input::Addon::System::System(): Error, couldn't install Allegro5's Joystick."));
			raiseInputException("Input::Addon::System::System(): Error, couldn't install Allegro5's Joystick.");
		}
		if( !al_install_mouse() )
		{
			Gorgon::Core::logWrite(std::string("Input::Addon::System::System(): Error, couldn't install Allegro5's Mouse."));
			raiseInputException("Input::Addon::System::System(): Error, couldn't install Allegro5's Mouse.");
		}
		Gorgon::Core::logWrite(std::string("Input::Addon::System::System(): Allegro5 Input System init Sucessfull."));
	}

	System::~System()
	{
		al_uninstall_keyboard();
		al_uninstall_joystick();
		al_uninstall_mouse();
		Gorgon::Core::logWrite( std::string("Input::Addon::System::~System(): Sucessfull") );
	}

	void System::set()
	{
		Gorgon::Input::System::set( new System() );
	}

	Gorgon::Input::KeyboardBase* System::getKeyboard() const
	{
		return new KeyboardBase();
	}


	Gorgon::Input::MouseBase* System::getMouse() const
	{
		return new MouseBase();
	}

	Gorgon::Input::JoystickBase* System::getJoystick( const int& pIndex ) const
	{
		return new JoystickBase( pIndex );
	}

	int System::getJoystickNumber() const
	{
		return  al_get_num_joysticks();
	}
}}}
