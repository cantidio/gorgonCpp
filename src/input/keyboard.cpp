#include <input/keyboard.hpp>
#include <input/keyboard_base.hpp>
#include <input/system.hpp>

namespace Gorgon{
namespace Input
{

	Keyboard::Keyboard()
	{
		mKeyboard = System::get().getKeyboard();
	}

	Keyboard::~Keyboard()
	{
		if(mKeyboard != NULL)
		{
			delete mKeyboard;
		}
	}

	Key Keyboard::getKey(const int& pKey) const
	{
		return mKeyboard->getKey(pKey);
	}

	void Keyboard::update()
	{
		mKeyboard->update();
	}

	bool Keyboard::isOpened() const
	{
		return mKeyboard->isOpened();
	}
}}
