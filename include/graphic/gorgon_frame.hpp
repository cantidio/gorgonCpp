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
#ifndef _GORGON_FRAME_
#define _GORGON_FRAME_
#include "../core/gorgon_file.hpp"
#include "gorgon_spritepack.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe que representa um frame de uma animação
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/08/2008
	 * @version	21/06/2009
	 * @ingroup	Graphic
	 * @todo	os offsets não estão funcionando
	 */
	class Frame
	{
		private:
			int mGroup;				/**<< Grupo do sprite do frame*/
			int mIndex;				/**<< Índice do sprite do frame*/
			int mRealIndex;			/**<< Índice real do sprite do frame no SpritePack*/
			int mTime;				/**<< Tempo que o frame deve ser exibido*/
			Point mOffset;			/**<< Offset do frame*/
			Mirroring mMirroring;	/**<< Espelhamento do sprite do frame*/
			int mAngle;				/**<< Ângulo do sprite do frame*/
			//int transparence;
		public:
			/**
			 * método construtor de classe
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	23/02/2009
			 */
			Frame();
			/**
			 * método construtor de classe
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	03/05/2011
			 * @param	const int&			pGroup		, grupo do sprite do frame
			 * @param	const int&			pIndex		, index do sprite do frame
			 * @param	const int& 			pTime		, tempo que o frame deve ser exibido
			 * @param	const Mirroring&	pMirroring	, espelhamento do sprite do frame
			 * @param	const int&			pAngle		, ângulo do sprite do frame
			 * @param	const Point&		pOffset		, offset do sprite do frame
			 */
			Frame
			(
				const int&			pGroup,
				const int&			pIndex,
				const int&			pTime,
				const Mirroring&	pMirroring	= Mirroring::Normal,
				const int&			pAngle		= 0,
				const Point&		pOffset		= Point(0,0)
			);
			/**
			 * método construtor que busca as informações em um arquivo já aberto
			 *
			 * @author Cantidio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			Frame(Core::File& pFile);
			/**
			 * método para descrever o frame
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	std::string
			 */
 			std::string describe() const;
			/**
			 * método para retornar o grupo do sprite que o frame indica
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/08/2008
			 * @return	int
			 */
			int getGroup() const;
			/**
			 * método para retornar o índice do sprite que o frame indica
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/08/2008
			 * @return	int
			 */
			int getIndex() const;
			/**
			 * método para retornar o índice real do sprite que o frame indica
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/08/2008
			 * @return	int
			 */
			int getRealIndex() const;
			/**
			 * método para retornar o shift no eixo x do sprite que o frame indica
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	03/05/2011
			 * @return	Point
			 */
			Point getOffset() const;
			/**
			 * método para retornar o tempo que o frame deve ser exibido
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/08/2008
			 * @return	int
			 */
			int getTime() const;
			/**
			 * método para retornar o espelhamento do sprite que o frame indica
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	27/02/2009
			 * @return	Mirroring
			 */
			Mirroring getMirroring() const;
			/**
			 * método para retornar o angulo que o sprite deve ser desenhado
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/08/2008
			 * @return	int
			 */
			int getAngle() const;
			/**
			 * Método para setar o grupo do frame
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pGroup, o grupo do sprite
			 */
			void setGroup(const int& pGroup);
			/**
			 * Método para setar o índice do frame
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pIndex, o índice do sprite
			 */
			void setIndex(const int& pIndex);
			/**
			 * Método para setar o índice real do sprite que o frame indica
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	23/02/2009
			 * @param	const int& pIndex, o índice real do sprite
			 */
			void setRealIndex(const int& pIndex);
			/**
			 * Método para setar o tempo de exibição do frame
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pTime, o tempo de exibição do frame
			 */
			void setTime(const int& pTime);
			/**
			 * Método para setar o offset
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/05/2011
			 * @version	03/05/2011
			 * @param	const Point& pOffset, offset do frame
			 */
			void setOffset(const Point& pOffset);
			/**
			 * Método para setar o offset horizontal
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pXOffset, o offset horizontal do sprite
			 */
			void setXOffset(const int& pXOffset);
			/**
			 * Método para setar o offset vertical
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pYOffset, o offset vertical do sprite
			 */
			void setYOffset(const int& pYOffset);
			/**
			 * Método para setar o espelhamento do frame
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const Mirroring& pMirroring, o espelhamento do sprite
			 */
			void setMirroring(const Mirroring& pMirroring);
			/**
			 * Método para setar o angulo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pAngle, o angulo do sprite
			 */
			void setAngle(const int& pAngle);
			/**
			 * método para otimizar as operações com o frame, achando o indice real do mesmo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	23/02/2009
			 * @param	const SpritePack& pSpritePack, ponteiro para o pacote de sprites, onde a pesquisa será feita
			 */
			void optimize(const SpritePack& pSpritePack);
			/**
			 * método para carregar os dados do frame de um arquivo já aberto
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void load(Core::File& pFile);
			/**
			 * método para salvar o frame em um arquivo já aberto previamente
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void save(Core::File& pFile);
	};
}}
#endif
