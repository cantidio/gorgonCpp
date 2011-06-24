#include <gorgon++/input/exception.hpp>
#include <SDL/SDL.h>

#include "system.hpp"
#include "mouse_base.hpp"
#include "keyboard_base.hpp"
#include "joystick_base.hpp"

namespace Gorgon	{
namespace Input		{
namespace Addon
{
	System::System()
	{
		if( SDL_Init( 0 ) < 0)
		{
			Core::logWrite("Input::Addon::System::System(): Error, couldn't start SDL.");
			raiseInputException("Input::Addon::System::System(): Error, couldn't start SDL.");
		}
		if( SDL_EventState(SDL_QUERY , SDL_KEYUP) && SDL_EventState(SDL_QUERY , SDL_KEYDOWN) )
		{
			Core::logWrite("Input::Addon::System::System(): Error, couldn't install SDL's Keyboard.");
			raiseInputException("Input::Addon::System::System(): Error, couldn't install SDL's Keyboard.");
		}
		if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) < 0)
		{
			Core::logWrite("Input::Addon::System::System(): Error, couldn't install SDL's Joystick.");
			raiseInputException("Input::Addon::System::System(): Error, couldn't install SDL's Joystick.");
		}
//		SDL_JoystickEventState(SDL_IGNORE);
		if( SDL_EventState(SDL_QUERY, SDL_MOUSEMOTION) && SDL_EventState(SDL_QUERY, SDL_MOUSEBUTTONDOWN) && SDL_EventState(SDL_QUERY, SDL_MOUSEBUTTONUP) )
		{
			Core::logWrite("Input::Addon::System::System(): Error, couldn't install SDL's Mouse.");
			raiseInputException("Input::Addon::System::System(): Error, couldn't install SDL's Mouse.");
		}
		Core::logWrite("Input::Addon::System::System(): SDL Input System init Sucessfull.");
	}

	System::~System()
	{
		SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
		Core::logWrite("Input::Addon::System::~System(): Sucessfull");
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
		return  SDL_NumJoysticks();
	}
}}}
