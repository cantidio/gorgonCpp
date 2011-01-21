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
#ifndef _GORGON_IMAGE_LOADER_
#define	_GORGON_IMAGE_LOADER_
#include <string>
#include "../core/gorgon_file.hpp"

namespace Gorgon
{
	class Image;
	/**
	 * Classe que representa um formato de imagem genérico
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	05/08/2009
	 * @version	21/01/2011
	 */
	class ImageLoader
	{
		private:
			static ImageLoader* mLoader;
		public:
			/**
			 * Método para retornar o loader atual
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/01/2011
			 * @version	07/01/2011
			 * @return	ImageLoader&
			 */
			static ImageLoader& getLoader();
			/**
			 * Método para setar o loader atual
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	06/01/2011
			 * @version	07/01/2011
			 * @param	ImageLoader* pImageLoader, ponteiro para o novo loader
			 */
			static void setLoader(ImageLoader* pImageLoader);
			/**
			 * Método genérico para carregar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/08/2009
			 * @version	05/08/2009
			 * @param	Image&				pImage		, destino da imagem a ser carregada
			 * @param	const std::string	pImageName	, nome da imagem a ser carregada
			 */
			virtual void load(Image& pImage, const std::string& pImageName) const;
			/**
			 * Método genérico para carregar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/08/2009
			 * @version	05/08/2009
			 * @param	Image&		pImage			, destino da imagem a ser carregada
			 * @param	File&		pFile			, arquivo onde a imagem está,
			 * @param	const int&	pSizeOfImage	, o tamanho da imagem em bytes
			 */
			virtual void load
			(
				Image& pImage,
				Core::File& pFile,
				const int& pSizeOfImage = 0
			) const;
			/**
			 * Método genérico para salvar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/08/2009
			 * @version	05/08/2009
			 * @param	Image&	pImage	, destino da imagem a ser carregada
			 * @param	File&	pFile	, arquivo onde a imagem está
			 */
			virtual void save(Image& pImage, Core::File& pFile) const;
			/**
			 * Método genérico para salvar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/08/2009
			 * @version	05/08/2009
			 * @param	Image&				pImage		, destino da imagem a ser carregada
			 * @param	const std::string	pImageName	, nome da imagem a ser carregada
			 */
			virtual void save(Image& pImage, const std::string& pImageName) const;
	};
}
#endif
