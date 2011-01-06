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
 *  Copyright (C) 2008-2011  Gorgon Team
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
#ifndef _GORGON_IMAGE_FORMAT_BMP_INFO_HEADER_
#define _GORGON_IMAGE_FORMAT_BMP_INFO_HEADER_
#include <gorgon++/core/gorgon_file.hpp>

/**
 * @todo criar enums para os defines abaixo
 */
#define BI_RGB          0
#define BI_RLE8         1
#define BI_RLE4         2
#define BI_BITFIELDS    3

#define OS2_1			1
#define OS2_2			2
#define Windows_3		3
#define Windows_4		4

namespace Gorgon
{
	class Image;
	/**
	 * Classe que representa o cabeçálho de informações de uma imagem bmp
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/02/2009
	 * @version	19/02/2009
	 * @ingroup	Graphic
	 */
	class ImageLoaderBmpInfoHeader
	{
		private:
			/**
			 * Tamanho deste header em bytes
			 */
			unsigned long mSize;
			/**
			 * Largura da Imagem
			 */
			unsigned long mWidth;
			/**
			 * Altura da Imagem
			 */
			unsigned long mHeight;
			/**
			 * Número de color planes
			 */
			unsigned short mPlanes;
			/**
			 * Número de bits por pixel
			 */
			unsigned short mBitsPerPixel;
			/**
			 * Métodos de compressão usados
			 */
			unsigned long mCompression;
			/**
			 * Tamanho do bitmap em bytes
			 */
			unsigned long mSizeOfBitmap;
			/**
			 * Resolução horizontal em pixels por metro
			 */
			unsigned long mHorizontalResolution;
			/**
			 * Resolução vertical em pixels por metro
			 */
			unsigned long mVerticalResolution;
			/**
			 * Número de cores na imagem
			 */
			unsigned long mColorsUsed;
			/**
			 * Número mínimo de cores importantes
			 */
			unsigned long mColorsImportant;

		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/02/2009
			 * @version	16/02/2009
			 */
			ImageLoaderBmpInfoHeader();
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/02/2009
			 * @version	16/02/2009
			 * @param	File& pFile, ponteiro para o arquivo a carregar o header
			 */
			ImageLoaderBmpInfoHeader(Core::File& pFile);
			/**
			 * Método que preenche os valores do header dado uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	19/02/2009
			 * @param	const Image& pImage, imagem que irá gerar o header
			 */
			void fill(const Image& pImage);
			/**
			 * Método para descrever a header
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	29/05/2009
			 * @return	std::string
			 */
			std::string describe() const;
			/**
			 * Método para salvar o header em um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/02/2009
			 * @version	17/02/2009
			 * @param	File& file, ponteiro para o arquivo já aberto
			 */
			void save(Core::File& file) const;
			/**
			 * Método para carregar o header de um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/02/2009
			 * @version	17/02/2009
			 * @param	File& file, ponteiro para o arquivo
			 */
			void load(Core::File& file);
			/**
			 * Método que retorna o tamanho do cabeçá-lho
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getSize() const;
			/**
			 * Método que retorna a largura da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getWidth() const;
			/**
			 * Método que retorna a altura da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getHeight() const;
			/**
			 * Método que retorna o número de color Planes da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned short getPlanes() const;
			/**
			 * Método que retorna o número de bits per pixel da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned short getBpp() const;
			/**
			 * Método que retorna a compressão da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getCompression() const;
			/**
			 * Método que retorna o tamanho em bits dos dados da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getSizeOfBitmap() const;
			/**
			 * Método que retorna a resolução horizontal em pixels por metro
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getHorizontalResolution()	const;
			/**
			 * Método que retorna a resolução vertical em pixels por metro
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getVerticalResolution() const;
			/**
			 * Método que retorna o número de cores usadas na imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getColorsUsed() const;
			/**
			 * Método que retorna o número de cores importantes
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getColorsImportant() const;
			
			/**
			 * Método que retorna a versão do bitmap
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned int getVersion() const;
	};
}
#endif
