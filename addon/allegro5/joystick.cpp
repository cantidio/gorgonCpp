#include "joystick.hpp"
namespace Gorgon{
namespace Addon
{
	JoystickAllegro::JoystickAllegro(const int& pIndex) : Joystick(pIndex)
	{
		al_install_joystick();
		mJoystick	= al_get_joystick(mIndex);
		if(mJoystick)//abriu corretamente
		{
			mName			= al_get_joystick_name(mJoystick);
			mButtonNumber	= al_get_joystick_num_buttons(mJoystick);
			mStickNumber	= al_get_joystick_num_sticks(mJoystick);
		}
		else
		{
			throw (0);
		}
	}

	JoystickAllegro::~JoystickAllegro()
	{
		 al_release_joystick(mJoystick);
	}

	bool JoystickAllegro::isOpened()
	{
		return al_get_joystick_active(mJoystick);
	}

	void JoystickAllegro::update()
	{
		al_get_joystick_state(mJoystick, mJoystickState);
	}

	int JoystickAllegro::getJoystickNumber()
	{
		return al_get_num_joysticks();
	}

	Stick JoystickAllegro::getStick(const int& pStick) const
	{
		const int axesNumber = al_get_joystick_num_axes(mJoystick, pStick);
		Stick stick( axesNumber);
		for(register int i = 0; i < axesNumber; ++i)
		{
			stick.setAxis(i, mJoystickState.stick[pStick].axis[i]);
		}
		return stick;
	}

	float JoystickAllegro::getButton(const int& pButtonIndex) const
	{
		return (pButtonIndex < mButtonNumber) ? mJoystickState->button[pButtonIndex] : 0;
	}

}}
