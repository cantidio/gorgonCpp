#include<gorgon++/gorgon.hpp>
#include<gorgon++/addon/allegro5/keyboard_handler.hpp>
using namespace Gorgon;
using namespace Gorgon::Input;
using namespace Gorgon::Addon;
int main()
{
	KeyboardHandlerAllegro::set();
	Keyboard a;
	
	return 0;
}
