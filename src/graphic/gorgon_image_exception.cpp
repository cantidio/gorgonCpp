#include "graphic/gorgon_image_exception.hpp"
#undef ImageException

namespace Gorgon{
namespace Graphic
{
	ImageException::ImageException
	(
		const std::string&	pMessage,
		const std::string&	pSubModule,
		const std::string&	pFile,
		const std::string&	pFunction,
		const int&			pLine
	) : Exception(pMessage,"Image: "+pSubModule,pFile,pFunction,pLine){}
}}
