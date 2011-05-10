#include<gorgon++/gorgon.hpp>
#include<gorgon++/addon/allegro5/keyboard_handler.hpp>
#include<allegro5/allegro.h>
using namespace Gorgon;
using namespace Gorgon::Input;
using namespace Gorgon::Addon;
using namespace std;



int main()
{


	KeyboardHandlerAllegro::set();
	Keyboard a;
	cout << (a.isOpened() ? "opened" : "not opened") << endl;
	
	
	
	while(!a.getKey(Key::ESCAPE).isPressed())
	{
	a.update();
	}
//	al_destroy_display(display);
	return 0;
}
