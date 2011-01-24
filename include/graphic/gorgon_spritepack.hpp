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
#ifndef _GORGON_SPRITE_PACK_
#define _GORGON_SPRITE_PACK_
#include <vector>
#include "gorgon_sprite.hpp"
#include "gorgon_spritepack_exception.hpp"
#include "gorgon_spritepack_header.hpp"
#include "../core/gorgon_file.hpp"
#include "../core/gorgon_string.hpp"

namespace Gorgon
{
	/**
	 * Classe que representa um pacote de sprites
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	22/01/2009
	 * @version	06/01/2011
	 * @ingroup	Graphic
	 */
	class SpritePack
	{
		protected:
			/**
			 * vetor com todos sprites inseridos no pacote
			 */
			std::vector<Sprite> mSprites;
			/**
			 * Variável que guarda a paleta global do pacote, ou seja se algum sprite não possuir uma paleta de cores,
			 * então usará a paleta global
			 */
			Palette* mGlobalPalette;
			/**
			 * Variável que guardará um sprite todo transparente e o menor possível, para retornar quando não encontrar
			 * o sprite especificado
			 */
			static Sprite* mNotFound;
			/**
			 * Verdadeiro se a paleta for linkada, falso se for interna
			 */
			bool mPalLinked;
		protected:
			/**
			 * Método que retira um sprite de um spriteSheet
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	28/02/2009
			 * @version	28/02/2009
			 * @see		SpritePack(Image sheet, const int& backgroundColor)
			 * @param	Image& pImage				, imagem a tirar o sprite
			 * @param	const int& pPosX			, posição x que começará a recortar o sprite
			 * @param	const int& pPosY			, posição y que começará a recortar o sprite
			 * @param	const int& pGroup			, grupo do sprite que será recortado
			 * @param	const int& pIndex,			, índice do sprite que será recortado
			 * @param	const int& pBackgorundColor	, cor de fundo, cor a ser ignorada
			 * @details
			 *			É esse método que é chamado para auxiliar o construtor que recebe um spriteSheet
			 */
			int getSpriteInSpriteSheet
			(
				Image&		pImage,
				const int&	pPosX,
				const int&	pPosY,
				const int&	pGroup,
				const int&	pIndex,
				const int&	pBackgroundColor
			);

			/**
			 * Método para achar os limites de uma imagem, a partir de um determinado ponto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/09/2009
			 * @final	29/09/2009
			 * @param	const Image& pImage
			 * @param	std::vector<Point>&	pPositions			, vetor com as posições já percorridas pelo método
			 * @param	Point&				pInit				, posição do ponto superior esquerdo da imagem
			 * @param	Point&				pEnd				, posição do ponto inferior direito da imagem
			 * @param	int&				pTransparentColor	, cor transparent da imagem
			 */
			void findImageLimits
			(
				const Image& pImage,
				std::vector<Point>& pPositions,
				Point&				pInit,
				Point&				pEnd,
				const int&			pTransparentColor
			);
		public:
			/**
			 * Método construtor de classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	22/01/2009
			 */
			SpritePack();
			/**
			 * Método construtor de classe, que transforma um para de tiles em um spritePack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/01/2009
			 * @version	23/01/2009
			 * @param	const Image&	pImageSheet		, a imagem que possui os tites que deseja adicionar ao sprite pack
			 * @param	const int&		pWidth			, largura de cada tile
			 * @param	const int&		pHeight			, altura de cada tile
			 * @param	const int&		pJumpPixels		, número de pixels a saltar a cada tile
			 */
			SpritePack
			(
				const Image&	pImageSheet,
				const int&		pWidth,
				const int&		pHeight,
				const int&		pJumpPixels	= 0
			);
			/**
			 * Método Construtor que recebe um spriteSheet e separa as imagens adicionando-as ao pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/09/2009
			 * @version	29/09/2009
			 * @param	Image		pImageSheet			, imagem a ser recortada e adicionada ao spritepack
			 * @para	const int&	pBackgroundColor	, cor a ser ignorada
			 */
			SpritePack(Image pImageSheet, const int& pBackgroundColor);
			/**
			 * Método construtor que recebe  um spritesSheet e o separa
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	28/02/2009
			 * @version	28/02/2009
			 * @see		getSpriteInSpriteSheet
			 * @param	const Image& pImageSheet	, a imagem do spriteSheet
			 * @param	const int& pBackgroundColor	, cor de fundo do sheet
			 * @details
			 *			Esse método funciona da seguinte maneira:
			 * O método roda a imagem ignorando a backgroundColor, assim que acha uma cor diferente da backgroundColor,
			 * ele assume que ali começa uma imagem, ou seja as imagens devem estar com uma cor de fundo diferente do
			 * sheet inteiro, para que o método as possa identificar. Esse método faz a localização da imagem de cima para baixo
			 * e da esquerda para a direita, ou seja as imagens mais altas serão incluídas primeiro, e das que começam na mesma posição
			 * em y as mais a esquerda serão incluídas primeiro.
			 */
			//SpritePack(Image pImageSheet, const int& pBackgroundColor);
			/**
			 * Método Construtor de Cópia
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	22/01/2009
			 * @param	const SpritePack& pSpritePackOriginal, spritepack original
			 */
			SpritePack(const SpritePack& pSpritePackOriginal);
			/**
			 * Método construtor de classe iniciado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	20/05/2009
			 * @param	const Core::String& pFileName, nome do arquivo com as informações do pacote
			 */
			SpritePack(const Core::String& pFileName);
			/**
			 * Método construtor de classe iniciado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			SpritePack(Core::File& pFile);
			/**
			 * Método destrutor de classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	23/01/2009
			 */
			virtual ~SpritePack();
			/**
			 * Método para ordenar os sprites do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @todo	implementar esse método
			 */
			void sort();
			/**
			 * Método para adicionar um sprite ao pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	21/06/2009
			 * @param	const Sprite& pSprite , sprite a ser adicionado ao pacote
			 */
			void add(const Sprite& pSprite);
			/**
			 * Método para adicionar um sprite ao pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/03/2009
			 * @version	21/06/2009
			 * @param	const Sprite&	pSprite	, sprite a ser adicionado ao pacote
			 * @param	const int&		pPos	, posição que o sprite será inserido no spritepack
			 */
			void add(const Sprite& pSprite,const int& pPos);
			/**
			 * Método para remover um sprite do pacote por sua posição no vetor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	06/01/2011
			 * @param	const unsigned int& pPos, posição a ser removida
			 */
			void remove(const unsigned int& pPos);
			/**
			 * Método para remover um sprite do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	21/06/2009
			 * @param	const int& pGroup , grupo do sprite a ser removido
			 * @param	const int& pIndex , indice do sprite a ser removido
			 */
			void remove(const int& pGroup, const int& pIndex);
			/**
			 * Método para retornar o número de sprites no pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	06/01/2011
			 * @return	unsigned int
			 */
			unsigned int getSize() const;
			/**
			 * Método para retornar a posição de um determinado sprite identificado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	06/01/2011
			 * @param	const int& pGroup , grupo do sprite
			 * @param	const int& pIndex , indice do sprite
			 * @return	unsigned int
			 */
			unsigned int getSpriteRealIndex(const int& pGroup,const int& pIndex) const;
			/**
			 * Método que seta um offset global para todos os sprites do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	24/01/2008
			 * @param	const int& pXOffset, offset horizontal
			 * @param	const int& pYOffset, offset vertical
			 */
			void setGlobalOffset(const int& pXOffset,const int& pYOffset);
			/**
			 * Método para retirar as bordas transparentes dos sprites, deixando somente a parte útil da mesma e os alinhando
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	25/01/2008
			 * @todo	modificar o nome do método para trim
			 */
			void clipAll();
/*			vector<Sprite*> getSpritesInGroup(int group)	const;*/

			/**
			 * Método para retornar o sprite de uma determinada posição
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	06/01/2011
			 * @param	const int& pPos, posição que o sprite será retornado
			 * @return	Sprite&
			 */
			Sprite&	getSprite(const unsigned int& pPos);
			/**
			 * Método para retornar o sprite de uma determinada posição de forma constante
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @version	06/01/2011
			 * @param	const int& pPos, posição que o sprite será retornado
			 * @return	const Sprite&
			 */
			const Sprite& getSprite(const unsigned int& pPos) const;
			/**
			 * Método para retornar um sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	11/08/2008
			 * @param	const int& pGroup, grupo do sprite
			 * @param	const int& pIndex, indice do sprite
			 * @return	Sprite&
			 */
			Sprite&	getSprite(const int& pGroup,const int& pIndex);
			/**
			 * Método para retornar um sprite de forma constante
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	11/08/2008
			 * @param	const int& pGroup, grupo do sprite
			 * @param	const int& pIndex, indice do sprite
			 * @return	const Sprite&
			 */
			const Sprite& getSprite(const int& pGroup,const int& pIndex) const;
			/**
			 * Método para setar a paleta de cores global
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/09/2008
			 * @version	23/01/2009
			 * @param	Palette* pPalette, ponteiro para a paleta de cores
			 */
			void setGlobalPalette(Palette* pPalette);
			/**
			 * Método para aplicar a paleta de cores global a todos sprites do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/01/2009
			 * @version	23/01/2009
			 * @param	const bool& pForce, se for false substituirá apenas as paletas dos sprites que não tiverem paleta de cores
			 */
			void applyGlobalPalette(const bool& pForce = false);
			/**
			 * Método para criar uma paleta de cores global para o pacote de sprites
			 *
			 * @todo implementar esse método
			 */
//			void createGlobalPalette(int red=255, int green=0, int blue=255);

			/**
			 * Método para salvar os sprites em um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	07/08/2009
			 * @param	const Core::String& pFileName, nome do arquivo para salvar
			 * @param	ImageLoader*	pImageLoader	, ponteiro para o formato de imagem a salvar
			 */
			virtual void save(const Core::String& pFileName, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Método para salvar os sprites em um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	07/01/2011
			 * @param	File& pFile, ponteiro para o arquivo já aberto
			 * @param	ImageLoader*	pImageLoader	, ponteiro para o formato de imagem a salvar
			 */
			virtual void save(Core::File& pFile, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Método para carregar os sprites de um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	07/01/2011
			 * @param	const Core::String& pFileName, string com o nome do arquivo
			 */
			virtual void load(const Core::String& pFileName);
			/**
			 * Método para carregar os sprites de um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			virtual void load(Core::File& pFile);
			/**
			 * operador para acessar o SpritePack como um vetor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	06/01/2011
			 * @param	const unsigned int& pPos, inteiro sem sinal que representa a posição que deseja acessar
			 * @return	Sprite&
			 */
			Sprite& operator [](const unsigned int& pPos);
			/**
			 * Operador para acessar o SpritePack como um vetor de forma constante
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @version	06/01/2011
			 * @param	const unsigned int& pPos, inteiro sem sinal que representa a posição que deseja acessar
			 * @return	const Sprite&
			 */
			const Sprite& operator [](const unsigned int& pPos) const;
			/**
			 * operador para acessar o SpritePack através de seus identificadores
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	27/02/2009
			 * @param	const int& pGroup, inteiro sem sinal que representa o grupo do sprite a ser acessado
			 * @param	const int& pIndex, inteiro sem sinal que representa o indice do sprite a ser acessado
			 * @return	Sprite&
			 */
			Sprite& operator ()(const int& pGroup,const int& pIndex);
			/**
			 * Operador para acessar o SpritePack através de seus identificadores de forma constante
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @version	21/06/2009
			 * @param	const int& pGroup, inteiro sem sinal que representa o grupo do sprite a ser acessado
			 * @param	const int& pIndex, inteiro sem sinal que representa o indice do sprite a ser acessado
			 * @return	const Sprite&
			 */
			const Sprite& operator ()(const int& pGroup,const int& pIndex) const;
			void operator =(const SpritePack& pSpritePack);
			void saveScript(const Core::String& pFileName);
			void loadScript(const Core::String& pFileName);
	};
}
#endif
