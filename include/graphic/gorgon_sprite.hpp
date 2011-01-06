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
 *  Copyright (C) 2008-2009  Gorgon Team
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
#include "gorgon_image.hpp"
#include "gorgon_sprite_exception.hpp"
#include "gorgon_sprite_header.hpp"

namespace Gorgon
{
	/**
	 * Classe responsável por tratar das funções de sprites
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	01/05/2008
	 * @version	21/06/2009
	 * @ingroup	Graphic
	 */
	class Sprite : public Image
	{
		private:
			/**
			 * Guarda o grupo ao qual o sprite pertence
			 */
			int mGroup;
			/**
			 * Guarda o índice do sprite no grupo
			 */
			int mIndex;
			/**
			 * Guarda o offset no eixo x do sprite
			 */
			int mXOffset;
			/**
			 * Guarda o offset no eixo y do sprite
			 */
			int mYOffset;
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/01/2009
			 * @param	const Image&	pImage		, imagem do sprite
			 * @param	const int&		pGroup		, grupo do sprite
			 * @param	const int&		pIndex		, indice do sprite
			 * @param	const int&		pXOffset	, offset no eixo x
			 * @param	const int&		pYOffset	, offset no eixo y
			 */
			Sprite
			(
				const Image&	pImage,
				const int&		pGroup		= 0,
				const int&		pIndex		= 0,
				const int&		pXOffset	= 0,
				const int&		pYOffset	= 0
			);
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/01/2009
			 * @param	const std::string& pSpriteName, nome do arquivo com o sprite
			 */
			Sprite(const std::string& pSpriteName);
			/**
			 * Método Construtor de cópia
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/01/2009
			 * @param	const Sprite& pSpriteOrig, Sprite original
			 */
			Sprite(const Sprite& pSpriteOrig);
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, ponteiro para o arquivo já aberto
			 */
			Sprite(Core::File& pFile);
			~Sprite();
			/**
			 * Método para descrever o sprite
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
			void clipNoBorder();
			/**
			 * Método para carregar o sprite de um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	const std::string& pSpriteName, nome do arquivo a ser aberto
			 */
			virtual void load(const std::string& pSpriteName);
			/**
			 * Método para carregar o sprite de um arquivo ja aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			virtual void load(Core::File& pFile);
			/**
			 * Método para salvar o sprite em um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	const string& pSpriteName, nome do arquivo a salvar o sprite
			 * @param	ImageFormat* pImageFormat, ponteiro para o formato de imagem a salvar
			 */
			virtual void save(const std::string& pSpriteName,const ImageFormat& pImageFormat = ImageFormatAutodetect());
			/**
			 * Método para salvar o sprite em um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	File&			pFile			, arquivo já aberto
			 * @param	imageFormat*	pImageFormat	, ponteiro para o formato de imagem a salvar
			 */
			virtual void save(Core::File& pFile,const ImageFormat& pImageFormat = ImageFormatAutodetect());
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
			 * Método para setar o offset horizontal do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	24/01/2008
			 * @param	const int& pXOffset, offset horizontal do sprite
			 */
			void setXOffset(const int& pXOffset);
			/**
			 * Método para setar o offset vertical do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	24/01/2008
			 * @param	const int& pYOffset, offset vertical do sprite
			 */
			void setYOffset(const int& pYOffset);

			/**
			 * Método para retornar o grupo do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	21/01/2009
			 * @return	const int&
			 */
			const int& getGroup() const;
			/**
			 * Método para retornar o indice do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	21/01/2009
			 * @return	const int&
			 */
			const int& getIndex() const;
			/**
			 * Método para retornar o offset no eixo x do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	21/01/2009
			 * @return	const int&
			 */
			const int& getXOffset() const;
			/**
			 * Método para retornar o offset no eixo y do sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	09/08/2008
			 * @version	21/01/2009
			 * @return	const int&
			 */
			const int& getYOffset() const;
			/**
			 * Método para desenhar um Sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	24/01/2009
			 * @param	const Image&	pSprite	, sprite a ser desenhada
			 * @param	const int&		pPosX	, posição no eixo x a desenhar o sprite
			 * @param	const int&		pPosY	, posição no eixo
			 */
			void drawSprite
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY
			);
			/**
			 * Método para desenhar um Sprite esticado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2009
			 * @version	26/01/2009
			 * @param	const Sprite&	pSprite	, imagem que deseja-se desenhar
			 * @param	const int&		pPosX	, posição no eixo x
			 * @param	const int&		pPosY	, posição no eixo y
			 * @param	const int&		pXScale	, escala horizontal
			 * @param	const int&		pYScale	, escala vertical
			 */
			void drawSpriteStretched
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY,
				const int&		pXScale,
				const int&		pYScale
			);
			/**
			 * Método para desenhar um Sprite invertido
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	27/02/2009
			 * @param	const Sprite&		pSprite		, sprite que deseja-se desenhar
			 * @param	const int&			pPosX		, posição no eixo x
			 * @param	const int&			pPosY		, posição no eixo y
			 * @param	const Mirroring&	pMirroring	, tipo de espelhamento
			 */
			void drawSpriteFlipped
			(
				const Sprite&		pSprite,
				const int&			pPosX,
				const int&			pPosY,
				const Mirroring&	pMirroring = Mirroring::Normal
			);
			/**
			 * Método para desenhar um Sprite invertido verticalmente
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	24/01/2009
			 * @param	const Sprite&	pSprite	, sprite que deseja-se desenhar
			 * @param	const int&		pPosX	, posição no eixo x a desenhar o sprite
			 * @param	const int&		pPosY	, posição no eixo y a desenhar o sprite
			 */
			void drawSpriteFlippedV
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY
			);
			/**
			 * Método para desenhar um Sprite invertido horizontalmente
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	24/01/2009
			 * @param	const Sprite&	pSprite	, sprite que deseja-se desenhar
			 * @param	const int&		pPosX	, posição no eixo x a desenhar o sprite
			 * @param	const int&		pPosY	, posição no eixo y a desenhar o sprite
			 */
			void drawSpriteFlippedH
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY
			);
			/**
			 * Método para desenhar um Sprite invertido verticalmente e horizontalmente
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	24/01/2009
			 * @param	const Sprite&	pSprite	, sprite que deseja-se desenhar
			 * @param	const int&		pPosX	, posição no eixo x a desenhar o sprite
			 * @param	const int&		pPosY	, posição no eixo y a desenhar o sprite
			 */
			void drawSpriteFlippedVH
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY
			);
			/**
			 * Método para desenhar um Sprite com transparencia ou blender
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2009
			 * @version	24/01/2009
			 * @param	const Sprite&	pSprite	, sprite que deseja-se desenhar
			 * @param	const int&		pPosX	, posição no eixo x a desenhar o sprite
			 * @param	const int&		pPosY	, posição no eixo y a desenhar o sprite
			 */
			void drawSpriteTrans
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY,
				const float&	pTrans = 0.5
			);
			/**
			 * Método para desenhar um Sprite com transparencia ou blender
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/04/2010
			 * @version	20/04/2010
			 * @param	const Sprite&		pSprite		, sprite que deseja-se desenhar
			 * @param	const int&			pPosX		, posição no eixo x a desenhar o sprite
			 * @param	const int&			pPosY		, posição no eixo y a desenhar o sprite
			 * @param	const Mirroring&	pMirroring	, espelhamento
			 */
			void drawSpriteTransFlipped
			(
				const Sprite&		pSprite,
				const int&			pPosX,
				const int&			pPosY,
				const float&		pTrans = 0.5,
				const Mirroring&	pMirroring = Mirroring::Normal
			);
			void drawSpriteAdd
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY,
				const Color&	pColorAdd,
				const Color&	pColorSub,
				const float&	pTrans = 0.5
			);
			/**
			 * Método para desenhar um Sprite rotacionado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	24/01/2009
			 * @param	const Sprite&	pSprite	, sprite que deseja-se desenhar
			 * @param	const int&		pPosX	, posição no eixo x a desenhar o sprite
			 * @param	const int&		pPosY	, posição no eixo y a desenhar o sprite
			 * @param	const int&		pAngle	, angulo a desenhar o sprite
			 * @todo	consertar o nome da funćão
			 */
			void drawSpriteRoteted
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY,
				const int&		pAngle
			);
			/**
			 * Método para desenhar um Sprite rotacionada e invertida
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	27/02/2009
			 * @param	const Sprite&		pSprite		, sprite que deseja-se desenhar
			 * @param	const int&			pPosX		, posição no eixo x a desenhar o sprite
			 * @param	const int&			pPosY		, posição no eixo y a desenhar o sprite
			 * @param	const int&			pAngle		, angulo a desenhar o sprite
			 * @param	const Mirroring&	pMirroring	, tipo de espelhamento do sprite
			 */
			void drawSpriteRotetedFlipped
			(
				const Sprite&		pSprite,
				const int&			pPosX,
				const int&			pPosY,
				const int&			pAngle,
				const Mirroring&	pMirroring = Mirroring::Normal
			);
			/**
			 * Método para desenhar um Sprite rotacionada e invertida verticalmente
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	24/01/2009
			 * @param	const Sprite&	pSprite	, sprite que deseja-se desenhar
			 * @param	const int&		pPosX	, posição no eixo x a desenhar o sprite
			 * @param	const int&		pPosY	, posição no eixo y a desenhar o sprite
			 * @param	const int&		pAngle	, angulo a desenhar o sprite
			 */
			void drawSpriteRotetedFlippedV
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY,
				const int&		pAngle
			);
			/**
			 * Método para desenhar um Sprite rotacionada e invertida horizontalmente
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	26/02/2009
			 * @param	const Sprite&	pSprite	, sprite que deseja-se desenhar
			 * @param	const int&		pPosX	, posição no eixo x a desenhar o sprite
			 * @param	const int&		pPosY	, posição no eixo y a desenhar o sprite
			 * @param	const int&		pAngle	, angulo a desenhar o sprite
			 */
			void drawSpriteRotetedFlippedH
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY,
				const int&		pAngle
			);
			/**
			 * Método para desenhar um Sprite rotacionada e invertida verticalmente e horizontalmente
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/05/2008
			 * @version	24/01/2009
			 * @param	const Sprite&	pSprite	, sprite que deseja-se desenhar
			 * @param	const int&		pPosX	, posição no eixo x a desenhar o sprite
			 * @param	const int&		pPosY	, posição no eixo y a desenhar o sprite
			 * @param	const int&		pAngle	, angulo a desenhar o sprite
			 */
			void drawSpriteRotetedFlippedVH
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY,
				const int&		pAngle
			);
			/**
			 * Método para copiar o Sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	02/07/2008
			 * @version	25/01/2009
			 * @param	const Sprite&	pSprite		, sprite a ser colado
			 * @param	const int&		pPosX		, posição x na imagem que irá colar a outra
			 * @param	const int&		pPosY		, posição y na imagem que irá colar a outra
			 * @param	const int& 		pSourcePosX	, posição x na imagem passada que começará a colar
			 * @param	const int& 		pSourcePosY , posição x na imagem passada que começará a colar
			 * @param	const int& 		pWidth		, largura do corte
			 * @param	const int&		pHeight		, altura do corte
			 * @param	const bool		pMasked		, se irá permitir transparência ou não
			 */
			void blitSprite
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY,
				const int&		pSourcePosX	=  0,
				const int&		pSourcePosY	=  0,
				const int&		pWidth		= -1,
				const int&		pHeight		= -1,
				const bool&		pMasked		= false
			);
			/**
			 * Método para copiar um Sprite esticado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2009
			 * @version	25/01/2009
			 * @param	const Sprite&	pSprite			, sprite a ser colado
			 * @param	const int&		pPosX			, posição x na imagem que irá colar a outra
			 * @param	const int&		pPosY			, posição y na imagem que irá colar a outra
			 * @param	const int&		pXScale			, número de vezes que irá multiplicar o tamanho do sprite original no eixo x
			 * @param	const int&		pYScale			, número de vezes que irá multiplicar o tamanho do sprite original no eixo y
			 * @param	const int& 		pSourcePosX		, posição x na imagem passada que começará a colar
			 * @param	const int& 		pSourcePosY 	, posição x na imagem passada que começará a colar
			 * @param	int		 		pSourceWidth	, largura do corte na imagem passada
			 * @param	int				pSourceHeight	, altura do corte na imagem passada
			 * @param	bool			pMasked			, se irá permitir transparência ou não
			 */
			void blitSpriteStretched
			(
				const Sprite&	pSprite,
				const int&		pPosX,
				const int&		pPosY,
				const int&		pXScale			= -1,
				const int&		pYScale			= -1,
				const int&		pSourcePosX		=  0,
				const int&		pSourcePosY		=  0,
				const int&		pSourceWidth	= -1,
				const int&		pSourceHeight	= -1,
				const bool&		pMasked			= false
			);
	};
}
#endif
