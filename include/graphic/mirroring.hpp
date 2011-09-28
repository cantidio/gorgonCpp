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
#ifndef _GORGON_MIRRORING_
#define _GORGON_MIRRORING_

namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe para tratar de espelhamento
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	26/02/2009
	 * @version	20/05/2011
	 * @ingroup	Graphic
	 */
	class Mirroring
	{
		public:
			//typedef char MType ;
			/**
			 * Tipos de espelhamento
			 */
			enum Type
			{
				Normal	= 0,	/**< sem espelhamento. */
				HFlip	= 1,	/**< espelhado horizontalmente. */
				VFlip	= 2,	/**< espelhado verticalmente. */
				VHFlip	= 3,	/**< espelhado verticalmente e horizontalmente*/
				HVFlip	= 3		/**< espelhado verticalmente e horizontalmente*/
			};
		private:
			/**
			 * Valor do espelhamento da classe
			 */
			Type mType;
		public:
			/**
			 * Método Construtor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/02/2009
			 * @version	27/02/2009
			 * @param	const char& type, tipo do espelhamento
			 */
			Mirroring(const Mirroring::Type& type=Mirroring::Normal);
			/**
			 * Método para retornar o tipo do espelhamento da Classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	27/02/2009
			 * @return	const Mirroring::Type&
			 */
			const Mirroring::Type& getType() const;
			/**
			 * Método para retornar o valor do espelhamento da Classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/02/2009
			 * @version	27/02/2009
			 * @param	const char& type, novo tipo de espelhamento
			 */
			void setType(const Mirroring::Type& type);
			/**
			 * Operador de igualdade
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	20/05/2009
			 * @param	const Mirroring& mirroring, classe que deseja-se igualar
			 * @return	Mirroring&
			 */
			Mirroring& operator =(const Mirroring& mirroring);
			/**
			 * Operador de igualdade
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	20/05/2009
			 * @param	const char& mirroring, valor do espelhamento
			 * @return	Mirroring&
			 */
			Mirroring& operator =(const Mirroring::Type& mirroring);
			/**
			 * Operador de +=
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	20/05/2009
			 * @param	const Mirroring& mirroring, espelhamento que deseja-se "somar"
			 */
			void operator += (const Mirroring& mirroring);
			/**
			 * Operador de somatório
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	27/02/2009
			 * @param	const Mirroring& mirroring, espelhamento que deseja-se "somar"
			 * @return	Mirroring
			 */
			Mirroring operator + (const Mirroring& mirroring);
			/**
			 * Operador de verificação de igualdade
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/02/2009
			 * @version	27/02/2009
			 * @param	const Mirroring& mirroring, espelhamento que deseja-se comparar
			 * @return	bool
			 */
			bool operator == (const Mirroring& mirroring);
	};
}}
#endif
