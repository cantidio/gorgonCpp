#include "graphic/gorgon_image_format_pcx_exception.hpp"
#undef ImageException
#undef ImageFormatPcxException

namespace Gorgon
{
	ImageFormatPcxException::ImageFormatPcxException
	(
		const std::string	pMessage,
		const std::string	pFile,
		const std::string	pFunction,
		const int			pLine
	) : ImageException(pMessage,"ImageFormatPcx",pFile,pFunction,pLine){}
}
