#include "graphic/gorgon_sprite.hpp"

namespace Gorgon
{
	Sprite::Sprite
	(
		const Image&	pImage,
		const int&		pGroup,
		const int&		pIndex,
		const int&		pXOffset,
		const int&		pYOffset
	) : Image(pImage)
	{
		mGroup		= pGroup;
		mIndex		= pIndex;
		mXOffset	= pXOffset;
		mYOffset	= pYOffset;
	}

	Sprite::Sprite(const std::string& pSpriteName) : Image()
	{
		load(pSpriteName);
	}

	Sprite::Sprite(Core::File& pFile) : Image()
	{
		load(pFile);
	}

	Sprite::Sprite(const Sprite& pSpriteOrig) : Image(pSpriteOrig)
	{
		mGroup		= pSpriteOrig.mGroup;
		mIndex		= pSpriteOrig.mIndex;
		mXOffset	= pSpriteOrig.mXOffset;
		mYOffset	= pSpriteOrig.mYOffset;
	}	

	Sprite::~Sprite()
	{
		//std::cout << "Group:   " << mGroup	<< std::endl;
		//std::cout << "Index:   " << mIndex	<< std::endl << std::endl;
	}
	
	std::string Sprite::describe() const
	{
		std::stringstream out;
		out << "Gorgon Sprite"			<< std::endl;
		out << "Group:   " << mGroup	<< std::endl;
		out << "Index:   " << mIndex	<< std::endl;
		out << "xOffset: " << mXOffset	<< std::endl;
		out << "yOffset: " << mYOffset	<< std::endl;
		out << Image::describe();
		return out.str();
	}
	
	void Sprite::clipNoBorder()
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
		setXOffset(getXOffset() - x);
		setYOffset(getYOffset() - y);
	}
	
	void Sprite::load(const std::string& pSpriteName)
	{
		Core::File file(pSpriteName,std::ios::in | std::ios::binary);
		
		if(file.is_open())
		{
			load(file);
		}
		else
		{
			throw SpriteException("Unable to load Sprite: "+pSpriteName+".");
		}
		
	}

	void Sprite::load(Core::File& pFile)
	{
		SpriteHeader header(pFile);
		if(header.isValid())
		{
			pFile.readInt8();					//retirar isso no future
			
			ImageLoaderAutodetect ImageLoader;
			ImageLoader.load(*this,pFile);

			setGroup	(pFile.readInt32());
			setIndex	(pFile.readInt32());
			setXOffset	(pFile.readInt32());
			setYOffset	(pFile.readInt32());
		}
		else
		{
			header.returnFilePosition(pFile);
			throw SpriteException("Unable to load Sprite due to incorrect format.");
		}
	}

	void Sprite::save(const std::string& pSpriteName,const ImageLoader& pImageLoader)
	{
		Core::File file(pSpriteName,std::ios::out | std::ios::binary);

		if(file.is_open())
		{
			save(file,pImageLoader);
		}
		else
		{
			throw SpriteException("Unable to save Sprite: "+pSpriteName+".");
		}
	}

	void Sprite::save(Core::File& pFile,const ImageLoader& pImageLoader)
	{
		SpriteHeader::save(pFile);
		
		pFile.writeInt8( 0 ); //retirar isso

		pImageLoader.save( static_cast<Image&>(*this),pFile);
		
		pFile.writeInt32(getGroup());
		pFile.writeInt32(getIndex());
		pFile.writeInt32(getXOffset());
		pFile.writeInt32(getYOffset());
	}

	void Sprite::setGroup(const int& pGroup)
	{
		mGroup = pGroup;
	}

	void Sprite::setIndex(const int& pIndex)
	{
		mIndex = pIndex;
	}

	void Sprite::setXOffset(const int& pXOffset)
	{
		mXOffset = pXOffset;
	}

	void Sprite::setYOffset(const int& pYOffset)
	{
		mYOffset = pYOffset;
	}

	const int& Sprite::getGroup() const
	{
		return mGroup;
	}

	const int& Sprite::getIndex() const
	{
		return mIndex;
	}

	const int& Sprite::getXOffset()	const
	{
		return mXOffset;
	}

	const int& Sprite::getYOffset()	const
	{
		return mYOffset;
	}

	void Sprite::drawSprite
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY
	)
	{
		drawImage
		(
			pSprite,
			pPosX - pSprite.getXOffset(),
			pPosY - pSprite.getYOffset()
		);
	}

	void Sprite::drawSpriteStretched
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pXScale,
		const int&		pYScale
	)
	{
		drawImageStretched
		(
			pSprite,
			pPosX - (pSprite.getXOffset() * pXScale),
			pPosY - (pSprite.getYOffset() * pYScale),
			pSprite.getWidth() * pXScale,
			pSprite.getHeight() * pYScale
		);
	}

	void Sprite::drawSpriteFlipped
	(
		const Sprite&		pSprite,
		const int&			pPosX,
		const int&			pPosY,
		const Mirroring&	pMirroring
	)
	{
		switch(pMirroring.getType())
		{
			case Mirroring::Normal:	drawSprite(pSprite,pPosX,pPosY);			break;
			case Mirroring::VFlip:	drawSpriteFlippedV(pSprite,pPosX,pPosY);	break;
			case Mirroring::HFlip:	drawSpriteFlippedH(pSprite,pPosX,pPosY);	break;
			case Mirroring::VHFlip:	drawSpriteFlippedVH(pSprite,pPosX,pPosY);	break;
		}
	}

	void Sprite::drawSpriteFlippedV
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY
	)
	{
		drawImageFlippedV
		(
			pSprite,
			pPosX - pSprite.getXOffset(),
			pPosY - (pSprite.getHeight() - pSprite.getYOffset())
		);
	}

	void Sprite::drawSpriteFlippedH
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY
	)
	{
		drawImageFlippedH
		(
			pSprite,
			pPosX - (pSprite.getWidth() - pSprite.getXOffset()),
			pPosY - pSprite.getYOffset()
		);
	}

	void Sprite::drawSpriteFlippedVH
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY
	)
	{
		drawImageFlippedVH
		(
			pSprite,
			pPosX - (pSprite.getWidth() - pSprite.getXOffset()),
			pPosY - (pSprite.getHeight() - pSprite.getYOffset())
		);
	}

	void Sprite::drawSpriteTrans
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY,
		const float&	pTrans
	)
	{
		drawImageTrans
		(
			pSprite,
			pPosX - pSprite.getXOffset(),
			pPosY - pSprite.getYOffset(),
			pTrans
		);
	}

	void Sprite::drawSpriteTransFlipped
	(
		const Sprite&		pSprite,
		const int&			pPosX,
		const int&			pPosY,
		const float&		pTrans,
		const Mirroring&	pMirroring
	)
	{
		drawImageTransFlipped
		(
			pSprite,
			pPosX - pSprite.getXOffset(),
			pPosY - pSprite.getYOffset(),
			pTrans,
			pMirroring
		);
	}

	void Sprite::drawSpriteAdd
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY,
		const Color&	pColorAdd,
		const Color&	pColorSub,
		const float&	pTrans
	)
	{
		drawImageAdd
		(
			pSprite,
			pPosX - pSprite.getXOffset(),
			pPosY - pSprite.getYOffset(),
			pColorAdd,
			pColorSub,
			pTrans
		);
	}

	void Sprite::drawSpriteRoteted
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pAngle
	)
	{
		drawImageRoteted
		(
			pSprite,
			pPosX,
			pPosY,
			pAngle,
			pSprite.getXOffset(),
			pSprite.getYOffset()
		);
	}

	void Sprite::drawSpriteRotetedFlipped
	(
		const Sprite&		pSprite,
		const int&			pPosX,
		const int&			pPosY,
		const int&			pAngle,
		const Mirroring&	pMirroring
	)
	{
		switch(pMirroring.getType())
		{
			case Mirroring::Normal:	drawSpriteRoteted(pSprite,pPosX,pPosY,pAngle);			break;
			case Mirroring::VFlip:	drawSpriteRotetedFlippedV(pSprite,pPosX,pPosY,pAngle);	break;
			case Mirroring::HFlip:	drawSpriteRotetedFlippedH(pSprite,pPosX,pPosY,pAngle);	break;
			case Mirroring::VHFlip:	drawSpriteRotetedFlippedVH(pSprite,pPosX,pPosY,pAngle);	break;
		}
	}

	void Sprite::drawSpriteRotetedFlippedV
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pAngle
	)
	{
		drawImageRotetedFlippedV
		(
			pSprite,
			pPosX,
			pPosY,
			pAngle,
			pSprite.getXOffset(),
			pSprite.getHeight() - pSprite.getYOffset()
		);
	}

	void Sprite::drawSpriteRotetedFlippedH
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pAngle
	)
	{
		drawImageRotetedFlippedH
		(
			pSprite,
			pPosX,
			pPosY,
			pAngle,
			pSprite.getXOffset(),
			pSprite.getHeight() - pSprite.getYOffset()
		);
	}

	void Sprite::drawSpriteRotetedFlippedVH
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pAngle
	)
	{
		drawImageRotetedFlippedVH
		(
			pSprite,
			pPosX,
			pPosY,
			pAngle,
			pSprite.getXOffset(),
			pSprite.getYOffset()
		);
	}

	void Sprite::blitSprite
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pSourcePosX,
		const int&		pSourcePosY,
		const int&		pWidth,
		const int&		pHeight,
		const bool&		pMasked
	)
	{
		blitImage
		(
			pSprite,
			pPosX - pSprite.getXOffset(),
			pPosY - pSprite.getYOffset(),
			pSourcePosX,
			pSourcePosY,
			pWidth,
			pHeight,
			pMasked
		);
	}

	void Sprite::blitSpriteStretched
	(
		const Sprite&	pSprite,
		const int&		pPosX,
		const int&		pPosY,
		const int&		pXScale,
		const int&		pYScale,
		const int&		pSourcePosX,
		const int&		pSourcePosY,
		const int&		pSourceWidth,
		const int&		pSourceHeight,
		const bool&		pMasked
	)
	{
		blitImageStretched
		(
			pSprite,
			pPosX-(pXScale * pSprite.getXOffset()),
			pPosY-(pYScale * pSprite.getYOffset()),
			pSprite.getWidth() * pXScale,
			pSprite.getHeight() * pYScale,
			pSourcePosX,
			pSourcePosY,
			pSourceWidth,
			pSourceHeight,
			pMasked
		);
	}
}
