#include "../include/gorgon_image_loader_unknown.hpp"
#include <graphic/gorgon_image_exception.hpp>

namespace Gorgon
{
	void ImageLoaderUnknown::load(Image& pImage, const std::string& pImageName) const
	{
		throw ImageException("Unknowned image format.");
	}

	void ImageLoaderUnknown::load(Image& pImage, Core::File& pFile) const
	{
		throw ImageException("Unknowned image format.");
	}

	void ImageLoaderUnknown::save(Image& pImage, Core::File& pFile) const
	{
		throw ImageException("Unknowned image format.");
	}

	void ImageLoaderUnknown::save(Image& pImage, const std::string& pImageName) const
	{
		throw ImageException("Unknowned image format.");
	}
}
