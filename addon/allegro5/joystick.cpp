#include "joystick.hpp"
#include <allegro5/allegro.h>

#include <stdio.h>
namespace Gorgon{
namespace Addon
{
	JoystickAllegro::JoystickAllegro(const int& pIndex) : JoystickBase(pIndex)
	{
		mJoystickState = new ALLEGRO_JOYSTICK_STATE;
		if(al_init() && al_install_joystick())
		{
			mJoystick	= al_get_joystick(mIndex);
			if(mJoystick)//abriu corretamente
			{
				mName			= al_get_joystick_name(mJoystick);
				mButtonNumber	= al_get_joystick_num_buttons(mJoystick);
				mStickNumber	= al_get_joystick_num_sticks(mJoystick);
				update();
			}
			else
			{
				throw ("Conecte algum joystick");
			}
		}
		else
		{
			throw ("error ao iniciar a bagaça");
		}
	}

	JoystickAllegro::~JoystickAllegro()
	{
		delete mJoystickState;
		al_release_joystick(mJoystick);
	}

	bool JoystickAllegro::isOpened() const
	{
		return al_get_joystick_active(mJoystick);
	}

	void JoystickAllegro::update()
	{
		al_get_joystick_state(mJoystick, mJoystickState);
	}

	Input::Stick JoystickAllegro::getStick(const int& pStick) const
	{
		const int axesNumber = al_get_joystick_num_axes(mJoystick, pStick);
		Input::Stick stick( axesNumber );
		for(register int i = 0; i < axesNumber; ++i)
		{
			stick.setAxis(i, mJoystickState->stick[pStick].axis[i]);
		}
		return stick;
	}

	float JoystickAllegro::getButton(const int& pButtonIndex) const
	{
		return (pButtonIndex < mButtonNumber) ? mJoystickState->button[pButtonIndex] : 0;
	}

}}
