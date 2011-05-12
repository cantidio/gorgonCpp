#include "mouse_handler.hpp"
#include "mouse.hpp"
#include <gorgon++/core/gorgon_log.hpp>
#include <gorgon++/core/gorgon_string.hpp>
namespace Gorgon{
namespace Addon
{
	MouseHandlerAllegro::MouseHandlerAllegro()
	{
		Core::logWrite(Core::String("MouseHandlerAllegro::MouseHandlerAllegro(): Sucessfull."));
	}
	MouseHandlerAllegro::~MouseHandlerAllegro()
	{
		Core::logWrite(Core::String("MouseHandlerAllegro::~MouseHandlerAllegro(): Sucessfull."));
	}
	void MouseHandlerAllegro::set()
	{
		static MouseHandlerAllegro handler;
		Input::MouseHandler::set(handler);
	}
	Input::MouseBase* MouseHandlerAllegro::getMouse() const
	{
		return new MouseAllegro();
	}
}}
