#include "../include/gorgon_image_loader_unknown.hpp"
#include <gorgon++/graphic/exception.hpp>

namespace Gorgon
{
	void ImageLoaderUnknown::load(Graphic::Image& pImage, const std::string& pImageName) const
	{
		raiseGraphicException("ImageLoaderUnknown::load(pImage,\""+pImageName+"\"): Error, unknown image format.");
	}

	void ImageLoaderUnknown::load
	(
		Graphic::Image& pImage,
		Core::File& pFile,
		const int& pImageSize
	) const
	{
		raiseGraphicException("ImageLoaderUnknown::load(pImage,pFile,pImageSize): Error, unknown image format.");
	}

	void ImageLoaderUnknown::save(Graphic::Image& pImage, Core::File& pFile) const
	{
		raiseGraphicException("ImageLoaderUnknown::load(pImage,pFile): Error, unknown image format.");
	}

	void ImageLoaderUnknown::save(Graphic::Image& pImage, const std::string& pImageName) const
	{
		raiseGraphicException("ImageLoaderUnknown::save(pImage,\""+pImageName+"\"): Error, unknown image format.");
	}
}
