#include <addon/allegro5/input/mouse_base.hpp>
#include <allegro5/allegro.h>

namespace Gorgon	{
namespace Allegro5	{
namespace Input
{
	MouseBase::MouseBase()
	{
		mState = new ALLEGRO_MOUSE_STATE;
		mButton[Gorgon::Input::MouseButton::LEFT]		= 1;
		mButton[Gorgon::Input::MouseButton::MIDDLE]		= 3;
		mButton[Gorgon::Input::MouseButton::RIGHT]		= 2;
		mButton[Gorgon::Input::MouseButton::WHEEL_UP]	= 4;
		mButton[Gorgon::Input::MouseButton::WHEEL_DOWN]	= 5;
	}

	MouseBase::~MouseBase()
	{
		if( mState )
		{
			delete mState;
		}
	}

	void MouseBase::update()
	{
		al_get_mouse_state( mState );
		mPosition = Gorgon::Core::Point
		(
			al_get_mouse_state_axis( mState, 0 ),
			al_get_mouse_state_axis( mState, 1 )
		);
		al_set_mouse_z( 0 );
	}

	bool MouseBase::isOpened() const
	{
		return al_is_mouse_installed();
	}

	Core::Point MouseBase::getPosition() const
	{
		return mPosition;
	}

	bool MouseBase::getButton( const Gorgon::Input::MouseButton::Id& pButton ) const
	{
		if( pButton < Gorgon::Input::MouseButton::WHEEL_UP )
		{
			 return al_mouse_button_down( mState, mButton[pButton] );
		}
		else if( pButton == Gorgon::Input::MouseButton::WHEEL_UP )
		{
			const int z = al_get_mouse_state_axis( mState, 2 );
			return ( z > 0 ) ? true : false;
		}
		else if( pButton <= Gorgon::Input::MouseButton::WHEEL_DOWN )
		{
			const int z = al_get_mouse_state_axis( mState, 2 );
			return ( z < 0 ) ? true : false;
		}
		return false;
	}
}}}
