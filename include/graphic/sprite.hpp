/*
 *
 *    __     ___   _ __    __     ___     ___
 *  /'_ `\  / __`\/\`'__\/'_ `\  / __`\ /' _ `\
 * /\ \L\ \/\ \L\ \ \ \//\ \L\ \/\ \L\ \/\ \/\ \
 * \ \____ \ \____/\ \_\\ \____ \ \____/\ \_\ \_\
 *  \/___L\ \/___/  \/_/ \/___L\ \/___/  \/_/\/_/
 *    /\____/              /\____/
 *    \_/__/               \_/__/
 *
 *  Copyright (C) 2008-2011  Cantidio Oliveira Fontes
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */
#ifndef _GORGON_SPRITE_
#define _GORGON_SPRITE_
#include <iostream>
#include <string>
#include "image.hpp"
#include "sprite_header.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Class that represents a sprite
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	01/05/2008
	 * @version	03/05/2011
	 * @ingroup	Graphic
	 * @todo	Comentar toda a classe em ingles
	 */
	class Sprite : public Image
	{
		private:
			int mGroup;				/**<< The group of the sprite*/
			int mIndex;				/**<< The index of the sprite in its group*/
			Core::Point mOffset;	/**<< The offset of the image*/
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	03/05/2011
			 * @param	const Image&		pImage	, image of the sprite
			 * @param	const int&			pGroup	, group of the sprite
			 * @param	const int&			pIndex	, index of the sprite
			 * @param	const Core::Point&	pOffset	, offset of the sprite
			 */
			Sprite
			(
				const Image&		pImage,
				const int&			pGroup	= 0,
				const int&			pIndex	= 0,
				const Core::Point&	pOffset	= Core::Point(0,0)
			);
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/01/2009
			 * @param	const std::string&	pSpriteName		, name of the file that has the sprite data
			 * @param	ImageLoader*		pImageLoader	, imageLoader responsable for saving the sprites
			 */
			Sprite(const std::string& pSpriteName, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	Core::File&		pFile			, file previously opened that has the sprite data
			 * @param	ImageLoader*	pImageLoader	, imageLoader responsable for saving the sprites
			 */
			Sprite(Core::File& pFile, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Copy Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/01/2009
			 * @param	const Sprite& pSpriteOrig, Sprite original
			 */
			Sprite(const Sprite& pSpriteOrig);
			/**
			 * Method that describes the sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	23/01/2009
			 * @return	std::string
			 */
			std::string describe() const;
			/**
			 * Método para cortar as bordas transparentes do sprite respeitando seus offsets
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2009
			 * @version	03/06/2009
			 */
			void trim();
			/**
			 * Method that loads the sprite from a file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	const std::string&	pSpriteName		, name of the file that have the sprite data
			 * @param	ImageLoader*		pImageLoader	, imageLoader responsable for saving the sprites
			 */
			virtual void load(const std::string& pSpriteName, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Method that loads the sprite from a previously opened file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	Core::File&		pFile			, previously opened file that holds the sprite data
			 * @param	ImageLoader*	pImageLoader	, imageLoader responsable for saving the sprites
			 */
			virtual void load(Core::File& pFile, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Método para salvar o sprite em um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	const string& pSpriteName, nome do arquivo a salvar o sprite
			 * @param	ImageLoader* pImageLoader, ponteiro para o formato de imagem a salvar
			 */
			virtual void save(const std::string& pSpriteName,const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Método para salvar o sprite em um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	File&			pFile			, arquivo já aberto
			 * @param	ImageLoader*	pImageLoader	, ponteiro para o formato de imagem a salvar
			 */
			virtual void save(Core::File& pFile,const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Método para setar o grupo do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	24/01/2008
			 * @param	const int& pGroup, grupo do sprite
			 */
			void setGroup(const int& pGroup);
			/**
			 * Método para setar o índice do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	24/01/2008
			 * @param	const int& pIndex, índice do sprite
			 */
			void setIndex(const int& pIndex);
			/**
			 * Método para setar o offset do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/05/2011
			 * @version	03/05/2011
			 * @param	const Core::Point& pOffset, offset do sprite
			 */
			void setOffset(const Core::Point& pOffset);
			/**
			 * Método para retornar o grupo do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	21/01/2009
			 * @return	int
			 */
			int getGroup() const;
			/**
			 * Método para retornar o indice do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	21/01/2009
			 * @return	int
			 */
			int getIndex() const;
			/**
			 * Método para retornar o offset do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	03/05/2011
			 * @return	Core::Point
			 */
			Core::Point getOffset() const;
			/**
			 * Método para desenhar um Sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	03/05/2011
			 * @param	const Image&		pSprite		, sprite a ser desenhada
			 * @param	const Core::Point&	pPosition	, posição a desenhar o sprite
			 */
			void drawSprite(const Sprite& pSprite, const Core::Point& pPosition);
			/**
			 * Método para desenhar um Sprite esticado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2009
			 * @version	26/01/2011
			 * @param	const Sprite&		pSprite		, imagem que deseja-se desenhar
			 * @param	const Core::Point&	pPosition	, posição a desenhar o sprite
			 * @param	const int&			pXScale		, escala horizontal
			 * @param	const int&			pYScale		, escala vertical
			 */
			void drawSpriteStretched
			(
				const Sprite&		pSprite,
				const Core::Point&	pPosition,
				const int&			pXScale,
				const int&			pYScale
			);
			/**
			 * Método para desenhar um Sprite invertido
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	03/05/2011
			 * @param	const Sprite&		pSprite		, sprite que deseja-se desenhar
			 * @param	const Core::Point&	pPosition	, posição a desenhar o sprite
			 * @param	const Mirroring&	pMirroring	, tipo de espelhamento
			 */
			void drawSpriteFlipped
			(
				const Sprite&		pSprite,
				const Core::Point&	pPosition,
				const Mirroring&	pMirroring = Mirroring::Normal
			);
			/**
			 * Método para desenhar um Sprite com transparencia ou blender
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2009
			 * @version	03/05/2011
			 * @param	const Sprite&		pSprite		, sprite que deseja-se desenhar
			 * @param	const Core::Point&	pPosition	, posição a desenhar o sprite
			 * @param	const float&		pTrans		, transparencia do sprite [0 - 1]
			 */
			void drawSpriteTrans
			(
				const Sprite&		pSprite,
				const Core::Point&	pPosition,
				const float&		pTrans = 0.5
			);
			/**
			 * Método para desenhar um Sprite com transparencia ou blender
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/04/2010
			 * @version	03/05/2011
			 * @param	const Sprite&		pSprite		, sprite que deseja-se desenhar
			 * @param	const Core::Point&	pPosition	, posição a desenhar o sprite
			 * @param	const float&		pTrans		, transparencia do sprite [0 - 1]
			 * @param	const Mirroring&	pMirroring	, espelhamento
			 */
			void drawSpriteTransFlipped
			(
				const Sprite&		pSprite,
				const Core::Point&	pPosition,
				const float&		pTrans = 0.5,
				const Mirroring&	pMirroring = Mirroring::Normal
			);
			/**
			 * @todo comentar isso ou excluir
			 */
			void drawSpriteAdd
			(
				const Sprite&		pSprite,
				const Core::Point&	pPosition,
				const Color&		pColorAdd,
				const Color&		pColorSub,
				const float&		pTrans = 0.5
			);
			/**
			 * Método para desenhar um Sprite rotacionado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	03/05/2011
			 * @param	const Sprite&		pSprite	, sprite que deseja-se desenhar
			 * @param	const Core::Point&	pPosition	, posição no eixo x a desenhar o sprite
			 * @param	const int&			pAngle	, angulo a desenhar o sprite
			 */
			void drawSpriteRotated
			(
				const Sprite&		pSprite,
				const Core::Point&	pPosition,
				const int&			pAngle
			);
			/**
			 * Método para desenhar um Sprite rotacionada e invertida
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	03/05/2011
			 * @param	const Sprite&		pSprite		, sprite que deseja-se desenhar
			 * @param	const Core::Point&	pPosition	, posição a desenhar o sprite
			 * @param	const int&			pAngle		, angulo a desenhar o sprite
			 * @param	const Mirroring&	pMirroring	, tipo de espelhamento do sprite
			 */
			void drawSpriteRotatedFlipped
			(
				const Sprite&		pSprite,
				const Core::Point&	pPosX,
				const int&			pAngle,
				const Mirroring&	pMirroring = Mirroring::Normal
			);
			/**
			 * Método para copiar o Sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	02/07/2008
			 * @version	03/05/2011
			 * @param	const Sprite&		pSprite			, sprite a ser colado
			 * @param	const Core::Point&	pPosition		, posição na imagem que irá colar a outra
			 * @param	const Core::Point&	pSourcePosition	, posição na imagem passada que começará a colar
			 * @param	const int& 			pWidth			, largura do corte
			 * @param	const int&			pHeight			, altura do corte
			 * @param	const bool			pMasked			, se irá permitir transparência ou não
			 */
			void blitSprite
			(
				const Sprite&		pSprite,
				const Core::Point&	pPosition,
				const Core::Point&	pSourcePosition	=  Core::Point(0,0),
				const int&			pWidth			= -1,
				const int&			pHeight			= -1,
				const bool&			pMasked			= false
			);
			/**
			 * Método para copiar um Sprite esticado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2009
			 * @version	03/05/2011
			 * @param	const Sprite&		pSprite			, sprite a ser colado
			 * @param	const Core::Point&	pPosition		, posição na imagem que irá colar a outra
			 * @param	const int&			pXScale			, número de vezes que irá multiplicar o tamanho do sprite original no eixo x
			 * @param	const int&			pYScale			, número de vezes que irá multiplicar o tamanho do sprite original no eixo y
			 * @param	const Core::Point&	pSourcePosition	, posição na imagem passada que começará a colar
			 * @param	const int		 	pSourceWidth	, largura do corte na imagem passada
			 * @param	const int			pSourceHeight	, altura do corte na imagem passada
			 * @param	const bool			pMasked			, se irá permitir transparência ou não
			 */
			void blitSpriteStretched
			(
				const Sprite&		pSprite,
				const Core::Point&	pPosition,
				const int&			pXScale			= -1,
				const int&			pYScale			= -1,
				const Core::Point&	pSourcePosition	=  Core::Point(0,0),
				const int&			pSourceWidth	= -1,
				const int&			pSourceHeight	= -1,
				const bool&			pMasked			= false
			);
	};
}}
#endif
