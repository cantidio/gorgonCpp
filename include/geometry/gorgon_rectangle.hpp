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
 *  Copyright (C) 2008-2010  Cantidio Oliveira Fontes
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
#ifndef _GORGON_GEOMETRY_RECTANGLE_
#define _GORGON_GEOMETRY_RECTANGLE_
#include "../core/point.hpp"
#include <string>
#include <sstream>

namespace Gorgon
{
	/**
	 * Classe que representa um retângulo
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	27/03/2009
	 * @version	19/06/2009
	 * @ingroup	Geometry
	 */
	class Rectangle
	{
		private:
			/**
			 * The width of the rectangle
			 */
			int mWidth;
			/**
			 * The height of the rectangle
			 */
			int mHeight;
			/**
			 * Posição do retângulo no espaço
			 */
			Core::Point mPosition;
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/03/2009
			 * @version	31/03/2009
			 * @param	const int&			pWidth		, largura do retângulo
			 * @param	const int&			pHeight		, altura do retângulo
			 * @param	const Core::Point&	pPosition	, posição do retângulo
			 */
			Rectangle
			(
				const int&			pWidth		= 0,
				const int&			pHeight		= 0,
				const Core::Point&	pPosition	= Core::Point(0,0)
			);
			/**
			 * Método para descrever os atributos do retângulo
			 *
			 * @author	Cantidio Oliveira Fontew
			 * @since	19/06/2009
			 * @version	19/06/2009
			 * @return	std::string
			 */
			std::string describe() const;
			/**
			 * Método para setar o valor da largura do retângulo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/03/2009
			 * @version	27/03/2009
			 * @param	const int& pWidth, largura do retângulo
			 */
			void setWidth(const int& pWidth);
			/**
			 * Método para setar o valor da altura do retângulo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/03/2009
			 * @version	27/03/2009
			 * @param	const int& pHeight, altura do retângulo
			 */
			void setHeight(const int& pHeight);
			/**
			 * Método para setar o valor da posicão do retângulo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	31/03/2009
			 * @version	31/03/2009
			 * @param	const Core::Point& pPosition, posição do retângulo
			 */
			void setPosition(const Core::Point& pPosition);
			/**
			 * Método para retornar a largura do retângulo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/03/2009
			 * @version	27/03/2009
			 * @return	int
			 */
			int getWidth() const;
			/**
			 * Método para retornar a altura do retângulo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/03/2009
			 * @version	27/03/2009
			 * @return	int
			 */
			int getHeight() const;
			/**
			 * Método para retorna a posição do retângulo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	31/03/2009
			 * @version	31/03/2009
			 * @return	Core::Point
			 */
			Core::Point getPosition() const;
			/**
			 * Método retorna verdadeiro se houve interceção entre 2 retângulos
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/03/2009
			 * @version	31/03/2009
			 * @param	const Rectangle&	pRectangle					, retangulo que deseja-se verificar se houve a interceção
			 * @param	const Core::Point&	pAbsolutePosition			, posição atual do retangulo que chamou o método
			 * @param	const Core::Point&	pAbsoluteRectanglePosition	, posição atual do outro retangulo
			 * @return	bool
			 */
			bool intersect
			(
				const Rectangle& pRectangle,
				const Core::Point& pAbsolutePosition			= Core::Point(0,0),
				const Core::Point& pAbsoluteRectanglePosition	= Core::Point(0,0)
			) const;
	};
}
#endif
