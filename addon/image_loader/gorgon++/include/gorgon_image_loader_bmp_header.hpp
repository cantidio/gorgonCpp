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
#ifndef _GORGON_IMAGE_FORMAT_BMP_HEADER_
#define _GORGON_IMAGE_FORMAT_BMP_HEADER_
#include <iostream>
#include <gorgon++/core/file.hpp>
#include "gorgon_image_loader_bmp_info_header.hpp"
namespace Gorgon
{
	/**
	 * Classe que representa o cabeçá-lho do arquivo de uma imagem bmp
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/02/2009
	 * @version	17/02/2009
	 * @ingroup	Graphic
	 */
	class ImageLoaderBmpHeader
	{
		private:
			/**
			 * Número que representa o arquivo como sendo uma imagem BMP
			 */
			static const int mImageLoaderBmpMagicNumber;
			/**
			 * Tipo do arquivo lido, deve ser sempre 4D42h ("BM")
			 */
			unsigned short  mFileType;
			/**
			 * Tamanho do arquivo lido em bytes
			 */
			unsigned long  mFileSize; //DWORD
			/**
			 * Bits reservados sempre 0
			 */
			unsigned short mReserved1;
			/**
			 * Bits reservados sempre 0
			 */
			unsigned short mReserved2;
			/**
			 * Posição que começa os dados da imagem em bytes
			 */
			unsigned long  mBitmapOffset;//DWORD
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/02/2009
			 * @version	16/02/2009
			 */
			ImageLoaderBmpHeader();
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/02/2009
			 * @version	16/02/2009
			 * @param	File& pFile, arquivo a abrir o header
			 */
			ImageLoaderBmpHeader(Core::File& pFile);
			/**
			 * Método que preenche os dados do header dados o infoHeader
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	19/02/2009
			 * @param	const ImageBmpInfoHeader& pInfoHeader, o infoHeader da imagem gerado previamente
			 */
			void fill(const ImageLoaderBmpInfoHeader& pInfoHeader);
			/**
			 * Método que descreve os atributos da classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	19/02/2009
			 * @return	std::string
			 */
			std::string describe() const;
			/**
			 * Método que salva o header em um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/02/2009
			 * @version	17/02/2009
			 * @param	File& pFile, arquivo a salvar o header
			 */
			void save(Core::File& pFile)	const;
			/**
			 * Método que carrega o header de um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/02/2009
			 * @version	17/02/2009
			 * @param	File& file, arquivo a carregar o header
			 */
			void load(Core::File& pFile);
			/**
			 * Método que retorna se o header é válido ou não
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/02/2009
			 * @version	16/02/2009
			 * @return	bool
			 */
			bool isValid() const;
			/**
			 * Método que retorna o tamanho do header
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getSize() const;
			/**
			 * Método que retorna o tamanho do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getFileSize() const;
			/**
			 * Método que retorna a posição em que começa a imagem em bytes
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 * @return	unsigned long
			 */
			unsigned long getBitmapOffset() const;
			
			/**
			 * Método que seta o tamanho do arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	18/02/2009
			 * @param	const int& pSize, tamanho do arquivo
			 */
			void setFileSize(const int& pSize);
			/**
			 * Método que seta a posição em que começa a imagem em bytes
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	18/02/2009
			 * @param	const int& pOffset, posição em que começa imagem
			 */
			void setBitmapOffset(const int& pOffset);
	};
}
#endif
