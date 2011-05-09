#include "keyboard_base.hpp"

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
				mKeyboard = NULL;
			}
			~Keyboard()
			{
				if(mKeyboard != NULL) delete mKeyboard;
			}
			inline Key getKey(const Key& pKey) const
			{
				return mKeyboard->getKey(pKey);
			}//return the state of the key
			inline void update()
			{
				mKeyboard->update();
			}
	};
}}
