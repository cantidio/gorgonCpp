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
#ifndef _GORGON_IMAGE_
#define _GORGON_IMAGE_
#include <fstream>
#include <vector>
#include <string>
#include <allegro.h>
#include "../core/point.hpp"
#include "palette.hpp"
#include "image_exception.hpp"
#include "mirroring.hpp"
#include "color.hpp"
#include "image_loader.hpp"

//#include "../geometry/gorgon_rectangle.hpp"

namespace Gorgon{
namespace Graphic
{
	const char imageUnknownCod	= 0;
	/**
	 * Classe de Imagem
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	20/01/2009
	 * @version	13/12/2009
	 * @todo	implementar os métodos save e load da classe
	 * @ingroup	Graphic
	 */
	class Image
	{
		protected:

			BITMAP* mData;/**<< Variável que guarda a imagem em si*/
			BITMAP* mDataBuffer;/**<< Variável que guarda um buffer da imagem, onde são realizadas todas operacões se mudar a paleta ou a imagem ele deve ser atualizado*/
			Palette* mPalette;/**<< Ponteiro para a paleta de cores, se a imagem possuir uma*/
			/**
			 * Variável que guarda se a imagem é linkada
			 * Se a imagem for linkada ela não será destruída pelos métodos
			 */
			bool mImgLinked;
			bool mFreePalette;/**<< Variável que guarda se a paleta será desalocada pela classe */
			/**
			 * @todo remover essa variável
			 */
			char mImgType;
		public:
			Image(const std::string& pFileName, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			Image(Core::File& pFile, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Método construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	24/01/2009
			 * @param	BITMAP*		pBitmap		, ponteiro para a imagem
			 * @param	Palette*	pPalette	, ponteiro para a palheta de cores
			 */
			Image(BITMAP* bBitmap = NULL, Palette* pPalette = NULL);
			/**
			 * Método construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	17/02/2009
			 * @param	const int& pWidth	, largura da noma imagem criada
			 * @param	const int& pHeight	, altura da noma imagem criada
			 * @param	const int& pBpp		, bits por pixel da nova imagem criada
			 * @param	const int& pColor	, cor de fundo da nova imagem criada
			 * @todo	tirar o desktop_color_depth da li
			 */
			Image
			(
				const int& pWidth,
				const int& pHeight,
				const int& pBpp		= get_color_depth(),
				const int& pColor	= 0xFF00FF
			);
			/**
			 * Método construtor de cópia
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/01/2009
			 * @version	21/01/2009
			 * @param	const Image& pImage, imagem original
			 */
			Image(const Image& pImage);
			/**
			 * Método destrutor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	25/01/2009
			 */
			virtual ~Image();
			/**
			 * Método para carregar uma imagem de um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	07/08/2009
			 * @param	const std::string&	pFileName		, nome do arquivo a ser aberto
			 * @param	const ImageLoader&	pImageLoader	, formato da imagem a ser aberta
			 */
			virtual void load(const std::string& pFileName,const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Método para carregar uma imagem de um arquivo ja aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	07/08/2009
			 * @param	File&				pFile			, arquivo já aberto
			 * @param	const ImageLoader&	pImageLoader	, formato da imagem a ser aberta
			 */
			virtual void load(Core::File& pFile,const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Método para salvar o sprite em um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/06/2009
			 * @param	const string& pSpriteName, nome do arquivo a salvar o sprite
			 * @param	ImageLoader* pImageLoader, ponteiro para o formato de imagem a salvar
			 */
			virtual void save(const std::string& pFileName,const ImageLoader& pImageLoader = ImageLoader::getLoader());
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
			 * Método que recria a imagem com as especificações dadas
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @param	const int& pWidth	, largura da noma imagem criada
			 * @param	const int& pHeight	, altura da noma imagem criada
			 * @param	const int& pBpp		, bits por pixel da nova imagem criada
			 * @param	const int& pColor	, cor de fundo da nova imagem criada
			 */
			void create
			(
				const int& pWidth,
				const int& pHeight,
				const int& pBpp		= get_color_depth(),
				const int& pColor	= 0xFF00FF
			);
			/**
			 * Método para descrever a imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/01/2009
			 * @version	21/01/2008
			 * @return	const std::string
			 */
			std::string describe() const;
			/**
			 * Método para setar a imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	20/01/2009
			 * @param	BITMAP* pBitmap, ponteiro para a imagem
			 */
			void setImg(BITMAP* pBitmap);
			/**
			 * Método para setar o tipo da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/01/2009
			 * @version	23/01/2009
			 * @param	const char& pImgType, tipo da imagem
			 * @todo 	remover esse método
			 */
			void setType(const char& pImgType);
			/**
			 * Método para setar a paleta de cores
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	20/01/2009
			 * @param	Palette *pPalette, ponteiro para a paleta
			 * @details	a paleta não será desalocada
			 */
			void setPalette(Palette *pPalette, const bool& pFreeSource = false);
			/**
			 * Método para setar a paleta de cores
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	02/05/2011
			 * @version	02/05/2011
			 * @param	const Palette& pPalette, paleta a ser copiada
			 * @details	esse método copia a paleta para a imagem
			 */
			void setPalette(const Palette& pPalette);
			/**
			 * Método para usar a paleta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	20/10/2009
			 */
			void usePalette() const;
			/**
			 * Método para atualizar o buffer da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	25/01/2009
			 * @details
			 *			Esse método deve ser chamado logo depois de se desenhar
			 * alguma coisa em uma imagem de 8 bpp
			 */
			void updateBuffer();
			/**
			 * Método para pegar a Paleta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	20/01/2009
			 * @return	Palette*
			 */
			Palette* getPalette() const;
			/**
			 * Método para retornar a imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	21/01/2009
			 * @return	BITMAP*
			 */
			BITMAP* getImg() const;
			/**
			 * Método para retornar o bpp da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	13/02/2009
			 * @return	int
			 */
			int getColorDepth() const;
			/**
			 * Método para retornar o número de cores usadas na imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/01/2009
			 * @version	18/02/2009
			 * @return	int
			 */
			int getColorNumber() const;
			/**
			 * Método para retornar um pixel da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	18/02/2009
			 * @param	const int&	pPosX			, posicao x do pixel na imagem
			 * @param	const int&	pPosY			, posicao y do pixel na imagem
			 * @param	const bool&	pAbsoluteValue	, se verdadeiro sempre retorna
			 * o valor absoluto do pixel, mesmo esse sendo 8 bits e tendo apenas
			 * de 1 a 255 para representar sua cor, se estiver falso, realiza a
			 * conversão e semre retorna o valor exato da cor do pixel, se for 8
			 * bits busca essa valor na palheta de cores
			 * @return	int
			 */
			int getPixel
			(
				const int&	pPosX,
				const int&	pPosY,
				const bool&	pAbsoluteValue = false
			) const;

			int getPixel
			(
				const Core::Point& pPosition,
				const bool& pAbsoluteValue = false
			) const;
			/**
			 * Método para retornar a cor em determinada parte da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/06/2009
			 * @version	25/06/2009
			 * @param	const int&	pPosX , posicao x do pixel na imagem
			 * @param	const int&	pPosY , posicao y do pixel na imagem
			 * @return	Color
			 */
			Color getColor(const int& pPosX,const int& pPosY) const;
			/**
			 * Método para returnar a largura da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	06/01/2011
			 * @return	unsigned int
			 */
			unsigned int getWidth() const;
			/**
			 * Método para retornar a altura da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	06/01/2011
			 * @return	unsigned int
			 */
			unsigned int getHeight() const;
			/**
			 * Método para retornar o tipo da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/01/2008
			 * @version	23/01/2008
			 * @return	char
			 */
			char getType() const;
			/**
			 * Método para achar o ponto em y que a imagem comeca, descartando a tranparência
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	24/01/2008
			 * @return	int
			 */
			int getDelimiterUp() const;
			/**
			 * Método para achar o ponto em x que a imagem começa, descartando a transparência
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	24/01/2008
			 * @return	int
			 */
			int getDelimiterLeft() const;
			/**
			 * Método para achar o ponto em y que a imagem termina
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	24/01/2008
			 * @return	int
			 */
			int getDelimiterDown() const;
			/**
			 * Método para achar o ponto em x que a imagem termina
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	24/01/2008
			 * @return	int
			 */
			int getDelimiterRight() const;
			/**
			 * Método para cortar a imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	24/01/2008
			 * @param	const int& pPosX	, posição no eixo x
			 * @param	const int& pPosY	, posição no eixo y
			 * @param	const int& pWidth	, largura
			 * @param	const int& pHeight	, altura
			 */
			void clip
			(
				const int& pPosX,
				const int& pPosY,
				const int& pWidth,
				const int& pHeight
			);
			/**
			 * Método para cortar as bordas transparentes da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	25/01/2008
			 */
			void clipNoBorder();
			/**
			 * Método para limpar a imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	13/02/2009
			 * @param	const int& pColor, cor a limpar a imagem
			 * @todo	passar um objeto Color aki
			 */
			void clear(const int& pColor = 0);
			/**
			 * Método para desenhar um pixel na imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	02/05/2011
			 * @param	const int& pPosX	, posicao x do pixel na imagem
			 * @param	const int& pPosY	, posicao y do pixel na imagem
			 * @param	const int& pColor	, cor do pixel
			 * @todo	substituir isso pelo objeto de cor
			 */
			void drawPixel
			(
				const int& pPosX,
				const int& pPosY,
				const int& pColor
			);
			/**
			 * Método para desenhar uma linha na imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Core::Point& pPosX1	, posição de início da linha
			 * @param	const Core::Point& pPosX2	, posição de término da linha
			 * @param	const Color& pColor	, cor da linha
			 * @todo	substituir pelo objeto Color
			 */
			void drawLine
			(
				const Core::Point& pPos1,
				const Core::Point& pPos2,
				const Color& pColor
			);
			/**
			 * Método para desenhar um retângulo na imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Core::Point& pPos1 , posição de início do retângulo
			 * @param	const Core::Point& pPos2 , posição de término do retângulo
			 * @param	const Color& pColor , cor do retângulo
			 * @param	const bool& pFill , se irá preencher o retangulo com a cor
			 */
			void drawRectangle
			(
				const Core::Point&	pPos1,
				const Core::Point&	pPos2,
				const Color&		pColor,
				const bool&			pFill = false
			);
			/**
			 * Método para desenhar um circulo na imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Core::Point& 	pPosition	, posição do círculo
			 * @param	const int& 		pRadius		, radio do círculo
			 * @param	const Color& 	pColor		, cor do círculo
			 * @param	const bool&		pFill		, se irá preencher o círculo com a cor
			 */
			void drawCircle
			(
				const Core::Point&	pPosition,
				const int&		pRadius,
				const Color&	pColor,
				const bool&		pFill = false
			);
			/**
			 * Método para desenhar uma elipse na imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Point& 	pPosition	, posição da elipse
			 * @param	const int& 		pRadiusX	, raio do eixo x da elipse
			 * @param	const int& 		pRadiusY	, raio do eixo y da elipse
			 * @param	const Color& 	pColor		, cor da elipse
			 * @param	const bool&		pFill		, se irá preencher a elipse toda com a cor
			 */
			void drawEllipse
			(
				const Core::Point&	pPosition,
				const int&		pRadiusX,
				const int&		pRadiusY,
				const Color&	pColor,
				const bool&		pFill = false
			);
			/**
			 * Método para desenhar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Image&	pImage		, imagem a ser desenhada
			 * @param	const Core::Point&	pPosition	, posição a desenhar a imagem
			 */
			void drawImage(const Image& pImage, const Core::Point& pPosition);
			/**
			 * Método para desenhar uma imagem esticada
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Image&	pImage		, imagem a ser desenhada
			 * @param	const Core::Point&	pPosition	, posição a desenhar a imagem
			 * @param	const int&		pWidth		, largura a desenhar a imagem
			 * @param	const int&		pHeight		, altura a desenhar a imagem
			 */
			void drawImageStretched
			(
				const Image&		pImage,
				const Core::Point&	pPosition,
				const int&			pWidth,
				const int&			pHeight
			);
			/**
			 * Método para desenhar uma imagem invertida verticalmente
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Image&	pImage	, imagem a ser desenhada
			 * @param	const int&		pPosX	, posição nom eixo x a desenhar a imagem
			 * @param	const int&		pPosY	, posição nom eixo y a desenhar a imagem
			 */
//			void drawImageFlippedV
//			(
//				const Image&	pImage,
//				const int&		pPosX,
//				const int&		pPosY
//			);
			/**
			 * Método para desenhar uma imagem invertida horizontalmete
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Image&	pImage	, imagem a ser desenhada
			 * @param	const int&		pPosX	, posição nom eixo x a desenhar a imagem
			 * @param	const int&		pPosY	, posição nom eixo y a desenhar a imagem
			 */
//			void drawImageFlippedH
//			(
//				const Image&	pImage,
//				const int&		pPosX,
//				const int&		pPosY
//			);
			/**
			 * Método para desenhar uma imagem invertida verticalmente e horizontalmente
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Image&	pImage	, imagem a ser desenhada
			 * @param	const int&		pPosX	, posição nom eixo x a desenhar a imagem
			 * @param	const int&		pPosY	, posição nom eixo y a desenhar a imagem
			 */
//			void drawImageFlippedVH
//			(
//				const Image&	pImage,
//				const int&		pPosX,
//				const int&		pPosY
//			);
			/**
			 * Método para desenhar uma imagem invertida
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Image&		pImage		, imagem a ser desenhada
			 * @param	const Core::Point&	pPosition	, posição a desenhar a imagem
			 * @param	const Mirroring&	pMirroring	, espelhamento a aplicar na imagem
			 */
			void drawImageFlipped
			(
				const Image&		pImage,
				const Core::Point&	pPosition,
				const Mirroring&	pMirroring = Mirroring::Normal
			);
			/**
			 * Método para desenhar uma imagem com transparencia
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Image&		pImage		, imagem a ser desenhada
			 * @param	const Core::Point&	pPosition	, posição a desenhar a imagem
			 * @param	const float&		pTrans		, valor da transparência de 0 a 1
			 * @todo	Otimizar
			 */
			void drawImageTrans
			(
				const Image&		pImage,
				const Core::Point&	pPosition,
				const float&		pTrans = 0.5
			);
			/**
			 * Método para desenhar uma imagem com transparencia e invertida
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/04/2010
			 * @version	03/05/2011
			 * @param	const Image&		pImage		, imagem a ser desenhada
			 * @param	const Core::Point&		pPosition	, posição a desenhar a imagem
			 * @param	const float&		pTrans		, valor da transparência de 0 a 1
			 * @param	const Mirroring&	pMirroring	, espelhamento
			 * @todo	Otimizar
			 */
			void drawImageTransFlipped
			(
				const Image&		pImage,
				const Core::Point&	pPosition,
				const float&		pTrans = 0.5,
				const Mirroring&	pMirroring = Mirroring::Normal
			);
			/**
			 * Método para desenhar uma imagem com add
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/06/2009
			 * @version	03/05/2011
			 * @param	const Image&	pImage		, imagem a ser desenhada
			 * @param	const Core::Point&	pPosition	, posição a desenhar a imagem
			 * @param	const Color&	pColorAdd	, cor a ser adicionada
			 * @param	const Color&	pColorSub	, cor a ser subtraída
			 * @param	const float&	pTrans		, proporção da transparencia
			 * @todo	Otimizar
			 */
			void drawImageAdd
			(
				const Image&		pImage,
				const Core::Point&	pPosition,
				const Color&		pColorAdd,
				const Color&		pColorSub,
				const float&		pTrans = 0.5
			);
			/**
			 * Método para desenhar uma imagem rotacionada
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Image&	pImage		, imagem a ser desenhada
			 * @param	const Core::Point&	pPosition	, posição a desenhar a imagem
			 * @param	const int&		pAangle		, angulo a desenhar a imagem
			 * @param	const Core::Point&	pAlign		, alinhamento
			 */
			void drawImageRotated
			(
				const Image&		pImage,
				const Core::Point&	pPosition,
				const int&			pAngle,
				const Core::Point&		pAlign = Core::Point(0,0)
			);
			/**
			 * Método para desenhar uma imagem rotacionada e invertida
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Image&		pImage		, imagem a ser desenhada
			 * @param	const Core::Point&		pPosition	, posição a desenhar a imagem
			 * @param	const int&			pAngle		, angulo a desenhar a imagem
			 * @param	const Mirroring&	pMirroring	, espelhamento
			 * @param	const Core::Point&		pAlign		, alinhamento

			 */
			void drawImageRotatedFlipped
			(
				const Image&		pImage,
				const Core::Point&	pPosition,
				const int&			pAngle,
				const Mirroring&	pMirroring	= Mirroring::Normal,
				const Core::Point&	pAlign		= Core::Point(0,0)
			);
			/**
			 * Método para desenhar uma imagem rotacionada e invertida verticalmente
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	13/02/2009
			 * @param	const Image&	pImage	, imagem a ser desenhada
			 * @param	const int&		pPosX	, posição nom eixo x a desenhar a imagem
			 * @param	const int&		pPosY	, posição nom eixo y a desenhar a imagem
			 * @param	const int&		pAangle	, angulo a desenhar a imagem
			 * @param	const int&		pXAlign	, alinhamento no eixo x
			 * @param	const int&		pYAlign	, alinhamento no eixo y
			 */
//			void drawImageRotetedFlippedV
//			(
//				const Image&	pImage,
//				const int&		pPosX,
//				const int&		pPosY,
//				const int&		pAngle,
//				const int&		pXAlign = 0,
//				const int&		pYAlign = 0
//			);
			/**
			 * Método para desenhar uma imagem rotacionada e invertida horizontalmente
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	13/02/2009
			 * @param	const Image&	pImage	, imagem a ser desenhada
			 * @param	const int&		pPosX	, posição nom eixo x a desenhar a imagem
			 * @param	const int&		pPosY	, posição nom eixo y a desenhar a imagem
			 * @param	const int&		pAangle	, angulo a desenhar a imagem
			 * @param	const int&		pXAlign	, alinhamento no eixo x
			 * @param	const int&		pYAlign	, alinhamento no eixo y
			 */
//			void drawImageRotetedFlippedH
//			(
//				const Image&	pImage,
//				const int&		pPosX,
//				const int&		pPosY,
//				const int&		pAngle,
//				const int&		pXAlign = 0,
//				const int&		pYAlign = 0
//			);
			/**
			 * Método para desenhar uma imagem rotacionada e invertida verticalmente e horizontalmente
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	13/02/2009
			 * @param	const Image&	pImage	, imagem a ser desenhada
			 * @param	const int&		pPosX	, posição nom eixo x a desenhar a imagem
			 * @param	const int&		pPosY	, posição nom eixo y a desenhar a imagem
			 * @param	const int&		pAangle	, angulo a desenhar a imagem
			 * @param	const int&		pXAlign	, alinhamento no eixo x
			 * @param	const int&		pYAlign	, alinhamento no eixo y
			 */
//			void drawImageRotetedFlippedVH
//			(
//				const Image&	pImage,
//				const int&		pPosX,
//				const int&		pPosY,
//				const int&		pAngle,
//				const int&		pXAlign = 0,
//				const int&		pYAlign = 0
//			);
			/**
			 * Método para imprimir std::strings
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	03/05/2011
			 * @param	const std::string&	pText		, texto
			 * @param	const Core::Point&	pPosition	, posição a imprimir o texto
			 * @param	const Color&		pColor		, cor a imprimir
			 * @param	const Color&		pBgColor	, cor de fundo, use -1 para transparente
			 */
			void drawText
			(
				const std::string&	pText,
				const Core::Point&	pPosition,
				const Color&		pColor		= 0,
				const Color&		pBgColor	= -1
			);
			/**
			 * Método para imprimir std::strings formatadas ao estilo printf
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	03/05/2011
			 * @param	const Core::Point&	pPosition	, posição a imprimir o texto
			 * @param	const Color&		pColor		, cor a imprimir
			 * @param	const Color&		pBgColor	, cor de fundo, use -1 para transparente
			 * @param	const char*			pText		, texto formatado
			 * @param	...								, as variáveis de formato
			 */
			void drawText
			(
				const Core::Point&	pPosition,
				const Color&		pColor,
				const Color&		pBgColor,
				const char* 		pText,
				...
			);
			/**
			 * Método para copiar a imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Image&		pImage			, imagem a ser colada
			 * @param	const Core::Point&	pPosition		, posição na imagem que irá colar a outra
			 * @param	const Core::Point&	pSourcePosition	, posição na imagem passada que começará a colar
			 * @param	const int& 			pWidth			, largura do corte
			 * @param	const int&			pHeight			, altura do corte
			 * @param	bool				pMasked			, se irá permitir transparência ou não
			 */
			void blitImage
			(
				const Image&		pImage,
				const Core::Point&	pPosition,
				const Core::Point&	pSourcePosition	=  Core::Point(0,0),
				const int&			pWidth			= -1,
				const int&			pHeight			= -1,
				const bool&			pMasked			= false
			);
			/**
			 * Método para copiar a imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	03/05/2011
			 * @param	const Image&		pImage			, imagem a ser colada
			 * @param	const Core::Point&	pPosition		, posição na imagem que irá colar a outra
			 * @param	const int&			pWidth			, largura que ocupará na imagem
			 * @param	const int&			pHeight			, altura que ocupará na imagem
			 * @param	const Core::Point& 	pSourcePosition	, posição na imagem passada que começará a colar
			 * @param	const int&			pSourceWidth	, largura do corte na imagem passada
			 * @param	const int&			pSourceHeight	, altura do corte na imagem passada
			 * @param	const bool&			pMasked			, se irá permitir transparência ou não
			 */
			void blitImageStretched
			(
				const Image&		pImage,
				const Core::Point&	pPosition,
				const int&			pWidth			= -1,
				const int&			pHeight			= -1,
				const Core::Point&	pSourcePosition	=  Core::Point(0,0),
				const int&			pSourceWidth	= -1,
				const int&			pSourceHeight	= -1,
				const bool&			pMasked			= false
			);
			/**
			 * Método que retorna se a imagem está vazia, ou sejá preenchida com a cor transparente
			 *
			 * @author  Cantidio Oliveira Fontes
			 * @since   13/12/2009
			 * @version 13/12/2009
			 * @return  bool
			 */
			bool isEmpty() const;
			/**
			 * Operador de comparação
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	13/12/2009
			 * @param	const Image& pImage, imagem a se comparar
			 * @return	bool
			 */
			bool operator ==(const Image& pImage) const;
			/**
			 * Operador de igualdade
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	24/01/2009
			 * @param	const Image& pImage, imagem a ser atribuída
			 */
			void operator =(const Image& pImage);
	};
}}
#endif
