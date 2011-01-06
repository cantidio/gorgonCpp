#include <gorgon++/gorgon.hpp>
#include <chipmunk/chipmunk.h>
#define print() printf("debug: %d\n",__LINE__)
#include <gorgon++/include/physics/physics.hpp>
#include <math.h>

int main()
{
	allegro_init();
	install_keyboard();
	Gorgon::Video::init("CHIPMUNK-TEST",640,480);
	Gorgon::Video video = Gorgon::Video::get();
	Gorgon::Sprite sGround(Gorgon::Image(640,4),0,0,0,0);
	sGround.drawRectangle(0,0,639,3,0x00FF00);
	
	cpInitChipmunk();
	cp_collision_slop = 0.2f;

	Chipmunk::Space space;
	space.setIterations(10);
	space.setGravity(Gorgon::Point(0,100));
	space.setDamping(0.9);
	space.resizeStaticHash(30.0f);
	space.resizeActiveHash(30.0f);

	//ground
	Chipmunk::ShapeSegment ground(Gorgon::Point(0,476), Gorgon::Point(640,476), 0.0f, space.getStaticBody());
	ground.setElasticity(0.8f);
	ground.setFrictionCoefficient(0.5f);
	space.addShape(ground); space.addShape(ground);

	//poly
	std::vector<Gorgon::Point> verts;
	for(int i=0; i<5; i++){
		float angle = -2 * Chipmunk::PI * i / ((float) 5);
		verts.push_back( Gorgon::Point( 30 * cos(angle), 30 * sin(angle)) );
	}
	Chipmunk::Body poly
	(
		1.0f,
		Chipmunk::Body::getMomentForPolygon
		(
			1.0f,
			verts,
			Gorgon::Point(0,0)
		)
	);
	poly.setPosition(Gorgon::Point(150, 0));
	poly.setVelocity(Gorgon::Point(0,-20));
	space.addBody(poly);
		
	Chipmunk::ShapePolygon polyShape(verts, Gorgon::Point(0,0), poly);
	polyShape.setFrictionCoefficient(0.3f);
	polyShape.setElasticity(0.8f);
	space.addShape(polyShape);
	
	//box
	int width = 30, height = 30;
	Chipmunk::Body boxBody(15, Chipmunk::Body::getMomentForBox(15,width,height));
	boxBody.setPosition(Gorgon::Point(250,140));
	//boxBody.setVelocity(Gorgon::Point(0,-80));
	space.addBody(boxBody);
		
	Chipmunk::ShapeBox boxShape(width,height,boxBody);
	space.addShape(boxShape);
	boxShape.setElasticity(0.2f);
	boxShape.setFrictionCoefficient(0.9f);
	
	//ball1
	cpFloat radius	= 30.0f;
	cpFloat mass	= 10.0f;
	Chipmunk::Body ballBody(mass, Chipmunk::Body::getMomentForCircle(mass, radius, 0.0f));
	ballBody.setPosition(Gorgon::Point(50,40 + radius + 50));
	ballBody.setVelocity(Gorgon::Point(0,-80));
	space.addBody(ballBody);
		
	Chipmunk::ShapeCircle ballShape(radius,Gorgon::Point(0,0),ballBody);
	space.addShape(ballShape);
	ballShape.setElasticity(0.8f);
	ballShape.setFrictionCoefficient(0.9f);
	
	//ball2
	Chipmunk::Body ballBodya(mass, Chipmunk::Body::getMomentForCircle(mass, radius, 0.0f));
	ballBodya.setPosition(Gorgon::Point(50,400));
	ballBodya.setVelocity(Gorgon::Point(0,-20));
	space.addBody(ballBodya);
	
	Chipmunk::ShapeCircle ballShapea(radius,Gorgon::Point(0,0),ballBodya);
	space.addShape(ballShapea);
	ballShapea.setElasticity(0.8f);
	ballShapea.setFrictionCoefficient(0.9f);
	
	int angle = 0;
	while(!key[KEY_ESC])
	{
		if(key[KEY_RIGHT])		poly.applyForce(Gorgon::Point(5,0),Gorgon::Point(0,0));
		else if(key[KEY_LEFT])	poly.applyForce(Gorgon::Point(-5,0),Gorgon::Point(0,0));
		else					poly.resetForces();
		
		if(key[KEY_D])			ballBodya.applyForce(Gorgon::Point(5,0),Gorgon::Point(0,0));
		else if(key[KEY_A])		ballBodya.applyForce(Gorgon::Point(-5,0),Gorgon::Point(0,0));
		else					ballBodya.resetForces();
		
		if(key[KEY_SPACE])		poly.setVelocity(Gorgon::Point(0,-180));
		space.runStep(60.0f);

		video.clear();
//		ground.draw(video,0x0000FF);
//		ballShapea.draw(video,0xFF0000);
//		ballShape.draw(video,0x00FF00);
//		polyShape.draw(video,0x00FFFF);

		space.draw(video);
		
		video.show();
		rest(30);
	}
	
	return 0;
}

