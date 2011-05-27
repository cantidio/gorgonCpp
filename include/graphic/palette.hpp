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
#ifndef _GORGON_PALETTE_
#define _GORGON_PALETTE_
#include <sstream>
#include <allegro.h>
#include "../core/file.hpp"
#include "../core/exception.hpp"
/**@todo retirar esse allegro daqui*/
namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe responsavel por tratar das paletas de cores
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/08/2008
	 * @version	06/08/2009
	 * @ingroup	Graphic
	 */
	class Palette
	{
		private:
			/**
			 * Paleta de Cores RGB
			 * Paleta de Cores com valores normais de rgb
			 */
			RGB mPal[256];
			/**
			 * Paleta de Cores RGB
			 * Paleta de Cores com valores rgb/4, valores usados pelo allegro
			 */
			RGB mPal2[256];
		public:
			/**
			 * Método construtor sem parâmetro
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	08/08/2008
			 */
			Palette();
			/**
			 * Método construtor que recebe uma cor para preencher toda a paleta
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	int pRed	, quantidade de vermelho da cor
			 * @param	int pBlue	, quantidade de azul da cor
			 * @param	int pGreen	, quantidade de verde da cor
			 */
			Palette
			(
				const int& pRed,
				const int& pGreen,
				const int& pBlue
			);
			/**
			 * Método construtor inicializado
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	14/08/2008
			 * @param	const std::string& pPaletteName, nome do arquivo com a palheta
			 * @param	int colors, número de cores a ser carregado, default=256
			 */
			Palette(const std::string& pPaletteName);
			/**
			 * Método construtor inicializado
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	17/02/2009
			 * @param	File&		pFile			, arquivo já aberto
			 * @param	const int&	pColorNumber	, número de cores a ser carregado
			 * @param	const int&	pJumpBytes		, número de bytes a saltar a cada conjunto RGB lido
			 */
			Palette
			(
				Core::File&	pFile,
				const int&	pColorNumber	= 256,
				const int&	pJumpBytes		= 0
			);
			/**
			 * Método destrutor de classe
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 */
			~Palette();
			/**
			 * Método para descrever os atributos da classe
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @return	std::string
			 */
			std::string describe() const;
			/**
			 * Método para retornar uma c�pia da paleta de cores
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @return	Palette *
			 */
			Palette* clone() const;
			/**
			 * Método para apagar uma palheta de cores
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/01/2009
			 */
			void erase();
			/**
			 * Método para aplicar a palheta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 */
			void set() const;
			/**
			 * Método para pegar a paleta atual
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/01/2009
			 * @version	21/01/2009
			 */
			void get();
			/**
			 * Método para inverter a palheta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	18/02/2009
			 * @param	const int& pColorNumber, número de cores a inverter de posição
			 */
			void inverse(const int& pColorNumber = 256);
			/**
			 * Método que troca os valores de azul por vermelho e vermelho por azul em toda palheta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 */
			void switchBlueForRed();
			/**
			 * Método que troca os valores de azul por verde e verde por azul em toda palheta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 */
			void switchBlueForGreen();
			/**
			 * Método que troca os valores de vermelho por verde e verde e vermelho em toda palheta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 */
			void switchRedForGreen();
			/**
			 * Método para retornar uma cor de uma posição da paleta
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	13/08/2008
			 * @param	int pPos, posição que deseja-se obter a cor
			 * @return	int
			 */
			int getColor(const int& pPos) const;
			/**
			 * Método para retornar o valor de vermelho de uma posição da paleta
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	int pPos , posição que deseja-se obter o vermelho
			 * @return	int
			 */
			int getRed(const int& pPos) const;
			/**
			 * Método para retornar o valor de verde de uma posição da paleta
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	int pPos , posição que deseja-se obter o verde
			 * @return	int
			 */
			int getGreen(const int& pPos) const;
			/**
			 * Método para retornar o valor de azul de uma posição da paleta
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	int pos, posição que deseja-se obter o azul
			 * @return	int, valor do azul se a posição existir, se não retorna 0
			 */
			int getBlue(const int& pPos)	const;
			/**
			 * Método para colocar uma determinada cor em uma posição da paleta
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	int pRed	, valor do vermelho da cor
			 * @param	int pGreen	, valor do verde da cor
			 * @param	int pBlue	, valor do azul da cor
			 * @param	int pPos	, posição que deseja-se setar a cor
			 */
			void setColor
			(
				const int& pRed,
				const int& pGreen,
				const int& pBlue,
				const int& pPos
			);
			/**
			 * Método para setar o valor de vermelho de determinada posição da paleta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	int pRed , valor do vermelho
			 * @param	int pPos , posição a colocar o vermelho
			 */
			void setRed(const int& pRed,const int& pPos);
			/**
			 * Método para setar o valor de verde de determinada posição da paleta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	int pGreen	, valor do verde
			 * @param	int pPos	, posição a colocar o verde
			 */
			void setGreen(const int& pGreen,const int& pPos);
			/**
			 * Método para setar o valor de azul de determinada posição da paleta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	int pBlue	, valor do azul
			 * @param	int pPos	, posição a colocar o azul
			 */
			void setBlue(const int& pBlue,const int& pPos);
			/**
			 * Método para salvar a palheta em um arquivo, já aberto
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since 	30/04/2008
			 * @version 17/02/2008
			 * @param 	File&		pFile			, arquivo já aberto
			 * @param	const int&	pColorNumber	, número de cores que ser� salvo no arquivo, default=256
			 * @param	const int&	pJumpBytes		, número de bytes a escrever a cada conjunto RGB lido
			 */
			void save
			(
				Core::File&	pFile,
				const int&	pColorNumber	= 256,
				const int&	pJumpBytes		= 0
			) const;
			/**
			 * Método para salvar a palheta em um arquivo
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since 	30/04/2008
			 * @version 17/02/2008
			 * @param 	const std::string&	pPaletteName , o nome do arquivo a ser salvo
			 * @param	const int&			pColorNumber , número de cores a salvar
			 */
			void save(const std::string& pPaletteName,const int& pColorNumber = 256) const;
			/**
			 * Método para carregar uma paleta de cores da mem�ria
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since 	29/04/2008
			 * @version	06/08/2009
			 * @param	File&		pFile			, arquivo já aberto
			 * @param	const int&	pColorNumber	, número de cores a carregar
			 * @param	const int&	pJumpBytes		, número de bytes a saltar a cada conjunto RGB lido
			 */
			void load
			(
				Core::File&	pFile,
				const int&	pColorNumber	= 256,
				const int&	pJumpBytes		= 0
			);
			/**
			 * Método para carregar uma paleta de cores de um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	17/02/2009
			 * @param	const std::string&	pPaletteName , nome do arquivo da paleta
			 * @param	const int&			pColorNumber , número de cores a carregar
			 */
			void load(const std::string& pPaletteName,const int& pColorNumber = 256);
	};
}}
#endif
