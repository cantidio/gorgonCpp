#include <graphic/image.hpp>
#include <graphic/exception.hpp>

namespace Gorgon{
namespace Graphic
{
	Image::Image(const std::string& pFileName,const ImageLoader& pImageLoader)
	{
		mData		= NULL;
		mDataBuffer	= NULL;
		mPalette	= NULL;
		load(pFileName,pImageLoader);
	}

	Image::Image(Core::File& pFile, const ImageLoader& pImageLoader)
	{
		mData		= NULL;
		mDataBuffer	= NULL;
		mPalette	= NULL;
		load(pFile,pImageLoader);
	}
	
	Image::Image(BITMAP* pBitmap, Palette *pPalette)
	{
		mData			= pBitmap;
		mDataBuffer		= NULL;
		mPalette		= pPalette;
		mImgLinked		= true;
		mFreePalette	= false;
		setType(imageUnknownCod);
		updateBuffer();
	}

	Image::Image
	(
		const int& pWidth,
		const int& pHeight,
		const int& pBpp,
		const int& pColor
	)
	{
		mData			= (pBpp < 8) ? create_bitmap_ex(8,pWidth,pHeight) : create_bitmap_ex(pBpp,pWidth,pHeight);
		mDataBuffer		= NULL;
		mPalette		= NULL;
		mImgLinked		= false;
		mFreePalette	= true;
		clear(pColor);
		updateBuffer();
		setType(imageUnknownCod);
	}

	Image::Image(const Image& pImage)
	{
		(*this) = pImage;
	}

	Image::~Image()
	{
		if(mData != mDataBuffer)
		{
			if(!mImgLinked && mData)
			{
				destroy_bitmap(mData);
				mData = NULL;
			}
			if(mDataBuffer)
			{
				destroy_bitmap(mDataBuffer);
				mDataBuffer = NULL;
			}
		}
		else
		{
			if(!mImgLinked && mData)
			{
				destroy_bitmap(mData);
				mData		= NULL;
				mDataBuffer	= NULL;
			}
		}
		if(mFreePalette && mPalette)
		{
			delete mPalette;
			mPalette = NULL;
		}
	}

	void Image::load(const std::string& pFileName,const ImageLoader& pImageLoader)
	{
		pImageLoader.load(*this,pFileName);
	}

	void Image::load(Core::File& pFile, const ImageLoader& pImageLoader)
	{
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

	void Image::create
	(
		const int& pWidth,
		const int& pHeight,
		const int& pBpp,
		const int& pColor
	)
	{
		if(mData && !mImgLinked)
		{
			destroy_bitmap(mData);
		}
		if(mDataBuffer)
		{
			destroy_bitmap(mDataBuffer);
		}
		if(mPalette && mFreePalette)
		{
			delete mPalette;
		}

		mData			= (pBpp < 8) ? create_bitmap_ex(8,pWidth,pHeight) : create_bitmap_ex(pBpp,pWidth,pHeight);
		mDataBuffer		= NULL;
		mPalette		= NULL;
		mImgLinked		= false;
		mFreePalette	= true;
		clear(pColor);
		updateBuffer();
	}

	std::string Image::describe() const
	{
		std::stringstream out;
		out << "Image Descriptor" 	<< std::endl;
		out << "Have Data:      " 	<< (mData 			? "Yes" : "No") << std::endl;
		out << "Image Linked:   " 	<< (mImgLinked		? "Yes" : "No") << std::endl;
		out << "Have Palette:   " 	<< (mPalette		? "Yes" : "No") << std::endl;
		out << "Palette Linked: " 	<< (!mFreePalette	? "Yes" : "No")	<< std::endl;
		if(mData)
		{
			out << "Width:          " 	<< getWidth() 		<< std::endl;
			out << "Height:         " 	<< getHeight() 		<< std::endl;
			out << "BPP:            " 	<< getColorDepth()	<< std::endl;
		}
		return out.str();
	}

	/**@todo remover esse método*/
	void Image::setImg(BITMAP* pBitmap)
	{
		if(mData)
		{
			destroy_bitmap(mData);
		}
		mData		= pBitmap;
		mImgLinked	= true;
		updateBuffer();
	}
	/**@todo remover esse método*/
	void Image::setType(const char& pImgType)
	{
		mImgType = pImgType;
	}

	void Image::setPalette(Palette* pPalette, const bool& pFreeSource)
	{
		mPalette		= pPalette;
		mFreePalette	= pFreeSource;
		updateBuffer();
	}

	void Image::setPalette(const Palette& pPalette)
	{
		mPalette		= pPalette.copy();
		mFreePalette	= true;
		updateBuffer();
	}

	void Image::usePalette() const
	{
		if(mPalette)
		{
			mPalette->set();
		}
	}

	void Image::updateBuffer()
	{
		/**
		 * @todo criar o bpp de acordo com o usado no geral
		 * */
		if(mData && getColorDepth() == 8)
		{
			if(!mDataBuffer)
			{
				mDataBuffer = create_bitmap_ex(get_color_depth(),getWidth(),getHeight());
			}
			else if(mDataBuffer->w != mData->w || mDataBuffer->h != mData->h)
			{
				destroy_bitmap(mDataBuffer);
				mDataBuffer = create_bitmap_ex(get_color_depth(),getWidth(),getHeight());
			}
			usePalette();
			blit
			(
				mData,
				mDataBuffer,
				0,0,0,0,
				getWidth(),
				getHeight()
			);
		}
		else
		{
			mDataBuffer = mData;
		}
	}

	Palette* Image::getPalette() const
	{
		return mPalette;
	}

	/**@todo remover esse método*/
	BITMAP* Image::getImg() const
	{
		return mDataBuffer;
	}

	int Image::getColorDepth() const
	{
		return (mData != NULL) ? bitmap_color_depth(mData) : 0;
	}
	
	int Image::getColorNumber() const
	{
		std::vector<int> colors;
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
		}
		return colors.size();
	}
	
	int Image::getPixel
	(
		const int&	pPosX,
		const int&	pPosY,
		const bool&	pAbsoluteValue
	) const
	{
		/**@todo remover esse método deixar somente o método abaixo*/
		if(mData == NULL)
		{
			std::stringstream out;
			out << "Image::getPixel(" << pPosX << ", " << pPosY << ", ";
			out << (pAbsoluteValue ? "true" : "false") << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		if(getColorDepth() == 8 && mPalette && !pAbsoluteValue)
		{
			return getPalette()->getColor(getpixel(mData,pPosX,pPosY));
		}
		return getpixel(mData,pPosX,pPosY);
	}
	
	int Image::getPixel(const Core::Point& pPosition, const bool& pAbsoluteValue) const
	{
		if(mData == NULL)
		{
			std::stringstream out;
			out << "Image::getPixel(Core::Point(" << pPosition.getX() << "," << pPosition.getY()<< "), ";
			out << (pAbsoluteValue ? "true" : "false") << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		if(getColorDepth() == 8 && mPalette && !pAbsoluteValue)
		{
			return getPalette()->getColor(getpixel(mData,pPosition.getX(),pPosition.getY()));
		}
		return getpixel(mData,pPosition.getX(),pPosition.getY());
	}
	/**@todo mudar isso para point*/
	Color Image::getColor(const int& pPosX, const int& pPosY) const
	{
		if(mData == NULL)
		{
			std::stringstream out;
			out << "Image::getColor(" << pPosX << ", " << pPosY << ", ";
			out << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		if(getColorDepth() == 8 && mPalette)
		{
			return Color(getPalette()->getColor(getpixel(mData,pPosX,pPosY)));
		}
		return Color(getpixel(mData,pPosX,pPosY));
	}

	unsigned int Image::getWidth() const
	{
		return (mData != NULL) ? mData->w : 0;
	}

	unsigned int Image::getHeight() const
	{
		return (mData != NULL) ? mData->h : 0;
	}

	/**@todo remover esse método*/
	char Image::getType() const
	{
		return mImgType;
	}

	int Image::getDelimiterUp()  const
	{
		int i,j, transparent = makecol(255,0,255);
		bool col = false;
		for(j=0; j < getHeight(); ++j)
		{
			for(i = 0; i < getWidth(); ++i)
			{
				if(getPixel(i,j) != transparent)
				{
					col = true;
					break;
				}
			}
			if(col)
			{
				break;
			}
		}
		return j;
	}

	int Image::getDelimiterLeft()  const
	{
		int i,j, transparent = makecol(255,0,255);
		bool col = false;
		for(i = 0; i < getWidth(); ++i)
		{
			for(j = 0; j < getHeight(); ++j)
			{
				if(getPixel(i,j) != transparent)
				{
					col = true;
					break;
				}
			}
			if(col)
			{
				break;
			}
		}
		return i;
	}

	int Image::getDelimiterDown()  const
	{
		int i,j, transparent=makecol(255,0,255);
		bool col=false;
		for(j = getHeight()-1; j > -1; --j)
		{
			for(i = getWidth()-1; i > -1; --i)
			{
				if(getPixel(i,j) != transparent)
				{
					col = true;
					break;
				}
			}
			if(col)
			{
				break;
			}
		}
		return getHeight() - (j+1);
	}

	int Image::getDelimiterRight()  const
	{
		int i,j, transparent = makecol(255,0,255);
		bool col = false;
		for(i = getWidth()-1; i > -1; --i)
		{
			for(j = 0; j < getHeight(); ++j)
			{
				if(getPixel(i,j) != transparent)
				{
					col = true;
					break;
				}
			}
			if(col)
			{
				break;
			}
		}
		return getWidth() - (i+1);
	}

	void Image::clip
	(
		const int& pPosX,
		const int& pPosY,
		const int& pWidth,
		const int& pHeight
	)
	{
		if(!mData)
		{
			return;
		}
		if((pWidth != getWidth() || pHeight != getHeight()) && pWidth > 0 && pHeight > 0)
		{
			BITMAP* aux = create_bitmap_ex(getColorDepth(), pWidth, pHeight);
			blit
			(
				mData,
				aux,
				pPosX,
				pPosY,
				0,
				0,
				pWidth,
				pHeight
			);
			setImg(aux);
			mImgLinked = false;
		}
	}

	void Image::clipNoBorder()
	{
		int x = getDelimiterLeft();
		int y = getDelimiterUp();
		clip
		(
			x,
			y,
			getWidth() - x - getDelimiterRight(),
			getHeight() - y - getDelimiterDown()
		);
	}

	void Image::clear(const int& pColor)
	{
		if(mData == NULL)
		{
			std::stringstream out;
			out << "Image::clear(" << pColor << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		clear_to_color(mData,pColor);
	}
//-------------------------------------------------------------PRIMITIVES-----------------------------------------------------------

	void Image::drawPixel
	(
		const int& pPosX,
		const int& pPosY,
		const int& pColor
	)
	{
		if(mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawPixel(" << pPosX << ", " << pPosY << ", ";
			//out << "Color(" << pColor.getRed() << "," << pColor.getGreen() << "," << pColor.getBlue() << "," << pColor.getAlpha() << ")";
			out << pColor;
			out << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		/**
		 * @todo depois eu posso criar ponteiros para as funções e chamar por lá para evitar o switch
		 */
		//printf("BPP: %d - %d \n",getColorDepth(),get_color_depth());

		switch(getColorDepth())
		{
			case 8:		_putpixel(mData, pPosX, pPosY, pColor);		break;
			case 15:	_putpixel15(mData, pPosX, pPosY, pColor);	break;
			case 16:	_putpixel16(mData, pPosX, pPosY, pColor);	break;
			case 24:	_putpixel24(mData, pPosX, pPosY, pColor);	break;
			case 32:	_putpixel32(mData, pPosX, pPosY, pColor);	break;
		}
	}

	void Image::drawLine(const Core::Point& pPos1, const Core::Point& pPos2, const Color& pColor)
	{
		if(mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawLine(Core::Point(" << pPos1.getX() << "," << pPos1.getY() << "), Core::Point(" << pPos2.getX() << "," << pPos2.getY() << "), ";
			out << "Color(" << pColor.getRed() << "," << pColor.getGreen() << "," << pColor.getBlue() << "," << pColor.getAlpha() << ")";
			out << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		line
		(
			mData,
			pPos1.getX(), pPos1.getY(),
			pPos2.getX(), pPos2.getY(),
			pColor.get()
		);
	}

	void Image::drawRectangle
	(
		const Core::Point&	pPos1,
		const Core::Point&	pPos2,
		const Color&		pColor,
		const bool&			pFill
	)
	{
		if(mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawRectangle(Core::Point(" << pPos1.getX() << "," << pPos1.getY() << "), Core::Point(" << pPos2.getX() << "," << pPos2.getY() << "), ";
			out << "Color(" << pColor.getRed() << "," << pColor.getGreen() << "," << pColor.getBlue() << "," << pColor.getAlpha() << "), ";
			out << (pFill ? "true" : "false") << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}

		if(pFill)
		{
			rectfill
			(
				mData,
				pPos1.getX(), pPos1.getY(),
				pPos2.getX(), pPos2.getY(),
				pColor.get()
			);
		}
		else
		{
			rect
			(
				mData,
				pPos1.getX(), pPos1.getY(),
				pPos2.getX(), pPos2.getY(),
				pColor.get()
			);
		}
	}
	
	void Image::drawCircle
	(
		const Core::Point&	pPosition,
		const int&			pRadius,
		const Color&		pColor,
		const bool&			pFill
	)
	{
		if(mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawCircle(Core::Point(" << pPosition.getX() << "," << pPosition.getY() << ")," << pRadius;
			out << ",Color(" << pColor.getRed() << "," << pColor.getGreen() << "," << pColor.getBlue() << "," << pColor.getAlpha() << "),";
			out << (pFill ? "true" : "false") << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		if(pFill)
		{
			circlefill
			(
				mData,
				pPosition.getX(),
				pPosition.getY(),
				pRadius,
				pColor.get()
			);
		}
		else
		{
			circle
			(
				mData,
				pPosition.getX(),
				pPosition.getY(),
				pRadius,
				pColor.get()
			);
		}
	}

	void Image::drawEllipse
	(
		const Core::Point&	pPosition,
		const int&			pRadiusX,
		const int&			pRadiusY,
		const Color&		pColor,
		const bool&			pFill
	)
	{
		if(mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawEllipse(Core::Point(" << pPosition.getX() << "," << pPosition.getY() << "), " << pRadiusX << ", " << pRadiusY << ", ";
			out << "Color(" << pColor.getRed() << "," << pColor.getGreen() << "," << pColor.getBlue() << "," << pColor.getAlpha() << "), ";
			out << (pFill ? "true" : "false") << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		if(pFill)
		{
			ellipsefill
			(
				mData,
				pPosition.getX(),
				pPosition.getY(),
				pRadiusX,
				pRadiusY,
				pColor.get()
			);
		}
		else
		{
			ellipse
			(
				mData,
				pPosition.getX(),
				pPosition.getY(),
				pRadiusX,
				pRadiusY,
				pColor.get()
			);
		}
	}

	void Image::blitImage
	(
		const Image&		pImage,
		const Core::Point&	pPosition,
		const Core::Point&	pSourcePosition,
		const int&			pWidth,
		const int&			pHeight,
		const bool&			pMasked
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			std::stringstream out;
			out << "Image::blitImage(" << (int)&pImage << ", Core::Point(" << pPosition.getX() << "," << pPosition.getY();
			out << "), Core::Point(" << pSourcePosition.getX() << "," << pSourcePosition.getY() << "), ";
			out << pWidth << ", " << pHeight << (pMasked ? "true" : "false") << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		int width	= (pWidth	== -1) ? pImage.getWidth()	: pWidth;
		int height	= (pHeight	== -1) ? pImage.getHeight()	: pHeight;
		pImage.usePalette();
		if(pMasked)
		{
			masked_blit
			(
				pImage.mDataBuffer,
				mData,
				pSourcePosition.getX(),
				pSourcePosition.getY(),
				pPosition.getX(),
				pPosition.getY(),
				width,
				height
			);
		}
		else
		{
			blit
			(
				pImage.mDataBuffer,
				mData,
				pSourcePosition.getX(),
				pSourcePosition.getY(),
				pPosition.getX(),
				pPosition.getY(),
				width,
				height
			);
		}
	}

	void Image::blitImageStretched
	(
		const Image&		pImage,
		const Core::Point&	pPosition,
		const int&			pWidth,
		const int&			pHeight,
		const Core::Point&	pSourcePosition,
		const int&			pSourceWidth,
		const int&			pSourceHeight,
		const bool&			pMasked
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			std::stringstream out;
			out << "Image::blitImageStretched(" << (int)&pImage << ", Core::Point(" << pPosition.getX() << "," << pPosition.getY() << "), ";
			out << pWidth << ", " << pHeight << ", Core::Point(" << pSourcePosition.getX() << "," << pSourcePosition.getY() << "), ";
			out << pSourceWidth << ", " << pSourceHeight << (pMasked ? "true" : "false") << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		int width			= (pWidth == -1)		?	getWidth()			: pWidth;
		int height			= (pHeight == -1)		?	getHeight()			: pHeight;
		int sourceWidth		= (pSourceWidth == -1)	?	pImage.getWidth()	: pSourceWidth;
		int sourceHeight	= (pSourceHeight == -1)	?	pImage.getHeight()	: pSourceHeight;
		
		if(pMasked)
		{
			masked_stretch_blit
			(
				pImage.mDataBuffer,
				mData,
				pSourcePosition.getX(),
				pSourcePosition.getY(),
				sourceWidth,
				sourceHeight,
				pPosition.getX(),
				pPosition.getY(),
				width,
				height
			);
		}
		else
		{
			stretch_blit
			(
				pImage.mDataBuffer,
				mData,
				pSourcePosition.getX(),
				pSourcePosition.getY(),
				sourceWidth,
				sourceHeight,
				pPosition.getX(),
				pPosition.getY(),
				width,
				height
			);
		}
	}

	void Image::drawImage(const Image& pImage, const Core::Point& pPosition)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawImage(" << (int)&pImage << ", Core::Point(" << pPosition.getX() << "," << pPosition.getY() << ")";
			out << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		draw_sprite
		(
			mData,
			pImage.mDataBuffer,
			pPosition.getX(),
			pPosition.getY()
		);
	}

	void Image::drawImageStretched
	(
		const Image&		pImage,
		const Core::Point&	pPosition,
		const int&			pWidth,
		const int&			pHeight
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawImageStretched(" << (int)&pImage << ", Core::Point(" << pPosition.getX() << "," << pPosition.getY() << "), ";
			out << pWidth << ", " << pHeight << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		stretch_sprite
		(
			mData,
			pImage.mDataBuffer,
			pPosition.getX(),
			pPosition.getY(),
			pWidth,
			pHeight
		);
	}

	void Image::drawImageFlipped
	(
		const Image&		pImage,
		const Core::Point&	pPosition,
		const Mirroring&	pMirroring
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawImageFlipped(" << (int)&pImage << ", Core::Point(" << pPosition.getX() << "," << pPosition.getY() << "), ";
			out << pMirroring.getType() << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		switch(pMirroring.getType())
		{
			case Mirroring::Normal:	drawImage(pImage,pPosition);															break;
			case Mirroring::VFlip:	draw_sprite_v_flip( mData, pImage.mDataBuffer, pPosition.getX(), pPosition.getY() );	break;
			case Mirroring::HFlip:	draw_sprite_h_flip( mData, pImage.mDataBuffer, pPosition.getX(), pPosition.getY() );	break;
			case Mirroring::VHFlip:	draw_sprite_vh_flip( mData, pImage.mDataBuffer, pPosition.getX(), pPosition.getY() );	break;
		}
	}

	void Image::drawImageTrans
	(
		const Image&		pImage,
		const Core::Point&	pPosition,
		const float&		pTrans
	)
	{
		if(mData == NULL || pImage.mDataBuffer == NULL)
		{
			std::stringstream out;
			out << "Image::drawImageTrans(" << (int)&pImage << ", Core::Point(" << pPosition.getX() << "," << pPosition.getY() << "), ";
			out << pTrans << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		set_trans_blender(255, 255, 255, 255*pTrans);
		drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
		draw_trans_sprite(mData, pImage.mDataBuffer, pPosition.getX(), pPosition.getY());
	}

	void Image::drawImageTransFlipped
	(
		const Image&		pImage,
		const Core::Point&	pPosition,
		const float&		pTrans,
		const Mirroring&	pMirroring
	)
	{
		if(mData == NULL || pImage.mDataBuffer == NULL)
		{
			std::stringstream out;
			out << "Image::drawImageTransFlipped(" << (int)&pImage << ", Core::Point(" << pPosition.getX() << "," << pPosition.getY() << "), ";
			out << pTrans << ", " << pMirroring.getType() << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		Image aux(getWidth(),getHeight());
		aux.drawImageFlipped(pImage,pPosition,pMirroring);
		drawImageTrans(aux,pPosition,pTrans);
	}

	void Image::drawImageAdd
	(
		const Image&		pImage,
		const Core::Point&	pPosition,
		const Color&		pColorAdd,
		const Color&		pColorSub,
		const float&		pTrans
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawImageAdd(" << (int)&pImage << ", Core::Point(" << pPosition.getX() << "," << pPosition.getY() << "), ";
			out << "Color(" << pColorAdd.getRed() << "," << pColorAdd.getGreen() << "," << pColorAdd.getBlue() << "," << pColorAdd.getAlpha() << "), ";
			out << "Color(" << pColorSub.getRed() << "," << pColorSub.getGreen() << "," << pColorSub.getBlue() << "," << pColorSub.getAlpha() << "), ";
			out << pTrans << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}

		const int xLimit = (getWidth()	> pImage.getWidth()		+ pPosition.getX()) ? pImage.getWidth()		+ pPosition.getX() : getWidth();
		const int yLimit = (getHeight()	> pImage.getHeight()	+ pPosition.getY()) ? pImage.getHeight()	+ pPosition.getY() : getHeight();
		const Color tranparent(255,0,255);
		register int i,j,x,y;
		register Color a;
		register Color b;
		const float aTransValue = 1 - pTrans;

		for(i = pPosition.getY(), y = 0; i < yLimit; ++i, ++y)
		{
			for(j = pPosition.getX(), x = 0; j < xLimit; ++j, ++x)
			{
				b = pImage.getColor(x,y);
				if(b != tranparent)
				{
					a = getColor(j,i);
					if(a != tranparent)
					{
						//fazer o somatorio das cores pColorSub + pColorAdd, antes
						drawPixel(j,i,(a*aTransValue + (b - pColorSub + pColorAdd)*pTrans).get());
					}
					else
					{
						drawPixel(j,i,b.get());
					}
				}
			}
		}
	}

	void Image::drawImageRotated
	(
		const Image&		pImage,
		const Core::Point&	pPosition,
		const int&			pAngle,
		const Core::Point&	pAlign
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawImageRotated(" << (int)&pImage << ", Core::Point(" << pPosition.getX() << "," << pPosition.getY() << "), ";
			out << pAngle << ", Core::Point(" << pAlign.getX() << "," << pAlign.getY() << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		pivot_sprite
		(
			mData				, pImage.mDataBuffer,
			pPosition.getX()	, pPosition.getY(),
			pAlign.getX()		, pAlign.getY(),
			itofix(pAngle)
		);
	}

	void Image::drawImageRotatedFlipped
	(
		const Image&		pImage,
		const Core::Point&	pPosition,
		const int&			pAngle,
		const Mirroring&	pMirroring,
		const Core::Point&	pAlign
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawImageRotatedFlipped(" << (int)&pImage << ", Core::Point(" << pPosition.getX() << "," << pPosition.getY() << "), ";
			out << pAngle << ", " << pMirroring.getType() << ", Core::Point(" << pAlign.getX() << "," << pAlign.getY() << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		switch(pMirroring.getType())
		{
			case Mirroring::Normal:
				drawImageRotated
				(
					pImage,
					pPosition,
					pAngle,
					pAlign
				);
				break;
			case Mirroring::VFlip:
				pivot_sprite_v_flip
				(
					mData				, pImage.mDataBuffer,
					pPosition.getX()	, pPosition.getY(),
					pAlign.getX()		, pAlign.getY(),
					itofix(pAngle)
				);
				break;
			case Mirroring::HFlip:
				pivot_sprite_v_flip
				(
					mData				, pImage.mDataBuffer,
					pPosition.getX()	, pPosition.getY(),
					pAlign.getX()		, pAlign.getY(),
					itofix(pAngle + 128)
				);
				break;
			case Mirroring::VHFlip:
				pivot_sprite
				(
					mData				, pImage.mDataBuffer,
					pPosition.getX()	, pPosition.getY(),
					pAlign.getX()		, pAlign.getY(),
					itofix(pAngle+128)
				);
				break;
		}
	}

	void Image::drawText
	(
		const std::string&	pText,
		const Core::Point&	pPosition,
		const Color&		pColor,
		const Color&		pBgColor
	)
	{
		if(mData == NULL)
		{
			std::stringstream out;
			out << "Image::drawText(" << pText << ", Core::Point(" << pPosition.getX() << "," << pPosition.getY() << "), ";
			out << "Color(" << pColor.getRed() << "," << pColor.getGreen() << "," << pColor.getBlue() << "," << pColor.getAlpha() << "), ";
			out << "Color(" << pBgColor.getRed() << "," << pBgColor.getGreen() << "," << pBgColor.getBlue() << "," << pBgColor.getAlpha() << "), ";
			out << "): Error, trying the access a non loaded image";
			raiseGraphicException(out.str());
		}
		textout_ex
		(
			mData,
			font,
			pText.c_str(),
			pPosition.getX(),
			pPosition.getY(),
			pColor.get(),
			pBgColor.get()
		);
	}

	void Image::drawText
	(
		const Core::Point&	pPosition,
		const Color&		pColor,
		const Color&		pBgColor,
		const char*			pText,
		...
	)
	{
		char buf[512];
		va_list ap;
		ASSERT(mData);
		ASSERT(pText);
		va_start(ap,pText);
		uvszprintf(buf,sizeof(buf),pText,ap);
		va_end(ap);

		drawText(buf,pPosition,pColor,pBgColor);
	}

	bool Image::isEmpty() const
	{
		register int h,w;
		Color trans(255,0,255);
		for(h = getHeight() - 1; h > -1; --h)
		{
			for(w = getWidth() - 1; w > -1; --w)
			{
				if(getColor(w,h) != trans)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool Image::operator ==(const Image& pImage) const
	{
		register int h,w;
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
		}
	}

	void Image::operator =(const Image& pImage)
	{
		mData		= NULL;
		mDataBuffer	= NULL;
		mPalette	= NULL;
		setType(pImage.getType());

		if(pImage.mPalette)
		{
			setPalette(pImage.getPalette()->copy());
		}
		if(pImage.mData)
		{
			mData = create_bitmap_ex
			(
				pImage.getColorDepth(),
				pImage.getWidth(),
				pImage.getHeight()
			);
			blit
			(
				pImage.mData,
				mData,
				0,
				0,
				0,
				0,
				pImage.getWidth(),
				pImage.getHeight()
			);
		}
		updateBuffer();
		mImgLinked	= false;
		mFreePalette = true;
	}
}}
