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
#ifndef _GORGON_IMAGE_FORMAT_BMP_
#define _GORGON_IMAGE_FORMAT_BMP_
#include <gorgon++/graphic/gorgon_image_loader.hpp>
#include "gorgon_image_loader_bmp_exception.hpp"
#include "gorgon_image_loader_bmp_header.hpp"
#include "gorgon_image_loader_bmp_info_header.hpp"

/*
#define 1BitColorNumber		2
#define 4BitColorNumber		16
#define 8BitColorNumber		256
#define 24BitColorNumber	16777216
#define 32BitColorNumber	?
*/
namespace Gorgon
{
	/**
	 * Classe de Imagem Bitmap
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	20/01/2009
	 * @version	07/08/2009
	 * @ingroup	Graphic
	 */
	class ImageLoaderBmp : public ImageLoader
	{
		public:
			/**
			 * Método para carregar uma imagem bitmap
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	07/08/2009
			 * @param	Image&				pImage		, imagem de destino
			 * @param	const std::string&	pImageName	, nome do Imagem Bmp a carregar
			 */
			virtual void load(Image& pImage,const std::string& pImageName) const;
			/**
			 * Método para carregar uma imagem ImageBmp de um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	21/01/2011
			 * @param	Image&		pImage			, imagem de destino
			 * @param	File&		pFile			, ponteiro para um arquivo já aberto
			 * @param	const int&	pSizeOfImage	, o tamanho da imagem em bytes, não é utilizado
			 */
			virtual void load
			(
				Image& pImage,
				Core::File& pFile,
				const int& pSizeOfImage = 0
			) const;
			/**
			 * Método para salvar o bitmap
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	07/08/2009
			 * @param	Image&				pImage		, imagem a ser salva
			 * @param	const std::string&	pImageName	, nome do arquivo Imagem Bmp a ser salvo
			 */
			virtual void save(Image& pImage,const std::string& pImageName) const;
			/**
			 * Método para salvar o bitmap em um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/01/2009
			 * @version	07/08/2009
			 * @param	Image&	pImage	, imagem a ser salva
			 * @param	File&	pFile	, ponteiro para o arquivo já aberto
			 */
			virtual void save(Image& pImage, Core::File& pFile) const;
		private:
			/**
			 * Método que carrega a paleta de cores do bmp
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	07/08/2009
			 * @param	Image&						pImage		, imagem de destino
			 * @param	ImageLoaderBmpHeader&		pHeader		, header da imagem bmp
			 * @param	ImageLoaderBmpInfoHeader&	pInfoHeader	, infoheader da imagem bmp
			 * @param	File&						pFile		, ponteiro para o arquivo
			 */
			void loadPalette
			(
				Image& pImage,
				ImageLoaderBmpHeader& pHeader,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
			/**
			 * Método que carrega os dados de uma imagem de 1 bit sem compressão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	07/08/2009
			 * @param	Image&						pImage		, imagem de destino
			 * @param	ImageLoaderBmpHeader&		pHeader		, header da imagem bmp
			 * @param	ImageLoaderBmpInfoHeader&	pInfoHeader	, infoheader da imagem bmp
			 * @param	File&						pFile		, ponteiro para o arquivo
			 */
			void loadUncompressed1BitData
			(
				Image& pImage,
				ImageLoaderBmpHeader& pHeader,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
			/**
			 * Método que carrega os dados de uma imagem de 4 bits sem compressão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	07/08/2009
			 * @param	Image&						pImage		, imagem de destino
			 * @param	ImageLoaderBmpHeader&		pHeader		, header da imagem bmp
			 * @param	ImageLoaderBmpInfoHeader&	pInfoHeader	, infoheader da imagem bmp
			 * @param	File&						pFile		, ponteiro para o arquivo
			 */
			void loadUncompressed4BitData
			(
				Image& pImage,
				ImageLoaderBmpHeader& pHeader,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
			/**
			 * Método que carrega os dados de uma imagem de 8 bits  sem compressão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	07/08/2009
			 * @param	Image&						pImage		, imagem de destino
			 * @param	ImageLoaderBmpHeader&		pHeader		, header da imagem bmp
			 * @param	ImageLoaderBmpInfoHeader&	pInfoHeader	, infoheader da imagem bmp
			 * @param	File&						pFile		, ponteiro para o arquivo
			 */
			void loadUncompressed8BitData
			(
				Image& pImage,
				ImageLoaderBmpHeader& pHeader,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
			/**
			 * Método que carrega os dados de uma imagem de 24 bits sem compressão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	07/08/2009
			 * @param	Image&						pImage		, imagem de destino
			 * @param	ImageLoaderBmpInfoHeader&	pInfoHeader	, infoheader da imagem
			 * @param	File&						pFile		, ponteiro para o arquivo
			 */
			void loadUncompressed24BitData
			(
				Image& pImage,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
			/**
			 * Método que carrega os dados de uma imagem de 32 bits sem compressão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	07/08/2009
			 * @param	Image&						pImage		, imagem de destino
			 * @param	ImageLoaderBmpInfoHeader&	pInfoHeader	, infoheader da imagem
			 * @param	File&						pFile		, ponteiro para o arquivo
			 */
			void loadUncompressed32BitData
			(
				Image& pImage,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
			/**
			 * Método que carrega os dados de uma imagem sem compressão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	07/08/2009
			 * @param	Image&						pImage		, imagem de destino
			 * @param	ImageLoaderBmpHeader&		pHeader		, header da imagem bmp
			 * @param	ImageLoaderBmpInfoHeader&	pInfoHeader	, infoheader da imagem bmp
			 * @param	File&						pFile		, ponteiro para o arquivo
			 */
			void loadUncompressedData
			(
				Image& pImage,
				ImageLoaderBmpHeader& pHeader,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
			/**
			 * Método que carrega os dados de uma imagem com compressão RLE8
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	18/02/2009
			 * @param	File& pFile, ponteiro para o arquivo
			 * @todo 	implementar esse método
			 */
			void loadRLE8CompressedData(Image& pImage, Core::File& pFile) const;
			/**
			 * Método que carrega os dados de uma imagem com compressão RLE4
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	18/02/2009
			 * @param	File& file, ponteiro para o arquivo
			 * @todo	implementar esse método
			 */
			void loadRLE4CompressedData(Image& pImage, Core::File& pFile) const;
			/**
			 * Método que carrega os dados de uma imagem com compressão BitFields
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	18/02/2009
			 * @param	File& file, ponteiro para o arquivo
			 * @todo	implementar esse método
			 */
			void loadBitFieldsCompressedData(Image& pImage, Core::File& pFile) const;
			/**
			 * Método que salva os dados da palheta de cores de  uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	07/08/2009
			 * @param	Image& pImage				, imagem a ser salva
			 * @param	ImageLoaderBmpInfoHeader&	, infoheader da imagem
			 * @param	File& pFile					, ponteiro para o arquivo
			 */
			void savePalette
			(
				Image& pImage,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
			/**
			 * Método que salva os dados de uma imagem de 1 bit
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	07/08/2009
			 * @param	Image& pImage				, imagem a ser salva
			 * @param	ImageLoaderBmpInfoHeader&	, infoheader da imagem
			 * @param	File& pFile					, ponteiro para o arquivo
			 */
			void saveUncompressed1BitData
			(
				Image& pImage,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
			/**
			 * Método que salva os dados de uma imagem de 4 bits
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	07/08/2009
			 * @param	Image& pImage				, imagem a ser salva
			 * @param	ImageLoaderBmpInfoHeader&	, infoheader da imagem
			 * @param	File& pFile					, ponteiro para o arquivo
			 */
			void saveUncompressed4BitData
			(
				Image& pImage,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
			/**
			 * Método que salva os dados de uma imagem de 8 bits
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	07/08/2009
			 * @param	Image& pImage				, imagem a ser salva
			 * @param	ImageLoaderBmpInfoHeader&	, infoheader da imagem
			 * @param	File& pFile					, ponteiro para o arquivo
			 */
			void saveUncompressed8BitData
			(
				Image& pImage,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
			/**
			 * Método que salva os dados de uma imagem de 24 bits
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	07/08/2009
			 * @param	Image& pImage	, imagem a ser salva
			 * @param	File& pFile		, ponteiro para o arquivo
			 */
			void saveUncompressed24BitData(Image& pImage, Core::File& pFile) const;
			/**
			 * Método que salva os dados de uma imagem de 32 bits
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	07/08/2009
			 * @param	Image& pImage	, imagem a ser salva
			 * @param	File& pFile		, ponteiro para o arquivo
			 */
			void saveUncompressed32BitData(Image& pImage, Core::File& pFile) const;
			/**
			 * Método que salva os dados de uma imagem sem compressão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/02/2009
			 * @version	07/08/2009
			 * @param	Image& pImage				, imagem a ser salva
			 * @param	ImageLoaderBmpInfoHeader&	, infoheader da imagem
			 * @param	File& pFile					, ponteiro para o arquivo
			 */
			void saveUncompressedData
			(
				Image& pImage,
				ImageLoaderBmpInfoHeader& pInfoHeader,
				Core::File& pFile
			) const;
	};
}
#endif
