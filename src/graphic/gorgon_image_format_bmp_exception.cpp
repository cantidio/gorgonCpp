#include "graphic/gorgon_image_format_bmp_exception.hpp"
#undef ImageException
#undef ImageFormatBmpException

namespace Gorgon
{
	ImageFormatBmpException::ImageFormatBmpException
	(
		const std::string&	pMessage,
		const std::string&	pFile,
		const std::string&	pFunction,
		const int&			pLine
	) : ImageException(pMessage,"ImageFormatBmp",pFile,pFunction,pLine){}
}
