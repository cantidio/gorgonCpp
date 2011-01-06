#include "graphic/gorgon_image_format_unknown.hpp"
#include "graphic/gorgon_image_exception.hpp"

namespace Gorgon
{
	void ImageFormatUnknown::load(Image& pImage, const std::string& pImageName) const
	{
		throw ImageException("Unknowned image format.");
	}

	void ImageFormatUnknown::load(Image& pImage, Core::File& pFile) const
	{
		throw ImageException("Unknowned image format.");
	}

	void ImageFormatUnknown::save(Image& pImage, Core::File& pFile) const
	{
		throw ImageException("Unknowned image format.");
	}

	void ImageFormatUnknown::save(Image& pImage, const std::string& pImageName) const
	{
		throw ImageException("Unknowned image format.");
	}
}
