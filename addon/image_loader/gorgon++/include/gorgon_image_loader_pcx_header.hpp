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
#ifndef _GORGON_IMAGE_FORMAT_PCX_HEADER_
#define _GORGON_IMAGE_FORMAT_PCX_HEADER_
#include <sstream>
#include <gorgon++/core/file.hpp>
#include "gorgon_image_loader_pcx_exception.hpp"

/**
 * @todo criaar um enum para os dados abaixo
 */
#define ImageLoaderPcx1Bit	0
#define	ImageLoaderPcx4Bit	1
#define	ImageLoaderPcx8Bit	2
#define	ImageLoaderPcx24Bit	3

namespace Gorgon
{
	namespace Graphic
	{
		class Palette;
		class Image;
	}
	/**
	 * Classe que representa o header de imagens pcx
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	13/08/2008
	 * @version	23/06/2009
	 * @ingroup	Graphic
	 */
	class ImageLoaderPcxHeader
	{
		private:
			/**
			 * PCX Id Number, must be always 0x0A
			 */
			char	mIdentifier;
			/**
			 * Version Number
			 */
			char	mVersion;
			/**
			 * Encoding Format
			 */
			char	mEncoding;
			/**
			 * Bits per Pixel
			 */
			char	mBitsPerPixel;
			/**
			 * Left of image
			 */
			short	mXStart;
			/**
			 * Top of Image
			 */
			short	mYStart;
			/**
			 * Right of Image
			 */
			short	mXEnd;
			/**
			 * Bottom of image
			 */
			short	mYEnd;
			/**
			 * Horizontal Resolution
			 */
			short	mHRes;
			/**
			 * Vertical Resolution
			 */
			short	mVRes;
			/**
			 * 16-Color EGA Palette
			 */
			Graphic::Palette* mPalette;
			/**
			 * Number of Bit Planes
			 */
			char	mNumBitPlanes;
			/**
			 * Bytes per Scan-line
			 */
			short	mBytesPerLine;
			/**
			 * Palette Type
			 */
			short	mPaletteType;
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	20/01/2009
			 */			
			ImageLoaderPcxHeader();
			/**
			 * Método destrutor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	26/02/2009
			 */
			~ImageLoaderPcxHeader();
			/**
			 * Método que retorna o tipo da imagem lida
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	26/02/2009
			 * @return	int
			 */
			int getType() const;
			/**
			 * Método para preencher o header dada uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	19/02/2009
			 * @param	const Graphic::Image& image, imagem a gerar o header
			 */
			void fill(const Graphic::Image& pImage);
			/**
			 * Método para descrever os valores do header
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	19/02/2009
			 * @version	19/02/2009
			 */
			std::string describe() const;
			/**
			 * Método para retornar a largura da imagem
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	15/08/2008
			 * @return	int
			 */
			int getWidth() const;
			/**
			 * Método para retornar a altura da imagem
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	15/08/2008
			 * @return	int
			 */
			int getHeight() const;
			/**
			 * Método para retornar o número de bits por pixel
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	19/02/2009
			 * @version	19/02/2009
			 * @return	int
			 */
			int getBitsPerPixel() const;
			/**
			 * Método para retornar o número de bit planes da imagem
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	19/02/2009
			 * @version	19/02/2009
			 * @return	int
			 */
			int getNumBitPlanes() const;
			/**
			 * Método para retornar o número de bytes por linha da imagem
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	19/02/2009
			 * @version	19/02/2009
			 * @return	int
			 */
			int getBytesPerLine() const;
			/**
			 * Método para retornar a paleta de 16 cores
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	26/02/2009
			 * @return	Palette*
			 */
			Graphic::Palette* getPalette() const;
			/**
			 * Método para salvar o cabeçalho da imagem
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	06/06/2008
			 * @version	23/06/2009
			 * @param	File& file, ponteiro para o arquivo
			 */
			void save(Core::File& pFile) const;
			/**
			 * Método para carregar as informações do cabeçálho da imagem
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	28/11/2007
			 * @version	23/06/2009
			 * @param	std::fstream *file, ponteiro para o arquivo
			 */
			void load(Core::File& pFile);
			/**
			 * Método para retornar se o cabeçálho é válido ou não
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	19/02/2009
			 * @version	19/02/2009
			 * @return	bool
			 */
			bool isValid() const;
			/**
			 * Método para retornar o tamanho da imagem lida
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	19/02/2009
			 * @version	19/02/2009
			 * @return	bool
			 */
			long getImageSize() const;
	};
}
#endif

