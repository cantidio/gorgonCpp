#include <gorgon++/gorgon.hpp>
#include <gorgon++/addon/sdl/mouse_handler.hpp>
#include <gorgon++/addon/allegro5/mouse_handler.hpp>
#include <iostream>
#include <SDL/SDL.h>
#include <allegro5/allegro.h>
using namespace Gorgon;
using namespace Gorgon::Input;
using namespace Gorgon::Addon;
using namespace std;

ALLEGRO_DISPLAY *display = NULL;

bool initAllegro()
{
	if(!al_init())	return false;
	display = al_create_display(640, 480);
	if(!display)	return false;
	MouseHandlerAllegro::set();
	return true;
}
void closeAllegro()
{
	al_destroy_display(display);
}
bool initSDL()
{
	if( SDL_Init( SDL_INIT_VIDEO ) < 0)			return false;
    if( !SDL_SetVideoMode( 640, 480, 0, 0 ) )	return false;
    MouseHandlerSDL::set();
}
void closeSDL()
{
	SDL_Quit();
}
int main()
{
	initAllegro();
	
	Mouse a;
	Point pos;
	cout << (a.isOpened() ? "opened" : "not opened") << endl;
	while(!a.getButton(MouseBase::LEFT))
	{
		pos = a.getPosition();
//		pos.describe();
		a.update();
	}
	closeAllegro();
	return 0;
}
