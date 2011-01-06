#ifndef _GORGON_SFF_SPRITEPACK_
#define	_GORGON_SFF_SPRITEPACK_
#include "gorgon_spritepack.hpp"

namespace Gorgon
{
	class SffSpritePack : public SpritePack
	{
		public:
			SffSpritePack();
			SffSpritePack(const std::string& fileName);
			SffSpritePack(Core::File& pFile);

			void load(const std::string& pSpriteName);
			Sprite loadSprite(Core::File& pFile) const;
			void load(Core::File& pFile);
	};
}
#endif

