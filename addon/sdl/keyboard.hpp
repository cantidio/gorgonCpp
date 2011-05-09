#include <gorgon++/input/keyboard_base.hpp>

namespace Gorgon{
namespace Addon{

	class KeyboardSDL : public KeyboardBase
	{
		public:
			KeyboardSDL();
			~KeyboardSDL();
			virtual Key getKey(const int& pKeyValue) const = 0;
			virtual void update() = 0;
	};
}}
