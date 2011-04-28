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
//
#include <gorgon++/graphic/gorgon_image_loader.hpp>
#include <gorgon++/gorgon.hpp>
namespace Gorgon
{
	/**
	 * Classe que representa o loader de imagens da lib Magick++
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/01/2011
	 * @version	28/04/2011
	 */
	class ImageLoaderMagick : public ImageLoader
	{
		public:

			ImageLoaderMagick(char* pRunDir = NULL);
			/**
			 * Método genérico para carregar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2011
			 * @version	07/01/2011
			 * @param	Image&				pImage		, destino da imagem a ser carregada
			 * @param	const std::string	pImageName	, nome da imagem a ser carregada
			 */
			virtual void load(Image& pImage, const std::string& pImageName) const;
			/**
			 * Método genérico para carregar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2011
			 * @version	07/01/2011
			 * @param	Image&		pImage			, destino da imagem a ser carregada
			 * @param	File&		pFile			, arquivo onde a imagem está
			 * @param	const int&	pSizeOfImage	, tamanho da imagem a ser carregada
			 */
			virtual void load
			(
				Image&		pImage,
				Core::File&	pFile,
				const int&	pSizeOfImage
			) const;
			/**
			 * Método genérico para salvar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2011
			 * @version	08/01/2011
			 * @param	Image&	pImage	, destino da imagem a ser carregada
			 * @param	File&	pFile	, arquivo onde a imagem está
			 * @todo	permitir passar o tipo de imagem a ser salva
			 */
			virtual void save(Image& pImage, Core::File& pFile) const;
			/**
			 * Método genérico para salvar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2011
			 * @version	08/01/2011
			 * @param	Image&				pImage		, destino da imagem a ser carregada
			 * @param	const std::string	pImageName	, nome da imagem a ser carregada
			 */
			virtual void save(Image& pImage, const std::string& pImageName) const;
			/**
			 * Método para setar o formato que o loader irá salvar as imagens
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	28/04/2011
			 * @version	28/04/2011
			 * @param	const std::string& pSaveFormat, formato a ser salvo ex. BMP, PNG, PCX..
			 */
			virtual void setSaveFormat(const std::string& pSaveFormat);
	};
}
