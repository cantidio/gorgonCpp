#include <graphic/gorgon_spritepack.hpp>
#include <sstream>
#include <script/gorgon_script.hpp>

namespace Gorgon
{
	/**
	 * Método para informar se o vetor possui a posição pesquisada
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/09/2009
	 * @version	29/09/2009
	 * @param	const std::vector<Point>&	pVector , vetor a realizar a pesquisa
	 * @param	const Point&				pPoint	, ponto a pesquisar
	 * @return	bool
	 */
	bool positionInVector(const std::vector<Point>& pVector,const Point& pPoint)
	{
		for(register int i = pVector.size() - 1; i > -1; --i)
		{
			if(pVector[i] == pPoint)
			{
				return true;
			}
		}
		return false;
	}
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

	SpritePack::SpritePack
	(
		const Image&	pImageSheet,
		const int&		pWidth,
		const int&		pHeight,
		const int&		pJumpPixels
	)
	{
		/**
		 * @todo arrumar um jeito mais eficiente de tratar os sprites faltosos
		 */
		if(mNotFound == NULL)
		{
			mNotFound = new Sprite(Image(1,1));
		}
		int group,index;
		unsigned int j,i;
		for(group = 0, j = pJumpPixels; j < pImageSheet.getHeight(); j += pHeight + pJumpPixels,++group)
		{
			for(index = 0, i = pJumpPixels; i < pImageSheet.getWidth(); i += pWidth + pJumpPixels,++index)
			{
				add
				(
					Sprite
					(
						Image
						(
							pWidth,
							pHeight,
							pImageSheet.getColorDepth()
						),
						group,
						index
					)
				);
				(*this)[getSize()-1].clear();
				(*this)[getSize()-1].blitImage(pImageSheet,0,0,i,j,pWidth,pHeight);
				(*this)[getSize()-1].setType(pImageSheet.getType());
			}
		}
		mPalLinked = false;
		if(pImageSheet.getPalette())
		{
			mGlobalPalette	= pImageSheet.getPalette()->copy();
		}
		else
		{
			mGlobalPalette	= new Palette(255,0,255);
		}
		applyGlobalPalette();
	}

	void SpritePack::findImageLimits
	(
		const Image&		pImage,
		std::vector<Point>&	pPositions,
		Point&				pInit,
		Point&				pEnd,
		const int&			pTransparentColor
	)
	{
		Point current = pPositions[pPositions.size() - 1];//pixel atual
		if(current.getX() < pInit.getX())	pInit.setX(current.getX());
		if(current.getX() > pEnd.getX())	pEnd.setX(current.getX());
		if(current.getY() > pEnd.getY())	pEnd.setY(current.getY());

		if //cima
		(
			current.getY() - 1  > pInit.getY()
			&& pImage.getPixel(Point(current.getX(),current.getY() - 1)) != pTransparentColor
			&& !positionInVector(pPositions,Point(current.getX(),current.getY() - 1))
		)
		{
//			printf("cima\n");
			pPositions.push_back(Point(current.getX(),current.getY()-1));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //baixo
		(
			current.getY() + 1  < pImage.getHeight()
			&& pImage.getPixel(Point(current.getX(),current.getY() + 1)) != pTransparentColor
			&& !positionInVector(pPositions,Point(current.getX(),current.getY() + 1))
		)
		{
//			printf("baixo\n");
			pPositions.push_back(Point(current.getX(),current.getY() + 1));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //direita
		(
			current.getX() + 1  < pImage.getWidth()
			&& pImage.getPixel(Point(current.getX() + 1,current.getY())) != pTransparentColor
			&& !positionInVector(pPositions,Point(current.getX() + 1,current.getY()))
		)
		{
//			printf("direita\n");
			pPositions.push_back(Point(current.getX() + 1,current.getY()));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //esquerda
		(
			current.getX() - 1  > -1
			&& pImage.getPixel(Point(current.getX() - 1,current.getY())) != pTransparentColor
			&& !positionInVector(pPositions,Point(current.getX() - 1,current.getY()))
		)
		{
//			printf("esquerda\n");
			pPositions.push_back(Point(current.getX() - 1,current.getY()));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //esquerda cima
		(
			current.getY() - 1 > pInit.getY()
			&& current.getX() - 1 > -1
			&& pImage.getPixel(Point(current.getX() - 1,current.getY() - 1)) != pTransparentColor
			&& !positionInVector(pPositions,Point(current.getX() - 1,current.getY() - 1))
		)
		{
//			printf("esquerda-cima\n");
			pPositions.push_back(Point(current.getX() - 1,current.getY() - 1));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //esquerda baixo
		(
			current.getY() + 1 < pImage.getHeight()
			&& current.getX() - 1 > -1
			&& pImage.getPixel(Point(current.getX() - 1,current.getY() + 1)) != pTransparentColor
			&& !positionInVector(pPositions,Point(current.getX() - 1,current.getY() + 1))
		)
		{
//			printf("esquerda-baixo\n");
			pPositions.push_back(Point(current.getX() - 1,current.getY() + 1));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //direita cima
		(
			current.getY() - 1 > pInit.getY()
			&& current.getX() + 1 < pImage.getWidth()
			&& pImage.getPixel(Point(current.getX() + 1,current.getY() - 1)) != pTransparentColor
			&& !positionInVector(pPositions,Point(current.getX() + 1,current.getY() - 1))
		)
		{
//			printf("direita-cima\n");
			pPositions.push_back(Point(current.getX() + 1,current.getY() - 1));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //direita baixo
		(
			current.getY() + 1 < pImage.getHeight()
			&& current.getX() + 1 < pImage.getWidth()
			&& pImage.getPixel(Point(current.getX() + 1,current.getY() + 1)) != pTransparentColor
			&& !positionInVector(pPositions,Point(current.getX() + 1,current.getY() + 1))
		)
		{
//			printf("direita-baixo\n");
			pPositions.push_back(Point(current.getX() + 1,current.getY() + 1));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
	}
	
	/*SpritePack::SpritePack(Image pImageSheet,const int& pTransparentColor)
	{
		std::vector<Point> positions;
		Point pos,init,end;
		int width, height;
		for(pos.setY(0); pos.getY() < pImageSheet.getHeight(); pos.addY(1))
		{
			for(pos.setX(0); pos.getX() < pImageSheet.getWidth(); pos.addX(1))
			{
				if(pImageSheet.getPixel(pos.getX(),pos.getY()) != pTransparentColor)
				{
					init = end = pos;
					positions.clear();
					positions.push_back(init);
					findImageLimits
					(
						pImageSheet,
						positions,
						init,
						end,
						pTransparentColor
					);
					width	= end.getX() - init.getX() + 1;
					height	= end.getY() - init.getY() + 1;
					add
					(
						Sprite
						(
							Image
							(
								width,
								height,
								pImageSheet.getColorDepth()
							),
							0,
							0
						)
					);					
					(*this)[getSize() - 1].blitImage(pImageSheet,0,0,init.getX(),init.getY(),width,height);
					(*this)[getSize() - 1].updateBuffer();

					/**
					 * @todo verificar o erro abaixo, axo que é por causa da paleta de cores, quando tem uma
					 *
					 * pImageSheet.drawRectangle
					(
						init.getX(),
						init.getY(),
						init.getX() + width,
						init.getY() + height,
						Color(84,109,142),//pTransparentColor,
						true
					);*//*
					rectfill
					(
						pImageSheet.getImg(),
						init.getX(),
						init.getY(),
						end.getX(),
						end.getY(),
						pTransparentColor
					);
					
				}
			}
		}
	}*/


	int SpritePack::getSpriteInSpriteSheet
	(
		Image&		pImage,
		const int&	pPosX,
		const int&	pPosY,
		const int&	pGroup,
		const int&	pIndex,
		const int&	pBackgroundColor
	)
	{
		unsigned int i,j,width = 0,height = 0;
		//printf("antony\n");
		for(i = pPosY; i < pImage.getHeight(); ++i)
		{
			for(j = pPosX; j < pImage.getWidth(); ++j)
			{
				if
				(
					pImage.getPixel(j,i) == pBackgroundColor
					|| j == (pImage.getWidth() - 1)
				)
				{
					if(j - pPosX > width)
					{
						width = j - pPosX;
					}
					break;
				}

			}
			if(j == pPosX)
			{
				break;
			}
		}
		height = i - pPosY;
		if(height < 1 || width < 1)
		{
			return 1;
		}
		//printf("width: %d, height: %d\n",width,height);
		Sprite sprite(Image(width,height,pImage.getColorDepth()),pGroup,pIndex);
		sprite.setType(pImage.getType());
		sprite.blitImage(pImage,0,0,pPosX,pPosY,width,height);
		sprite.updateBuffer();
		if(!sprite.isEmpty())
		{
			add(sprite);
		}
		pImage.drawRectangle
		(
			pPosX,
			pPosY,
			pPosX + width,
			pPosY + height,
			pBackgroundColor,
			true
		);
		return width;
	}

	/**
	 * @bug esse método está bugaddo, as vezes não consegue achar td extenção do sprite
	 */
	SpritePack::SpritePack
	(
		Image pImageSheet,
		const int& pBackgroundColor
	)
	{
		if(mNotFound == NULL)
		{
			mNotFound = new Sprite(Image(1,1));
		}
		int group, index;
		int x, y;

		for(y = group = 0; y < pImageSheet.getHeight(); ++y)
		{
			for(x = index = 0; x < pImageSheet.getWidth(); ++x)
			{
				if(pImageSheet.getPixel(x,y) != pBackgroundColor)
				{
					//printf("X:%d, Y: %d bG: %d, found: %d\n",x,y,pBackgroundColor,pImageSheet.getPixel(x,y));
					const int offset = getSpriteInSpriteSheet
					(
						pImageSheet,
						x,
						y,
						group,
						index,
						pBackgroundColor
					);
					//printf("imagem encontrada posxy: %d, %d, offset:%d\n",x,y,offset);

					x += offset - 1;
					++index;
				}
			}
			if(index != 0)
			{
				++group;
			}
		}
		mPalLinked = false;
		if(pImageSheet.getPalette())
		{
			mGlobalPalette	= pImageSheet.getPalette()->copy();
		}
		else
		{
			mGlobalPalette	= new Palette(255,0,255);
		}
		applyGlobalPalette();
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

	void SpritePack::setGlobalOffset(const int& pXOffset,const int& pYOffset)
	{
		for(unsigned int i = 0; i < getSize(); ++i)
		{
			(*this)[i].setXOffset(pXOffset);
			(*this)[i].setYOffset(pYOffset);
		}
	}

	void SpritePack::clipAll()
	{
		int x;
		int y;
		for(unsigned int i = 0; i < getSize(); ++i)
		{
			x = (*this)[i].getDelimiterLeft();
			y = (*this)[i].getDelimiterUp();
			(*this)[i].clip
			(
				x,
				y,
				(*this)[i].getWidth() - x - (*this)[i].getDelimiterRight(),
				(*this)[i].getHeight() - y - (*this)[i].getDelimiterDown()
			);
			(*this)[i].setXOffset((*this)[i].getXOffset() - x);
			(*this)[i].setYOffset((*this)[i].getYOffset() - y);
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
	void SpritePack::saveScript(const Core::String& pFileName)
	{
		Core::File file(pFileName,std::ios::out);
		std::vector<Core::String> pieces;
		Core::String subfilename;
		Core::String dir;

		pieces = pFileName.explode("/");
		for(unsigned int i = 0; i < pieces.size() - 1; ++i)
		{
			dir.append(pieces[i]);
			dir.append("/");
		}
		pieces = pieces.back().explode(".");
		subfilename.append(pieces[0]);
		for(unsigned int i = 1; i < pieces.size() - 1; ++i)
		{
			subfilename.append(".");
			subfilename.append(pieces[i]);
		}

		if(file.is_open())
		{
			file << "spritepack = {\n";
			for(unsigned int i = 0; i < getSize(); ++i)
			{
				std::stringstream filename;
				filename << dir << subfilename << "_image_" << i << ".bmp";
				((Image)(*this)[i]).save(filename.str());

				file << "\t{\n";
				file << "\t\tgroup   = " << (*this)[i].getGroup()	<< ",\n";
				file << "\t\tindex   = " << (*this)[i].getIndex()	<< ",\n";
				file << "\t\txoffset = " << (*this)[i].getXOffset()	<< ",\n";
				file << "\t\tyoffset = " << (*this)[i].getYOffset()	<< ",\n";
				file << "\t\timage   = " << "\"" << subfilename << "_image_" << i << ".bmp\"\n";
				file << "\t},\n";
			}
			file << "}";
		}
	}

	void SpritePack::loadScript(const Core::String& pFileName)
	{
		Script::Lua script(pFileName);
		script.executeString("function getSpriteNumber()	return #spritepack				end");
		script.executeString("function getSpriteLocation(i)	return spritepack[i].image		end");
		script.executeString("function getSpriteGroup(i)	return spritepack[i].group		end");
		script.executeString("function getSpriteIndex(i)	return spritepack[i].index		end");
		script.executeString("function getSpriteXOffset(i)	return spritepack[i].xoffset	end");
		script.executeString("function getSpriteYOffset(i)	return spritepack[i].yoffset	end");
		std::vector<Core::String> pieces = pFileName.explode("/");
		Core::String dir;

		for(unsigned int i = 0; i < pieces.size() - 1; ++i)
		{
			dir.append(pieces[i]);
			dir.append("/");
		}
		const int sprites = script.function("getSpriteNumber",Script::LuaParam(),1).getNumericValue();

		for(int i = 1; i <= sprites; ++i)
		{
			std::stringstream image;
			image << dir << script.function("getSpriteLocation", Script::LuaParam("i",i),1).getStringValue();
			this->add
			(
				Sprite
				(
					Image( image.str() ),
					script.function("getSpriteGroup", Script::LuaParam("i",i),1).getNumericValue(),
					script.function("getSpriteIndex", Script::LuaParam("i",i),1).getNumericValue(),
					script.function("getSpriteXOffset", Script::LuaParam("i",i),1).getNumericValue(),
					script.function("getSpriteYOffset", Script::LuaParam("i",i),1).getNumericValue()
				)
			);
		}
	}
}
