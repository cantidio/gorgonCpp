#include "keyboard.hpp"
#include <allegro5/allegro.h>
#include <gorgon++/core/gorgon_log.hpp>
namespace Gorgon{
namespace Addon
{
	KeyboardAllegro::KeyboardAllegro()
	{
		mState = new ALLEGRO_KEYBOARD_STATE;
		if(al_install_keyboard())
		{
			mKey[Input::Key::A]				= ALLEGRO_KEY_A;
			mKey[Input::Key::B]				= ALLEGRO_KEY_B;
			mKey[Input::Key::C]				= ALLEGRO_KEY_C;
			mKey[Input::Key::D]				= ALLEGRO_KEY_D;
			mKey[Input::Key::E]				= ALLEGRO_KEY_E;
			mKey[Input::Key::F]				= ALLEGRO_KEY_F;
			mKey[Input::Key::G]				= ALLEGRO_KEY_G;
			mKey[Input::Key::H]				= ALLEGRO_KEY_H;
			mKey[Input::Key::I]				= ALLEGRO_KEY_I;
			mKey[Input::Key::J]				= ALLEGRO_KEY_J;
			mKey[Input::Key::K]				= ALLEGRO_KEY_K;
			mKey[Input::Key::L]				= ALLEGRO_KEY_L;
			mKey[Input::Key::M]				= ALLEGRO_KEY_M;
			mKey[Input::Key::N]				= ALLEGRO_KEY_N;
			mKey[Input::Key::O]				= ALLEGRO_KEY_O;
			mKey[Input::Key::P]				= ALLEGRO_KEY_P;
			mKey[Input::Key::Q]				= ALLEGRO_KEY_Q;
			mKey[Input::Key::R]				= ALLEGRO_KEY_R;
			mKey[Input::Key::S]				= ALLEGRO_KEY_S;
			mKey[Input::Key::T]				= ALLEGRO_KEY_T;
			mKey[Input::Key::U]				= ALLEGRO_KEY_U;
			mKey[Input::Key::V]				= ALLEGRO_KEY_V;
			mKey[Input::Key::W]				= ALLEGRO_KEY_W;
			mKey[Input::Key::X]				= ALLEGRO_KEY_X;
			mKey[Input::Key::Y]				= ALLEGRO_KEY_Y;
			mKey[Input::Key::Z]				= ALLEGRO_KEY_Z;
			mKey[Input::Key::NUM_1]			= ALLEGRO_KEY_1;
			mKey[Input::Key::NUM_2]			= ALLEGRO_KEY_2;
			mKey[Input::Key::NUM_3]			= ALLEGRO_KEY_3;
			mKey[Input::Key::NUM_4]			= ALLEGRO_KEY_4;
			mKey[Input::Key::NUM_5]			= ALLEGRO_KEY_5;
			mKey[Input::Key::NUM_6]			= ALLEGRO_KEY_6;
			mKey[Input::Key::NUM_7]			= ALLEGRO_KEY_7;
			mKey[Input::Key::NUM_8]			= ALLEGRO_KEY_8;
			mKey[Input::Key::NUM_9]			= ALLEGRO_KEY_9;
			mKey[Input::Key::NUM_0]			= ALLEGRO_KEY_0;
			mKey[Input::Key::PAD_1]			= ALLEGRO_KEY_PAD_1;
			mKey[Input::Key::PAD_2]			= ALLEGRO_KEY_PAD_2;
			mKey[Input::Key::PAD_3]			= ALLEGRO_KEY_PAD_3;
			mKey[Input::Key::PAD_4]			= ALLEGRO_KEY_PAD_4;
			mKey[Input::Key::PAD_5]			= ALLEGRO_KEY_PAD_5;
			mKey[Input::Key::PAD_6]			= ALLEGRO_KEY_PAD_6;
			mKey[Input::Key::PAD_7]			= ALLEGRO_KEY_PAD_7;
			mKey[Input::Key::PAD_8]			= ALLEGRO_KEY_PAD_8;
			mKey[Input::Key::PAD_9]			= ALLEGRO_KEY_PAD_9;
			mKey[Input::Key::PAD_0]			= ALLEGRO_KEY_PAD_0;
			mKey[Input::Key::F1]			= ALLEGRO_KEY_F1;
			mKey[Input::Key::F2]			= ALLEGRO_KEY_F2;
			mKey[Input::Key::F3]			= ALLEGRO_KEY_F3;
			mKey[Input::Key::F4]			= ALLEGRO_KEY_F4;
			mKey[Input::Key::F5]			= ALLEGRO_KEY_F5;
			mKey[Input::Key::F6]			= ALLEGRO_KEY_F6;
			mKey[Input::Key::F7]			= ALLEGRO_KEY_F7;
			mKey[Input::Key::F8]			= ALLEGRO_KEY_F8;
			mKey[Input::Key::F9]			= ALLEGRO_KEY_F9;
			mKey[Input::Key::F10]			= ALLEGRO_KEY_F10;
			mKey[Input::Key::F11]			= ALLEGRO_KEY_F11;
			mKey[Input::Key::F12]			= ALLEGRO_KEY_F12;
			mKey[Input::Key::ESCAPE]		= ALLEGRO_KEY_ESCAPE;
			mKey[Input::Key::MINUS]			= ALLEGRO_KEY_MINUS;
			mKey[Input::Key::EQUALS]		= ALLEGRO_KEY_EQUALS;
			mKey[Input::Key::BACKSPACE]		= ALLEGRO_KEY_BACKSPACE;
			mKey[Input::Key::TAB]			= ALLEGRO_KEY_TAB;
			mKey[Input::Key::OPENBRACE]		= ALLEGRO_KEY_OPENBRACE;
			mKey[Input::Key::CLOSEBRACE]	= ALLEGRO_KEY_CLOSEBRACE;
			mKey[Input::Key::ENTER]			= ALLEGRO_KEY_ENTER;
			mKey[Input::Key::SEMICOLON]		= ALLEGRO_KEY_SEMICOLON;
			mKey[Input::Key::QUOTE]			= ALLEGRO_KEY_QUOTE;
			mKey[Input::Key::BACKSLASH]		= ALLEGRO_KEY_BACKSLASH;
			mKey[Input::Key::COMMA]			= ALLEGRO_KEY_COMMA;
			mKey[Input::Key::SLASH]			= ALLEGRO_KEY_SLASH;
			mKey[Input::Key::SPACE]			= ALLEGRO_KEY_SPACE;
			mKey[Input::Key::PRINT_SCREEN]	= ALLEGRO_KEY_PRINTSCREEN;
			mKey[Input::Key::PAUSE]			= ALLEGRO_KEY_PAUSE;
			mKey[Input::Key::INSERT]		= ALLEGRO_KEY_INSERT;
			mKey[Input::Key::DELETE]		= ALLEGRO_KEY_DELETE;
			mKey[Input::Key::HOME]			= ALLEGRO_KEY_HOME;
			mKey[Input::Key::END]			= ALLEGRO_KEY_END;
			mKey[Input::Key::PAGE_UP]		= ALLEGRO_KEY_PGUP;
			mKey[Input::Key::PAGE_DOWN]		= ALLEGRO_KEY_PGDN;
			mKey[Input::Key::LEFT]			= ALLEGRO_KEY_LEFT;
			mKey[Input::Key::RIGHT]			= ALLEGRO_KEY_RIGHT;
			mKey[Input::Key::UP]			= ALLEGRO_KEY_UP;
			mKey[Input::Key::DOWN]			= ALLEGRO_KEY_DOWN;
			mKey[Input::Key::PAD_SLASH]		= ALLEGRO_KEY_PAD_SLASH;
			mKey[Input::Key::PAD_MINUS]		= ALLEGRO_KEY_PAD_MINUS;
			mKey[Input::Key::PAD_PLUS]		= ALLEGRO_KEY_PAD_PLUS;
			mKey[Input::Key::PAD_ASTERISK]	= ALLEGRO_KEY_PAD_ASTERISK;
			mKey[Input::Key::PAD_EQUALS]	= ALLEGRO_KEY_EQUALS;
			mKey[Input::Key::PAD_DELETE]	= ALLEGRO_KEY_PAD_DELETE;
			mKey[Input::Key::PAD_ENTER]		= ALLEGRO_KEY_PAD_ENTER;
			mKey[Input::Key::RIGHT_CONTROL]	= ALLEGRO_KEY_RCTRL;
			mKey[Input::Key::LEFT_CONTROL]	= ALLEGRO_KEY_LCTRL;
			mKey[Input::Key::RIGHT_SHIFT]	= ALLEGRO_KEY_RSHIFT;
			mKey[Input::Key::LEFT_SHIFT]	= ALLEGRO_KEY_LSHIFT;
			mKey[Input::Key::RIGHT_ALT]		= ALLEGRO_KEY_ALTGR;
			mKey[Input::Key::LEFT_ALT]		= ALLEGRO_KEY_ALT;
			mKey[Input::Key::LEFT_WIN]		= ALLEGRO_KEY_LWIN;
			mKey[Input::Key::RIGHT_WIN]		= ALLEGRO_KEY_RWIN;
			mKey[Input::Key::MENU]			= ALLEGRO_KEY_MENU;
			mKey[Input::Key::SCROOL_LOCK]	= ALLEGRO_KEY_SCROLLLOCK;
			mKey[Input::Key::NUM_LOCK]		= ALLEGRO_KEY_NUMLOCK;
			mKey[Input::Key::CAPS_LOCK]		= ALLEGRO_KEY_CAPSLOCK;
		}
		else
		{
			throw ("KeyboardAllegro::KeyboardAllegro(): Error: could not install the keyboard driver.");
		}
	}

	KeyboardAllegro::~KeyboardAllegro()
	{
		if(mState)
		{
			delete mState;
		}
	}

	bool KeyboardAllegro::isOpened() const
	{
		return al_is_keyboard_installed();
	}

	void KeyboardAllegro::update()
	{
		al_get_keyboard_state(mState);
	}

	Input::Key KeyboardAllegro::getKey(const int& pKeyValue) const
	{
		return Input::Key(pKeyValue, al_key_down(mState, mKey[pKeyValue]));
	}
}}
