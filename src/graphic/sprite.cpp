#include <graphic/sprite.hpp>
#include <graphic/exception.hpp>
#include <sstream>

#include <core/debug.hpp>

namespace Gorgon{
namespace Graphic
{
	std::string Sprite::describe() const
	{
		std::stringstream out;
		out << "Gorgon::Graphic::Sprite::describe()\n";
		out << "Group:   " << mGroup			<< std::endl;
		out << "Index:   " << mIndex			<< std::endl;
		out << "xOffset: " << mOffset.getX()	<< std::endl;
		out << "yOffset: " << mOffset.getY()	<< std::endl;
		out << Image::describe();
		return out.str();
	}

	Sprite::Sprite()
	{
		mGroup	= 0;
		mIndex	= 0;
		mOffset	= Core::Point(0,0);
	}

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

	Sprite::Sprite(const Sprite& pSpriteOrig) : Image(pSpriteOrig)
	{
		mGroup		= pSpriteOrig.mGroup;
		mIndex		= pSpriteOrig.mIndex;
		mOffset		= pSpriteOrig.mOffset;
	}

	Sprite::Sprite(const std::string& pSpriteName) : Image()
	{
		load( pSpriteName );
	}

	Sprite::Sprite( Core::File& pFile ) : Image()
	{
		load( pFile );
	}

	void Sprite::trim()
	{
		/*int x = getDelimiterLeft();
		int y = getDelimiterUp();
		clip
		(
			x,
			y,
			getWidth() - x - getDelimiterRight(),
			getHeight() - y - getDelimiterDown()
		);
		setOffset( getOffset() - Core::Point(x,y) );*/
	}
	void Sprite::draw( const Core::Point& pPosition) const
	{
		Image::draw(pPosition - mOffset);
	}

	void Sprite::draw(const Core::Point& pPosition, const Mirroring& pMirroring) const//drawFlipped
	{
		Core::Point position = pPosition - mOffset;
		if((pMirroring.getType() & Mirroring::HFlip) == Mirroring::HFlip )
		{
			position.setX( position.getX() - (getWidth() - mOffset.getX()) );
		}
		if((pMirroring.getType() & Mirroring::VFlip) == Mirroring::VFlip )
		{
			position.setY( position.getY() - (getHeight() - mOffset.getY()) );
		}
		Image::draw(pPosition, pMirroring);
	}

	void Sprite::draw( const Core::Point& pPosition, const float& pAngle ) const//draw rotated
	{
		Image::draw(pPosition, pAngle, mOffset);
	}

	void Sprite::draw//draw rotated flipped
	(
		const Core::Point&	pPosition,
		const float&		pAngle,
		const Mirroring&	pMirroring
	) const
	{
		Core::Point offset = mOffset;
		if(pMirroring.getType() == Mirroring::HFlip || pMirroring.getType() == Mirroring::VFlip)
		{
			offset = Core::Point( mOffset.getX(), getHeight() - mOffset.getY() );
		}
		Image::draw(pPosition, pAngle, offset, pMirroring);
	}

	void Sprite::draw
	(
		const Core::Point& pPosition,
		const int& pWidth,
		const int& pHeight,
		const Mirroring& pMirroring
	) const //draw scaled flipped
	{
		Core::Point scaleFactor( pWidth / (float)getWidth(), pHeight / (float)getHeight() );//float necessário pois os operandos são int,  se não não retorna numeros quebrados
		Core::Point position;

		if((pMirroring.getType() & Mirroring::HFlip) == Mirroring::HFlip )
		{
			position.setX( pPosition.getX() - ( pWidth - mOffset.getX()*scaleFactor.getX() ));
		}
		else
		{
			position.setX( pPosition.getX() - mOffset.getX()*scaleFactor.getX() );
		}
		if((pMirroring.getType() & Mirroring::VFlip) == Mirroring::VFlip )
		{
			position.setY( pPosition.getY() - ( pHeight - mOffset.getY()*scaleFactor.getY() ));
		}
		else
		{
			position.setY( pPosition.getY() - mOffset.getY()*scaleFactor.getY() );
		}
		Image::draw
		(
			position,
			pWidth,
			pHeight,
			pMirroring
		);
	}

	void Sprite::draw(const Core::Point& pPosition, const Color& pTint) const//drawTinted
	{
		Image::draw(pPosition - mOffset, pTint);
	}

	void Sprite::draw
	(
		const Core::Point& pPosition,
		const Color& pTint,
		const Mirroring& pMirroring
	) const//drawTintedFlipped
	{
		Core::Point position = pPosition - mOffset;
		if((pMirroring.getType() & Mirroring::HFlip) == Mirroring::HFlip )
		{
			position.setX( position.getX() - (getWidth() - mOffset.getX()) );
		}
		if((pMirroring.getType() & Mirroring::VFlip) == Mirroring::VFlip )
		{
			position.setY( position.getY() - (getHeight() - mOffset.getY()) );
		}
		Image::draw(position,pTint,pMirroring);
	}

	void Sprite::draw
	(
		const Core::Point&	pPosition,
		const Color&		pTint,
		const float&		pAngle
	) const//drawTinted rotated
	{
		Image::draw(pPosition, pTint, pAngle, mOffset);
	}

	void Sprite::draw
	(
		const Core::Point&	pPosition,
		const Color&		pTint,
		const float&		pAngle,
		const Mirroring&	pMirroring
	) const//drawTinted rotated fliped
	{
		Core::Point offset = mOffset;
		if(pMirroring.getType() == Mirroring::HFlip || pMirroring.getType() == Mirroring::VFlip)
		{
			offset = Core::Point( mOffset.getX(), getHeight() - mOffset.getY() );
		}
		Image::draw(pPosition, pTint, pAngle, offset, pMirroring);
	}

	void Sprite::load( const std::string& pSpriteName )
	{
		Core::File file(pSpriteName,std::ios::in | std::ios::binary);

		if(file.is_open())
		{
			load( file );
		}
		else
		{
			raiseGraphicException("Sprite::load(\""+pSpriteName+"\"): Error, file couldn't be opened.");
		}
	}

	void Sprite::load( Core::File& pFile )
	{
		if(!pFile.is_open())
		{
			raiseGraphicException("Sprite::load(pFile): Error, the file isn't opened for reading.");
		}
		SpriteHeader header;
		try
		{
			header.load(pFile);

			setGroup	( header.getGroup()  );
			setIndex	( header.getIndex()  );
			setOffset	( header.getOffset() );

			Image::load( pFile, header.getSizeOfData() );
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
}}
