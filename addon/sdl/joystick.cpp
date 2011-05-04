#include "joystick.hpp"
namespace Gorgon{
namespace Addon
{
	JoystickSDL::JoystickSDL(const int& pIndex)
	{
		//SDL_JoystickEventState(SDL_ENABLE);//habilita receber eventos dos joysticks
		mJoystick = SDL_Joystick *SDL_JoystickOpen(mIndex);
		if(mJoystick)//abriu corretamente
		{
			mName			= SDL_JoystickName(mIndex);
			mButtonNumber	= SDL_JoystickNumButtons(mJoystick);
			mStickNumber	= 1 + ;

		}
		else
		{
			throw(0);//lançar uma exception
		}
	}

	JoystickSDL::~JoystickSDL()
	{
		if(isOpened())
		{
			SDL_JoystickClose(mJoystick);
			mJoystick	= NULL;
			mName		= "";
			mButtons	= 0;

		}
	}

	bool JoystickSDL::isOpened() const
	{
		return SDL_JoystickOpened(mIndex) ? true : false;
	}
	void JoystickSDL::update()
	{
		SDL_Event event;
		switch(event.type)
		{
			case SDL_JOYAXISMOTION:
			case SDL_JoyButtonEvent:
			case SDL_JoyHatEvent:
		}
	};
	int JoystickSDL::getJoystickNumber()
	{
		return SDL_NumJoysticks();
	}
}}

