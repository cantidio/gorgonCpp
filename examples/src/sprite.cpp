#include <gorgon++/gorgon.hpp>
#include <gorgon++/addon/image_loader/magick++/gorgon_image_loader.hpp>

using namespace Gorgon;
using namespace std;
int main()
{
	allegro_init();
	install_keyboard();
	try
	{
		ImageLoader::setLoader(new ImageLoaderMagick());
		Video::init("Teste da classe Sprite");
		Video video = Video::get();
		Sprite normal(Image("../resources/pcx24bits.pcx"),0,0,12,47);
		normal.save("sprite.gspr");
		Sprite normal1("sprite.gspr");
		int angle1 = 0;
		int angle2 = 0;
		while(!key[KEY_ESC])
		{
			video.clear();
			for(int i=0; i<5; i++)
			{
				for(int j=0; j<4; j++)
				{
					int ang= ((i+j)%2) ? angle1 : angle2;
					video.drawSpriteRoteted(normal1	,80+i*40,70+j*40,ang		);
					video.drawSpriteRoteted(normal1	,80+i*40,70+j*40,ang+128+64	);
					video.drawSpriteRoteted(normal1	,80+i*40,70+j*40,ang+128	);
					video.drawSpriteRoteted(normal1	,80+i*40,70+j*40,ang+64		);
				}
			}
			//video->drawImageStretched(normal1,20,30,normal1.getWidth(),normal1.getHeight());
			//video->drawImageStretched(normal2,20,90,normal2.getWidth(),normal2.getHeight());
	//		video->drawSpriteRoteted(normal1,80,80,angle1);
		//	video->drawSpriteRoteted(normal1,80,80,angle2);
			video.drawText("Teste da classe Sprite.",10,0,makecol(255,255,255));
			video.drawText(10,10,makecol(255,255,255),-1,"Angle1: %d",angle1);
			video.drawText(10,20,makecol(255,255,255),-1,"Angle2: %d",angle2);
			video.show();
			angle1+=2;
			angle2-=2;
			if(angle2<0)	angle2 = 255;
			if(angle1>=255)	angle1 = 0;
		}
	}
	catch(Core::Exception& e)
	{
		cout << e.what();
	}
	return 0;
}
