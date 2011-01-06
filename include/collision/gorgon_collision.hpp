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
#ifndef _GORGON_COLLISION_
#define _GORGON_COLLISION_
#include <vector>
#include <sstream>
#include "gorgon_collision_frame.hpp"

namespace Gorgon
{
	/**
	 * Classe que representa uma colisão de uma animação
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/08/2008
	 * @version	21/06/2009
	 * @ingroup Collision
	 */
	class Collision
	{
		private:
			/**
			 * Grupo da Colisão
			 */
			int mGroup;
			/**
			 * Índice da colisão
			 */
			int mIndex;
			/**
			 * Vetor com as colisões
			 */
			std::vector<CollisionFrame> mCollisions;
			/**
			 * Objeto que é retornado toda vez que uma colisão não é encontrada
			 */
			static CollisionFrame notFound;
		public:
			/**
			 * Método construtor de classe vazio
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/04/2009
			 * @param	const int& pGroup , grupo da colisão
			 * @param	const int& pIndex , índice da colisão
			 */
			Collision(const int& pGroup = 0, const int& pIndex = 0);
			/**
			 * Método construtor de classe, carreda as informações da memória
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/04/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			Collision(Core::File& pFile);
			/**
			 * Método construtor de classe, carrega as informações de um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/04/2009
			 * @param	const std::string& pFileName, nome do arquivo a carregar os dados
			 */
			Collision(const std::string& pFileName);
			/**
			 * Método destrutor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/04/2009
			 */
			virtual ~Collision();
			/**
			 * Método para retornar o grupo da colisão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @return	int
			 */
			int getGroup() const;
			/**
			 * Método para retornar o índice da colisão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @return	int
			 */
			int getIndex() const;
			/**
			 * Método para setar o grupo da colisão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const int& pGroup , grupo a ser atribuído a colisão
			 */
			void setGroup(const int& pGroup);
			/**
			 * Método para setar o grupo da colisão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const int& pIndex , índice a ser atribuído a colisão
			 */
			void setIndex(const int& pIndex);
			/**
			 * Método para descrever o pacote de colisões
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/04/2009
			 * @return	std::string
			 */
			std::string describe() const;
			/**
			 * Método para retornar quantas Colisões o pacote possui
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/04/2009
			 * @return	int
			 */
			int getSize() const;
			/**
			 * Método para adicionar uma Colisão ao pacote
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/04/2009
			 * @param	const CollisionFrame& pCollisionFrame, colisão a ser adicionada ao pacote
			 */
			void add(const CollisionFrame& pCollisionFrame);
			/**
			 * Método para remover uma colisão de uma determinada posição
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/04/2009
			 * @param	const int& pPos, posição a ser removida
			 */
			void remove(const int& pPos);
			/**
			 * MKétodo para salvar o pacote de colisões em um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo, já aberto
			 */
			void save(Core::File& pFile) const;
			/**
			 * Método para salvar o pacote de colisões em um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const std::string& pFileName, nome do arquivo a salvar
			 */
			void save(const std::string& pFileName) const;
			/**
			 * Método para carregar o pacote de colisões de um arquivo já aberto
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			void load(Core::File& pFile);
			/**
			 * Método para carregar o pacote de colisões de um arquivo
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const std::string& pFileName, nome do arquivo a carregar as colisões
			 */
			void load(const std::string& pFileName);
			/**
			 * Operador para acessar uma determinada posição no pacote
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/04/2009
			 * @param	const int& pPos, posição que deseja-se acessar
			 * @return	ColisionFrame&
			 */
			CollisionFrame& operator[](const unsigned int& pPos);
			/**
			 * Operador para acessar uma determinada posição no pacote de forma constante
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	18/06/2009
			 * @param	const int& pPos, posição que deseja-se acessar
			 * @return	const ColisionFrame&
			 */
			const CollisionFrame& operator[](const unsigned int& pPos) const;
	};
}
#endif
