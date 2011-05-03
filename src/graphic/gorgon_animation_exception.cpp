#include "graphic/gorgon_animation_exception.hpp"
#undef AnimationException

namespace Gorgon{
namespace Graphic
{
	AnimationException::AnimationException
	(
		const std::string& pMessage,
		const std::string& pFile,
		const std::string& pFunction,
		const int& pLine
	) : Exception(pMessage,"Animation",pFile,pFunction,pLine){}
}}

