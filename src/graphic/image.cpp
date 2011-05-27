#include <graphic/image.hpp>
#include <graphic/system.hpp>
#include <graphic/exception.hpp>
#include <vector>

namespace Gorgon{
namespace Graphic
{
	std::string Image::describe() const
	{
		std::stringstream out;
		out << "Gorgon::Graphic::Image::describe()" 	<< std::endl;
		out << "Have Data:    " 	<< (mImage 			? "Yes" : "No") << std::endl;
		out << "Have Palette: " 	<< (mPalette		? "Yes" : "No") << std::endl;
		out << "Free Image:   " 	<< (mFreeImage		? "Yes" : "No") << std::endl;
		out << "Free Palette  " 	<< (mFreePalette	? "Yes" : "No")	<< std::endl;
		if(mImage)
		{
			out << "Image Width:  " 	<< getWidth() 	<< std::endl;
			out << "Image Height: " 	<< getHeight() 	<< std::endl;
			out << "Image Bpp:    " 	<< getBpp()		<< std::endl;
		}
		return out.str();
	}
	
	void Image::create
	(
		const int&		pWidth,
		const int&		pHeight,
		const int&		pBpp
	)
	{
		if(mImage != NULL && mFreeImage) //tem objeto e o mesmo é interno
		{
			mImage->create(pWidth,pHeight,pBpp);
		}
		else//se o objeto aponta para fora da classe ou, não tem objeto cria um novo
		{
			ImageBase* image = System::get().getImage();
			image->create(pWidth, pHeight, pBpp);
			setImageBase(image,true);
		}
		setPalette(NULL, true);
	}
	
	Image::Image()
	{
		mImage			= NULL;
		mPalette		= NULL;
		mFreeImage		= true;
		mFreePalette	= true;
	}
	
	Image::Image
	(
		const int&		pWidth,
		const int&		pHeight,
		const int&		pBpp
	)
	{
		mImage			= NULL;
		mPalette		= NULL;
		mFreeImage		= true;
		mFreePalette	= true;
		create(pWidth,pHeight,pBpp);
	}

	Image::Image(const Image& pImage)
	{
		mImage			= NULL;
		mPalette		= NULL;
		mFreeImage		= true;
		mFreePalette	= true;
		(*this) = pImage;
	}
	
	Image::Image(const std::string& pFileName,const ImageLoader& pImageLoader)
	{
		mImage			= NULL;
		mPalette		= NULL;
		mFreeImage		= true;
		mFreePalette	= true;
		load(pFileName, pImageLoader);
	}

	Image::Image(Core::File& pFile, const ImageLoader& pImageLoader)
	{
		setImageBase(NULL, true);
		setPalette	(NULL, true);
		load(pFile, pImageLoader);
	}

	Image::~Image()
	{
		if(mImage	!= NULL && mFreeImage)		delete mImage;
		if(mPalette	!= NULL && mFreePalette)	delete mPalette;
	}
	
	void Image::setImageBase(ImageBase* pImage, const bool& pFreeSource)
	{
		if(mImage != NULL && mFreeImage)
		{
			delete mImage;
		}
		mImage		= pImage;
		mFreeImage	= pFreeSource;
	}
	
	void Image::setImageBase(const ImageBase& pImage)
	{
		setImageBase(pImage.clone(),true);
	}
	
	const ImageBase* Image::getImageBase() const
	{
		return mImage;
	}
	
	void Image::setPalette(Palette *pPalette, const bool& pFreeSource)
	{
		if(mPalette != NULL && mFreePalette)
		{
			delete mPalette;
		}
		mPalette		= pPalette;
		mFreePalette	= pFreeSource;
	}
	
	void Image::setPalette(const Palette& pPalette)
	{
		setPalette( pPalette.clone(), true );
	}
	
	const Palette* Image::getPalette() const
	{
		return mPalette;
	}
	
	void Image::usePalette() const
	{
		if(mPalette)
		{
			mPalette->set();
		}
	}
	
	int Image::getWidth() const
	{
		return (mImage != NULL) ? mImage->getWidth() : 0;
	}
	
	int Image::getHeight() const
	{
		return (mImage != NULL) ? mImage->getHeight() : 0;
	}
	
	int Image::getBpp() const
	{
		return (mImage != NULL) ? mImage->getBpp() : 0;
	}
	
	void Image::setAlphaMask(const Color& pColor)
	{
		if(mImage != NULL)
		{
			mImage->setAlphaMask(pColor);
		}
	}
	
	Color Image::getAlphaMask() const
	{
		return (mImage != NULL) ? mImage->getAlphaMask() : Color(0,0,0,0);
	}
	
	int Image::getColorNumber() const
	{
		std::vector<int> colors;
		/*
		int color		= 0;
		unsigned int x,y,k;
		bool exists;
		
		for(y = 0; y < getHeight(); ++y)
		{
			for(x = 0; x < getWidth(); ++x)
			{
				color = getPixel(x,y,true);
				for(k = 0, exists = false; k < colors.size(); ++k)
				{
					if(color == colors[k])
					{
						exists = true;
						break;
					}
				}
				if(!exists)
				{
					colors.push_back(color);
				}
			}
		}*/
		return colors.size();
	}
	
	Color Image::getPixel(const Core::Point& pPosition) const
	{
		return (mImage != NULL) ? mImage->getPixel(pPosition) : Color(0,0,0,0);
	}
	
	void Image::setAsTarget()
	{
		if(mImage != NULL)
		{
			mImage->setAsTarget();
		}
	}

	void Image::clear(const Color& pColor)
	{
		if(mImage != NULL)
		{
			mImage->clear(pColor);
		}
	}

	void Image::draw(const Core::Point& pPosition) const
	{
		if(mImage != NULL)
		{
			mImage->draw(pPosition);
		}
	}
	
	void Image::draw(const Core::Point& pPosition, const Mirroring& pMirroring) const
	{
		if(mImage != NULL)
		{
			mImage->draw(pPosition, pMirroring);
		}
	}
	
	void Image::draw//draw rotated
	(
		const Core::Point&	pPosition,
		const float&		pAngle,
		const Core::Point&	pCenter
	) const
	{
		if(mImage != NULL)
		{
			mImage->draw(pPosition, pAngle, pCenter);
		}
	}
	
	void Image::draw//draw rotated flipped
	(
		const Core::Point&	pPosition,
		const float&		pAngle,
		const Core::Point&	pCenter,
		const Mirroring&	pMirroring
	) const
	{
		if(mImage != NULL)
		{
			mImage->draw(pPosition, pAngle, pCenter, pMirroring);
		}
	}
	
	void Image::draw
	(
		const Core::Point& pPosition,
		const int& pWidth,
		const int& pHeight,
		const Mirroring& pMirroring
	) const//drawScaled
	{
		if(mImage != NULL)
		{
			mImage->draw(pPosition,pWidth,pHeight,pMirroring);
		}
	}
	
	void Image::draw(const Core::Point& pPosition, const Color& pTint) const//drawTinted
	{
		if(mImage != NULL)
		{
			mImage->draw(pPosition,pTint);
		}
	}
	
	void Image::draw
	(
		const Core::Point& pPosition,
		const Color& pTint,
		const Mirroring& pMirroring
	) const//drawTinted
	{
		if(mImage != NULL)
		{
			mImage->draw(pPosition, pTint, pMirroring);
		}
	}
	
	void Image::draw
	(
		const Core::Point& pPosition,
		const Color& pTint,
		const float& pAngle,
		const Core::Point& pCenter
	) const//drawTinted rotated
	{
		if(mImage != NULL)
		{
			mImage->draw(pPosition, pTint, pAngle, pCenter);
		}
	}
	
	void Image::draw
	(
		const Core::Point&	pPosition,
		const Color&		pTint,
		const float&		pAngle,
		const Core::Point&	pCenter,
		const Mirroring&	pMirroring
	) const//drawTinted rotated fliped
	{
		if(mImage != NULL)
		{
			mImage->draw(pPosition, pTint, pAngle, pCenter, pMirroring);
		}
	}
			
	bool Image::isEmpty() const
	{
		register Core::Point pos;
		for(pos.setY(getHeight() - 1); pos.getY() > -1; pos.subY(1))
		{
			for(pos.setX(getWidth() - 1); pos.getX() > -1; pos.subX(1))
			{
				if(getPixel(pos) != getAlphaMask())//será que isso funciona?
				{
					return false;
				}
			}
		}
		return true;
	}

	bool Image::operator ==(const Image& pImage) const
	{
		/*register int h,w;
		for(h = getHeight() - 1; h > -1; --h)
		{
			for(w = getWidth() - 1; w > -1; --w)
			{
				if(pImage.getColor(w,h) != getColor(w,h))
				{
					return false;
				}
			}
		}
		if
		(
			getHeight() == pImage.getHeight() &&
			getWidth() == pImage.getWidth()
		)
		{
			return true;
		}
		else
		{
			return false;
		}*/
		return false;
	}

	void Image::operator =(const Image& pImage)
	{
		setImageBase	((pImage.mImage		!= NULL) ? pImage.mImage->clone()	: NULL, true);
		setPalette		((pImage.mPalette	!= NULL) ? pImage.mPalette->clone()	: NULL, true);
	}
	
	void Image::load(const std::string& pFileName,const ImageLoader& pImageLoader)
	{
		setImageBase(System::get().getImage(),true);
		pImageLoader.load(*this,pFileName);
	}

	void Image::load(Core::File& pFile, const ImageLoader& pImageLoader)
	{
		setImageBase(System::get().getImage(),true);
		pImageLoader.load(*this,pFile);
	}

	void Image::save(const std::string& pFileName,const ImageLoader& pImageLoader)
	{
		pImageLoader.save(*this,pFileName);
	}

	void Image::save(Core::File& pFile, const ImageLoader& pImageLoader)
	{
		pImageLoader.load(*this,pFile);
	}
}}
