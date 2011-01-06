#include "graphic/gorgon_animationpack_exception.hpp"
#undef AnimationPackException

namespace Gorgon
{
	AnimationPackException::AnimationPackException
	(
		const std::string& pMessage,
		const std::string& pFile,
		const std::string& pFunction,
		const int& pLine
	) : Exception(pMessage,"AnimationPack",pFile,pFunction,pLine){}
}

