#include <addon/sdl/input/mouse_base.hpp>

namespace Gorgon {
namespace Input  {
namespace Addon
{
	MouseBase::MouseBase()
	{
		mButton[MouseButton::LEFT]			= SDL_BUTTON_LEFT;
		mButton[MouseButton::MIDDLE]		= SDL_BUTTON_MIDDLE;
		mButton[MouseButton::RIGHT]			= SDL_BUTTON_RIGHT;
		mButton[MouseButton::WHEEL_UP]		= SDL_BUTTON_WHEELUP;
		mButton[MouseButton::WHEEL_DOWN]	= SDL_BUTTON_WHEELDOWN;
	}

	void MouseBase::update()
	{
		int x,y;
		SDL_PumpEvents();
		mState = SDL_GetMouseState(&x, &y);
		mPosition = Core::Point(x,y);
	}

	bool MouseBase::isOpened() const
	{
		return SDL_EventState(SDL_QUERY, SDL_MOUSEMOTION)	&&
			SDL_EventState(SDL_QUERY, SDL_MOUSEBUTTONDOWN)	&&
			SDL_EventState(SDL_QUERY, SDL_MOUSEBUTTONUP);
	}

	Core::Point MouseBase::getPosition() const
	{
		return mPosition;
	}

	bool MouseBase::getButton(const MouseButton::Id& pButton) const
	{
		if(pButton < (MouseButton::LAST_BUTTON))
		{
			return (mState & SDL_BUTTON( mButton[pButton] ));
		}
		return false;
	}
}}}
