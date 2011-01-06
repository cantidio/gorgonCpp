#include "../include/gorgon_image_loader_bmp_exception.hpp"
#undef ImageException
#undef ImageLoaderBmpException

namespace Gorgon
{
	ImageLoaderBmpException::ImageLoaderBmpException
	(
		const std::string&	pMessage,
		const std::string&	pFile,
		const std::string&	pFunction,
		const int&			pLine
	) : ImageException(pMessage,"ImageLoaderBmp",pFile,pFunction,pLine){}
}
