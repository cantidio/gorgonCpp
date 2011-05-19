#include <graphic/sprite.hpp>
#include <graphic/exception.hpp>

namespace Gorgon{
namespace Graphic
{
	Sprite::Sprite
	(
		const Image&		pImage,
		const int&			pGroup,
		const int&			pIndex,
		const Core::Point&	pOffset
	) : Image(pImage)
	{
		mGroup	= pGroup;
		mIndex	= pIndex;
		mOffset	= pOffset;
	}

	Sprite::Sprite(const std::string& pSpriteName, const ImageLoader& pImageLoader) : Image()
	{
		load(pSpriteName,pImageLoader);
	}

	Sprite::Sprite(Core::File& pFile, const ImageLoader& pImageLoader) : Image()
	{
		load(pFile,pImageLoader);
	}

	Sprite::Sprite(const Sprite& pSpriteOrig) : Image(pSpriteOrig)
	{
		mGroup		= pSpriteOrig.mGroup;
		mIndex		= pSpriteOrig.mIndex;
		mOffset		= pSpriteOrig.mOffset;
	}	

	std::string Sprite::describe() const
	{
		std::stringstream out;
		out << "Gorgon Sprite"					<< std::endl;
		out << "Group:   " << mGroup			<< std::endl;
		out << "Index:   " << mIndex			<< std::endl;
		out << "xOffset: " << mOffset.getX()	<< std::endl;
		out << "yOffset: " << mOffset.getY()	<< std::endl;
		out << Image::describe();
		return out.str();
	}
	
	void Sprite::trim()
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
		setOffset( getOffset() - Core::Point(x,y) );
	}
	
	void Sprite::load(const std::string& pSpriteName, const ImageLoader& pImageLoader)
	{
		Core::File file(pSpriteName,std::ios::in | std::ios::binary);
		
		if(file.is_open())
		{
			load(file, pImageLoader);
		}
		else
		{
			raiseGraphicException("Sprite::load(\""+pSpriteName+"\"): Error, file couldn't be opened.");
		}
	}

	void Sprite::load(Core::File& pFile, const ImageLoader& pImageLoader)
	{
		if(!pFile.is_open())
		{
			raiseGraphicException("Sprite::load(pFile): Error, the file isn't opened for reading.");
		}
		SpriteHeader header;
		try
		{
			header.load(pFile);

			setGroup	(header.getGroup());
			setIndex	(header.getIndex());
			setOffset	(header.getOffset());

			pImageLoader.load
			(
				*this,
				pFile,
				header.getSizeOfData()
			);
		}
		catch(Core::Exception& exception)
		{
			header.returnFilePosition(pFile);
			raiseGraphicExceptionE("Sprite::load(pFile): Error loading the Sprite.",exception);
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
			raiseGraphicException("Sprite::save(\""+pSpriteName+"\"): Error, the file couldn't be opened fro writting.");
		}
	}

	void Sprite::save(Core::File& pFile,const ImageLoader& pImageLoader)
	{
		SpriteHeader header;
		try
		{
			//escreve o header vazio...
			header.save(pFile);
			std::streampos pos1 = pFile.tellp();

			pImageLoader.save(static_cast<Image&>(*this), pFile);

			std::streampos pos2 = pFile.tellp();

			header.returnFilePosition(pFile);

			header.setGroup		(mGroup);
			header.setIndex		(mIndex);
			header.setOffset	(mOffset);
			header.setSizeOfData(pos2 - pos1);
			/**@todo arrumar um jeito mais eficiente de se fazer isso, talvez o imageLoader retornar o tamanho da futura imagem*/
			header.save(pFile);//agora salva o header com seu valor verdadeiro
			pFile.seekp(pos2);//retorna o ponteiro para o seu lugar certo.
		}
		catch(Core::Exception& exception)
		{
			header.returnFilePosition(pFile);
			raiseGraphicExceptionE("Sprite::save(pFile): Error while saving Sprite.",exception);
		}
	}

	void Sprite::setGroup(const int& pGroup)
	{
		mGroup = pGroup;
	}

	void Sprite::setIndex(const int& pIndex)
	{
		mIndex = pIndex;
	}

	void Sprite::setOffset(const Core::Point& pOffset)
	{
		mOffset = pOffset;
	}

	int Sprite::getGroup() const
	{
		return mGroup;
	}

	int Sprite::getIndex() const
	{
		return mIndex;
	}

	Core::Point Sprite::getOffset() const
	{
		return mOffset;
	}

	void Sprite::drawSprite
	(
		const Sprite&	pSprite,
		const Core::Point&	pPosition
	)
	{
		drawImage(pSprite, pPosition - pSprite.mOffset );
	}

	void Sprite::drawSpriteStretched
	(
		const Sprite&		pSprite,
		const Core::Point&	pPosition,
		const int&			pXScale,
		const int&			pYScale
	)
	{
		drawImageStretched
		(
			pSprite,
			pPosition - (pSprite.getOffset() * Core::Point(pXScale,pYScale)),
			pSprite.getWidth() * pXScale,
			pSprite.getHeight() * pYScale
		);
	}

	void Sprite::drawSpriteFlipped
	(
		const Sprite&			pSprite,
		const Core::Point&		pPosition,
		const Mirroring&		pMirroring
	)
	{
		Core::Point position = pPosition - pSprite.mOffset;
		if((pMirroring.getType() & Mirroring::HFlip) == Mirroring::HFlip )
		{
			position.setX( position.getX() - (pSprite.getWidth() - pSprite.mOffset.getX()) );
		}
		if((pMirroring.getType() & Mirroring::VFlip) == Mirroring::VFlip )
		{
			position.setY( position.getY() - (pSprite.getHeight() - pSprite.mOffset.getY()) );
		}
		drawImageFlipped(pSprite, position, pMirroring);
	}

	void Sprite::drawSpriteTrans
	(
		const Sprite&		pSprite,
		const Core::Point&	pPosition,
		const float&		pTrans
	)
	{
		drawImageTrans(pSprite, pPosition - pSprite.mOffset, pTrans);
	}

	void Sprite::drawSpriteTransFlipped
	(
		const Sprite&		pSprite,
		const Core::Point&	pPosition,
		const float&		pTrans,
		const Mirroring&	pMirroring
	)
	{
		drawImageTransFlipped
		(
			pSprite,
			pPosition - pSprite.mOffset,
			pTrans,
			pMirroring
		);
	}

	void Sprite::drawSpriteAdd
	(
		const Sprite&		pSprite,
		const Core::Point&	pPosition,
		const Color&		pColorAdd,
		const Color&		pColorSub,
		const float&		pTrans
	)
	{
		drawImageAdd
		(
			pSprite,
			pPosition - pSprite.mOffset,
			pColorAdd,
			pColorSub,
			pTrans
		);
	}

	void Sprite::drawSpriteRotated
	(
		const Sprite&		pSprite,
		const Core::Point&	pPosition,
		const int&			pAngle
	)
	{
		drawImageRotated
		(
			pSprite,
			pPosition,
			pAngle,
			pSprite.mOffset
		);
	}

	void Sprite::drawSpriteRotatedFlipped
	(
		const Sprite&		pSprite,
		const Core::Point&	pPosition,
		const int&			pAngle,
		const Mirroring&	pMirroring
	)
	{
		Core::Point off = pSprite.mOffset;
		if(pMirroring.getType() == Mirroring::HFlip || pMirroring.getType() == Mirroring::VFlip)
		{
			off = Core::Point( pSprite.mOffset.getX(), pSprite.getHeight() - pSprite.mOffset.getY() );
		}
		drawImageRotatedFlipped( pSprite, pPosition, pAngle, pMirroring, off );
	}

	void Sprite::blitSprite
	(
		const Sprite&		pSprite,
		const Core::Point&	pPosition,
		const Core::Point&	pSourcePosition,
		const int&			pWidth,
		const int&			pHeight,
		const bool&			pMasked
	)
	{
		blitImage
		(
			pSprite,
			pPosition - pSprite.mOffset,
			pSourcePosition,
			pWidth,
			pHeight,
			pMasked
		);
	}

	void Sprite::blitSpriteStretched
	(
		const Sprite&		pSprite,
		const Core::Point&	pPosition,
		const int&			pXScale,
		const int&			pYScale,
		const Core::Point&	pSourcePosition,
		const int&			pSourceWidth,
		const int&			pSourceHeight,
		const bool&			pMasked
	)
	{
		blitImageStretched
		(
			pSprite,
			pPosition - (Core::Point(pXScale,pYScale)*pSprite.mOffset),
			pSprite.getWidth() * pXScale,
			pSprite.getHeight() * pYScale,
			pSourcePosition,
			pSourceWidth,
			pSourceHeight,
			pMasked
		);
	}
}}
