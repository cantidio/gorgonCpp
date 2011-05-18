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
#ifndef _GORGON_SPRITE_PACK_
#define _GORGON_SPRITE_PACK_
#include <vector>
#include "sprite.hpp"
#include "spritepack_exception.hpp"
#include "spritepack_header.hpp"
#include "../core/file.hpp"
#include "../core/string.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe que representa um pacote de sprites
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	22/01/2009
	 * @version	06/01/2011
	 * @ingroup	Graphic
	 */
	class SpritePack
	{
		protected:
			/**
			 * vetor com todos sprites inseridos no pacote
			 */
			std::vector<Sprite> mSprites;
			/**
			 * Variável que guarda a paleta global do pacote, ou seja se algum sprite não possuir uma paleta de cores,
			 * então usará a paleta global
			 */
			Palette* mGlobalPalette;
			/**
			 * Variável que guardará um sprite todo transparente e o menor possível, para retornar quando não encontrar
			 * o sprite especificado
			 */
			static Sprite* mNotFound;
			/**
			 * Verdadeiro se a paleta for linkada, falso se for interna
			 */
			bool mPalLinked;
		public:
			/**
			 * Método construtor de classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	22/01/2009
			 */
			SpritePack();
			/**
			 * Método Construtor de Cópia
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	22/01/2009
			 * @param	const SpritePack& pSpritePackOriginal, spritepack original
			 */
			SpritePack(const SpritePack& pSpritePackOriginal);
			/**
			 * Método construtor de classe iniciado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	20/05/2009
			 * @param	const Core::String& pFileName, nome do arquivo com as informações do pacote
			 */
			SpritePack(const Core::String& pFileName);
			/**
			 * Método construtor de classe iniciado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			SpritePack(Core::File& pFile);
			/**
			 * Método destrutor de classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	23/01/2009
			 */
			virtual ~SpritePack();
			/**
			 * Método para ordenar os sprites do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @todo	implementar esse método
			 */
			void sort();
			/**
			 * Método para adicionar um sprite ao pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	21/06/2009
			 * @param	const Sprite& pSprite , sprite a ser adicionado ao pacote
			 */
			void add(const Sprite& pSprite);
			/**
			 * Método para adicionar um sprite ao pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/03/2009
			 * @version	21/06/2009
			 * @param	const Sprite&	pSprite	, sprite a ser adicionado ao pacote
			 * @param	const int&		pPos	, posição que o sprite será inserido no spritepack
			 */
			void add(const Sprite& pSprite,const int& pPos);
			/**
			 * Método para remover um sprite do pacote por sua posição no vetor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	06/01/2011
			 * @param	const unsigned int& pPos, posição a ser removida
			 */
			void remove(const unsigned int& pPos);
			/**
			 * Método para remover um sprite do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	21/06/2009
			 * @param	const int& pGroup , grupo do sprite a ser removido
			 * @param	const int& pIndex , indice do sprite a ser removido
			 */
			void remove(const int& pGroup, const int& pIndex);
			/**
			 * Método para retornar o número de sprites no pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	06/01/2011
			 * @return	unsigned int
			 */
			unsigned int getSize() const;
			/**
			 * Método para retornar a posição de um determinado sprite identificado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	06/01/2011
			 * @param	const int& pGroup , grupo do sprite
			 * @param	const int& pIndex , indice do sprite
			 * @return	unsigned int
			 */
			unsigned int getSpriteRealIndex(const int& pGroup,const int& pIndex) const;
			/**
			 * Método que seta um offset global para todos os sprites do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	04/05/2011
			 * @param	const Core::Point& pOffset, offset
			 */
			void setGlobalOffset(const Core::Point& pOffset);
			/**
			 * Método para retirar as bordas transparentes dos sprites, deixando somente a parte útil da mesma e os alinhando
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	25/01/2008
			 * @todo	modificar o nome do método para trim
			 */
			void trimAll();
/*			vector<Sprite*> getSpritesInGroup(int group)	const;*/

			/**
			 * Método para retornar o sprite de uma determinada posição
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	06/01/2011
			 * @param	const int& pPos, posição que o sprite será retornado
			 * @return	Sprite&
			 */
			Sprite&	getSprite(const unsigned int& pPos);
			/**
			 * Método para retornar o sprite de uma determinada posição de forma constante
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @version	06/01/2011
			 * @param	const int& pPos, posição que o sprite será retornado
			 * @return	const Sprite&
			 */
			const Sprite& getSprite(const unsigned int& pPos) const;
			/**
			 * Método para retornar um sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	11/08/2008
			 * @param	const int& pGroup, grupo do sprite
			 * @param	const int& pIndex, indice do sprite
			 * @return	Sprite&
			 */
			Sprite&	getSprite(const int& pGroup,const int& pIndex);
			/**
			 * Método para retornar um sprite de forma constante
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	11/08/2008
			 * @param	const int& pGroup, grupo do sprite
			 * @param	const int& pIndex, indice do sprite
			 * @return	const Sprite&
			 */
			const Sprite& getSprite(const int& pGroup,const int& pIndex) const;
			/**
			 * Método para setar a paleta de cores global
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/09/2008
			 * @version	23/01/2009
			 * @param	Palette* pPalette, ponteiro para a paleta de cores
			 */
			void setGlobalPalette(Palette* pPalette);
			/**
			 * Método para aplicar a paleta de cores global a todos sprites do pacote
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/01/2009
			 * @version	23/01/2009
			 * @param	const bool& pForce, se for false substituirá apenas as paletas dos sprites que não tiverem paleta de cores
			 */
			void applyGlobalPalette(const bool& pForce = false);
			/**
			 * Método para criar uma paleta de cores global para o pacote de sprites
			 *
			 * @todo implementar esse método
			 */
//			void createGlobalPalette(int red=255, int green=0, int blue=255);

			/**
			 * Método para salvar os sprites em um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	07/08/2009
			 * @param	const Core::String& pFileName, nome do arquivo para salvar
			 * @param	ImageLoader*	pImageLoader	, ponteiro para o formato de imagem a salvar
			 */
			virtual void save(const Core::String& pFileName, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Método para salvar os sprites em um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	07/01/2011
			 * @param	File& pFile, ponteiro para o arquivo já aberto
			 * @param	ImageLoader*	pImageLoader	, ponteiro para o formato de imagem a salvar
			 */
			virtual void save(Core::File& pFile, const ImageLoader& pImageLoader = ImageLoader::getLoader());
			/**
			 * Método para carregar os sprites de um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	07/01/2011
			 * @param	const Core::String& pFileName, string com o nome do arquivo
			 */
			virtual void load(const Core::String& pFileName);
			/**
			 * Método para carregar os sprites de um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			virtual void load(Core::File& pFile);
			/**
			 * operador para acessar o SpritePack como um vetor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	06/01/2011
			 * @param	const unsigned int& pPos, inteiro sem sinal que representa a posição que deseja acessar
			 * @return	Sprite&
			 */
			Sprite& operator [](const unsigned int& pPos);
			/**
			 * Operador para acessar o SpritePack como um vetor de forma constante
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @version	06/01/2011
			 * @param	const unsigned int& pPos, inteiro sem sinal que representa a posição que deseja acessar
			 * @return	const Sprite&
			 */
			const Sprite& operator [](const unsigned int& pPos) const;
			/**
			 * operador para acessar o SpritePack através de seus identificadores
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	27/02/2009
			 * @param	const int& pGroup, inteiro sem sinal que representa o grupo do sprite a ser acessado
			 * @param	const int& pIndex, inteiro sem sinal que representa o indice do sprite a ser acessado
			 * @return	Sprite&
			 */
			Sprite& operator ()(const int& pGroup,const int& pIndex);
			/**
			 * Operador para acessar o SpritePack através de seus identificadores de forma constante
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @version	21/06/2009
			 * @param	const int& pGroup, inteiro sem sinal que representa o grupo do sprite a ser acessado
			 * @param	const int& pIndex, inteiro sem sinal que representa o indice do sprite a ser acessado
			 * @return	const Sprite&
			 */
			const Sprite& operator ()(const int& pGroup,const int& pIndex) const;
			/**
			 * Operador de igualdade
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2011
			 * @version	24/01/2011
			 * @param	const SpritePack& pSpritePack
			 */
			void operator =(const SpritePack& pSpritePack);
			/**
			 * Method that saves the spritepack throught a lua script
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/01/2011
			 * @version	27/04/2011
			 * @param	const Core::String& pFileName, the name of the script
			 */
			void saveScript(const Core::String& pFileName);
			/**
			 * Method that loads a spritepack throught a lua script
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/01/2011
			 * @version	27/04/2011
			 * @param	const Core::String& pFileName, the name of the script to load
			 */
			void loadScript(const Core::String& pFileName);
	};
}}
#endif
