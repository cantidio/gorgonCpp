#include <gorgon++/gorgon.hpp>

using namespace Gorgon;
using namespace std;
int main()
{
	allegro_init();
	install_keyboard();
	try
	{
		Video				video = Video::get();
		SpritePack			spritePack("../resources/klona.gspk");
		AnimationPack		animationPack;
		AnimationHandler	handler(spritePack,animationPack);
		int angle = 0;
		Mirroring mirroring;
		int x = 25,y = 25;
		
		animationPack.add(Animation(0,0,true));		//animação parado
		animationPack(0,0).add(Frame(0,0,15));
		animationPack(0,0).add(Frame(0,1,15));
		animationPack(0,0).add(Frame(0,2,15));
		animationPack(0,0).add(Frame(0,3,15));
		animationPack(0,0).add(Frame(0,2,15));
		animationPack(0,0).add(Frame(0,1,15));
		
		animationPack.add(Animation(10,0,true));	//animação andando
		animationPack(10,0).add(Frame(0,4,5));
		animationPack(10,0).add(Frame(0,5,5));
		animationPack(10,0).add(Frame(0,6,5));
		animationPack(10,0).add(Frame(0,7,5));
		animationPack(10,0).add(Frame(0,8,5));
		animationPack(10,0).add(Frame(0,9,5));
		animationPack(10,0).add(Frame(0,10,5));
		animationPack(10,0).add(Frame(0,11,5));
		
		animationPack.add(Animation(20,0,true));	//animação pulando
		animationPack(20,0).add(Frame(0,12,5));
		animationPack(20,0).add(Frame(0,13,5));
		animationPack(20,0).add(Frame(0,14,5));
		animationPack(20,0).add(Frame(0,15,5));
		animationPack(20,0).add(Frame(0,16,5));
		
		animationPack.add(Animation(20,1));			//animação caindo
		animationPack(20,1).add(Frame(0,17,5));
		animationPack(20,1).add(Frame(0,18,5));
		animationPack(20,1).add(Frame(0,19,5));
		animationPack(20,1).add(Frame(0,20,5));
		animationPack(20,1).add(Frame(0,21,5));
		animationPack(20,1).add(Frame(0,22,5));
		animationPack(20,1).add(Frame(0,23,5));
		animationPack(20,1).add(Frame(0,24,5));
		animationPack(20,1).add(Frame(0,25,5));
		animationPack(20,1).add(Frame(0,26,5));
		
		handler.optimize();//very important to improve speed

		while(!key[KEY_ESC])
		{
			if(key[KEY_RIGHT] || key[KEY_LEFT])		handler.changeAnimation(10,0);
			else									handler.changeAnimation(0,0);

			if(key[KEY_RIGHT])
			{
				++angle;
				mirroring=Mirroring::Normal;
			}
			else if (key[KEY_LEFT])
			{
				--angle;
				mirroring=Mirroring::HFlip;
			}

			handler.playByStep();
			video.clear();
			for(int i=0; i<10; ++i)
			{
				for(int j=0; j<7; ++j)
				{
					handler.draw(video,x+i*30,y+j*30,mirroring,angle);
				}
			}

			video.show();
			rest(1000);
		}
	}
	catch(Exception e)
	{
		cout << e.getMessage() << endl;
	}
	return 0;
}
