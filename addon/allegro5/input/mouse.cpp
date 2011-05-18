#include "mouse.hpp"
#include <gorgon++/core/log.hpp>
#include <gorgon++/core/string.hpp>
#include <allegro5/allegro.h>
namespace Gorgon{
namespace Addon
{
	MouseAllegro::MouseAllegro()
	{
		mState = NULL;
		if(al_install_mouse())
		{
			mState = new ALLEGRO_MOUSE_STATE;
			mButton[Input::MouseBase::LEFT]			= 1;
			mButton[Input::MouseBase::MIDDLE]		= 3;
			mButton[Input::MouseBase::RIGHT]		= 2;
			mButton[Input::MouseBase::WHEEL_UP]		= 4;
			mButton[Input::MouseBase::WHEEL_DOWN]	= 5;
		}
		else
		{
			Core::logWrite(Core::String("MouseAllegro::MouseAllegro(): Error: could not install the mouse driver."));
			throw ("MouseAllegro::MouseAllegro(): Error: could not install the mouse driver.");
		}
	}
	MouseAllegro::~MouseAllegro()
	{
		al_uninstall_mouse();
		if(mState) delete mState;
	}
	void MouseAllegro::update()
	{
		al_get_mouse_state(mState);
		mPosition = Core::Point
		(
			al_get_mouse_state_axis(mState, 0),
			al_get_mouse_state_axis(mState, 1)
		);
		al_set_mouse_z(0);
	}
	bool MouseAllegro::isOpened() const
	{
		return al_is_mouse_installed();
	}
	Core::Point MouseAllegro::getPosition() const
	{
		return mPosition;
	}
	bool MouseAllegro::getButton(const Input::MouseBase::Button& pButton) const
	{
		if(pButton < (Input::MouseBase::WHEEL_UP))
		{
			 return al_mouse_button_down(mState, mButton[pButton]);
		}
		else if(pButton == Input::MouseBase::WHEEL_UP)
		{
			const int z = al_get_mouse_state_axis(mState, 2);
			return (z > 0) ? true : false;
		}
		else if(pButton <= Input::MouseBase::WHEEL_DOWN)
		{
			const int z = al_get_mouse_state_axis(mState, 2);
			return (z < 0) ? true : false;
		}
		return false;
	}
}}
