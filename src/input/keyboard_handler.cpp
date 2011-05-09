#include <input/keyboard_handler.hpp>
#include <input/keyboard_base_null.hpp>
namespace Gorgon{
namespace Input
{
	KeyboardHandler* KeyboardHandler::mHandler = NULL;

	KeyboardHandler::KeyboardHandler(){}
	KeyboardHandler::~KeyboardHandler(){}
	KeyboardHandler& KeyboardHandler::get()
	{
		if(mHandler == NULL)
		{
			static KeyboardHandler handler;
			set(handler);
		}
		return *mHandler;
	}

	void KeyboardHandler::set(KeyboardHandler& pHandler)
	{
		//não se deleta o objeto de o mesmo não for NULL, pois os mesmos foram criados de maneira statica
		mHandler = &pHandler;
	}

	KeyboardBase* KeyboardHandler::getKeyboard() const
	{
		return new KeyboardBaseNull();
	}
}}
