#include "graphic/gorgon_sprite_exception.hpp"

#undef ImageException
#undef SpriteException
namespace Gorgon
{
	SpriteException::SpriteException
	(
		const std::string&	pMessage,
		const std::string&	pFile,
		const std::string&	pFunction,
		const int&			pLine
	) : ImageException(pMessage,"Sprite",pFile,pFunction,pLine){}
}
