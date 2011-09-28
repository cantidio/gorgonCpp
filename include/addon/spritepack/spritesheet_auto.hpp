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
#ifndef _GORGON_SPRITEPACK_SPRITESHEET_AUTO_
#define _GORGON_SPRITEPACK_SPRITESHEET_AUTO_
#include "../../graphic/spritepack.hpp"

namespace Gorgon{
namespace Addon
{
	class SpriteSheetAuto: public Graphic::SpritePack
	{
		public:
			/**
			 * Método construtor que recebe  um spritesSheet e o separa
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	28/02/2009
			 * @version	28/02/2009
			 * @see		getSpriteInSpriteSheet
			 * @param	const Graphic::Image& pImageSheet	, a imagem do spriteSheet
			 * @param	const Graphic::Color& pBackgroundColor	, cor de fundo do sheet
			 * @details
			 *			Esse método funciona da seguinte maneira:
			 * O método roda a imagem ignorando a backgroundColor, assim que acha uma cor diferente da backgroundColor,
			 * ele assume que ali começa uma imagem, ou seja as imagens devem estar com uma cor de fundo diferente do
			 * sheet inteiro, para que o método as possa identificar. Esse método faz a localização da imagem de cima para baixo
			 * e da esquerda para a direita, ou seja as imagens mais altas serão incluídas primeiro, e das que começam na mesma posição
			 * em y as mais a esquerda serão incluídas primeiro.
			 */
			SpriteSheetAuto(const Graphic::Image pImageSheet, const Graphic::Color& pBackgroundColor);
		protected:
			/**
			 * Método para achar os limites de uma imagem, a partir de um determinado ponto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/09/2009
			 * @final	29/09/2009
			 * @param	const Graphic::Image&		pImage
			 * @param	std::vector<Core::Point>&	pPositions			, vetor com as posições já percorridas pelo método
			 * @param	Core::Point&				pInit				, posição do ponto superior esquerdo da imagem
			 * @param	Core::Point&				pEnd				, posição do ponto inferior direito da imagem
			 * @param	const Graphic::Color&		pTransparentColor	, cor transparent da imagem
			 */
			void findImageLimits
			(
				const Graphic::Image&		pImage,
				std::vector<Core::Point>&	pPositions,
				Core::Point&				pInit,
				Core::Point&				pEnd,
				const Graphic::Color&		pTransparentColor
			);
	};
}}
#endif
