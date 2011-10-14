#include <addon/allegro5/input/joystick_base.hpp>
#include <input/exception.hpp>
#include <allegro5/allegro.h>
#include <stdio.h>

namespace Gorgon	{
namespace Allegro5	{
namespace Input
{
	JoystickBase::JoystickBase( const int& pIndex ) : Gorgon::Input::JoystickBase( pIndex )
	{
		mJoystickState	= new ALLEGRO_JOYSTICK_STATE;
		mJoystick		= al_get_joystick(mIndex);
		if( mJoystick )	//abriu corretamente
		{
			mName			= al_get_joystick_name(mJoystick);
			mButtonNumber	= al_get_joystick_num_buttons(mJoystick);
			mStickNumber	= al_get_joystick_num_sticks(mJoystick);
			update();
		}
		else
		{
			raiseInputException( "Input::Addon::JoystickBase::JoystickBase(): Error, couldn't get the requested Allegro5 joystick." );
		}
	}

	JoystickBase::~JoystickBase()
	{
		delete mJoystickState;
		al_release_joystick( mJoystick );
	}

	bool JoystickBase::isOpened() const
	{
		return al_get_joystick_active( mJoystick );
	}

	void JoystickBase::update()
	{
		al_get_joystick_state( mJoystick, mJoystickState );
	}

	Gorgon::Input::Stick JoystickBase::getStick( const int& pStick ) const
	{
		const int axesNumber = al_get_joystick_num_axes( mJoystick, pStick );
		Gorgon::Input::Stick stick( axesNumber );
		for( register int i = 0; i < axesNumber; ++i )
		{
			stick.setAxis( i, mJoystickState->stick[pStick].axis[i] );
		}
		return stick;
	}

	float JoystickBase::getButton(const int& pButtonIndex) const
	{
		return ( pButtonIndex < mButtonNumber ) ? mJoystickState->button[pButtonIndex] : 0;
	}

}}}
