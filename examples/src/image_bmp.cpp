#include <gorgon++/gorgon.hpp>

using namespace Gorgon;
using namespace std;
int main()
{
	allegro_init();
	install_keyboard();
	try
	{
		Video::init("Teste da classe ImageBmp");
		Video video = Video::get();

		int angle1 = 0;
		int angle2 = 255;
		Image normal("../resources/bmp8bits.bmp",ImageFormatBmp());
		while(!key[KEY_ESC])
		{
			video.clear();
			for(register int i = 0; i < 5; i++)
			{
				for(register int j = 0; j < 4; j++)
				{
					const int ang= ((i+j)%2) ? angle1 : angle2;
					video.drawImageRoteted(normal,80+i*40,70+j*40,ang);
					video.drawImageRoteted(normal,80+i*40,70+j*40,ang+128+64);
					video.drawImageRoteted(normal,80+i*40,70+j*40,ang+128);
					video.drawImageRoteted(normal,80+i*40,70+j*40,ang+64);
				}
			}
			video.drawText("Teste da classe ImageBmp.",10,0,0xFFFFFF);
			video.drawText(10,10,0xFFFFFF,-1,"Angle : %d",angle1);
			video.drawText(10,20,0xFFFFFF,-1,"Angle2: %d",angle2);
			video.show();
			angle1+=2;
			angle2-=2;
			if(angle2<0)	angle2=255;
			if(angle1>=255)	angle1=0;
		}
	}
	catch(Exception e)
	{
		cout << e.getMessage() << endl;
	}
	return 0;
}END_OF_MAIN()
