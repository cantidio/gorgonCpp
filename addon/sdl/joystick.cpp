#include "joystick.hpp"

namespace Gorgon{
namespace Addon
{
	JoystickSDL::JoystickSDL(const int& pIndex)
	{
		//SDL_JoystickEventState(SDL_ENABLE);//habilita receber eventos dos joysticks
		mJoystick = SDL_JoystickOpen(mIndex);

		if(mJoystick)//abriu corretamente
		{
			const int axes	= SDL_JoystickNumAxes(mJoystick);
			const int hats	= SDL_JoystickNumHats(mJoystick);
			mButtonNumber	= SDL_JoystickNumButtons(mJoystick);
			mName			= SDL_JoystickName(mIndex);
			mStickNumber	= ((axes>0)?1:0) + ((hats>0)?1:0);
		}
		else
		{
			throw ("Conecte algum joystick");
		}
	}

	JoystickSDL::~JoystickSDL()
	{
		if(isOpened())
		{
			SDL_JoystickClose(mJoystick);
		}
	}

	bool JoystickSDL::isOpened() const
	{
		return SDL_JoystickOpened(mIndex) ? true : false;
	}

	void JoystickSDL::update()
	{
		SDL_JoystickUpdate();
	};

	Input::Stick JoystickSDL::getStick(const int& pStick) const
	{
		const int hats = SDL_JoystickNumHats(mJoystick);
		const int axes = (SDL_JoystickNumAxes(mJoystick)>3) ? 3 : SDL_JoystickNumAxes(mJoystick);
		/**@todo SDL just suport 3 axes in a joystick, fix it ok*/
		if(pStick == 0 && (hats>0))// (mStickNumber-1))//SDL
		{
			Input::Stick stick( hats );

			for(register int i = 0; i < hats; ++i)
			{
				stick.setAxis(i, SDL_JoystickGetHat(mJoystick,i));
			}
			return stick;
		}
		else if(axes>0)
		{
			Input::Stick stick( axes );
			for(register int i = 0; i < axes; ++i)
			{
				float axis = SDL_JoystickGetAxis(mJoystick,i)/32768.f;
				stick.setAxis(i, axis);
			}
			return stick;
		}
		else
		{
			return Input::Stick(0);
		}
	}

	float JoystickSDL::getButton(const int& pButtonIndex) const
	{
		return (pButtonIndex < mButtonNumber) ? SDL_JoystickGetButton(mJoystick, pButtonIndex) : 0;
	}
}}
