#include "joystick_handler.hpp"
#include "joystick.hpp"
#include <allegro5/allegro.h>
#include <gorgon++/core/gorgon_log.hpp>
#include <gorgon++/core/gorgon_string.hpp>
namespace Gorgon{
namespace Addon
{
	JoystickHandlerAllegro::JoystickHandlerAllegro()
	{
		if( !(al_init() && al_install_joystick()) )
		{
			Core::logWrite(Core::String("JoystickHandlerAllegro::JoystickHandlerAllegro(): Error, could not open Handler."));
			throw("Couldn't create allegro5 joystick handler.");
		}
		Core::logWrite(Core::String("JoystickHandlerAllegro::JoystickHandlerAllegro(): Sucessfull."));
	}

	JoystickHandlerAllegro::~JoystickHandlerAllegro()
	{
		Core::logWrite(Core::String("JoystickHandlerAllegro::~JoystickHandlerAllegro()"));
	}

	void JoystickHandlerAllegro::set()
	{
		static JoystickHandlerAllegro handler;
		Input::JoystickHandler::set(handler);
	}

	Input::JoystickBase* JoystickHandlerAllegro::getJoystick(const int& pIndex) const
	{
		return new JoystickAllegro(pIndex);
	}

	int JoystickHandlerAllegro::getJoystickNumber() const
	{
		return  al_get_num_joysticks();
	}
}}

