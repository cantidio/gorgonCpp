#include "../../include/graphic/gorgon_video.hpp"

using namespace Gorgon;
using namespace std;
int main()
{
	allegro_init();
	install_keyboard();
	try
	{
		Video::init("Teste da classe ImagePcx");
		Video	video	= Video::get();
		int 	angle	= 0;
		int 	angle2	= 255;
		Image	normal("../resources/pcx8bits.pcx",ImageFormatPcx());
		stringstream *text;

		while(!key[KEY_ESC])
		{
			video.clear();
			for(register int i = 0; i < 5; i++)
			{
				for(register int j = 0; j < 4; j++)
				{
					const int ang= ((i+j)%2) ? angle : angle2;
					video.drawImageRoteted(normal,80+i*40,70+j*40,ang);
					video.drawImageRoteted(normal,80+i*40,70+j*40,ang+128+64);
					video.drawImageRoteted(normal,80+i*40,70+j*40,ang+128);
					video.drawImageRoteted(normal,80+i*40,70+j*40,ang+64);
				}
			}
			video.drawText("Teste da classe ImagePcx",10,0,makecol(255,255,255));
			video.drawText(10,10,makecol(255,255,255),-1,"Angle:  %d",angle);
			video.drawText(10,20,makecol(255,255,255),-1,"Angle2: %d",angle2);
			video.show();
	
			angle++;
			angle2--;
			if(angle2==-1) angle2=255;
			if(angle==255) angle=0;
		}
	}
	catch(Exception e)
	{
		cout << e.getMessage() << endl;
	}
	return 0;
}
