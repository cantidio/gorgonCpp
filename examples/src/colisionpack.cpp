#include <gorgon++/gorgon.hpp>
using namespace Gorgon;
int main()
{
	allegro_init();
	install_keyboard();
	try
	{
		Video			video = Video::get();
		CollisionPack	acollisionPack;
		CollisionPack	collisionPack;
		Point c1(10,10),c2(150,10);
	
		acollisionPack.add(Collision(0,0));
		acollisionPack(0,0).add(CollisionFrame());
	
		acollisionPack(0,0)[0].add(Rectangle(50,50,Point(0,0)));
		acollisionPack(0,0)[0].add(Rectangle(50,50,Point(60,0)));
		acollisionPack(0,0)[0].add(Rectangle(50,50,Point(0,60)));
		acollisionPack(0,0)[0].add(Rectangle(50,50,Point(60,60)));
	
		acollisionPack.add(Collision(10,0));
		acollisionPack(10,0).add(CollisionFrame());
		acollisionPack(10,0)[0].add(Rectangle(50,50,Point(0,0)));
		acollisionPack(10,0)[0].add(Rectangle(50,50,Point(60,60)));
	
		acollisionPack.save("teste.gcpk");
		collisionPack.load("teste.gcpk");
	
		while(!key[KEY_ESC])
		{
			if(key[KEY_UP])			c1.subY(1);
			else if(key[KEY_DOWN])	c1.addY(1);
			
		
			if(key[KEY_RIGHT])		c1.addX(1);
			else if(key[KEY_LEFT])	c1.subX(1);
	
			if(key[KEY_W])			c2.subY(1);
			else if(key[KEY_S])		c2.addY(1);
			
		
			if(key[KEY_D])			c2.addX(1);
			else if(key[KEY_A])		c2.subX(1);
	
			video.clear();
			collisionPack(0,0)[0].draw(c1,Color(0,255,0),video);
			collisionPack(10,0)[0].draw(c2,Color(255,0,0),video);
		
			if(collisionPack(0,0)[0].colide(collisionPack(10,0)[0],c1,c2))
			{
				video.drawText("Colidiu!",10,10,makecol(255,0,0),-1);
			}
			else
			{
				video.drawText("Não Colidiu!",10,10,makecol(255,255,255),-1);
			}
		
			video.show();
			rest(16);
		}
	}
	catch(Exception e)
	{
		std::cout << e.getMessage() << std::endl;
	}
}

