#include <gorgon++/gorgon.hpp>
#include <gorgon++/addon/animationpack/gorgon_animationpack_lua.hpp>
using namespace Gorgon;
using namespace Gorgon::Graphic;
int main(int argc, char** argv)
{
	if(argc == 3 )
	{
		AnimationPackLua a(argv[1]);
		
		printf("animacoes encontradas: %d\n",a.getSize());
		
		printf("%s\n",a.describe().c_str());
		AnimationPack b(a);
		b.save(argv[2]);
	}
	else
	{
		printf("usage: ./animationpack_lua_to_gorgon.e anim.lua anim.gap\n");
	}
	return 0;
}
