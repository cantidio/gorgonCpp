#include <graphic/spritepack.hpp>
#include <graphic/exception.hpp>
#include <sstream>

namespace Gorgon{
namespace Graphic
{
	Sprite* SpritePack::mNotFound = NULL;

	SpritePack::SpritePack()
	{
		if(mNotFound == NULL)	mNotFound = new Sprite( Image(1, 1) );
		mGlobalPalette	= new Palette(256);
		mPalLinked		= false;
	}

	SpritePack::SpritePack(const SpritePack& pSpritePackOriginal)
	{
		if(mNotFound == NULL)	mNotFound = new Sprite(Image(1,1));
/*@todo desalocar antes de receber*/
		mGlobalPalette	= NULL;
		mPalLinked		= false;
		(*this) = pSpritePackOriginal;
	}

	SpritePack::SpritePack(const std::string& pFileName, const ImageLoader& pImageLoader)
	{
		if(mNotFound == NULL)	mNotFound = new Sprite(Image(1,1));
		load(pFileName,pImageLoader);
	}

	SpritePack::SpritePack(Core::File& pFile, const ImageLoader& pImageLoader)
	{
		if(mNotFound == NULL)	mNotFound = new Sprite(Image(1,1));
		load(pFile,pImageLoader);
	}

	SpritePack::~SpritePack()
	{
		if(!mPalLinked && mGlobalPalette)
		{
			delete mGlobalPalette;
		}
		mSprites.clear();
	}

	void SpritePack::setGlobalOffset(const Core::Point& pOffset)
	{
		for(int i = 0; i < getSize(); ++i)
		{
			(*this)[i].setOffset(pOffset);
		}
	}

	void SpritePack::trimAll()
	{
		for(int i = 0; i < getSize(); ++i)
		{
			(*this)[i].trim();
		}
	}

	void SpritePack::add(const Sprite& pSprite)
	{
		mSprites.push_back(pSprite);
	}

	void SpritePack::add(const Sprite& pSprite,const int& pPos)
	{
		mSprites.insert(mSprites.begin() + pPos, pSprite);
	}

	void SpritePack::remove(const int& pPos)
	{
		if(pPos >= 0 && pPos < (int)mSprites.size())
		{
			mSprites.erase(mSprites.begin() + pPos);
		}
	}

	void SpritePack::remove(const int& pGroup,const int& pIndex)
	{
		remove(getSpriteRealIndex(pGroup,pIndex));
	}

	int SpritePack::getSize()	const
	{
		return mSprites.size();
	}

	int SpritePack::getSpriteRealIndex(const int& pGroup,const int& pIndex) const
	{
		for(int i = 0; i < (int)mSprites.size(); ++i)
		{
			if(mSprites[i].getGroup() == pGroup && mSprites[i].getIndex() == pIndex)
			{
				return i;
			}
		}
		return -1;
	}

	Sprite& SpritePack::getSprite(const int& pPos)
	{
		if(pPos >= 0 && pPos < (int)mSprites.size())
		{
			return mSprites[pPos];
		}
		return *mNotFound;
	}

	const Sprite& SpritePack::getSprite(const int& pPos) const
	{
		if(pPos >= 0 && pPos < (int)mSprites.size())
		{
			return mSprites[pPos];
		}
		return *mNotFound;
	}

	Sprite& SpritePack::getSprite(const int& group,const int& index)
	{
		return getSprite(getSpriteRealIndex(group,index));
	}

	const Sprite& SpritePack::getSprite(const int& group,const int& index) const
	{
		return getSprite(getSpriteRealIndex(group,index));
	}

	Sprite& SpritePack::operator [](const int& pPos)
	{
		return getSprite(pPos);
	}

	const Sprite& SpritePack::operator [](const int& pPos) const
	{
		return getSprite(pPos);
	}

	Sprite& SpritePack::operator ()(const int& pGroup,const int& pIndex)
	{
		return getSprite(pGroup,pIndex);
	}

	const Sprite& SpritePack::operator ()(const int& pGroup,const int& pIndex) const
	{
		return getSprite(pGroup,pIndex);
	}

	void SpritePack::operator =(const SpritePack& pSpritePack)
	{
		if(!mPalLinked && mGlobalPalette)
		{
			delete mGlobalPalette;
		}
		mSprites.clear();
		mGlobalPalette	= (pSpritePack.mGlobalPalette) ? pSpritePack.mGlobalPalette->clone() : NULL;
		mPalLinked		= false;
		for(register int i = 0; i < pSpritePack.getSize(); ++i)
		{
			add(Sprite(pSpritePack[i]));
		}
	}

	void SpritePack::setGlobalPalette(Palette* pPalette)
	{
		if(!mPalLinked && mGlobalPalette)
		{
			delete mGlobalPalette;
		}
		mGlobalPalette	= pPalette;
		mPalLinked		= true;
	}

	void SpritePack::applyGlobalPalette(const bool& pForce)
	{
		/**@todo utilizar openmp aqui*/
		for(register int i = 0; i < getSize(); ++i)
		{
			if(!getSprite(i).getPalette() || (getSprite(i).getPalette() && pForce))
			{
				getSprite(i).setPalette(mGlobalPalette,false);
			}
		}
	}

	/**
	 * Métodbo para criar uma paleta de cores global para todos os sprites do pacote
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	25/08/2008
	 * @version	25/08/2008
	 */
/*	void SpritePack::createGlobalPalette(int red, int green, int blue)
	{
		for(int i=0; i<this->size(); (*this)[i]->getOtimizedPalette(red,green,blue,this->globalPalette),++i);
	}*/

	void SpritePack::save(Core::File& pFile,const ImageLoader& pImageLoader)
	{
		const int spriteSize	= mSprites.size();
		bool globPal			= (mGlobalPalette) ? true : false;
		SpritePackHeader::save(pFile);
		
		pFile.writeBool(globPal);
		if(globPal)
		{
			mGlobalPalette->save(pFile);
		}
		
		pFile.writeInt32(spriteSize);
		for(int i = 0; i < spriteSize; ++i)
		{
			mSprites[i].save(pFile,pImageLoader);
		}
	}

	void SpritePack::save(const std::string& pFileName, const ImageLoader& pImageLoader)
	{;
		Core::File file(pFileName,std::ios::out | std::ios::binary);

		if(file.is_open())
		{
			try
			{
				save(file,pImageLoader);
				file.close();
			}
			catch(Core::Exception& exception)
			{
				raiseGraphicExceptionE("SpritePack::save(\""+pFileName+"\"): Error while saving the spritepack.",exception);
			}
		}
		else
		{
			raiseGraphicException("SpritepPack::save(\""+pFileName+"\"): Error, the file could not be opened for writting.");
		}
	}

	/**
	 * @todo tentar usar o algoritmo da zlib aqui
	 */
	void SpritePack::load(Core::File& pFile, const ImageLoader& pImageLoader)
	{
		if(pFile.is_open())
		{
			int					spriteSize;
			SpritePackHeader	header(pFile);

			if(header.isValid())
			{
				try
				{
					if(pFile.readBool())
					{
						mGlobalPalette = new Palette(pFile);
					}
					spriteSize = pFile.readInt32();
					for(int i = 0; i < spriteSize; ++i)
					{
						mSprites.push_back( Sprite(pFile,pImageLoader) );
					}
					mPalLinked = false;
				}
				catch(Core::Exception& exception)
				{
					raiseGraphicExceptionE("SpritePack::load(pFile): Error while loading the sprites into the spritepack.",exception);
				}
			}
			else
			{
				raiseGraphicException("SpritePack::load(pFile): Error, spritepack header seems to be invalid, maybe this isn't a gorgon spritepack");
			}
		}
		else
		{
			raiseGraphicException("SpritePack::load(pFile):Error, file is not opened for reading.");
		}
	}

	void SpritePack::load(const std::string& pFileName, const ImageLoader& pImageLoader)
	{
		Core::File file(pFileName,std::ios::in | std::ios::binary);
		if(file.is_open())
		{
			try
			{
				load(file, pImageLoader);
				file.close();
			}
			catch(Core::Exception& exception)
			{
				raiseGraphicExceptionE("SpritePack::load(\""+pFileName+"\"): Error while loading the spritepack",exception);
			}
		}
		else
		{
			raiseGraphicException("SpritePack::load(\""+pFileName+"\"): Error, the file couldn't be opened for reading.");
		}
	}
}}
