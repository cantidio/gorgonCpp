#include <graphic/gorgon_image_loader.hpp>
#include <graphic/gorgon_image_exception.hpp>

namespace Gorgon
{
	ImageLoader* ImageLoader::mLoader = NULL;
	std::string ImageLoader::mSaveFormat = "BMP";
	ImageLoader& ImageLoader::getLoader()
	{
		if(mLoader == NULL)
		{
			setLoader ( new ImageLoader() );
		}
		return *mLoader;
	}

	void ImageLoader::setLoader(ImageLoader* pImageLoader)
	{
		if( mLoader != NULL)
		{
			delete mLoader;
		}
		mLoader = pImageLoader;
	}

	void ImageLoader::load(Image& pImage, const std::string& pImageName) const
	{
		throw ImageException("Unable to load image, none ImageLoader is being used, please set a loader.");
	}
	void ImageLoader::load
	(
		Image& pImage,
		Core::File& pFile,
		const int& pSizeOfImage
	) const
	{
		throw ImageException("Unable to load image, none ImageLoader is being used, please set a loader.");
	}
	void ImageLoader::save(Image& pImage, Core::File& pFile) const
	{
		throw ImageException("Unable to save image, none ImageLoader is being used, please set a loader.");
	}
	void ImageLoader::save(Image& pImage, const std::string& pImageName) const
	{
		throw ImageException("Unable to save image, none ImageLoader is being used, please set a loader.");
	}
}
