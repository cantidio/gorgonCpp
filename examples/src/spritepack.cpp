#include <gorgon++/gorgon.hpp>
#include <gorgon++/addon/image_loader/magick++/gorgon_image_loader.hpp>
#include <gorgon++/addon/sdl/graphic/image_loader.hpp>
#include <gorgon++/addon/spritepack/spritepack_lua.hpp>
#include <gorgon++/addon/spritepack/spritesheet.hpp>
#include <gorgon++/addon/image_loader/gorgon++/include/gorgon_image_loader_autodetect.hpp>
const int X=320;
const int Y=240;
int zoom=1;
using namespace Gorgon;
using namespace Gorgon::Core;
using namespace Gorgon::Addon;
using namespace Gorgon::Graphic;
using namespace std;

void usageMSG()
{
	printf("opções Disponíveis:\n");
	printf("\t-image      [image.bmp]\n");
	printf("\t-spritepack [spritepack.gspk]\n");
	printf("\t-script     [script.lua]\n\n");
}

void showCommands()
{
	printf("Commands:\n");
	printf("Geral Functions:\n");
	printf("\tNext Sprite:                  Right\n");
	printf("\tPrev Sprite:                  Left\n");
	printf("\tSave:                         Ctrl + S\n");

	printf("\tTrim All:                     Ctrl + t");
	printf("\tToogle Transparence:          Ctrl + Q\n");
	printf("\tMark Sprite To Onion Skins:   Ctrl + 1\n");
	printf("\tZoom +:                       Ctrl + -\n");
	printf("\tZoom -:                       Ctrl + =\n\n");

	printf("Sprite Functions:\n");
	printf("\tAlign Sprite:                 Ctrl + Arrows\n");
	printf("\tSub SpriteGroup:              Shift + Up\n");
	printf("\tAdd SpriteGroup:              Shift + Down\n");
	printf("\tSub SpriteIndex:              Shift + Left\n");
	printf("\tAdd SpriteIndex:              Shift + Right\n");
	printf("\tTrim Sprite:                  Shift + t\n");

}
void createAnimationPack(const SpritePack& pSpritePack)
{
	AnimationPack animation;
//	animation.add(Animation(j,0,false));
	for(int i = 1; i < pSpritePack.getSize(); ++i)
	{

	}
}

int main(int argc, char** argv)
{
	allegro_init();
	install_keyboard();
	bool trans = false;
	try
	{
//		ImageLoader::setLoader(new ImageLoaderMagick());
		ImageLoader::setLoader(new ImageLoaderSDL());
		ImageLoader::getLoader().setSaveFormat("PNG");
		//ImageLoader::setLoader(new Gorgon::ImageLoaderAutodetect());
		Video::init("Teste da classe SpritePack",640,480);
		
		Video		video = Video::get();
		SpritePack	gspk;
		if(argc > 2)
		{
			if(std::string(argv[1]).compare("-image") == 0)
			{
				gspk = SpriteSheet(Image(argv[2]),0xFF0000);
			}
			else if(std::string(argv[1]).compare("-spritepack") == 0)
			{
				gspk.load(argv[2]);
			}
			else if(std::string(argv[1]).compare("-script") == 0)
			{
				gspk = SpritePackLua(argv[2]);
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
		showCommands();
		

		Sprite buffer(Image(640,480));
		int counter		= 0;
		int onionIndex	= 0;
		while(!key[KEY_ESC])
		{
			buffer.clear();
			buffer.drawSpriteTrans(gspk[onionIndex],Point(X,Y),0.5);
			(trans) ? buffer.drawSprite(gspk[counter],Point(X,Y)) : buffer.blitSprite(gspk[counter],Point(X,Y));
			buffer.drawRectangle(Point(X-1,Y-1),Point(X+1,Y+1),0xFFFFFF,true);//draw a hot spot
			video.clear();

			video.blitSpriteStretched(buffer,Point(-X * (zoom-1),-Y * (zoom-1)),zoom,zoom);

			video.drawText("Gorgon SpritePack View",10,10,0xFFFFFF);
			video.drawText(Point(10,30),0xFFFFFF,-1,"Width:   %d",gspk[counter].getWidth());
			video.drawText(Point(10,40),0xFFFFFF,-1,"Height:  %d",gspk[counter].getHeight());
			video.drawText(Point(10,50),0xFFFFFF,-1,"Group:   %d",gspk[counter].getGroup());
			video.drawText(Point(10,60),0xFFFFFF,-1,"Index:   %d",gspk[counter].getIndex());
			video.drawText(Point(10,70),0xFFFFFF,-1,"xOffset: %d",gspk[counter].getOffset().getX());
			video.drawText(Point(10,80),0xFFFFFF,-1,"yOffset: %d",gspk[counter].getOffset().getY());
			video.drawText(Point(10,90),0xFFFFFF,-1,"counter: %d",counter);
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
					printf("salvando...");
					SpritePackLua a(gspk);
					a.save(file1);
					gspk.save(file2);
					printf("[ok]\n");
				}
				else if(key[KEY_T])
				{
					printf("trim sprite all\n");
					for(int i = 0; i < gspk.getSize(); ++i)
					{
						gspk[i].clipNoBorder();
					}
					printf("%d sprites trimmed.\n",gspk.getSize());
				}
				else if(key[KEY_Q])
				{
					printf("toogle transparence\n");
					trans = trans ? false : true;
				}
				else if(key[KEY_1])
				{
					printf("mark sprite %d to onion skin.\n",counter);
					onionIndex = counter;
				}
				else if(key[KEY_MINUS])
				{
					--zoom;
				}
				else if(key[KEY_EQUALS])
				{
					++zoom;
				}
				if(key[KEY_UP])
				{
					gspk[counter].setOffset( gspk[counter].getOffset() - Point(0,1) );
				}
				else if (key[KEY_DOWN])
				{
					gspk[counter].setOffset( gspk[counter].getOffset() + Point(0,1) );
				}
				if(key[KEY_RIGHT])
				{
					gspk[counter].setOffset( gspk[counter].getOffset() + Point(1,0) );
				}
				else if (key[KEY_LEFT])
				{
					gspk[counter].setOffset( gspk[counter].getOffset() - Point(1,0) );
				}
			}
			else if(key[KEY_LSHIFT])
			{
				if(key[KEY_UP])
				{
					gspk[counter].setGroup(gspk[counter].getGroup() - 1);
				}
				else if (key[KEY_DOWN])
				{
					gspk[counter].setGroup(gspk[counter].getGroup() + 1);
				}
				else if(key[KEY_LEFT])
				{
					gspk[counter].setIndex(gspk[counter].getIndex() - 1);
				}
				else if (key[KEY_RIGHT])
				{
					gspk[counter].setIndex(gspk[counter].getIndex() + 1);
				}
				else if(key[KEY_T])
				{
					printf("trim sprite\n");
					gspk[counter].clipNoBorder();
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

			key[KEY_MINUS]=key[KEY_EQUALS]=key[KEY_1]=key[KEY_S]=key[KEY_Q]=key[KEY_T]=key[KEY_DOWN]=key[KEY_UP]=key[KEY_LEFT]=key[KEY_RIGHT]=key[KEY_ENTER]=0;
		}
	}
	catch(Core::Exception& e)
	{
		cout << e.getMessage() << endl;
	}
	return 0;
}
