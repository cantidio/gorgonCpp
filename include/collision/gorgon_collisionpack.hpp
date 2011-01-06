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
 *  Copyright (C) 2008-2009  Gorgon Team
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
#ifndef _GORGON_COLLISION_PACK_
#define _GORGON_COLLISION_PACK_
#include <vector>
#include <sstream>
#include "gorgon_collision.hpp"

namespace Gorgon
{
	/**
	 * Classe que representa um pacote de colisões
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	18/06/2009
	 * @version	21/06/2009
	 * @ingroup	Collision
	 */
	class CollisionPack
	{
		private:
			/**
			 * Collision que é retornada sempre que uma colisão inexistente é requisitada
			 */
			static Collision mNotFound;
			/**
			 * Vetor que guarda as colisões
			 */
			std::vector<Collision> mCollision;
		public:
			/**
			 * Método construtor vazio
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 */
			CollisionPack();
			/**
			 * Método construtor que carrega os dados de um arquivo já aberto
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			CollisionPack(Core::File& pFile);
			/**
			 * Método construtor que carrega os dados de um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const std::string& pFileName, nome do arquivo a ser aberto para carregar os dados
			 */
			CollisionPack(const std::string& pFileName);
			/**
			 * Método destrutor de classe
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 */
			~CollisionPack();
			/**
			 * Método para descrever o pacote de colisões
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @return	std::string
			 */
			std::string describe() const;
			/**
			 * Método para retornar quantas colisões estão presentes no pacote
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @return	int
			 */
			int getSize() const;
			/**
			 * Método para limpar as colisões do pacote
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @return	int
			 */
			void clear();
			/**
			 * Método para retornar a posição da primeira colisão no pacote com as especificações fornecidas
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const int& pGroup, grupo da colisão
			 * @param	const int& pIndex, índice da colisão
			 * @return	int
			 */
			int getCollisionRealIndex(const int& pGroup, const int& pIndex) const;
			/**
			 * Método para adicionar uma colisão ao pacote
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const Collision& pCollision, ponteiro para a colisão a ser adicionada
			 */
			void add(const Collision& pCollision);
			/**
			 * Método para adicionar uma colisão ao pacote em uma determinada posição
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const Collision& pCollision, ponteiro para a colisão a ser adicionada
			 * @param	const int& pPos, posição a adicionar a colisão
			 */
			void add(const Collision& pCollision,const int& pPos);
			/**
			 * Método para remover uma colisão do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const int& pPos, posição que deseja-se remover
			 */
			void remove(const unsigned int& pPos);
			/**
			 * Método para remover uma colisão do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const int& pGroup, grupo da colisão que deseja-se remover
			 * @param	const int& pIndex, índice da colisão que deseja-se remover
			 * @details
			 *			Remove a colisão de grupo group e indice index do pacote, se por ventura o pacote
			 * possuir mais de uma colisão com o grupo e o índice especificados, remove apenas a primeira colisão
			 * encontrada
			 */
			void remove(const int& pGroup,const int& pIndex);
			/**
			 * Método para salvar o pacote de colisões em um arquivo já aberto previamente
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void save(Core::File& pFile) const;
			/**
			 * Método para salvar o pacote de colisões em um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	21/06/2009
			 * @param	std::string pFileName, nome do arquivo a ser salvo os dados do pacote de colisões
			 */
			void save(const std::string& pFileName) const;
			/**
			 * Método para carregar os dados do pacote de colisões de um arquivo já aberto
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void load(Core::File& pFile);
			/**
			 * Método para carregar os dados do pacote de colisões de um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	std::string pFileName, nome do arquivo a ser carregado
			 */
			void load(const std::string& pFileName);
			/**
			 * Operador para acessar alguma colisão dada sua posição
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const int& pPos, a posição que deseja-se selecionar
			 * @return	Collision&
			 */
			Collision& operator [](const int& pPos);
			/**
			 * Operador para acessar alguma colisão dada sua posição de forma constante
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const int& pPos, a posição que deseja-se selecionar
			 * @return	const Collision&
			 */
			const Collision& operator [](const int& pPos) const;
			/**
			 * Operador para acessar alguma colisão dados seu grupo e seu índice
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const int& pGroup, grupo da colisão
			 * @param	const int& pIndex, índice da colisão
			 * @return	Collision&
			 * @details
			 *			Esse Método pode ser muito custoso dado o tamanho de colisões
			 */
			Collision& operator ()(const int& pGroup,const int& pIndex);
			/**
			 * Operador para acessar alguma colisão dados seu grupo e seu índice de forma constante
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const int& pGroup, grupo da colisão
			 * @param	const int& pIndex, índice da colisão
			 * @return	const Collision&
			 * @details
			 *			Esse Método pode ser muito custoso dado o tamanho de colisões
			 */
			const Collision& operator ()(const int& pGroup,const int& pIndex) const;
	};
}
#endif
