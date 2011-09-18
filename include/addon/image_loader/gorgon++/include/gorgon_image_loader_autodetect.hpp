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
#ifndef _GORGON_IMAGE_LOADER_AUTODETECT_
#define	_GORGON_IMAGE_LOADER_AUTODETECT_
#include <gorgon++/graphic/image_loader.hpp>
#include "gorgon_image_loader_pcx.hpp"
#include "gorgon_image_loader_bmp.hpp"
#include "gorgon_image_loader_unknown.hpp"

namespace Gorgon
{
	/**
	 * Classe que representa um formato de arquivo de imagem qualquer
	 *
	 * @author	Cantídio Oliveira Fontes
	 * @since	05/08/2009
	 * @version	21/01/2011
	 */
	class ImageLoaderAutodetect : public Graphic::ImageLoader
	{
		public:
			/**
			 * Método para palpitar o formato da imagem por sua extensão
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/08/2009
			 * @version	05/08/2009
			 * @param	const std::string& pFileName, nome do arquivo
			 * @return	Graphic::ImageLoader*
			 */
			Graphic::ImageLoader* guessFormat(const std::string& pFileName) const;
			/**
			 * Método para carregar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/08/2009
			 * @version	06/08/2009
			 * @param	Graphic::Image&		pImage		, destino da imagem a ser carregada
			 * @param	const std::string	pImageName	, nome da imagem a ser carregada
			 */
			virtual void load(Graphic::Image& pImage, const std::string& pImageName) const;
			/**
			 * Método genérico para carregar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/08/2009
			 * @version	21/01/2011
			 * @param	Graphic::Image&		pImage			, destino da imagem a ser carregada
			 * @param	File&		pFile			, nome da imagem a ser carregada
			 * @param	const int&	pSizeOfImage	, o tamanho da imagem em bytes
			 */
			virtual void load
			(
				Graphic::Image& pImage,
				Core::File& pFile,
				const int& pSizeOfImage = 0
			) const ;
			/**
			 * Método para salvar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/08/2009
			 * @version	06/08/2009
			 * @param	Graphic::Image&		pImage		, imagem a ser salva
			 * @param	const std::string&	pImageName	, nome da imagem a salvar
			 */
			virtual void save(Graphic::Image& pImage, const std::string& pImageName) const;
			/**
			 * Método para salvar uma imagem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	05/08/2009
			 * @version	06/08/2009
			 * @param	Graphic::Image&	pImage	, imagem a ser salva
			 * @param	File&	pFile	, arquivo a receber a imagem
			 */
			virtual void save(Graphic::Image& pImage, Core::File& pFile) const;
	};
}
#endif
