#include <addon/allegro5/input/mouse_base.hpp>
#include <allegro5/allegro.h>

namespace Gorgon	{
namespace Input		{
namespace Addon
{
	MouseBase::MouseBase()
	{
		mState = new ALLEGRO_MOUSE_STATE;
		mButton[MouseButton::LEFT]			= 1;
		mButton[MouseButton::MIDDLE]		= 3;
		mButton[MouseButton::RIGHT]			= 2;
		mButton[MouseButton::WHEEL_UP]		= 4;
		mButton[MouseButton::WHEEL_DOWN]	= 5;
	}

	MouseBase::~MouseBase()
	{
		if(mState)
		{
			delete mState;
		}
	}

	void MouseBase::update()
	{
		al_get_mouse_state(mState);
		mPosition = Core::Point
		(
			al_get_mouse_state_axis(mState, 0),
			al_get_mouse_state_axis(mState, 1)
		);
		al_set_mouse_z(0);
	}

	bool MouseBase::isOpened() const
	{
		return al_is_mouse_installed();
	}

	Core::Point MouseBase::getPosition() const
	{
		return mPosition;
	}

	bool MouseBase::getButton(const MouseButton::Id& pButton) const
	{
		if(pButton < (MouseButton::WHEEL_UP))
		{
			 return al_mouse_button_down(mState, mButton[pButton]);
		}
		else if(pButton == MouseButton::WHEEL_UP)
		{
			const int z = al_get_mouse_state_axis(mState, 2);
			return (z > 0) ? true : false;
		}
		else if(pButton <= MouseButton::WHEEL_DOWN)
		{
			const int z = al_get_mouse_state_axis(mState, 2);
			return (z < 0) ? true : false;
		}
		return false;
	}
}}}
