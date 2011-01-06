#include <gorgon++/gorgon.hpp>

using namespace Gorgon;
using namespace std;
int main()
{
	try
	{
		Animation	anim;
		Animation	anim2;

		anim.add(Frame(10,0,10));
		anim.add(Frame(20,0,-1));

		anim.save("anim.ganim");
		anim2.load("anim.ganim");

		anim.describe();
		anim2.describe();
	}
	catch(Exception e)
	{
		cout << e.getMessage() << endl;
	}
	
	return 0;
}
