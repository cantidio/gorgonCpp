#ifndef _GORGON_KEYBOARD_
#define _GORGON_KEYBOARD_
#include "keyboard_base.hpp"
#include "keyboard_handler.hpp"
namespace Gorgon{
namespace Input
{
	class Keyboard
	{
		protected:
			KeyboardBase* mKeyboard;/**<< The implementation of the keyboard*/
		public:
			Keyboard()
			{
				mKeyboard = KeyboardHandler::get().getKeyboard();
			}
			~Keyboard()
			{
				if(mKeyboard != NULL) delete mKeyboard;
			}
			inline Key getKey(const int& pKey) const
			{
				return mKeyboard->getKey(pKey);
			}//return the state of the key
			inline void update()
			{
				mKeyboard->update();
			}
			inline bool isOpened() const
			{
				mKeyboard->isOpened();
			}
	};
}}
#endif
