#include<gorgon++/input/joystick.hpp>
#include<gorgon++/addon/allegro5/joystick_handler.hpp>
#include<gorgon++/addon/sdl/joystick_handler.hpp>
#include <iostream>
#include <stdlib.h>
using namespace Gorgon;
using namespace Gorgon::Input;
using namespace Gorgon::Addon;
using namespace std;
#include<SDL/SDL.h>
#define DEBUG(x) cout << "DEGUB-" << __LINE__ << ":" << x << endl
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//printf("[%.6d]  %6.0d %6d\n",(int)5,6,7); return 0;
	try
	{
		//JoystickHandlerAllegro::set();
		JoystickHandlerSDL::set();
		const int joyNum = JoystickHandler::get().getJoystickNumber();
		cout << "NUM: " << joyNum << endl;
		Joystick joy;
		bool sair=false;
		int i,j;
		
		sleep(1);
		do
		{
			system("clear");
			cout << joy.getName() << endl;
			
			
			joy.update();
			cout << "doido\n" << joy.getStickNumber() << endl;
			
			for(i = 0; i < joy.getStickNumber(); ++i)
			{	
				Input::Stick stick = joy.getStick(i);
				cout << "Stick" << i << endl;
				
				for(j=0; j < stick.getAxesNumber(); ++j)
				{
					cout << "\tAxis" << j << ": " << stick.getAxis(j) << endl;
				}
			}
			for(i = 0, j = 0; i < joy.getButtonNumber(); ++i)
			{
				cout << "Button" << i << ": " << joy.getButton(i) << "\t";
				if(i%2) cout << endl;
				if(joy.getButton(i)){ ++j; }
			}
			cout << endl;
			if(j>=4) sair = true;
			cout << "To quit, press 4 buttons" << endl;

		}while(!sair);
	}
	catch(...)
	{
		cout << "Conecte algum joystick\n";
	}
	return 0;
}

