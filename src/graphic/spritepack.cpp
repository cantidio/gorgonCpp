#include <graphic/spritepack.hpp>
#include <sstream>
#include <script/script.hpp>
/**
 * @todo retirar os scripts daqui, criar uma classe especializada*/
namespace Gorgon{
namespace Graphic
{
	Sprite* SpritePack::mNotFound = NULL;

	SpritePack::SpritePack()
	{
		if(mNotFound == NULL)
		{
			mNotFound = new Sprite(Image(1,1));
		}
		mGlobalPalette	= new Palette(255,0,255);
		mPalLinked		= false;
	}

	SpritePack::SpritePack(const SpritePack& pSpritePackOriginal)
	{
		if(mNotFound == NULL)
		{
			mNotFound = new Sprite(Image(1,1));
		}
		mGlobalPalette	= (pSpritePackOriginal.mGlobalPalette) ? pSpritePackOriginal.mGlobalPalette->copy() : NULL;
		mPalLinked		= false;
		for(unsigned int i = 0; i < pSpritePackOriginal.getSize(); ++i)
		{
			add(Sprite(pSpritePackOriginal[i]));
		}
	}

	SpritePack::SpritePack(const Core::String& pFileName)
	{
		if(mNotFound == NULL)
		{
			mNotFound = new Sprite(Image(1,1));
		}
		load(pFileName);
	}

	SpritePack::SpritePack(Core::File& pFile)
	{
		if(mNotFound == NULL)
		{
			mNotFound = new Sprite(Image(1,1));
		}
		load(pFile);
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
		for(unsigned int i = 0; i < getSize(); ++i)
		{
			(*this)[i].setOffset(pOffset);
		}
	}

	void SpritePack::trimAll()
	{
		for(unsigned int i = 0; i < getSize(); ++i)
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

	void SpritePack::remove(const unsigned int& pPos)
	{
		if(pPos >= 0 && pPos < mSprites.size())
		{
			mSprites.erase(mSprites.begin() + pPos);
		}
	}

	unsigned int SpritePack::getSize()	const
	{
		return mSprites.size();
	}

	void SpritePack::remove(const int& pGroup,const int& pIndex)
	{
		remove(getSpriteRealIndex(pGroup,pIndex));
	}

	unsigned int SpritePack::getSpriteRealIndex(const int& pGroup,const int& pIndex) const
	{
		unsigned int i;
		for(i = 0; i < mSprites.size(); ++i)
		{
			if(mSprites[i].getGroup() == pGroup && mSprites[i].getIndex() == pIndex)
			{
				break;
			}
		}
		return i;
	}

	Sprite& SpritePack::getSprite(const unsigned int& pPos)
	{
		if(pPos < mSprites.size())
		{
			return mSprites[pPos];
		}
		return *mNotFound;
	}

	const Sprite& SpritePack::getSprite(const unsigned int& pPos) const
	{
		if(pPos < mSprites.size())
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

	Sprite& SpritePack::operator [](const unsigned int& pPos)
	{
		return getSprite(pPos);
	}

	const Sprite& SpritePack::operator [](const unsigned int& pPos) const
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
		mGlobalPalette	= (pSpritePack.mGlobalPalette) ? pSpritePack.mGlobalPalette->copy() : NULL;
		mPalLinked		= false;
		for(unsigned int i = 0; i < pSpritePack.getSize(); ++i)
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
		for(unsigned int i = 0; i < getSize(); ++i)
		{
			if(!getSprite(i).getPalette() || (getSprite(i).getPalette() && pForce))
			{
				getSprite(i).setPalette(mGlobalPalette);
			}
		}
	}

	/**
	 * Método para criar uma paleta de cores global para todos os sprites do pacote
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

	void SpritePack::save(const Core::String& pFileName,const ImageLoader& pImageLoader)
	{
		Core::File file(pFileName,std::ios::out | std::ios::binary);

		if(file.is_open())
		{
			save(file,pImageLoader);
		}
		else
		{
			throw SpritePackException("Unable to save SpritePack: "+pFileName+".");
		}
	}

	/**
	 * @todo tentar usar o algoritmo da zlib aqui
	 */
	void SpritePack::load(Core::File& pFile)
	{
		int					spriteSize;
		SpritePackHeader	header(pFile);

		if(header.isValid())
		{
			if(pFile.readBool())
			{
				mGlobalPalette = new Palette(pFile);
			}
			spriteSize = pFile.readInt32();
			for(int i = 0; i < spriteSize; ++i)
			{
				mSprites.push_back(Sprite(pFile));
			}
			mPalLinked = false;
		}
		else
		{
			throw SpritePackException("Unable to load SpritePack due to incorrect format.");
		}
	}

	void SpritePack::load(const Core::String& pFileName)
	{
		Core::File file(pFileName,std::ios::in | std::ios::binary);
		if(file.is_open())
		{
			load(file);
		}
		else
		{
			throw SpritePackException("Unable to load SpritePack: "+pFileName+".");
		}
	}
}}
