#include <graphic/gorgon_image.hpp>

namespace Gorgon
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
		mData		= pBitmap;
		mDataBuffer	= NULL;
		mPalette	= pPalette;
		mImgLinked	= true;
		mPalLinked	= true;
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
		mData		= (pBpp < 8) ? create_bitmap_ex(8,pWidth,pHeight) : create_bitmap_ex(pBpp,pWidth,pHeight);
		mDataBuffer	= NULL;
		mPalette	= NULL;
		mImgLinked	= false;
		mPalLinked	= false;
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
		if(!mPalLinked && mPalette)
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
		if(mPalette && !mPalLinked)
		{
			delete mPalette;
		}

		mData		= (pBpp < 8) ? create_bitmap_ex(8,pWidth,pHeight) : create_bitmap_ex(pBpp,pWidth,pHeight);
		mDataBuffer	= NULL;
		mPalette		= NULL;
		mImgLinked	= false;
		mPalLinked	= false;
		clear(pColor);
		updateBuffer();
	}

	std::string Image::describe() const
	{
		std::stringstream out;
		out << "Image Descriptor" 	<< std::endl;
		out << "Have Data:      " 	<< (mData 		? "Yes" : "No") << std::endl;
		out << "Image Linked:   " 	<< (mImgLinked	? "Yes" : "No") << std::endl;
		out << "Have Palette:   " 	<< (mPalette	? "Yes" : "No") << std::endl;
		out << "Palette Linked: " 	<< (mPalLinked	? "Yes" : "No")	<< std::endl;
		if(mData)
		{
			out << "Width:          " 	<< getWidth() 		<< std::endl;
			out << "Height:         " 	<< getHeight() 		<< std::endl;
			out << "BPP:            " 	<< getColorDepth()	<< std::endl;
		}
		return out.str();
	}

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

	void Image::setType(const char& pImgType)
	{
		mImgType = pImgType;
	}

	void Image::setPalette(Palette* pPalette)
	{
		mPalette	= pPalette;
		mPalLinked	= true;
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
		if(mData && getColorDepth() == 8)
		{
			if(!mDataBuffer)
			{
				mDataBuffer = create_bitmap_ex(32,getWidth(),getHeight());
			}
			else if(mDataBuffer->w != mData->w || mDataBuffer->h != mData->h)
			{
				destroy_bitmap(mDataBuffer);
				mDataBuffer = create_bitmap_ex(32,getWidth(),getHeight());
			}
			usePalette();
			blit
			(
				mData,
				mDataBuffer,
				0,
				0,
				0,
				0,
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

	BITMAP* Image::getImg() const
	{
		return mDataBuffer;
	}

	int Image::getColorDepth() const
	{
		if(mData == NULL)
		{
			throw ImageException("Trying to get the color depth of a non loaded Image.");
		}
		return bitmap_color_depth(mData);
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
		if(mData == NULL)
		{
			throw ImageException("Trying to get pixel of a non loaded Image.");
		}
		if(getColorDepth() == 8 && mPalette && !pAbsoluteValue)
		{
			return getPalette()->getColor(getpixel(mData,pPosX,pPosY));
		}
		return getpixel(mData,pPosX,pPosY);
	}
	
	int Image::getPixel(const Point& pPosition, const bool& pAbsoluteValue) const
	{
		if(mData == NULL)
		{
			throw ImageException("Trying to get pixel of a non loaded Image.");
		}
		if(getColorDepth() == 8 && mPalette && !pAbsoluteValue)
		{
			return getPalette()->getColor(getpixel(mData,pPosition.getX(),pPosition.getY()));
		}
		return getpixel(mData,pPosition.getX(),pPosition.getY());
	}
	
	Color Image::getColor(const int& pPosX, const int& pPosY) const
	{
		if(mData == NULL)
		{
			throw ImageException("Trying to get pixel of a non loaded Image.");
		}
		if(getColorDepth() == 8 && mPalette)
		{
			return Color(getPalette()->getColor(getpixel(mData,pPosX,pPosY)));
		}
		return Color(getpixel(mData,pPosX,pPosY));

	}

	unsigned int Image::getWidth() const
	{
		if(mData == NULL)
		{
			throw ImageException("Trying to get the width of a non loaded Image.");
		}
		return mData->w;
	}

	unsigned int Image::getHeight() const
	{
		if(mData == NULL)
		{
			throw ImageException("Trying to get the height of a non loaded Image.");
		}
		return mData->h;
	}

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
			throw ImageException("Trying to clear a non loaded Image.");
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
			throw ImageException("Trying to put a pixel in a non loaded Image.");
		}
		putpixel
		(
			mData,
			pPosX,
			pPosY,
			pColor
		);
	}

	void Image::drawLine
	(
		const int& pPosX1,
		const int& pPosY1,
		const int& pPosX2,
		const int& pPosY2,
		const int& pColor
	)
	{
		if(mData == NULL)
		{
			throw ImageException("Trying to draw a line in a non loaded Image.");
		}
		line
		(
			mData,
			pPosX1,
			pPosY1,
			pPosX2,
			pPosY2,
			pColor
		);
	}

	void Image::drawRectangle
	(
		const int&		pPosX1,
		const int&		pPosY1,
		const int&		pPosX2,
		const int&		pPosY2,
		const Color&	pColor,
		const bool&		pFill
	)
	{
		if(mData == NULL)
		{
			throw ImageException("Trying to draw a rectangle in a non loaded Image.");
		}
		if(pFill)
		{
			rectfill
			(
				mData,
				pPosX1,
				pPosY1,
				pPosX2,
				pPosY2,
				pColor.get()
			);
		}
		else
		{
			rect
			(
				mData,
				pPosX1,
				pPosY1,
				pPosX2,
				pPosY2,
				pColor.get()
			);
		}
	}

	void Image::drawRectangle
	(
		const Point&		pPosition,
		const Rectangle&	pRectangle,
		const Color&		pColor,
		const bool&			pFill
	)
	{
		const Point position = pRectangle.getPosition();
		drawRectangle
		(
			pPosition.getX() + position.getX(),
			pPosition.getY() + position.getY(),
			pPosition.getX() + position.getX() + pRectangle.getWidth(),
			pPosition.getY() + position.getY() + pRectangle.getHeight(),
			pColor,
			pFill
		);
	}
	
	void Image::drawCircle
	(
		const int&	pPosX,
		const int&	pPosY,
		const int&	pRadius,
		const int&	pColor,
		const bool&	pFill
	)
	{
		if(mData == NULL)
		{
			throw ImageException("Trying to draw a circle in a non loaded Image.");
		}
		if(pFill)
		{
			circlefill
			(
				mData,
				pPosX,
				pPosY,
				pRadius,
				pColor
			);
		}
		else
		{
			circle
			(
				mData,
				pPosX,
				pPosY,
				pRadius,
				pColor
			);
		}
	}

	void Image::drawEllipse
	(
		const int&	pPosX,
		const int&	pPosY,
		const int&	pRadiusX,
		const int&	pRadiusY,
		const int&	pColor,
		const bool&	pFill
	)
	{
		if(mData == NULL)
		{
			throw ImageException("Trying to draw a elipse in a non loaded Image.");
		}
		if(pFill)
		{
			ellipsefill
			(
				mData,
				pPosX,
				pPosY,
				pRadiusX,
				pRadiusY,
				pColor
			);
		}
		else
		{
			ellipse
			(
				mData,
				pPosX,
				pPosY,
				pRadiusX,
				pRadiusY,
				pColor
			);
		}
	}

	void Image::blitImage
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pSourcePosX,
		const int&		pSourcePosY,
		const int&		pWidth,
		const int&		pHeight,
		const bool&		pMasked
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to blit a non loaded Image.");
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
				pSourcePosX,
				pSourcePosY,
				pPosX,
				pPosY,
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
				pSourcePosX,
				pSourcePosY,
				pPosX,
				pPosY,
				width,
				height
			);
		}
	}

	void Image::blitImageStretched
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pWidth,
		const int&		pHeight,
		const int&		pSourceX,
		const int&		pSourceY,
		const int&		pSourceWidth,
		const int&		pSourceHeight,
		const bool&		pMasked
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to blit a non loaded Image.");
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
				pSourceX,
				pSourceY,
				sourceWidth,
				sourceHeight,
				pPosX,
				pPosY,
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
				pSourceX,
				pSourceY,
				sourceWidth,
				sourceHeight,
				pPosX,
				pPosY,
				width,
				height
			);
		}
	}

	void Image::drawImage
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		draw_sprite
		(
			mData,
			pImage.mDataBuffer,
			pPosX,
			pPosY
		);
	}

	void Image::drawImageStretched
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pWidth,
		const int&		pHeight
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		stretch_sprite
		(
			mData,
			pImage.mDataBuffer,
			pPosX,
			pPosY,
			pWidth,
			pHeight
		);
	}

	void Image::drawImageFlippedV
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		draw_sprite_v_flip
		(
			mData,
			pImage.mDataBuffer,
			pPosX,
			pPosY
		);
	}

	void Image::drawImageFlippedH
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		draw_sprite_h_flip
		(
			mData,
			pImage.mDataBuffer,
			pPosX,
			pPosY
		);
	}

	void Image::drawImageFlippedVH
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		draw_sprite_vh_flip
		(
			mData,
			pImage.mDataBuffer,
			pPosX,
			pPosY
		);
	}

	void Image::drawImageFlipped
	(
		const Image&		pImage,
		const int&			pPosX,
		const int&			pPosY,
		const Mirroring&	pMirroring
	)
	{
		switch(pMirroring.getType())
		{
			case Mirroring::Normal:	drawImage(pImage,pPosX,pPosY);			break;
			case Mirroring::VFlip:	drawImageFlippedV(pImage,pPosX,pPosY);	break;
			case Mirroring::HFlip:	drawImageFlippedH(pImage,pPosX,pPosY);	break;
			case Mirroring::VHFlip:	drawImageFlippedVH(pImage,pPosX,pPosY);	break;
		}
	}

	void Image::drawImageTrans
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY,
		const float&	pTrans
	)
	{
		if(mData == NULL || pImage.mDataBuffer == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		set_trans_blender(255, 255, 255, 255*pTrans);
		drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
		draw_trans_sprite(mData,pImage.mDataBuffer,pPosX,pPosY);
	}

	void Image::drawImageTransFlipped
	(
		const Image&		pImage,
		const int&			pPosX,
		const int&			pPosY,
		const float&		pTrans,
		const Mirroring&	pMirroring
	)
	{
		if(mData == NULL || pImage.mDataBuffer == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		Image aux(getWidth(),getHeight());
		aux.drawImageFlipped(pImage,0,0,pMirroring);
		drawImageTrans(aux,pPosX,pPosY,pTrans);

	}

	void Image::drawImageAdd
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY,
		const Color&	pColorAdd,
		const Color&	pColorSub,
		const float&	pTrans
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		/*set_trans_blender(pColorAdd.getRed(), pColorAdd.getGreen(), pColorAdd.getRed(), 255*pTrans);
		drawing_mode(DRAW_MODE_XOR, NULL, 0, 0);
		draw_trans_sprite(mData,pImage.mDataBuffer,pPosX,pPosY);*/
		
		const int xLimit = (getWidth()	> pImage.getWidth()		+ pPosX) ? pImage.getWidth()	+ pPosX : getWidth();
		const int yLimit = (getHeight()	> pImage.getHeight()	+ pPosY) ? pImage.getHeight()	+ pPosY : getHeight();
		const Color tranparent(255,0,255);
		register int i,j,x,y;
		register Color a;
		register Color b;
		const float aTransValue = 1 - pTrans;

		for(i = pPosY, y = 0; i < yLimit; ++i, ++y)
		{
			for(j = pPosX, x = 0; j < xLimit; ++j, ++x)
			{
				b = pImage.getColor(x,y);
				if(b != tranparent)
				{
					a = getColor(j,i);
					if(a != tranparent)
					{
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

	void Image::drawImageRoteted
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pAngle,
		const int&		pXAlign,
		const int&		pYAlign
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		pivot_sprite
		(
			mData,
			pImage.mDataBuffer,
			pPosX,
			pPosY,
			pXAlign,
			pYAlign,
			itofix(pAngle)
		);
	}

	void Image::drawImageRotetedFlipped
	(
		const Image&		pImage,
		const int&			pPosX,
		const int&			pPosY,
		const int&			pAngle,
		const Mirroring&	pMirroring,
		const int&			pXAlign,
		const int&			pYAlign
	)
	{
		switch(pMirroring.getType())
		{
			case Mirroring::Normal:	drawImageRoteted(pImage,pPosX,pPosY,pAngle,pXAlign,pYAlign);			break;
			case Mirroring::VFlip:	drawImageRotetedFlippedV(pImage,pPosX,pPosY,pAngle,pXAlign,pYAlign);	break;
			case Mirroring::HFlip:	drawImageRotetedFlippedH(pImage,pPosX,pPosY,pAngle,pXAlign,pYAlign);	break;
			case Mirroring::VHFlip:	drawImageRotetedFlippedVH(pImage,pPosX,pPosY,pAngle,pXAlign,pYAlign);	break;
		}
	}

	void Image::drawImageRotetedFlippedV
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pAngle,
		const int&		pXAlign,
		const int&		pYAlign
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		pivot_sprite_v_flip
		(
			mData,
			pImage.mDataBuffer,
			pPosX,
			pPosY,
			pXAlign,
			pYAlign,
			itofix(pAngle)
		);
	}

	void Image::drawImageRotetedFlippedH
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pAngle,
		const int&		pXAlign,
		const int&		pYAlign
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		pivot_sprite_v_flip
		(
			mData,
			pImage.mDataBuffer,
			pPosX,
			pPosY,
			pXAlign,
			pYAlign,
			itofix(pAngle + 128)
		);
	}

	void Image::drawImageRotetedFlippedVH
	(
		const Image&	pImage,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pAngle,
		const int&		pXAlign,
		const int&		pYAlign
	)
	{
		if(mData == NULL || pImage.mData == NULL)
		{
			throw ImageException("Trying to draw a non loaded Image.");
		}
		pivot_sprite
		(
			mData,
			pImage.mDataBuffer,
			pPosX,
			pPosY,
			pXAlign,
			pYAlign,
			itofix(pAngle+128)
		);
	}

	void Image::drawText
	(
		const std::string&	pText,
		const int&			pPosX,
		const int&			pPosY,
		const int&			pColor,
		const int&			pBgColor
	)
	{
		if(mData == NULL)
		{
			throw ImageException("Trying to draw Text in a non loaded Image.");
		}
		textout_ex
		(
			mData,
			font,
			pText.c_str(),
			pPosX,
			pPosY,
			pColor,
			pBgColor
		);
	}

	void Image::drawText
	(
		const int&	pPosX,
		const int&	pPosY,
		const int&	pColor,
		const int&	pBgColor,
		const char*	pText,
		...
	)
	{
		char buf[512];
		va_list ap;
		
		if(mData == NULL)
		{
			throw ImageException("Trying to draw Text in a non loaded Image.");
		}
		
		ASSERT(mData);
		ASSERT(pText);
		va_start(ap,pText);
		uvszprintf(buf,sizeof(buf),pText,ap);
		va_end(ap);
		textout_ex
		(
			mData,
			font,
			buf,
			pPosX,
			pPosY,
			pColor,
			pBgColor
		);
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

		if(pImage.getPalette())
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
		mPalLinked	= false;
	}
}

