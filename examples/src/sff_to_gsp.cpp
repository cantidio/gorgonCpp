#include<gorgon++/gorgon++.hpp>
#include<gorgon++/addons/spritepack/spritepack_sff.hpp>
using namespace Gorgon;
int main()
{
	allegro_init();
	Video::init();
	SpritePackSff a();
	Palette pal();
	a->setGlobalPalette(&pal);
	a.save("teste.gsp");
}
