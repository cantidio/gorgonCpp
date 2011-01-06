#include "../../include/graphic/gorgon_video.hpp"
#include "../../include/graphic/gorgon_image.hpp"
using namespace Gorgon;
using namespace std;
#define dgb printf("%d\n",__LINE__);

int main()
{
	allegro_init();
	install_keyboard();
	try
	{
		Video::init("Teste da classe Image");//iniciamos a classe de vídeo
		Video video = Video::get();//pegamos um ponteiro para classe de vídeo para mais fácil acesso
		int angle1	= 0;
		int angle2	= 255;

		//criamos 2 imagens de 50 x 30
		Image normal(50,30);
		Image normal1(50,30);

		normal.drawText("Teste",0,0,makecol(0,0,255));	//desenhamos o texto Teste de azul na imagem
		normal1.drawText("Teste",0,0,makecol(255,0,0));	//desenhamos o texto Teste de vermelho na imagem
		while(!key[KEY_ESC])
		{
			video.clear();//limapamos o buffer do vídeo
			video.drawImage(normal,50,50);
			video.drawImage(normal1,150,50);
			for(register int i = 0; i < 5; i++)
			{
				for(register int j = 0; j < 4; j++)
				{
					const int ang = ((i+j)%2) ? angle1 : angle2;
					video.drawImageRoteted(normal1	,80+i*40,70+j*40,ang		);
					video.drawImageRoteted(normal	,80+i*40,70+j*40,ang+128+64	);
					video.drawImageRoteted(normal1	,80+i*40,70+j*40,ang+128	);
					video.drawImageRoteted(normal	,80+i*40,70+j*40,ang+64		);
				}
			}
			video.drawText("Teste da classe Image.",10,0,makecol(255,255,255));
			video.drawText(10,10,makecol(255,255,255),-1,"Angle  : %d",angle1);
			video.drawText(10,20,makecol(255,255,255),-1,"Angle2 : %d",angle2);
			video.show();

			angle1+=2;
			angle2-=2;
			if(angle2<0) angle2=255;
			if(angle1>=255) angle1=0;
		}
	}
	catch(Exception e)
	{
		cout << e.getMessage() << endl;
	}
	return 0;
}END_OF_MAIN()
