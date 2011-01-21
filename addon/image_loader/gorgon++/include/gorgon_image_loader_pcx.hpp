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
#ifndef _GORGON_IMAGE_FORMAT_PCX_
#define _GORGON_IMAGE_FORMAT_PCX_
#include <gorgon++/graphic/gorgon_image_loader.hpp>
#include "gorgon_image_loader_pcx_exception.hpp"
#include "gorgon_image_loader_pcx_header.hpp"

namespace Gorgon
{
	/**
	 * Classe de Imagem PCX
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	20/01/2009
	 * @version	07/08/2009
	 * @ingroup	Graphic
	 */
	class ImageLoaderPcx : public ImageLoader
	{
		public:
			/**
			 * Método para carregar a imagem de um arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	07/08/2009
			 * @param	const std::string& pImageName, nome da imagem a carregar
			 */
			virtual void load(Image& pImage, const std::string& pImageName) const;
			/**
			 * Método para carregar a imagem de um arquivo já aberto
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	28/11/2007
			 * @version	07/08/2009
			 * @param	Image&		pImage		, referencia para a imagem a ser carregada
			 * @param	Core::File&	pFile		, referencia para o arquivo que contem a imagem
			 * @param	const int&	pImageSize	, tamanho da imagem em bytes, campo não usado
			 */
			virtual void load
			(
				Image& pImage,
				Core::File& pFile,
				const int& pImageSize = 0
			) const;
			/**
			 * Método para salvar uma imagem pcx
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	15/08/2008
			 * @version	07/08/2009
			 * @param	const std::string& pImageName, nome do arquivo a ser salvo
			 */
			virtual void save(Image& pImage, const std::string& pImageName) const;
			/**
			 * Método para salvar uma imagem pcx
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/06/2008
			 * @version	07/08/2009
			 * @param	File& pFile, ponteiro para o arquivo já aberto
			 */
			virtual void save(Image& pImage, Core::File& pFile) const;
		private:
			/**
			 * Método para salvar os dados de uma imagem com 4 bit planes (4 bits)
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	07/08/2009
			 * @param	Image&					pImage	, imagem a ser salva
			 * @param	ImageLoaderPcxHeader&	pHeader	, header da imagem pcx
			 * @param	File&					pFile	, ponteiro do arquivo
			 */
			void saveEncoded4BitData
			(
				Image& pImage,
				ImageLoaderPcxHeader& pHeader,
				Core::File& pFile
			) const;
			/**
			 * Método para salvar os dados de uma imagem com 1 bit plane (8 bits)
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/06/2008
			 * @version	07/08/2009
			 * @param	Image&	pImage	, imagem a ser salva
			 * @param	File&	pFile	, ponteiro do arquivo
			 */
			void saveEncoded8BitData(Image& pImage, Core::File& pFile) const;
			/**
			 * Método para salvar os dados de uma imagem com 3 bit planes (24 bits)
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/06/2008
			 * @version	07/08/2009
			 * @param	Image&	pImage	, imagem a ser salva
			 * @param	File&	pFile	, ponteiro do arquivo
			 */
			void saveEncoded24BitData(Image& pImage, Core::File& pFile) const;
			/**
			 * Método para salvar os dados da imagem em si
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/06/2008
			 * @version	07/08/2009
			 * @param	Image&					pImage	, imagem a ser salva
			 * @param	ImageLoaderPcxHeader&	pHeader	, header da imagem pcx
			 * @param	File&					pFile	, ponteiro do arquivo
			 */
			void saveEncodedData
			(
				Image& pImage,
				ImageLoaderPcxHeader& pHeader,
				Core::File& pFile
			) const;
			/**
			 * Método para salvar a paleta de cores da imagem no arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/08/2008
			 * @version	07/08/2009
			 * @param	Image&					pImage	, imagem a ser salva
			 * @param	ImageLoaderPcxHeader&	pHeader	, header da imagem pcx
			 * @param	File&					pFile	, arquivo já aberto
			 */
			void savePaletteData
			(
				Image& pImage,
				ImageLoaderPcxHeader& pHeader,
				Core::File& pFile
			) const;
			/**
			 * Método para carregar os dados de uma imagem com 1 bit
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	20/02/2009
			 * @version	07/08/2009
			 * @param	Image&					pImage	, imagem de destino
			 * @param	ImageLoaderPcxHeader&	pHeader	, header da imagem pcx
			 * @param	File&					pFile	, arquivo já aberto
			 */
			void loadEncoded1BitData
			(
				Image& pImage,
				ImageLoaderPcxHeader& pHeader,
				Core::File& pFile
			) const;
			/**
			 * Método para carregar os dados de uma imagem com até 16 cores
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	07/08/2009
			 * @param	Image&					pImage	, imagem de destino
			 * @param	ImageLoaderPcxHeader&	pHeader	, header da imagem pcx
			 * @param	File&					pFile	, arquivo já aberto
			 */
			void loadEncoded4BitData
			(
				Image& pImage,
				ImageLoaderPcxHeader& pHeader,
				Core::File& pFile
			) const;
			/**
			 * Método para carregar os dados de uma imagem com 1 Plane (8 bits)
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	28/11/2007
			 * @version	07/08/2009
			 * @param	Image&					pImage	, imagem de destino
			 * @param	ImageLoaderPcxHeader&	pHeader	, header da imagem pcx
			 * @param	File&					pFile	, arquivo já aberto
			 */
			void loadEncoded8BitData
			(
				Image& pImage,
				ImageLoaderPcxHeader& pHeader,
				Core::File& pFile
			) const;
			/**
			 * Método para carregar os dados de uma imagem com 3 Planes (24 bits)
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	28/11/2007
			 * @version	07/08/2009
			 * @param	Image&					pImage	, imagem de destino
			 * @param	ImageLoaderPcxHeader&	pHeader	, header da imagem pcx
			 * @param	File&					pFile	, arquivo já aberto
			 */
			void loadEncoded24BitData
			(
				Image& pImage,
				ImageLoaderPcxHeader& pHeader,
				Core::File& pFile
			) const;
			/**
			 * Método para carregar os dados da imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	28/11/2007
			 * @version	07/08/2009
			 * @param	Image&					pImage	, imagem de destino
			 * @param	ImageLoaderPcxHeader&	pHeader	, header da imagem pcx
			 * @param	File&					pFile	, arquivo já aberto
			 */
			void loadEncodedData
			(
				Image& pImage,
				ImageLoaderPcxHeader& pHeader,
				Core::File& pFile
			) const;
			/**
			 * Método para carregar a paleta de cores da imagem no arquivo
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	18/08/2008
			 * @version	07/08/2009
			 * @param	Image&					pImage	, imagem de destino
			 * @param	ImageLoaderPcxHeader&	pHeader	, header da imagem pcx
			 * @param	File&					pFile	, arquivo já aberto
			 */
			void loadPaletteData
			(
				Image& pImage,
				ImageLoaderPcxHeader& pHeader,
				Core::File& pFile
			) const;
	};
}
#endif
