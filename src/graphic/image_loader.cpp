#include <graphic/image_loader.hpp>
#include <graphic/exception.hpp>

namespace Gorgon{
namespace Graphic
{
	ImageLoader* ImageLoader::mLoader		= NULL;
	std::string ImageLoader::mSaveFormat	= "BMP";
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
		raiseGraphicException("ImageLoader::load(): Error, unable to load image, none imageLoader is being used, please set a loader.");
	}

	void ImageLoader::load
	(
		Image& pImage,
		Core::File& pFile,
		const int& pSizeOfImage
	) const
	{
		raiseGraphicException("ImageLoader::load(): Error, unable to load image, none imageLoader is being used, please set a loader.");
	}

	void ImageLoader::save(Image& pImage, Core::File& pFile) const
	{
		raiseGraphicException("ImageLoader::load(): Error, unable to load image, none imageLoader is being used, please set a loader.");
	}

	void ImageLoader::save(Image& pImage, const std::string& pImageName) const
	{
		raiseGraphicException("ImageLoader::load(): Error, unable to load image, none imageLoader is being used, please set a loader.");
	}
}}
