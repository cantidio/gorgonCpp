#include "keyboard_key.hpp"
namespace Gorgon{
namespace Input
{
	class KeyboardBase
	{
		protected:
			static const int mKeysNumber = Key::KEY_LAST;/**<< the numbers of keys in the the keyboard*/
			int	mKey[Key::KEY_LAST];/**<< the array of the keys*/
		public:
			/**
			 * Method that returns if the keyboard is opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/05/2011
			 * @version	07/05/2011
			 * @return	bool
			 */
			virtual bool isOpened() const	= 0;
			virtual Key getKey(const int& pKeyValue) const = 0;
			virtual void update() = 0;
	};
}}
