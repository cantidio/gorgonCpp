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
#ifndef _GORGON_ANIMATION_
#define _GORGON_ANIMATION_
#include <string>
#include <vector>
#include "animation_frame.hpp"
#include "animation_exception.hpp"
#include "animation_header.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe que representa a definição de uma animação
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	13/08/2008
	 * @version	21/06/2009
	 * @ingroup	Graphic
	 */
	class Animation
	{
		private:
			AnimationHeader mHeader;			/**<< Header do arquivo Animation*/
			static AnimationFrame mNotFound;	/**<< Frame que é retornando sempre que um frame que não existe é requisitado*/
			std::vector<AnimationFrame> mFrame;	/**<< Vetor que guarda os frames da animação*/
			int	mGroup;							/**<< Grupo da animação*/
			int	mIndex;							/**<< Índice da animação*/
			bool mLooping;						/**<< Verdadeiro se a animação entra em loop*/
			int	mLoopFrame;						/**<< frame em que a animação entra em loop*/
			int mRepeatNumber;					/**<< número de vezes que a animação repetirá*/
		public:
			/**
			 * Método construtor vazio
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 */
			Animation();
			/**
			 * Método construtor inicializado
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @param	const int&	group		, grupo da animação
			 * @param	const int&	index		, índice da animação
			 * @param	const bool&	looping		, se a animação terá loop
			 * @param	const int&	loopFrame	, número do frame que a animação entrará em loop
			 * @param	const int&	repeatNumber, número de vezes que a animação repetirá
			 */
			Animation
			(
				const int&	pGroup,
				const int&	pIndex,
				const bool&	pLooping	= false,
				const int&	pLoopFrame	= 0,
				const int&	pRepeatNumber	= -1
			);
			/**
			 * Método construtor que carrefa os dados diretamente de um arquivo já aberto
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			Animation(Core::File& pFile);
			/**
			 * Método construtor que carrefa os dados diretamente de um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @param	const std::string& fileName, nome do arquivo a ser aberto
			 */
			Animation(const std::string& pFileName);
			/**
			 * Método destrutor de classe
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 */
			~Animation();
			/**
			 * Método para encontrar os índices reais de todos os frames de uma animacão dado o spritepack
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	24/02/2009
			 * @param	const SpritePack& spritePack, ponteiro para o spritepack
			 */
			void optimize(const SpritePack& pSpritePack);
			/**
			 * Método para descrever a animação
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	18/06/2009
			 * @return	std::string
			 */
			std::string describe();
			/**
			 * Método para retornar a posição do primeiro frame na animação com as especificação cedida
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	02/03/2009
			 * @param	const int& group	, grupo do frame
			 * @param	const int& index	, índice do frame
			 */
			int getFrameRealIndex(const int& pGroup, const int& pIndex);
			/**
			 * Método para adicionar um frame à animação
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const AnimationFrame& pFrame, frame a ser adicionado
			 */
			void add(const AnimationFrame& pFrame);
			/**
			 * Método para adicionar um frame à animação em uma determinada posição
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	21/06/2009
			 * @param	const AnimationFrame&	pFrame	, frame a ser adicionado
			 * @param	const int&				pPos	, posição que deverá ser adicionado
			 */
			void add(const AnimationFrame& pFrame,const int& pPos);
			/**
			 * Método para remover um frame da animação
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	06/01/2011
			 * @param	const unsigned int& pos, posição do frame na animação
			 */
			void remove(const unsigned int& pPos);
			/**
			 * Método para remover um frame da animação dados o grupo e o índice
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	02/03/2009
			 * @param	const int& pos, posição do frame na animação
			 */
			void remove(const int& pGroup,const int& pIndex);
			/**
			 * Método para retornar o número de frames da animação
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	int
			 */
			int	getSize() const;
			/**
			 * Método para retornar o grupo da animação
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	const int&
			 */
			int getGroup() const;
			/**
			 * Método para retornar o índice da animação
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	const int&
			 */
			int getIndex() const;
			/**
			 * Método para retornar se a animação possui loop
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	25/02/2009
			 * @return	const bool&
			 */
			bool getLooping() const;
			/**
			 * Método para retornar o frame de início do loop
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	25/02/2009
			 * @return	const int&
			 */
			int getLoopFrame() const;
			/**
			 * Método para retornar o número de repetições da animação
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	const int&
			 */
			int getRepeatNumber() const;
			/**
			 * Método para setar o grupo da animação
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @param	const int& group, grupo da animação
			 */
			void setGroup(const int& pGroup);
			/**
			 * Método para setar o índice da animação
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @param	const int& group, índice da animação
			 */
			void setIndex(const int& pIndex);
			/**
			 * Método para setar o looping da animação
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	24/02/2009
			 * @param	const bool& looping, true se a animação terá loop
			 */
			void setLooping(const bool& pLooping);
			/**
			 * Método para setar o frame em que a animação entrará em loop
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	24/02/2009
			 * @param	const int& loopFrame, frame em que a animação entrará em loop
			 */
			void setLoopFrame(const int& pLoopFrame);
			/**
			 * Método para setar o número de vezes que a animação ficará em loop
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	24/02/2009
			 * @param	const int& repeatNumber, número de vezes que a animação repetirá
			 */
			void setRepeatNumber(const int& pRepeatNumber);
			/**
			 * Método para salvar a animação em um arquivo já aberto previamente
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */	
			void save(Core::File& pFile);
			/**
			 * Método para salvar a animação em um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	21/06/2009
			 * @param	const std::string& fileName, nome do arquivo da animação a ser salva
			 */	
			void save(const std::string& pFileName);
			/**
			 * Método para carregar os dados da animação de um arquivo já aberto
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void load(Core::File& pFile);
			/**
			 * Método para carregar os dados da animação de um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const std::string& fileName, nome do arquivo da animação a ser aberta
			 */
			void load(const std::string& pFileName);
			/**
			 * Operador para acessar algum frame dada sua posição
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	06/01/2011
			 * @param	const unsigned int& pPos, a posição que deseja-se selecionar
			 * @return	AnimationFrame&
			 */
			AnimationFrame& operator [](const unsigned int& pPos);
			/**
			 * Operador para acessar algum frame dada sua posição de forma constante
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	06/01/2011
			 * @param	const unsigned int& pPos, a posição que deseja-se selecionar
			 * @return	AnimationFrame&
			 */
			const AnimationFrame& operator [](const unsigned int& pPos) const;
	};
}}
#endif
