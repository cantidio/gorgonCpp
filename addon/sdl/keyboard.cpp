#include "keyboard.hpp"
#include <SDL/SDL.h>
#include <gorgon++/core/gorgon_log.hpp>
namespace Gorgon{
namespace Addon
{
	//SDLMod* mModState = NULL;
	KeyboardSDL::KeyboardSDL()
	{
		SDL_EnableUNICODE( 1 );
		//SDL_WM_GrabInput(SDL_GRAB_ON);
	//	mModState = new SDLMod;

		SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
		//SDL_EventState(SDL_ENABLE , SDL_KEYDOWN);
		//SDL_EventState(SDL_ENABLE , SDL_KEYUP);

		mState = NULL;
		if(isOpened())//SDL_WM_GrabInput( SDL_GRAB_QUERY ) == SDL_GRAB_ON)
		{
			mKey[Input::Key::A]				= SDLK_a;
			mKey[Input::Key::B]				= SDLK_b;
			mKey[Input::Key::C]				= SDLK_c;
			mKey[Input::Key::D]				= SDLK_d;
			mKey[Input::Key::E]				= SDLK_e;
			mKey[Input::Key::F]				= SDLK_f;
			mKey[Input::Key::G]				= SDLK_g;
			mKey[Input::Key::H]				= SDLK_h;
			mKey[Input::Key::I]				= SDLK_i;
			mKey[Input::Key::J]				= SDLK_j;
			mKey[Input::Key::K]				= SDLK_k;
			mKey[Input::Key::L]				= SDLK_l;
			mKey[Input::Key::M]				= SDLK_m;
			mKey[Input::Key::N]				= SDLK_n;
			mKey[Input::Key::O]				= SDLK_o;
			mKey[Input::Key::P]				= SDLK_p;
			mKey[Input::Key::Q]				= SDLK_q;
			mKey[Input::Key::R]				= SDLK_r;
			mKey[Input::Key::S]				= SDLK_s;
			mKey[Input::Key::T]				= SDLK_t;
			mKey[Input::Key::U]				= SDLK_u;
			mKey[Input::Key::V]				= SDLK_v;
			mKey[Input::Key::W]				= SDLK_w;
			mKey[Input::Key::X]				= SDLK_x;
			mKey[Input::Key::Y]				= SDLK_y;
			mKey[Input::Key::Z]				= SDLK_z;
			mKey[Input::Key::NUM_0]			= SDLK_0;
			mKey[Input::Key::NUM_1]			= SDLK_1;
			mKey[Input::Key::NUM_2]			= SDLK_2;
			mKey[Input::Key::NUM_3]			= SDLK_3;
			mKey[Input::Key::NUM_4]			= SDLK_4;
			mKey[Input::Key::NUM_5]			= SDLK_5;
			mKey[Input::Key::NUM_6]			= SDLK_6;
			mKey[Input::Key::NUM_7]			= SDLK_7;
			mKey[Input::Key::NUM_8]			= SDLK_8;
			mKey[Input::Key::NUM_9]			= SDLK_9;
			mKey[Input::Key::PAD_0]			= SDLK_KP0;
			mKey[Input::Key::PAD_1]			= SDLK_KP1;
			mKey[Input::Key::PAD_2]			= SDLK_KP2;
			mKey[Input::Key::PAD_3]			= SDLK_KP3;
			mKey[Input::Key::PAD_4]			= SDLK_KP4;
			mKey[Input::Key::PAD_5]			= SDLK_KP5;
			mKey[Input::Key::PAD_6]			= SDLK_KP6;
			mKey[Input::Key::PAD_7]			= SDLK_KP7;
			mKey[Input::Key::PAD_8]			= SDLK_KP8;
			mKey[Input::Key::PAD_9]			= SDLK_KP9;
			mKey[Input::Key::F1]			= SDLK_F1;
			mKey[Input::Key::F2]			= SDLK_F2;
			mKey[Input::Key::F3]			= SDLK_F3;
			mKey[Input::Key::F4]			= SDLK_F4;
			mKey[Input::Key::F5]			= SDLK_F5;
			mKey[Input::Key::F6]			= SDLK_F6;
			mKey[Input::Key::F7]			= SDLK_F7;
			mKey[Input::Key::F8]			= SDLK_F8;
			mKey[Input::Key::F9]			= SDLK_F9;
			mKey[Input::Key::F10]			= SDLK_F10;
			mKey[Input::Key::F11]			= SDLK_F11;
			mKey[Input::Key::F12]			= SDLK_F12;
			mKey[Input::Key::ESCAPE]		= SDLK_ESCAPE;
			mKey[Input::Key::MINUS]			= SDLK_MINUS;
			mKey[Input::Key::EQUALS]		= SDLK_EQUALS;
			mKey[Input::Key::BACKSPACE]		= SDLK_BACKSPACE;
			mKey[Input::Key::TAB]			= SDLK_TAB;
			mKey[Input::Key::OPENBRACE]		= SDLK_LEFTBRACKET;
			mKey[Input::Key::CLOSEBRACE]	= SDLK_RIGHTBRACKET;
			mKey[Input::Key::ENTER]			= SDLK_RETURN;/**@todo verificar se o return é o enter msm*/
			mKey[Input::Key::SEMICOLON]		= SDLK_SEMICOLON;
			mKey[Input::Key::QUOTE]			= SDLK_QUOTE;
			mKey[Input::Key::BACKSLASH]		= SDLK_BACKSLASH;
			mKey[Input::Key::COMMA]			= SDLK_COMMA;
			mKey[Input::Key::SLASH]			= SDLK_SLASH;
			mKey[Input::Key::SPACE]			= SDLK_SPACE;
			mKey[Input::Key::PRINT_SCREEN]	= SDLK_PRINT;
			mKey[Input::Key::PAUSE]			= SDLK_PAUSE;
			mKey[Input::Key::INSERT]		= SDLK_INSERT;
			mKey[Input::Key::DELETE]		= SDLK_DELETE;
			mKey[Input::Key::HOME]			= SDLK_HOME;
			mKey[Input::Key::END]			= SDLK_END;
			mKey[Input::Key::PAGE_UP]		= SDLK_PAGEUP;
			mKey[Input::Key::PAGE_DOWN]		= SDLK_PAGEDOWN;
			mKey[Input::Key::LEFT]			= SDLK_LEFT;
			mKey[Input::Key::RIGHT]			= SDLK_RIGHT;
			mKey[Input::Key::UP]			= SDLK_UP;
			mKey[Input::Key::DOWN]			= SDLK_DOWN;
			mKey[Input::Key::PAD_SLASH]		= SDLK_KP_DIVIDE;
			mKey[Input::Key::PAD_MINUS]		= SDLK_KP_MINUS;
			mKey[Input::Key::PAD_PLUS]		= SDLK_KP_PLUS;
			mKey[Input::Key::PAD_ASTERISK]	= SDLK_KP_MULTIPLY;
			mKey[Input::Key::PAD_EQUALS]	= SDLK_KP_EQUALS;
			mKey[Input::Key::PAD_DELETE]	= SDLK_DELETE;//NOT AN KP
			mKey[Input::Key::PAD_ENTER]		= SDLK_KP_ENTER;
			mKey[Input::Key::MENU]			= SDLK_MENU;
			mKey[Input::Key::SCROLL_LOCK]	= SDLK_SCROLLOCK;
			mKey[Input::Key::LEFT_WIN]		= SDLK_LSUPER;
			mKey[Input::Key::RIGHT_WIN]		= SDLK_RSUPER;

			//MODIFICADORES
			mKey[Input::Key::RIGHT_CONTROL]	= KMOD_RCTRL;
			mKey[Input::Key::LEFT_CONTROL]	= KMOD_LCTRL;
			mKey[Input::Key::RIGHT_SHIFT]	= KMOD_RSHIFT;
			mKey[Input::Key::LEFT_SHIFT]	= KMOD_LSHIFT;
			mKey[Input::Key::RIGHT_ALT]		= KMOD_RALT;
			mKey[Input::Key::LEFT_ALT]		= KMOD_LALT;
			mKey[Input::Key::NUM_LOCK]		= KMOD_NUM;
			mKey[Input::Key::CAPS_LOCK]		= KMOD_CAPS;
		}
		else
		{
			throw ("KeyboardSDL::KeyboardSDL(): Error: could not install the keyboard driver.");
		}
	}

	KeyboardSDL::~KeyboardSDL()
	{

	}

	bool KeyboardSDL::isOpened() const
	{
		return SDL_EventState(SDL_QUERY , SDL_KEYUP) && SDL_EventState(SDL_QUERY , SDL_KEYDOWN);
		//return (SDL_WM_GrabInput( SDL_GRAB_QUERY ) == SDL_GRAB_ON) ? true : false;
	}

	void KeyboardSDL::update()
	{
		SDL_PumpEvents();
		mState		= SDL_GetKeyState(NULL);
		mModState	= SDL_GetModState();
	}

	Input::Key KeyboardSDL::getKey(const int& pKeyValue) const
	{
		switch(pKeyValue)
		{
			case Input::Key::LEFT_CONTROL:	case Input::Key::RIGHT_CONTROL:
			case Input::Key::LEFT_SHIFT:	case Input::Key::RIGHT_SHIFT:
			case Input::Key::LEFT_ALT:		case Input::Key::RIGHT_ALT:
			case Input::Key::CAPS_LOCK:		case Input::Key::NUM_LOCK:
				return  Input::Key(pKeyValue, (((mModState & pKeyValue) == pKeyValue) ? true : false));
			default:
				if(mState != NULL)
				{
					return  Input::Key(pKeyValue, (mState[mKey[pKeyValue]] ? true : false));
				}
				else
				{
					return Input::Key(pKeyValue,false);
				}
		}
	}
}}
