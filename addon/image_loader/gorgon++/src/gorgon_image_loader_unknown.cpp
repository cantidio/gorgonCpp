#include "../include/gorgon_image_loader_unknown.hpp"
#include <gorgon++/graphic/gorgon_image_exception.hpp>

namespace Gorgon
{
	void ImageLoaderUnknown::load(Graphic::Image& pImage, const std::string& pImageName) const
	{
		throw Graphic::ImageException("Unknowned image format.");
	}

	void ImageLoaderUnknown::load
	(
		Graphic::Image& pImage,
		Core::File& pFile,
		const int& pImageSize
	) const
	{
		throw Graphic::ImageException("Unknowned image format.");
	}

	void ImageLoaderUnknown::save(Graphic::Image& pImage, Core::File& pFile) const
	{
		throw Graphic::ImageException("Unknowned image format.");
	}

	void ImageLoaderUnknown::save(Graphic::Image& pImage, const std::string& pImageName) const
	{
		throw Graphic::ImageException("Unknowned image format.");
	}
}
