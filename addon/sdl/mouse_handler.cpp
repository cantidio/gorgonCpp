#include "mouse_handler.hpp"
#include "mouse.hpp"
namespace Gorgon{
namespace Addon
{
	MouseHandlerSDL::MouseHandlerSDL()
	{
		Core::logWrite(Core::String("MouseHandlerSDL::MouseHandlerSDL(): Sucessfull."));
	}
	MouseHandlerSDL::~MouseHandlerSDL()
	{
		Core::logWrite(Core::String("MouseHandlerSDL::~MouseHandlerSDL(): Sucessfull."));
	}
	void MouseHandlerSDL::set()
	{
		static MouseHandlerSDL handler;
		Input::MouseHandler::set(handler);
	}
	MouseBase* MouseHandlerSDL::getMouse() const
	{
		return new MouseSDL();
	}
}}
