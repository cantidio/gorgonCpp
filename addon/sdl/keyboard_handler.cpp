#include "keyboard_handler.hpp"
#include "keyboard.hpp"
namespace Gorgon{
namespace Addon
{
	KeyboardHandlerSDL::KeyboardHandlerSDL(){}
	KeyboardHandlerSDL::~KeyboardHandlerSDL(){}
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
