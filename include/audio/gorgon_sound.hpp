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
 *  Copyright (C) 2008-2010  Gorgon Team
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
#ifndef _GORGON_SOUND_
#define _GORGON_SOUND_
#include "gorgon_sound_exception.hpp"
#include "gorgon_sound_system.hpp"

namespace Gorgon{
namespace Audio
{
	/**
	 * Classe responsável por cuidar da representação de sons
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/01/2009
	 * @version	07/01/2009
	 * @ingroup	Audio
	 * @todo	abilitar as exceções na classe
	 * @todo	abilitar os logs na classe
	 * @todo	usar OpenAl, Alut
	 */
	class Sound
	{
		private:
			/**
			 * Ponteiro de um OutputStream
			 * Variável que guarda o som em si, se estiver em NULL é porque ocorreu algum erro
			 */
			audiere::OutputStreamPtr sound;
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	08/01/2009
			 * @param	string			soundLocation	, localização do som que deverá ser aberto
			 * @param	SoundSystem&	system			, sistema sonoro a ser usado para tocar o som
			 * @param	bool			bufferFirst		, define se ira fazer o buffer do arquivo todo primeiro
			 * @todo	deixar de colocar o sistema sonoro, assumir por default o ultimo
			 *			sistema sonoro criado talvez
			 */
			Sound
			(
				const std::string&	soundLocation,
				const bool&			bufferFirst	= false,
				SoundSystem*		system		= SoundSystem::lastSystem
			);
			/**
			 * Método destrutor de classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	07/01/2009
			 */
			~Sound();
			/**
			 * Método para checar se o som está tocando
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	07/01/2009
			 * @return	bool
			 */
			bool isPlaying() const;
			/**
			 * Método para começar a tocar o som
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	08/01/2009
			 */
			void play();
			/**
			 * Método para parar de tocar o som
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	07/01/2009
			 */
			void stop();
			/**
			 * Método para reiniciar o som
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	07/01/2009
			 */
			void reset();
			/**
			 * Método para setar a posição que o som estará tocando
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	07/01/2009
			 * @param	const int& position, posição que deseja setar ao som
			 */
			void setPosition(const int& position=0);
			/**
			 * Método para pegar a posição em que o som está tocando
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	07/01/2009
			 * @return	int
			 */
			int	getPosition() const;
			/**
			 * Método para setar o volume do som
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	07/01/2009
			 * @param	const float& volume, volume do som
			 */
			void setVolume(const float& volume);
			/**
			 * Método para pegar o volume do som
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	07/01/2009
			 * @return	float
			 */
			float getVolume() const;
			/**
			 * Método para retornar o tomanho do som
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	07/01/2009
			 * @return	int
			 */
			int	getLength() const;
	};
}}
#endif
