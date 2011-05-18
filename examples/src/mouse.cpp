#include <gorgon++/gorgon.hpp>
#include <gorgon++/addon/sdl/input/mouse_handler.hpp>
#include <gorgon++/addon/allegro5/input/mouse_handler.hpp>
#include <iostream>
#include <SDL/SDL.h>
#include <allegro5/allegro.h>
using namespace Gorgon;
using namespace Gorgon::Input;
using namespace Gorgon::Core;
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
    return true;
}
void closeSDL()
{
	SDL_Quit();
}
int main()
{
	initSDL();
	
	Mouse a;
	Point pos;
	cout << (a.isOpened() ? "opened" : "not opened") << endl;
	while(!a.getButton(MouseBase::LEFT))
	{
		a.update();
		if(a.getButton(MouseBase::WHEEL_UP))
		{
			cout << "Wheel up"  << endl;
		}
		else if(a.getButton(MouseBase::WHEEL_DOWN))
		{
			cout << "Wheel down"  << endl;
		}
		pos = a.getPosition();
//		pos.describe();
	}
	closeSDL();
	return 0;
}
