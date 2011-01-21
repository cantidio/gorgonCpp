#include <graphic/gorgon_image_loader_null.hpp>
#include <graphic/gorgon_image_exception.hpp>
namespace Gorgon
{
	bool ImageLoaderNull::init()
	{
		if(ImageLoader::mLoader != NULL)
		{
			delete ImageLoader::mLoader;
		}
		ImageLoader::mLoader = this;
		return true;
	}
	void ImageLoaderNull::load(Image& pImage, const std::string& pImageName) const
	{
		throw ImageException("Unable to load image, ImageLoaderNull is being used, please set a loader.");
	}
	void ImageLoaderNull::load(Image& pImage, Core::File& pFile) const
	{
		throw ImageException("Unable to load image, ImageLoaderNull is being used, please set a loader.");
	}
	void ImageLoaderNull::save(Image& pImage, Core::File& pFile) const
	{
		throw ImageException("Unable to save image, ImageLoaderNull is being used, please set a loader.");
	}
	void ImageLoaderNull::save(Image& pImage, const std::string& pImageName) const
	{
		throw ImageException("Unable to save image, ImageLoaderNull is being used, please set a loader.");
	}
}
