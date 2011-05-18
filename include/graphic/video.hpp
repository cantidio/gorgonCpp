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
#ifndef _GORGON_VIDEO_
#define	_GORGON_VIDEO_
#include <allegro.h>
#include "sprite.hpp"
#include "../core/log.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe para tratar do vídeo
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	16/07/2008
	 * @version	21/06/2009
	 * @ingroup	Graphic
	 * @todo	Implementar método para setar ícone da janela
	 */
	class Video : public Sprite
	{
		private:
			/**
			 * Esse estático ponteiro guarda uma instância da própria classe
			 */
			static Video* mSingleton;
			/**
			 * Variável que guarda a tela
			 * Essa variável é responsável por imprimir os dados na tela
			 */
			static Image* mScreen;

			/**
			 * Método construtor Privado
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/07/2008
			 * @version	21/06/2009
			 * @param	const std::string&	pWindowTitle	, título para aparecer na janela
			 * @param	const int&			pWidth			, largura da tela
			 * @param	const int&			pHeight			, altura da tela
			 * @param	const bool&			pFullscreen		, se verdadeiro inicia em tela cheia
			 * @param	const int&			pBpp			, número de bits por pixel
			 * @todo	Se não for possível iniciar o vídeo, lançar exceptions
			 */
			Video
			(
				const std::string&	pWindowTitle,
				const int&			pWidth,
				const int&			pHeight,
				const bool&			pFullscreen,
				const int&			pBpp
			);
		public:
			/**
			 * Método para iniciar a classe, caso a mesma não esteje inicializada
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/07/2008
			 * @version	21/06/2009
			 * @param	const std::string&	pWindowTitle	, título da janela
			 * @param	const int&			pWidth			, largura da janela
			 * @param	const int&			pHeight			, altura da janela
			 * @param	const bool&			pFullscreen		, se verdadeiro inicia em tela cheia
			 * @param	const int&			pBpp			, bits por pixel
			 */
			static void init
			(
				const std::string&	pWindowTitle	= "",
				const int&			pWidth			= 320,
				const int&			pHeight			= 240,
				const bool&			pFullscreen		= false,
				const int&			pBpp			= 32
			);
			static void halt();
			/**
			 * Método para setar o título da Janela
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	22/01/2009
			 * @param	const std::string& pWindowTitle, título da janela
			 */
			void setWindowTitle(const std::string& pWindowTitle);
			/**
			 * Método para retornar a instancia do video
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	22/01/2009
			 * @version	21/06/2009
			 * @return	Video&
			 */
			static Video& get();
			/**
			 * Método para mostrar o conteúdo do buffer na tela
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	16/07/2008
			 * @version	22/01/2009
			 */
			void show();
	};
}}
#endif
