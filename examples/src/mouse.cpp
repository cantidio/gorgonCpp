#include<gorgon++/gorgon.hpp>
#include<gorgon++/addon/sdl/mouse_handler.hpp>
#include<iostream>
#include<SDL/SDL.h>
using namespace Gorgon;
using namespace Gorgon::Input;
using namespace Gorgon::Addon;
using namespace std;
int main()
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
	MouseHandlerSDL::set();
	Mouse a;
	Point pos;
	cout << (a.isOpened() ? "opened" : "not opened") << endl;
	while(!a.getButton(MouseBase::LEFT))
	{
		pos = a.getPosition();
//		pos.describe();
		a.update();
	}
	return 0;
}
