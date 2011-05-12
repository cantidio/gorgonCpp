#include "keyboard_handler.hpp"
#include "keyboard.hpp"
#include <allegro5/allegro.h>
#include <gorgon++/core/gorgon_log.hpp>
#include <gorgon++/core/gorgon_string.hpp>
namespace Gorgon{
namespace Addon
{
	KeyboardHandlerAllegro::KeyboardHandlerAllegro()
	{
		if( !(al_init() && al_install_keyboard()) )
		{
			Core::logWrite(Core::String("KeyboardHandlerAllegro::KeyboardHandlerAllegro(): Error, could not open Handler."));
			throw("Couldn't create allegro5 keyboard handler.");
		}
		Core::logWrite(Core::String("KeyboardHandlerAllegro::KeyboardHandlerAllegro(): Sucessfull."));
	}

	KeyboardHandlerAllegro::~KeyboardHandlerAllegro()
	{
		al_uninstall_keyboard();
		Core::logWrite(Core::String("KeyboardHandlerAllegro::~KeyboardHandlerAllegro()\n"));
	}

	void KeyboardHandlerAllegro::set()
	{
		static KeyboardHandlerAllegro handler;
		Input::KeyboardHandler::set(handler);
	}

	Input::KeyboardBase* KeyboardHandlerAllegro::getKeyboard() const
	{
		return new KeyboardAllegro();
	}
}}

