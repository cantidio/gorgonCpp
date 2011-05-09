#include <gorgon++/input/keyboard_base.hpp>
//#include <gorgon++/input/keyboard_key.hpp>
struct ALLEGRO_KEYBOARD_STATE;
namespace Gorgon{
namespace Addon
{

	class KeyboardAllegro : public Input::KeyboardBase
	{
		protected:
			ALLEGRO_KEYBOARD_STATE* mState;
		public:
			KeyboardAllegro();
			virtual ~KeyboardAllegro();
			virtual bool isOpened() const;
			virtual void update();
			virtual Input::Key getKey(const int& pKeyValue) const;
	};
}}
