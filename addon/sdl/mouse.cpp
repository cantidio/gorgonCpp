#include "mouse.hpp"
namespace Gorgon{
namespace Addon
{
	void MouseSDL::update()
	{
		//http://www.libsdl.org/docs/html/eventfunctions.html
		//http://www.libsdl.org/docs/html/sdlgetmousestate.html
		//http://www.libsdl.org/docs/html/sdlgetrelativemousestate.html
		//http://www.libsdl.org/docs/html/sdlevent.html
		//http://lazyfoo.net/SDL_tutorials/lesson09/index.php
		SDL_PumpEvents();
		SDL_GetMouseState(int *x, int *y);
		//SDL_BUTTON_LEFT, SDL_BUTTON_MIDDLE, SDL_BUTTON_RIGHT, SDL_BUTTON_WHEELUP, SDL_BUTTON_WHEELDOWN
	}
	bool MouseSDL::isOpened() const
	{

	}
	Point MouseSDL::getPosition() const
	{

	}
	bool MouseSDL::getButton(const int& pButton) const
	{

	}
}}
