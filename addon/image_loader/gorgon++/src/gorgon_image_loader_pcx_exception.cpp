#include "../include/gorgon_image_loader_pcx_exception.hpp"
#undef ImageException
#undef ImageLoaderPcxException

namespace Gorgon
{
	ImageLoaderPcxException::ImageLoaderPcxException
	(
		const std::string	pMessage,
		const std::string	pFile,
		const std::string	pFunction,
		const int			pLine
	) : ImageException(pMessage,"ImageLoaderPcx",pFile,pFunction,pLine){}
}
