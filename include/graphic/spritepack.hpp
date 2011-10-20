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
#include "../core/file.hpp"
#include "../core/string.hpp"
#include "sprite.hpp"
#include "spritepack_header.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Class that represents a spritepack
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	22/01/2009
	 * @version	03/06/2011
	 * @ingroup	Graphic
	 */
	class SpritePack
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	22/01/2009
			 */
			SpritePack();
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	22/01/2009
			 * @param	const SpritePack& pSpritePackOriginal, original spritepack
			 */
			SpritePack( const SpritePack& pSpritePackOriginal );
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	19/10/2011
			 * @param	const std::string& pFileName, name of the file that contains the spritepack data
			 */
			SpritePack( const std::string& pFileName );
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	19/10/2011
			 * @param	Core::File& pFile, file previously opened that contains the spritepack data
			 */
			SpritePack( Core::File& pFile );
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	23/01/2009
			 */
			virtual ~SpritePack();
			/**
			 * Method that sorts the sprites in the package
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @todo	implementar esse método
			 */
			void sort();
			/**
			 * Method that inserts a sprite into the spritepack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	21/06/2009
			 * @param	const Sprite& pSprite , sprite that will be inserted into the package
			 */
			void add( const Sprite& pSprite );
			/**
			 * Method that inserts a sprite into the spritepack in a given position
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/03/2009
			 * @version	21/06/2009
			 * @param	const Sprite&	pSprite	, sprite that will be inserted into the package
			 * @param	const int&		pPos	, position that the sprite will be inserted
			 */
			void add( const Sprite& pSprite, const int& pPos );
			/**
			 * Method that removes a sprite from the spritepack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	06/01/2011
			 * @param	const int& pPos, index of the sprite to be removed
			 * @details
			 * 			This method will try to remove the sprite at the given index,
			 * if the index is out ou bounds, this method does nothing
			 */
			void remove( const int& pPos );
			/**
			 * Method that removes a sprite from the spritepack given its group and index
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	21/06/2009
			 * @param	const int& pGroup , sprite's group
			 * @param	const int& pIndex , sprite's index
			 * @details
			 * 			This method will try to find and remove the requested sprite.
			 * If there's more than 1 sprite with the given group and index, this method will just remove one of them.
			 * If no sprite is found, them this method does nothing
			 */
			void remove( const int& pGroup, const int& pIndex );
			/**
			 * Method that returns the number of sprites in the spritepack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	06/01/2011
			 * @return	int
			 */
			int getSize() const;
			/**
			 * Method that returns the position(index) of sprite in the spritepack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	06/01/2011
			 * @param	const int& pGroup , group of the sprite
			 * @param	const int& pIndex , index of the sprite
			 * @return	int
			 * @details
			 * 			This Method tries to find the requested sprite and returns its index,
			 * if the sprited couldn't be localized then this method returns -1
			 */
			int getSpriteRealIndex( const int& pGroup, const int& pIndex ) const;
			/**
			 * Method that sets a global offset to all sprites in the spritepack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	04/05/2011
			 * @param	const Core::Point& pOffset, offset
			 */
			void setGlobalOffset( const Core::Point& pOffset );
			/**
			 * Method that takes this color and makes it transparent for all the images in the spritesheet
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	01/06/2011
			 * @version	03/06/2011
			 * @param	const Color& pColor, the color that will be converted in transparent
			 */
			void setAlphaMask( const Color& pColor );
			/**
			 * Method that removes all transparent borders from all sprites in the pack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2008
			 * @version	25/01/2008
			 */
			void trimAll();
/*			vector<Sprite*> getSpritesInGroup(int group)	const;*/

			/**
			 * Method that returns the sprite of the requested position
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	06/01/2011
			 * @param	const int& pPos, index of the sprite in the spritepack
			 * @return	Sprite&
			 * @details
			 * 			This method tries to get the requested sprite, but if the sprite requested is out of bounds
			 * this method returns an empty sprite
			 */
			Sprite&	getSprite( const int& pPos );
			/**
			 * Method that returns the sprite of the requested position
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @version	06/01/2011
			 * @param	const int& pPos, index of the sprite in the spritepack
			 * @return	const Sprite&
			 * @details
			 * 			This method tries to get the requested sprite, but if the sprite requested is out of bounds
			 * this method returns an empty sprite.
			 */
			const Sprite& getSprite( const int& pPos ) const;
			/**
			 * Method that returns the sprite requested by its group and index
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	11/08/2008
			 * @param	const int& pGroup, sprite's group
			 * @param	const int& pIndex, sprite's index
			 * @return	Sprite&
			 */
			Sprite&	getSprite( const int& pGroup, const int& pIndex );
			/**
			 * Method that returns the sprite requested by its group and index
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/08/2008
			 * @version	11/08/2008
			 * @param	const int& pGroup, sprite's group
			 * @param	const int& pIndex, sprite's index
			 * @return	const Sprite&
			 */
			const Sprite& getSprite( const int& pGroup, const int& pIndex ) const;
			/**
			 * Method that sets the global palette
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/09/2008
			 * @version	23/01/2009
			 * @param	Palette* pPalette, pointer tho the global palette
			 * @todo	colocar a parada bacana aqui se vai liberar a memória e talz
			 */
			void setGlobalPalette( Palette* pPalette );
			/**
			 * Method that applies the global palette to all sprites in the spritepack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/01/2009
			 * @version	23/01/2009
			 * @param	const bool& pForce, if false this method will just swap the palettes of the sprites that dont have a color palette
			 */
			void applyGlobalPalette( const bool& pForce = false );
			/**
			 * Método para criar uma paleta de cores global para o pacote de sprites
			 *
			 * @todo implementar esse método
			 */
//			void createGlobalPalette(int red=255, int green=0, int blue=255);

			/**
			 * Method that saves the spritepack into a file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	07/08/2009
			 * @param	const std::string& pFileName	, name of the file that will store the spritepack
			 * @param	const std::string& pFormat		, imageLoader responsable for saving the sprites
			 */
			virtual void save( const std::string& pFileName, const std::string& pFormat );
			/**
			 * Method that saves the spritepak into a previously opened file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	07/01/2011
			 * @param	Core::File&			pFile	, reference to the file that will store the spritepack
			 * @param	const std::string&	pFormat	, imageLoader responsable for saving the sprites
			 */
			virtual void save( Core::File& pFile, const std::string& pFormat );
			/**
			 * Method that loads the spritepack from a file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	07/01/2011
			 * @param	const std::string&	pFileName		, the name of the file that stores the spritepack data
			 */
			virtual void load( const std::string& pFileName );
			/**
			 * Método para carregar os sprites de um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/08/2008
			 * @version	21/06/2009
			 * @param	Core::File&		pFile			, the name of the file that stores the spritepack data
			 */
			virtual void load( Core::File& pFile );
			/**
			 * Operator that access the spritepack and returns the sprite of the requested position
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	06/01/2011
			 * @param	const int& pPos, the position of the requested sprite
			 * @return	Sprite&
			 */
			Sprite& operator []( const int& pPos );
			/**
			 * Operator that access the spritepack and returns the sprite of the requested position
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @version	06/01/2011
			 * @param	const int& pPos, the position of the requested sprite
			 * @return	const Sprite&
			 */
			const Sprite& operator []( const int& pPos ) const;
			/**
			 * Operator that access the spritepack and returns the requested sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	27/02/2009
			 * @param	const int& pGroup, the sprite's group
			 * @param	const int& pIndex, the sprite's index
			 * @return	Sprite&
			 */
			Sprite& operator ()( const int& pGroup, const int& pIndex );
			/**
			 * Operator that access the spritepack and returns the requested sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	21/06/2009
			 * @version	21/06/2009
			 * @param	const int& pGroup, the sprite's group
			 * @param	const int& pIndex, the sprite's index
			 * @return	const Sprite&
			 */
			const Sprite& operator ()( const int& pGroup, const int& pIndex ) const;
			/**
			 * Operator that returns true if the 2 spritepacks have the same values
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2011
			 * @version	24/01/2011
			 * @param	const SpritePack& pSpritePack
			 */
			void operator =( const SpritePack& pSpritePack );
			/**
			 * Convert all sprites to the display format, for fast drawing
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/06/2011
			 * @version	14/06/2011
			 */
			void convertToDisplayFormat();
		protected:
			std::vector<Sprite>	mSprites;			/**<< Vector will all sprites*/
			Palette*			mGlobalPalette;		/**<< The global color table*/
			static Sprite*		mNotFound;			/**<< Empty sprite that is returned every time an unknown sprited is requested*/
			bool				mPalLinked;			/**<< True if the palette is linked, false otherwise*/
	};
}}
#endif
