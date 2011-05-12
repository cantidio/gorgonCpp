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
			mStickNumber	= ((axes>0)?1:0) + hats;
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
		const int axes = (SDL_JoystickNumAxes(mJoystick)>2) ? 2 : SDL_JoystickNumAxes(mJoystick);
		/**@todo SDL just suport 3 axes in a joystick, fix it ok*/
		if(pStick < hats)// (mStickNumber-1))//SDL
		{
			Input::Stick stick( 2 );
			Uint8 hat = SDL_JoystickGetHat(mJoystick,pStick);
			if((hat & SDL_HAT_LEFT) == SDL_HAT_LEFT)		stick.setAxis(0, -1);//x
			else if((hat & SDL_HAT_RIGHT) == SDL_HAT_RIGHT)	stick.setAxis(0, 1);//x
			else											stick.setAxis(0, 0);//x

			if((hat & SDL_HAT_UP) == SDL_HAT_UP)			stick.setAxis(1, -1);//y
			else if((hat & SDL_HAT_DOWN) == SDL_HAT_DOWN)	stick.setAxis(1, 1);//y
			else											stick.setAxis(1, 0);//y

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
