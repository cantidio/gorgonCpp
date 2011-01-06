#include <gorgon++/gorgon.hpp>

using namespace Gorgon;
using namespace std;
int main()
{
	try
	{
		AnimationPack	animpk;
		AnimationPack	animpk2;
	
		animpk.add(Animation(0,0));
		animpk.add(Animation(10,0));
		animpk.add(Animation(20,0));
		animpk.add(Animation(100,0));

		animpk(0,0).add(Frame(0,0,7,Mirroring::HFlip,90));
		animpk(0,0).add(Frame(0,1,5,Mirroring::VFlip,90));
		animpk(0,0).add(Frame(0,2,5,Mirroring::VHFlip,90));
		animpk(0,0).add(Frame(0,3,5,Mirroring::HFlip,90));
	
		animpk(10,0).add(Frame(10,0,3));
		animpk(10,0).add(Frame(10,0,5));
		animpk(10,0).add(Frame(10,2,5));
		animpk(10,0).add(Frame(10,3,-1));
	
		animpk(20,0).add(Frame(20,0,-1));
	
		animpk(100,0).add(Frame(1000,20,3));
		animpk(100,0).add(Frame(200,15,5));
		animpk(100,0).add(Frame(10,21,5));
		animpk(100,0).add(Frame(0,30,10,Mirroring::Normal,90));
	
		animpk.save("test.gapk");
		animpk2.load("test.gapk");
		animpk2.describe();
	}
	catch(Exception e)
	{
		cout << e.getMessage() << endl;
	}
	return 0;
}
