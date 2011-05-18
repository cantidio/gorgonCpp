#include "joystick_handler.hpp"
#include "joystick.hpp"
#include <gorgon++/core/log.hpp>
#include <gorgon++/core/string.hpp>

namespace Gorgon{
namespace Addon
{
	JoystickHandlerSDL::JoystickHandlerSDL()
	{
		if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) < 0)
		{
			Core::logWrite(Core::String("JoystickHandlerSDL::JoystickHandlerSDL(): Error: could not open Joystick Handler."));
			throw("Couldn't create SDL joystick handler.");
		}
		//SDL_JoystickEventState(SDL_QUERY);
		SDL_JoystickEventState(SDL_IGNORE);
		Core::logWrite(Core::String("JoystickHandlerSDL::JoystickHandlerSDL(): Sucessfull."));
	}

	JoystickHandlerSDL::~JoystickHandlerSDL()
	{
		Core::logWrite(Core::String("JoystickHandlerSDL::~JoystickHandlerSDL()"));
		SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
	}

	void JoystickHandlerSDL::set()
	{
		static JoystickHandlerSDL handler;
		Input::JoystickHandler::set(handler);
	}

	Input::JoystickBase* JoystickHandlerSDL::getJoystick(const int& pIndex) const
	{
		return new JoystickSDL(pIndex);
	}

	int JoystickHandlerSDL::getJoystickNumber() const
	{
		return  SDL_NumJoysticks();
	}
}}
