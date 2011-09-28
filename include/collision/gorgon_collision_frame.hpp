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
#ifndef _GORGON_COLLISION_FRAME_
#define _GORGON_COLLISION_FRAME_
#include <vector>
#include <sstream>
#include "../core/file.hpp"
#include "../geometry/gorgon_rectangle.hpp"
#include "../graphic/image.hpp"

namespace Gorgon
{
	/**
	 * Classe para o tratamento de colisoes
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/08/2008
	 * @version	21/06/2009
	 * @ingroup	Collision
	 */
	class CollisionFrame
	{
		private:
			/**
			 * Vetor com os retângulos de colisão
			 */
			std::vector<Rectangle> mBoxes;
			/**
			 * Retângulo retornado sempre que buscado algum retângulo não encontrado na classe
			 */
			static Rectangle mNotFound;
		public:
			/**
			 * Método construtor de classe
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/04/2009
			 */
			CollisionFrame();
			/**
			 * Método construtor de classe que carrega os dados da colisão de um arquivo já aberto
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			CollisionFrame(Core::File& pFile);
			/**
			 * Método para descrever a Colisão
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	13/04/2009
			 * @return	std::string
			 */
			std::string describe() const;
			/**
			 * Método para desenhar o frame de colisão em uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	19/06/2009
			 * @version	19/06/2009
			 * @param	const Core::Point&	pPosition	, posição em que a colisão será desenhada
			 * @param	const Color&		pColor		, cor em que a colisão será desenhada
			 * @param	Image&				pImage		, imagem de destino que a colisão será desenhada
			 */
			void draw
			(
				const Core::Point& pPosition,
				const Graphic::Color& pColor,
				Graphic::Image& pImage
			) const;
			/**
			 * Método para saber se uma determinada caixa de colisão colidiu com a outra
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/04/2009
			 * @param	const CollisionFrame& collision, ponteiro para a caixa de colisão
			 * @param	const Core::Point& absolutePosition, posição em que a colisão da classe se localiza no espaço
			 * @param	const Core::Point& absoluteCollisionFramePosition, posição em que a colisão que está-se testando está
			 * @return	bool
			 */
			bool colide
			(
				const CollisionFrame&	pCollisionFrame,
				const Core::Point&		pAbsolutePosition			= Core::Point(0,0),
				const Core::Point&		pAbsoluteColisionPosition	= Core::Point(0,0)
			) const;
			/**
			 * método para salvar a caixa de colisão em um arquivo já aberto previamente
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void save(Core::File& pFile) const;
			/**
			 * Método para carregar os dados da caixa de colisão de um arquivo já aberto
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void load(Core::File& pFile);
			/**
			 * Método para retornar o número de retângulos que compõem a colisão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/06/2009
			 * @version	04/06/2009
			 * @return	int
			 */
			int getSize() const;
			/**
			 * Método para adicionar um retângulo de colisão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	19/06/2009
			 * @version	19/06/2009
			 * @param	const Rectangle& pRectangle , retângulo a ser adicionado
			 */
			void add(const Rectangle& pRectangle);
			/**
			 * Método para adicionar um retângulo de colisão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	19/06/2009
			 * @version	19/06/2009
			 * @param	const Rectangle&	pRectangle	, retângulo a ser adicionado
			 * @param	const int&			pPos		, posição no vetor de retangulos
			 */
			void add(const Rectangle& pRectangle,const int& pPos);
			/**
			 * Operador para acessar uma determinada posição no pacote
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/04/2009
			 * @version	13/04/2009
			 * @param	const int& pPos, posição que deseja-se acessar
			 * @return	Rectangle&
			 */
			Rectangle& operator[](const int& pPos);
			/**
			 * Operador constante para acessar uma determinada posição no pacote
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/04/2009
			 * @version	13/04/2009
			 * @param	const int& pPos, posição que deseja-se acessar
			 * @return	const Rectangle&
			 */
			const Rectangle& operator[](const int& pPos) const;
	};
}
#endif
