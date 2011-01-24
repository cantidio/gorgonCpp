#include <gorgon++/gorgon.hpp>
#include <gorgon++/addon/image_loader/magick++/gorgon_image_loader.hpp>
#include <gorgon++/addon/image_loader/gorgon++/include/gorgon_image_loader_autodetect.hpp>

using namespace Gorgon;
using namespace std;
int main(int srgc, char** argv)
{
	allegro_init();
	install_keyboard();

	try
	{
		//ImageLoader::setLoader(new ImageLoaderAutodetect());
		ImageLoader::setLoader(new ImageLoaderMagick());
		Video::init("Teste da classe SpritePack",640,480);
		Video		video = Video::get();
		//SpritePack	gspk(ImagePcx("../resources/tileset2.pcx"),16,16);//59

		//SpritePack	gspk(Image("../resources/klona_48x48.pcx"),0xFF0000);
		SpritePack	gspk;

		gspk.loadScript("teste/teste.lua");////59
		//gspk.saveScript("teste.lua");
		//gspk.save("teste.gspk");

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
			video.drawImageStretched
			(
				(Image)gspk[counter],
				165,
				197,
				2 * gspk[counter].getWidth(),
				2 * gspk[counter].getHeight()
			);

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

			if(key[KEY_RIGHT])
			{
				++counter;
				if(counter >= gspk.getSize())
					counter = 0;
			}
			else if(key[KEY_LEFT])
			{
				--counter;
				if(counter < 0)
					counter = gspk.getSize() - 1;
			}
	
			key[KEY_DOWN]=key[KEY_UP]=key[KEY_LEFT]=key[KEY_RIGHT]=key[KEY_ENTER]=0;
		}
	}
	catch(Core::Exception& e)
	{
		cout << e.getMessage() << endl;
	}
	return 0;
}
