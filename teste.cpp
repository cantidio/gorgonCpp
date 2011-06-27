#include <iostream>
#include <gorgon++/addon/allegro5/graphic/system.hpp>
#include <gorgon++/addon/allegro5/input/system.hpp>
#include <gorgon++/addon/spritepack/tilesheet.hpp>
#include <gorgon++/addon/spritepack/spritepack_sff.hpp>
#include <gorgon++/gorgon.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace Gorgon;
using namespace Gorgon::Graphic;
using namespace Gorgon::Graphic::Addon;
using namespace Gorgon::Core;
using namespace Gorgon::Input;

const int width = 1280;
const int height = 720;

int main()
{
	try
	{
		Graphic::Addon::System::set();
		Input::Addon::System::set();

		Display display("TESTE GORGON Framework rev 211", width, height);

		Keyboard keyboard;
		Mouse mouse;

		time_t starttime, endtime;
		time( &starttime );
		//SpritePack sprites("caveira_vermelha.gspk");
		SpritePack sprites("/home/cantidio/Dropbox/mugen/char/foxy.gsp");

		//TileSheet sprites(Image("/home/cantidio/Development/gorgon++_plugin/examples/resources/klona_48x48.png"),46,46,1);

		//SpritePackSff sprites("/home/cantidio/god_orochi (2)/Mizuchi.sff");
		time(&endtime);
		printf("load time: %ld s \n",endtime-starttime);

		time( &starttime );
		sprites.setAlphaMask( Color(1,0,1) );
		time(&endtime);
		printf("alpha time: %ld s \n",endtime-starttime);

		time( &starttime );
		sprites.convertToDisplayFormat();
		time(&endtime);
		printf("convert time: %ld s \n",endtime-starttime);

		Point position(550,350);
		float ang = 0;

		float zoom = 5;
		int index = 0;

		while(1)
		{
			keyboard.update();
			mouse.update();
			if( keyboard.getKey( Input::Key::ESCAPE ).isPressed() )
			{
				break;
			}
			else if( keyboard.getKey( Input::Key::LEFT_ALT ).isPressed() && keyboard.getKey( Input::Key::ENTER ).isPressed() )
			{
				display.toogleFullScreen();
			}
			if( mouse.getButton(Input::MouseButton::LEFT) )	{	position = mouse.getPosition();		}
			if( mouse.getButton(Input::MouseButton::WHEEL_UP) )	{		zoom+= 0.5;	}
			else if( mouse.getButton(Input::MouseButton::WHEEL_DOWN) ){ zoom-= 0.5;	}
			if(zoom < 0 ) zoom = 0;
			display.clear(Graphic::Color(1,1,1));	//limpa a tela

			//sprites[index].draw( position, sprites[index].getWidth()*zoom, sprites[index].getHeight()*zoom, Graphic::Mirroring::HFlip);

			sprites[index].Sprite::draw( position,	ang, Graphic::Mirroring::Normal );

			Graphic::System::get().drawCircleFilled( position, 10, Graphic::Color( 0, 1, 0, 0.1 ) );

			//ang += 0.1;
			index++;

			if(index >= sprites.getSize()) index=0;

			al_flip_display();
			al_rest(0.01);

		}
	}
	catch(Core::Exception& exception)
	{
		exception.writeInLog();
		std::cout << "exception" << exception.what() << std::endl;
	}
	Graphic::System::halt();
	return 0;
}

/*
#include <gorgon++/addon/sdl/graphic/image_loader.hpp>
#include <gorgon++/addon/allegro5/graphic/system.hpp>
#include <gorgon++/addon/allegro5/input/system.hpp>
#include <gorgon++/gorgon.hpp>


#define print() printf("debug: %d\n",__LINE__)

#include <chipmunk/chipmunk.h>
#include <math.h>
using namespace Gorgon;
using namespace Gorgon::Graphic;
using namespace Gorgon::Core;
using namespace Gorgon::Input;
using namespace Gorgon::Physics;


Gorgon::Physics::DampedSpring* spring;
Gorgon::Physics::Body* addWheel(Gorgon::Physics::Space& pSpace, const Point& pPosition)
{
	cpFloat radius = 15.0f;	cpFloat mass = 1.0f;
	Gorgon::Physics::Body* body = pSpace.addBody(mass, Gorgon::Physics::Body::getMomentForCircle(mass, radius, 0.0f));
	body->setPosition(pPosition);
	Gorgon::Physics::Shape* shape = body->addShapeCircle(radius,Point(0,0));
	shape->setElasticity(0.0f);
	shape->setFriction(0.7f);
	shape->setGroup(1);
	return body;
}

Gorgon::Physics::Body* addChassis(Gorgon::Physics::Space& pSpace, const Point& pPosition)
{
	cpFloat mass = 10.0f;

	Gorgon::Physics::Body* body = pSpace.addBody( mass, Body::getMomentForBox(mass,80,30) );
	body->setPosition(pPosition);
	Gorgon::Physics::Shape* shape = body->addShapeBox(80,30);
	shape->setElasticity(0.0f);
	shape->setFriction(0.7f);
	shape->setGroup(1);
	return body;
}

Gorgon::Physics::Body* addCar(Gorgon::Physics::Space& pSpace, const Point& pPosition)
{
	Gorgon::Physics::Body* wheelA	= addWheel(pSpace,pPosition + Point(-30	, 60));
	Gorgon::Physics::Body* wheelB	= addWheel(pSpace,pPosition + Point(60	, 60));
	Gorgon::Physics::Body* chassis	= addChassis(pSpace,pPosition);

	pSpace.addConstraintGrooveJoint
	(
		*chassis, *wheelA,
		Point(-30,40),Point(-30,20),Point(0,0)
	);
	pSpace.addConstraintGrooveJoint
	(
		*chassis, *wheelB,
		Point(30,40),Point(30,20),Point(0,0)
	);
	pSpace.addConstraintDampedSpring
	(
		*chassis, *wheelA,
		Point(-30,0), Point(0,0),
		50.0f, 20.0f, 1.5f
	);

	spring = pSpace.addConstraintDampedSpring
	(
		*chassis, *wheelB,
		Point(30,0), Point(0,0),
		50.0f, 20.0f, 1.5f
	);
	return chassis;
}
void addBox(Gorgon::Physics::Space& pSpace, const Point& pPosition)
{
	cpFloat mass = 1.0f;
	Gorgon::Physics::Body* body = pSpace.addBody( mass, Body::getMomentForBox(mass,30,30) );
	body->setPosition(pPosition);
	Gorgon::Physics::Shape* shape = body->addShapeBox(30,30);
	shape->setElasticity(0.0f);
	shape->setFriction(0.7f);
}

int main()
{
	Graphic::Addon::System::set();
	Input::Addon::System::set();
	//ImageLoader::setLoader( new ImageLoaderSDL() );

	Display display("GORGON Framework rev 214 - Physics Test", 640, 480);
	Keyboard keyboard;
	Mouse mouse;

	Image a("hakumen.png");
	SpritePack b("foxy.gsp");
	b.setAlphaMask(Color(1,0,1));
printf("size: %d\n",b.getSize());
	Gorgon::Physics::init();
	cp_collision_slop = 0.5f;

	Gorgon::Physics::Space space;
	space.setIterations(10);
	space.setGravity(Point(0,100));
	space.setDamping(0.9);
	space.resizeStaticHash(30.0f);
	space.resizeActiveHash(30.0f);

	//ground
	Shape* shape = space.getStaticBody().addShapeSegment(Point(10,470), Point(630,470), 0.0f);
	shape->setElasticity(0.8f);
	shape->setFriction(0.5f);
	space.getStaticBody().addShapeSegment(Point(10,10), Point(630,10), 0.0f);
	space.getStaticBody().addShapeSegment(Point(10,10), Point(10,470), 0.0f);
	space.getStaticBody().addShapeSegment(Point(630,10), Point(630,470), 0.0f);

	//poly
	std::vector<Point> verts;



	verts.push_back(Point(-15,-15));
	verts.push_back(Point(-15, 15));
	verts.push_back(Point( 15, 15));
	verts.push_back(Point( 15,-15));


	Body* body = space.addBody( 1.0f, Body::getMomentForPolygon( 1.0f, verts, Point(0,0) ) );
	body->setPosition( Point( 350, 100 ) );
	body->setVelocity( Point( 0, -30 ) );
	shape = body->addShapePolygon( verts );
	shape->setFriction( 0.3f );
	shape->setElasticity( 0.9f );

	body = addCar( space, Point( 100,350 ) );

	addBox( space, Point( 150, 150) );
	addBox( space, Point( 170, 150) );
	addBox( space, Point( 350, 150) );
display.setAsTarget();
int i = 0;
	while(1)
	{
		keyboard.update();
		mouse.update();
		if( keyboard.getKey( Input::Key::ESCAPE ).isPressed() )
		{
			break;
		}
		else if( keyboard.getKey( Input::Key::LEFT_ALT ).isPressed() && keyboard.getKey( Input::Key::ENTER ).isPressed() )
		{
			display.toogleFullScreen();
		}
		if( keyboard.getKey( Input::Key::RIGHT ).isPressed() )		body->applyForce(Point(15,0),Point(0,0));
		else if( keyboard.getKey( Input::Key::LEFT ).isPressed() )	body->applyForce(Point(-15,0),Point(0,0));
		else														body->resetForces();

		if( keyboard.getKey( Input::Key::SPACE).isPressed() )		body->setVelocity(Point(0,-80));

		space.runStep(60.0f);

		display.clear( Color( 0.5f, 0.5f, 1.0f ) );

		b[i % b.getSize() ].draw(Point(150.0f,150.0f));
		space.draw();

i++;
		//spring->draw(video,0xFF0000);
		display.swapBuffers();

//		rest(30);
	}

	return 0;
}



*/
