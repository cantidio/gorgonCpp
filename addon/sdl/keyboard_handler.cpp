#include "keyboard_handler.hpp"
#include "keyboard.hpp"
namespace Gorgon{
namespace Addon
{
	KeyboardHandlerSDL::KeyboardHandlerSDL()
	{
		Core::logWrite(Core::String("KeyboardHandlerSDL::KeyboardHandlerSDL(): Sucessfull."));
	}
	KeyboardHandlerSDL::~KeyboardHandlerSDL()
	{
		Core::logWrite(Core::String("KeyboardHandlerSDL::~KeyboardHandlerSDL(): Sucessfull."));
	}
	void KeyboardHandlerSDL::set()
	{
		static KeyboardHandlerSDL handler;
		Input::KeyboardHandler::set(handler);
	}
	Input::KeyboardBase* KeyboardHandlerSDL::getKeyboard() const
	{
		return new KeyboardSDL();
	}
}}
