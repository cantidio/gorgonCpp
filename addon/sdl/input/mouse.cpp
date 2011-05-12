#include "mouse.hpp"
namespace Gorgon{
namespace Addon
{
	MouseSDL::MouseSDL()
	{
		mButton[Input::MouseBase::LEFT]			= SDL_BUTTON_LEFT;
		mButton[Input::MouseBase::MIDDLE]		= SDL_BUTTON_MIDDLE;
		mButton[Input::MouseBase::RIGHT]		= SDL_BUTTON_RIGHT;
		mButton[Input::MouseBase::WHEEL_UP]		= SDL_BUTTON_WHEELUP;
		mButton[Input::MouseBase::WHEEL_DOWN]	= SDL_BUTTON_WHEELDOWN;
	}
	void MouseSDL::update()
	{
		int x,y;
		SDL_PumpEvents();
		mState = SDL_GetMouseState(&x, &y);
		mPosition = Point(x,y);
	}
	bool MouseSDL::isOpened() const
	{
		return SDL_EventState(SDL_QUERY, SDL_MOUSEMOTION)	&&
			SDL_EventState(SDL_QUERY, SDL_MOUSEBUTTONDOWN)	&&
			SDL_EventState(SDL_QUERY, SDL_MOUSEBUTTONUP);
	}
	Point MouseSDL::getPosition() const
	{
		return mPosition;
	}
	bool MouseSDL::getButton(const Input::MouseBase::Button& pButton) const
	{
		if(pButton < (Input::MouseBase::LAST_BUTTON))
		{
			return (mState & SDL_BUTTON( mButton[pButton] ));
		}
		return false;
	}
}}
