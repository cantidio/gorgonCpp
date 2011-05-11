#include "mouse_handler.hpp"
#include "mouse.hpp"
#include <gorgon++/core/gorgon_log.hpp>
#include <gorgon++/core/gorgon_string.hpp>
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
	Input::MouseBase* MouseHandlerSDL::getMouse() const
	{
		return new MouseSDL();
	}
}}
