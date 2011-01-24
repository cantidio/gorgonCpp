#include <gorgon++/gorgon.hpp>
#include <gorgon++/addon/image_loader/magick++/gorgon_image_loader.hpp>

using namespace Gorgon;
using namespace std;
void usageMSG()
{
	printf("opções Disponíveis:\n");
	printf("\t-image      [image.bmp]\n");
	printf("\t-spritepack [spritepack.gspk]\n");
	printf("\t-script     [script.lua]\n\n");
}
int main(int argc, char** argv)
{
	allegro_init();
	install_keyboard();

	try
	{
		ImageLoader::setLoader(new ImageLoaderMagick());
		Video::init("Teste da classe SpritePack",640,480);
		Video		video = Video::get();
		SpritePack	gspk;
		if(argc > 2)
		{
			if(std::string(argv[1]).compare("-image") == 0)
			{
				gspk = SpritePack(Image(argv[2]),0xFF0000);
			}
			else if(std::string(argv[1]).compare("-spritepack") == 0)
			{
				gspk.load(argv[2]);
			}
			else if(std::string(argv[1]).compare("-script") == 0)
			{
				gspk.loadScript(argv[2]);
			}
			else
			{
				printf("opções erradas!\n");
				usageMSG();
				return 0;
			}
		}
		else
		{
			usageMSG();
			return 0;
		}

		int counter = 0;

		while(!key[KEY_ESC])
		{
			video.clear();
			video.blitSpriteStretched(gspk[counter],165,200,4,4);
			video.drawRectangle(165,200,168,204,0xFFFFFF,true);
			
			video.drawText("Gorgon SpritePack View",10,10,0xFFFFFF);
			video.drawText(10,30,0xFFFFFF,-1,"Group: %d",gspk[counter].getGroup());
			video.drawText(10,40,0xFFFFFF,-1,"Index: %d",gspk[counter].getIndex());
			video.drawText(10,50,0xFFFFFF,-1,"Width: %d",gspk[counter].getWidth());	
			video.drawText(10,60,0xFFFFFF,-1,"Height: %d",gspk[counter].getHeight());
			video.drawText(10,70,0xFFFFFF,-1,"xOffset: %d",gspk[counter].getXOffset());
			video.drawText(10,80,0xFFFFFF,-1,"yOffset: %d",gspk[counter].getYOffset());
			video.drawText(10,90,0xFFFFFF,-1,"counter: %d",counter);
			video.show();

			if(key[KEY_LCONTROL])
			{
				if(key[KEY_S])
				{
					std::string file1;
					std::string file2;

					printf("Digite o nome do spritepack a ser salvo:\n");
					cin >> file1;
					file2 = file1;

					file1.append(".lua");
					file2.append(".gspk");
					printf("salvando.\n");
					gspk.saveScript(file1);
					gspk.save(file2);
					printf("ok\n");
				}
				else if(key[KEY_T])
				{
					printf("trim sprite\n");
					gspk[counter].clipNoBorder();
				}
				if(key[KEY_UP])
				{
					gspk[counter].setYOffset(gspk[counter].getYOffset() - 1);
				}
				else if (key[KEY_DOWN])
				{
					gspk[counter].setYOffset(gspk[counter].getYOffset() + 1);
				}
				if(key[KEY_RIGHT])
				{
					gspk[counter].setXOffset(gspk[counter].getXOffset() + 1);
				}
				else if (key[KEY_LEFT])
				{
					gspk[counter].setXOffset(gspk[counter].getXOffset() - 1);
				}
			}
			else
			{
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
			}
	
			key[KEY_S]=key[KEY_T]=key[KEY_DOWN]=key[KEY_UP]=key[KEY_LEFT]=key[KEY_RIGHT]=key[KEY_ENTER]=0;
		}
	}
	catch(Core::Exception& e)
	{
		cout << e.getMessage() << endl;
	}
	return 0;
}
