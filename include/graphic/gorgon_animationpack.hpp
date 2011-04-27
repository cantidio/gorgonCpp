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
#ifndef _GORGON_ANIMATION_PACK_
#define _GORGON_ANIMATION_PACK_
#include <vector>
#include <fstream>
#include "gorgon_animation.hpp"
#include "gorgon_animationpack_exception.hpp"
#include "gorgon_animationpack_header.hpp"

namespace Gorgon
{
	/**
	 * Classe que representa um pacote de animações
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	13/08/2008
	 * @version	21/06/2009
	 * @ingroup	Graphic
	 */
	class AnimationPack
	{
		private:
			/**
			 * Header do arquivo do AnimationPack
			 */
			AnimationPackHeader mHeader;
			/**
			 * Animation que é retornada sempre que uma animação inexistente é requisitada
			 */
			static Animation mNotFound;
			/**
			 * Vetor que guarda as animações
			 */
			std::vector<Animation> mAnimation;
		public:
			/**
			 * Método construtor vazio
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 */
			AnimationPack();
			/**
			 * Método construtor que carrega os dados de um arquivo já aberto
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			AnimationPack(Core::File& pFile);
			/**
			 * Método construtor que carrega os dados de um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @param	const std::string& pFileName, nome do arquivo a ser aberto para carregar os dados
			 */
			AnimationPack(const std::string& pFileName);
			/**
			 * Método destrutor de classe
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 */
			~AnimationPack();
			/**
			 * Método para otimizar o pacote de animações
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 */
			void optimize(const SpritePack& pSpritePack);
			/**
			 * Método para descrever o pacote de animações
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	std::string
			 */
			std::string describe();
			/**
			 * Método para retornar quantas animações estão presentes no pacote
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	int
			 */
			int getSize();
			/**
			 * Método para limpar as animações do pacote
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	int
			 */
			void clear();
			/**
			 * Método para retornar a posição da primeira animação no pacote com as especificações fornecidas
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2008
			 * @version	02/03/2009
			 * @param	const int& pGroup, grupo da animação
			 * @param	const int& pIndex, índiceda animação
			 * @return	int
			 */
			int getAnimationRealIndex(const int& pGroup, const int& pIndex);
			/**
			 * Método para adicionar uma animação ao pacote
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const Animation& pAnimation, animação a ser adicionada
			 */
			void add(const Animation& pAnimation);
			/**
			 * Método para adicionar uma animação ao pacote em uma determinada posição
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2008
			 * @version	21/06/2009
			 * @param	const Animation&	pAnimation	, animação a ser adicionada
			 * @param	const int&			pPos		, posição a adicionar a animação
			 */
			void add(const Animation& pAnimation, const int& pPos);
			/**
			 * Método para remover uma animação do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	21/06/2009
			 * @param	const int& pPos, posição que deseja-se remover
			 */
			void remove(const int& pPos);
			/**
			 * Método para remover uma animação do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	02/03/2009
			 * @param	const int& pGroup, grupo da animação que deseja-se remover
			 * @param	const int& pIndex, índice da animação que deseja-se remover
			 * @details
			 *			Remove a animação de grupo group e indice index do pacote, se por ventura o pacote
			 * possuir mais de uma animação com o grupo e o índice especificados, remove apenas a primeira animação
			 * encontrada
			 */
			void remove(const int& pGroup,const int& pIndex);
			/**
			 * Método para salvar o pacote de animações em um arquivo já aberto previamente
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void save(Core::File& pFile);
			/**
			 * Método para salvar o pacote de animações em um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	std::string pFileName, nome do arquivo a ser salvo os dados do pacote de animações
			 */
			void save(const std::string& pFileName);
			/**
			 * Método para carregar os dados do pacote de animações de um arquivo já aberto
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void load(Core::File& pFile);
			/**
			 * Método para carregar os dados do pacote de animações de um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	std::string pFileName, nome do arquivo a ser carregado
			 */
			void load(const std::string& pFileName);
			/**
			 * operador para acessar alguma animação dada sua posição
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const int& pPos, a posição que deseja-se selecionar
			 * @return	Animation&
			 */
			Animation& operator [](const int& pPos);
			/**
			 * operador para acessar alguma animação dados seu grupo e seu índice
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const int& pGroup, grupo da animação
			 * @param	const int& pIndex, índice da animação
			 * @return	Animation&
			 * @details
			 *			Esse Método pode ser muito custoso dado o tamanho de animações
			 */
			Animation& operator ()(const int& pGroup,const int& pIndex);
	};
}
#endif
