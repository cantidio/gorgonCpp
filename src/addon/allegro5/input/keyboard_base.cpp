#include <addon/allegro5/input/keyboard_base.hpp>
#include <input/keyboard_key.hpp>
#include <core/log.hpp>
#include <allegro5/allegro.h>

namespace Gorgon	{
namespace Allegro5	{
namespace Input
{
	KeyboardBase::KeyboardBase()
	{
		mState									= new ALLEGRO_KEYBOARD_STATE;
		mKey[Gorgon::Input::Key::A]				= ALLEGRO_KEY_A;
		mKey[Gorgon::Input::Key::B]				= ALLEGRO_KEY_B;
		mKey[Gorgon::Input::Key::C]				= ALLEGRO_KEY_C;
		mKey[Gorgon::Input::Key::D]				= ALLEGRO_KEY_D;
		mKey[Gorgon::Input::Key::E]				= ALLEGRO_KEY_E;
		mKey[Gorgon::Input::Key::F]				= ALLEGRO_KEY_F;
		mKey[Gorgon::Input::Key::G]				= ALLEGRO_KEY_G;
		mKey[Gorgon::Input::Key::H]				= ALLEGRO_KEY_H;
		mKey[Gorgon::Input::Key::I]				= ALLEGRO_KEY_I;
		mKey[Gorgon::Input::Key::J]				= ALLEGRO_KEY_J;
		mKey[Gorgon::Input::Key::K]				= ALLEGRO_KEY_K;
		mKey[Gorgon::Input::Key::L]				= ALLEGRO_KEY_L;
		mKey[Gorgon::Input::Key::M]				= ALLEGRO_KEY_M;
		mKey[Gorgon::Input::Key::N]				= ALLEGRO_KEY_N;
		mKey[Gorgon::Input::Key::O]				= ALLEGRO_KEY_O;
		mKey[Gorgon::Input::Key::P]				= ALLEGRO_KEY_P;
		mKey[Gorgon::Input::Key::Q]				= ALLEGRO_KEY_Q;
		mKey[Gorgon::Input::Key::R]				= ALLEGRO_KEY_R;
		mKey[Gorgon::Input::Key::S]				= ALLEGRO_KEY_S;
		mKey[Gorgon::Input::Key::T]				= ALLEGRO_KEY_T;
		mKey[Gorgon::Input::Key::U]				= ALLEGRO_KEY_U;
		mKey[Gorgon::Input::Key::V]				= ALLEGRO_KEY_V;
		mKey[Gorgon::Input::Key::W]				= ALLEGRO_KEY_W;
		mKey[Gorgon::Input::Key::X]				= ALLEGRO_KEY_X;
		mKey[Gorgon::Input::Key::Y]				= ALLEGRO_KEY_Y;
		mKey[Gorgon::Input::Key::Z]				= ALLEGRO_KEY_Z;
		mKey[Gorgon::Input::Key::NUM_1]			= ALLEGRO_KEY_1;
		mKey[Gorgon::Input::Key::NUM_2]			= ALLEGRO_KEY_2;
		mKey[Gorgon::Input::Key::NUM_3]			= ALLEGRO_KEY_3;
		mKey[Gorgon::Input::Key::NUM_4]			= ALLEGRO_KEY_4;
		mKey[Gorgon::Input::Key::NUM_5]			= ALLEGRO_KEY_5;
		mKey[Gorgon::Input::Key::NUM_6]			= ALLEGRO_KEY_6;
		mKey[Gorgon::Input::Key::NUM_7]			= ALLEGRO_KEY_7;
		mKey[Gorgon::Input::Key::NUM_8]			= ALLEGRO_KEY_8;
		mKey[Gorgon::Input::Key::NUM_9]			= ALLEGRO_KEY_9;
		mKey[Gorgon::Input::Key::NUM_0]			= ALLEGRO_KEY_0;
		mKey[Gorgon::Input::Key::PAD_1]			= ALLEGRO_KEY_PAD_1;
		mKey[Gorgon::Input::Key::PAD_2]			= ALLEGRO_KEY_PAD_2;
		mKey[Gorgon::Input::Key::PAD_3]			= ALLEGRO_KEY_PAD_3;
		mKey[Gorgon::Input::Key::PAD_4]			= ALLEGRO_KEY_PAD_4;
		mKey[Gorgon::Input::Key::PAD_5]			= ALLEGRO_KEY_PAD_5;
		mKey[Gorgon::Input::Key::PAD_6]			= ALLEGRO_KEY_PAD_6;
		mKey[Gorgon::Input::Key::PAD_7]			= ALLEGRO_KEY_PAD_7;
		mKey[Gorgon::Input::Key::PAD_8]			= ALLEGRO_KEY_PAD_8;
		mKey[Gorgon::Input::Key::PAD_9]			= ALLEGRO_KEY_PAD_9;
		mKey[Gorgon::Input::Key::PAD_0]			= ALLEGRO_KEY_PAD_0;
		mKey[Gorgon::Input::Key::F1]			= ALLEGRO_KEY_F1;
		mKey[Gorgon::Input::Key::F2]			= ALLEGRO_KEY_F2;
		mKey[Gorgon::Input::Key::F3]			= ALLEGRO_KEY_F3;
		mKey[Gorgon::Input::Key::F4]			= ALLEGRO_KEY_F4;
		mKey[Gorgon::Input::Key::F5]			= ALLEGRO_KEY_F5;
		mKey[Gorgon::Input::Key::F6]			= ALLEGRO_KEY_F6;
		mKey[Gorgon::Input::Key::F7]			= ALLEGRO_KEY_F7;
		mKey[Gorgon::Input::Key::F8]			= ALLEGRO_KEY_F8;
		mKey[Gorgon::Input::Key::F9]			= ALLEGRO_KEY_F9;
		mKey[Gorgon::Input::Key::F10]			= ALLEGRO_KEY_F10;
		mKey[Gorgon::Input::Key::F11]			= ALLEGRO_KEY_F11;
		mKey[Gorgon::Input::Key::F12]			= ALLEGRO_KEY_F12;
		mKey[Gorgon::Input::Key::ESCAPE]		= ALLEGRO_KEY_ESCAPE;
		mKey[Gorgon::Input::Key::MINUS]			= ALLEGRO_KEY_MINUS;
		mKey[Gorgon::Input::Key::EQUALS]		= ALLEGRO_KEY_EQUALS;
		mKey[Gorgon::Input::Key::BACKSPACE]		= ALLEGRO_KEY_BACKSPACE;
		mKey[Gorgon::Input::Key::TAB]			= ALLEGRO_KEY_TAB;
		mKey[Gorgon::Input::Key::OPENBRACE]		= ALLEGRO_KEY_OPENBRACE;
		mKey[Gorgon::Input::Key::CLOSEBRACE]	= ALLEGRO_KEY_CLOSEBRACE;
		mKey[Gorgon::Input::Key::ENTER]			= ALLEGRO_KEY_ENTER;
		mKey[Gorgon::Input::Key::SEMICOLON]		= ALLEGRO_KEY_SEMICOLON;
		mKey[Gorgon::Input::Key::QUOTE]			= ALLEGRO_KEY_QUOTE;
		mKey[Gorgon::Input::Key::BACKSLASH]		= ALLEGRO_KEY_BACKSLASH;
		mKey[Gorgon::Input::Key::COMMA]			= ALLEGRO_KEY_COMMA;
		mKey[Gorgon::Input::Key::SLASH]			= ALLEGRO_KEY_SLASH;
		mKey[Gorgon::Input::Key::SPACE]			= ALLEGRO_KEY_SPACE;
		mKey[Gorgon::Input::Key::PRINT_SCREEN]	= ALLEGRO_KEY_PRINTSCREEN;
		mKey[Gorgon::Input::Key::PAUSE]			= ALLEGRO_KEY_PAUSE;
		mKey[Gorgon::Input::Key::INSERT]		= ALLEGRO_KEY_INSERT;
		mKey[Gorgon::Input::Key::DEL]			= ALLEGRO_KEY_DELETE;
		mKey[Gorgon::Input::Key::HOME]			= ALLEGRO_KEY_HOME;
		mKey[Gorgon::Input::Key::END]			= ALLEGRO_KEY_END;
		mKey[Gorgon::Input::Key::PAGE_UP]		= ALLEGRO_KEY_PGUP;
		mKey[Gorgon::Input::Key::PAGE_DOWN]		= ALLEGRO_KEY_PGDN;
		mKey[Gorgon::Input::Key::LEFT]			= ALLEGRO_KEY_LEFT;
		mKey[Gorgon::Input::Key::RIGHT]			= ALLEGRO_KEY_RIGHT;
		mKey[Gorgon::Input::Key::UP]			= ALLEGRO_KEY_UP;
		mKey[Gorgon::Input::Key::DOWN]			= ALLEGRO_KEY_DOWN;
		mKey[Gorgon::Input::Key::PAD_SLASH]		= ALLEGRO_KEY_PAD_SLASH;
		mKey[Gorgon::Input::Key::PAD_MINUS]		= ALLEGRO_KEY_PAD_MINUS;
		mKey[Gorgon::Input::Key::PAD_PLUS]		= ALLEGRO_KEY_PAD_PLUS;
		mKey[Gorgon::Input::Key::PAD_ASTERISK]	= ALLEGRO_KEY_PAD_ASTERISK;
		mKey[Gorgon::Input::Key::PAD_EQUALS]	= ALLEGRO_KEY_EQUALS;
		mKey[Gorgon::Input::Key::PAD_DELETE]	= ALLEGRO_KEY_PAD_DELETE;
		mKey[Gorgon::Input::Key::PAD_ENTER]		= ALLEGRO_KEY_PAD_ENTER;
		mKey[Gorgon::Input::Key::RIGHT_CONTROL]	= ALLEGRO_KEY_RCTRL;
		mKey[Gorgon::Input::Key::LEFT_CONTROL]	= ALLEGRO_KEY_LCTRL;
		mKey[Gorgon::Input::Key::RIGHT_SHIFT]	= ALLEGRO_KEY_RSHIFT;
		mKey[Gorgon::Input::Key::LEFT_SHIFT]	= ALLEGRO_KEY_LSHIFT;
		mKey[Gorgon::Input::Key::RIGHT_ALT]		= ALLEGRO_KEY_ALTGR;
		mKey[Gorgon::Input::Key::LEFT_ALT]		= ALLEGRO_KEY_ALT;
		mKey[Gorgon::Input::Key::LEFT_WIN]		= ALLEGRO_KEY_LWIN;
		mKey[Gorgon::Input::Key::RIGHT_WIN]		= ALLEGRO_KEY_RWIN;
		mKey[Gorgon::Input::Key::MENU]			= ALLEGRO_KEY_MENU;
		mKey[Gorgon::Input::Key::SCROLL_LOCK]	= ALLEGRO_KEY_SCROLLLOCK;
		mKey[Gorgon::Input::Key::NUM_LOCK]		= ALLEGRO_KEY_NUMLOCK;
		mKey[Gorgon::Input::Key::CAPS_LOCK]		= ALLEGRO_KEY_CAPSLOCK;
	}

	KeyboardBase::~KeyboardBase()
	{
		if( mState )
		{
			delete mState;
		}
	}

	bool KeyboardBase::isOpened() const
	{
		return al_is_keyboard_installed();
	}

	void KeyboardBase::update()
	{
		al_get_keyboard_state( mState );
	}

	Gorgon::Input::Key KeyboardBase::getKey( const int& pKeyValue ) const
	{
		return Gorgon::Input::Key( pKeyValue, al_key_down( mState, mKey[pKeyValue] ) );
	}
}}}
