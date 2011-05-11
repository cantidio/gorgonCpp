#include<gorgon++/gorgon.hpp>
#include<gorgon++/addon/allegro5/keyboard_handler.hpp>
#include<gorgon++/addon/sdl/keyboard_handler.hpp>
#include<allegro5/allegro.h>
#include<SDL/SDL.h>
using namespace Gorgon;
using namespace Gorgon::Input;
using namespace Gorgon::Addon;
using namespace std;

int main()
{
	try
	{
		 if( SDL_Init( SDL_INIT_VIDEO ) < 0)
		 {
            fprintf( stderr, "Could not initialise SDL: %s\n", SDL_GetError() );
            exit( -1 );
        }


        if( !SDL_SetVideoMode( 320, 200, 0, 0 ) ){
            fprintf( stderr, "Could not set video mode: %s\n", SDL_GetError() );
            SDL_Quit();
            exit( -1 );
            }
	
	
	
		KeyboardHandlerSDL::set();
		Keyboard a;
		cout << (a.isOpened() ? "opened" : "not opened") << endl;
	
	
	
		while(!a.getKey(Key::ESCAPE).isPressed())
		{
			a.update();
		}
	//	al_destroy_display(display);
	}
	catch(const char* a)
	{
		cout << "BUG: " << a << endl;
	}
	return 0;
}
