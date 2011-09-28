#include <graphic/image_base.hpp>

namespace Gorgon{
namespace Graphic
{
	ImageBase::ImageBase()
	{
		mWidth			= 0;
		mHeight			= 0;
		mBpp			= 0;
		mAlphaMask		= Graphic::Color(0.0, 0.0, 0.0, 0.0);
	}
	
	ImageBase::~ImageBase()
	{
	}
	
	void ImageBase::setAlphaMask(const Graphic::Color& pColor)
	{
		mAlphaMask = pColor;
		applyAlphaMask();
	}
	
	Graphic::Color ImageBase::getAlphaMask() const
	{
		return mAlphaMask;
	}
}}
	
