#include "graphic/gorgon_spritepack_exception.hpp"
#undef ImageException
#undef SpritePackException

namespace Gorgon
{
	SpritePackException::SpritePackException
	(
		const std::string&	pMessage,
		const std::string&	pFile,
		const std::string&	pFunction,
		const int&			pLine
	) : ImageException(pMessage,"SpritePack",pFile,pFunction,pLine){}
}
