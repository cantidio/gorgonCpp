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
#ifndef _GORGON_SPRITE_HEADER_
#define _GORGON_SPRITE_HEADER_
#include "../core/file.hpp"
#include "../core/file_header.hpp"
#include "image.hpp"
namespace Gorgon{
namespace Graphic
{

	/**
	 * Classe com o cabeçalho dos arquivos gorgon
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	23/01/2008
	 * @version	18/01/2011
	 * @ingroup	Graphic
	 */
	class SpriteHeader : public Core::FileHeader
	{
		private:
			static const std::string	mGorgonSpriteSignature;		/**< Assinatura do sprite Gorgon correto*/
			static const int			mGorgonSpriteMagicNumber;	/**< Número do sprite da gorgon correto */
			static const int			mGorgonSpriteVersion;		/**< the current version of the sprite*/
			std::streampos mGetPos;	/**< the position in the stream of the get pointer*/
			std::streampos mPutPos;	/**< the position in the stream of the set pointer*/
			int mSizeofData;		/**< the size of the image*/
			int mWidth;				/**< the width of the image*/
			int mHeight;			/**< the height of the image*/
			int mGroup;				/**< the group of the sprite*/
			int mIndex;				/**< the index of the sprite*/
			Core::Point mOffset;	/**< the offset of the sprite*/
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2008
			 * @version	23/11/2008
			 */
			SpriteHeader();
			/**
			 * Método Construtor iniciado com um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			SpriteHeader(Core::File& pFile);
			/**
			 * Método para salvar o header em um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2008
			 * @version	18/01/2011
			 * @param	File& pFile, arquivo já aberto
			 */
			void save(Core::File& pFile);
			/**
			 * Método para carregar o header de um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2008
			 * @version	18/01/2011
			 * @param	File& pFile, arquivo já aberto
			 */
			void load(Core::File& pFile);
			/**
			 * Method tha returns the position of the get and set pointers of the file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	23/11/2008
			 * @version	18/01/2011
			 * @param	File& pFile, opened file
			 */
			void returnFilePosition(Core::File& pFile);
			/**
			 * Method that sets the size of the data of the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/01/2011
			 * @version	18/01/2011
			 * @param	const int& pSizeOfData, the size of the image data
			 */
			void setSizeOfData(const int& pSizeOfData);
			/**
			 * Method that sets the group of the sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/01/2011
			 * @version	18/01/2011
			 * @param	const int& pGroup, the group of the sprite
			 */
			void setGroup(const int& pGroup);
			/**
			 * Method that sets the index of the sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/01/2011
			 * @version	18/01/2011
			 * @param	const int& pIndex, the index of the sprite
			 */
			void setIndex(const int& pIndex);
			/**
			 * Method that sets the XOffset of the sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/01/2011
			 * @version	03/05/2011
			 * @param	const Core::Point& pOffset, the offset of the sprite
			 */
			void setOffset(const Core::Point& pOffset);
			/**
			 * Method that returns the size of the data of the image
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/01/2011
			 * @version	18/01/2011
			 * @return	int
			 */
			int getSizeOfData() const;
			/**
			 * Method that returns the group of the sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/01/2011
			 * @version	18/01/2011
			 * @return	int
			 */
			int getGroup()		const;
			/**
			 * Method that returns the index of the sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/01/2011
			 * @version	18/01/2011
			 * @return	int
			 */
			int getIndex()		const;
			/**
			 * Method that returns the XOffset of the sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/01/2011
			 * @version	03/05/2011
			 * @return	Core::Point
			 */
			Core::Point getOffset()	const;
			/**
			 * Method that returns the size of header in bytes
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/01/2011
			 * @version	18/01/2011
			 * @return	int
			 */
			static int getSize();
	};
}}
#endif
