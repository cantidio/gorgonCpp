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
#ifndef _GORGON_COLOR_
#define	_GORGON_COLOR_
#include <string>
#include <sstream>

namespace Gorgon
{
	/**
	 * Classe responsável por representar uma cor
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/05/2009
	 * @version	25/06/2009
	 * @ingroup	Graphic
	 */
	class Color
	{
		private:
			/**
			 * Componente vermelho da cor
			 */
			unsigned char mRed;
			/**
			 * Componente verde da cor
			 */
			unsigned char mGreen;
			/**
			 * Componente azul da cor
			 */
			unsigned char mBlue;
			/**
			 * Componente alpha da cor
			 */
			unsigned char mAlpha;
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @param	const int& pRed		, valor do componente vermelho da cor
			 * @param	const int& pGreen	, valor do componente verde da cor
			 * @param	const int& pBlue	, valor do componente azul da cor
			 * @param	const int& pAlpha	, valor do componente alpha da cor
			 */
			Color
			(
				const int& pRed,
				const int& pGreen,
				const int& pBlue,
				const int& pAlpha = 0
			);
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/06/2009
			 * @version	25/06/2009
			 * @param	const int& pColor, valor da cor
			 */
			Color(const int& pColor = 0);
			/**
			 * Método Construtor de Cópia
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @param	const Color& pColor, objeto Color que será copiado para o objeto atual
			 */
			Color(const Color& pColor);
			/**
			 * Método Destrutor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 */
			virtual ~Color();
			/**
			 * Método responsável por descrever os valores da classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @return	std::string
			 */
			std::string describe();
			/**
			 * Método para setar o componente vermelho da cor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @param	const int& pRed, valor do componente vermelho
			 */
			void setRed(const int& pRed);
			/**
			 * Método para setar o componente verde da cor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @param	const int& pGreen, valor do componente verde
			 */
			void setGreen(const int& pGreen);
			/**
			 * Método para setar o componente azul da cor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @param	const int& pBlue, valor do componente azul
			 */
			void setBlue(const int& pBlue);
			/**
			 * Método para setar o componente alpha da cor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @param	const int& palpha, valor do componente alpha
			 */
			void setAlpha(const int& palpha);
			/**
			 * Método para setar os atributos da classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @param	const int& pRed		, valor do componente vermelho da cor
			 * @param	const int& pGreen	, valor do componente verde da cor
			 * @param	const int& pBlue	, valor do componente azul da cor
			 * @param	const int& pAlpha	, valor do componente alpha da cor
			 */
			void set
			(
				const int& pRed		= 0,
				const int& pGreen	= 0,
				const int& pBlue	= 0,
				const int& pAlpha	= 0
			);
			/**
			 * Método para pegar o valor do componente vermelho da cor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @return	int
			 */
			int getRed() const;
			/**
			 * Método para pegar o valor do componente verde da cor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @return	int
			 */
			int getGreen() const;
			/**
			 * Método para pegar o valor do componente azul da cor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @return	int
			 */
			int getBlue() const;
			/**
			 * Método para pegar o valor do componente alpha da cor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @return	int
			 */
			int getAlpha() const;
			/**
			 * Método para retornar o valor da cor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @return	int
			 */
			int get() const;
			/**
			 * Operador de soma
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @param	const Color& pColor, cor a somar
			 * @return	Color
			 */
			Color operator +(const Color& pColor) const;
			/**
			 * Operador de soma
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @param	const Color& pColor, cor a ser somada
			 */
			void operator +=(const Color& pColor);
			/**
			 * Operador de subtração
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @param	const Color& pColor, cor a subtraír
			 */
			Color operator -(const Color& pColor) const;
			/**
			 * Operador de subtração
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2009
			 * @param	const Color& pColor, cor a ser subtraída
			 */
			void operator -=(const Color& pColor);
			/**
			 * Operador de divisão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/06/2009
			 * @version	25/06/2009
			 * @param	const double& pValue, valor a dividir a cor
			 * @return	Color
			 */
			Color operator /(const double& pValue) const;
			/**
			 * Operador de multiplicação
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/06/2009
			 * @version	25/06/2009
			 * @param	const double& pValue, valor a multiplicar a cor
			 * @return	Color
			 */
			Color operator *(const double& pValue) const;
			/**
			 * Operador de igualdade
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/06/2009
			 * @version	25/06/2009
			 * @param	const Color& pColor, cor a verificar a igualdade
			 * @return	bool
			 */
			bool operator ==(const Color& pColor) const;
			/**
			 * Operador de diferença
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/06/2009
			 * @version	25/06/2009
			 * @param	const Color& pColor, cor a verificar a diferença
			 * @return	bool
			 */
			bool operator !=(const Color& pColor) const;
	};
}

#endif

