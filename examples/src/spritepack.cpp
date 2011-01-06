#include <gorgon++/gorgon.hpp>

using namespace Gorgon;
using namespace std;
int main()
{
	allegro_init();
	install_keyboard();
	try
	{
		Video::init("Teste da classe SpritePack",640,480);
		Video		video = Video::get();
		//SpritePack	gspk(ImagePcx("../resources/tileset2.pcx"),16,16);//59
		SpritePack	gspk(Image("../resources/alucard.pcx"),0xFF00FF);//59
		printf("saiu\n");
		int counter = 0;

		while(!key[KEY_ESC])
		{
			video.clear();
			/*video.drawSpriteStretched(gspk[counter],96,57,1,1);
			video.drawSpriteFlipped(gspk[counter],96,57,Mirroring::Normal);
			video.drawSpriteFlipped(gspk[counter],96,57,Mirroring::HFlip);
			video.drawSpriteFlipped(gspk[counter],96,57,Mirroring::VFlip);
			video.drawSpriteFlipped(gspk[counter],96,57,Mirroring::HVFlip);*/
			video.drawSpriteFlipped(gspk[counter],96,57,Mirroring::Normal);
			
			
			video.drawText("Gorgon Tile View",10,10,0xFFFFFF);	
			video.drawText(10,30,0xFFFFFF,-1,"Group: %d",gspk[counter].getGroup());
			video.drawText(10,40,0xFFFFFF,-1,"Index: %d",gspk[counter].getIndex());
			video.drawText(10,50,0xFFFFFF,-1,"Width: %d",gspk[counter].getWidth());	
			video.drawText(10,60,0xFFFFFF,-1,"Height: %d",gspk[counter].getHeight());
			video.drawText(10,70,0xFFFFFF,-1,"xOffset: %d",gspk[counter].getXOffset());
			video.drawText(10,80,0xFFFFFF,-1,"yOffset: %d",gspk[counter].getYOffset());
			video.drawText(10,90,0xFFFFFF,-1,"counter: %d",counter);
			video.show();

			if(key[KEY_RIGHT])	++counter;
			if(key[KEY_LEFT])	--counter;
	
			key[KEY_DOWN]=key[KEY_UP]=key[KEY_LEFT]=key[KEY_RIGHT]=key[KEY_ENTER]=0;

			if(counter >= gspk.getSize())	counter = 0;
			else if(counter<0)				counter = gspk.getSize() - 1;
		}
		gspk.save("../resources/explode.sprPk");
	}
	catch(Exception e)
	{
		cout << e.getMessage() << endl;
	}
}
