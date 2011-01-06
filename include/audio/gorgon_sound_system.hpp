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
#ifndef _GORGON_SOUND_SYSTEM_
#define _GORGON_SOUND_SYSTEM_
#include <iostream>
#include <audiere.h>
#include "gorgon_sound_system_exception.hpp"

namespace Gorgon{
namespace Audio
{
	/**
	 * Classe responsável por gerenciar o sistema sonoro
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/01/2009
	 * @version	20/05/2009
	 * @ingroup	Audio
	 * @todo	abilitar as exceções na classe
	 * @todo	abilitar os logs na classe
	 */
	class SoundSystem
	{
		private:
			/**
			 * Ponteiro para um AudioDevice
			 * Variável que guarda o dispositivo de áudio,se for NULL algum erro ocorreu
			 */
			audiere::AudioDevicePtr device;
		public:
			/**
			 * Ponteiro para o último SoundSystem instanciado
			 * Variável que guarda o ponteiro do último SoundSystem instanciado, útil para não precisar referenciar o SoundSystem sempre
			 */
			static SoundSystem* lastSystem;
			/**
			 * Método construtor de classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	20/05/2009
			 * @param	string device_name, nome do despositivo a se iniciar
			 */
			SoundSystem(const std::string device_name="autodetect");
			/**
			 * Método destrutor de classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	07/01/2009
			 */
			~SoundSystem();
			/**
			 * Método para retornar o ponteiro do despositivo sonoro
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	07/01/2009
			 * @version	20/05/2009
			 * @return	AudioDevice*
			 */
			audiere::AudioDevicePtr getDevice() const;
	};
}}
#endif
