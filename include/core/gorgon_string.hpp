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
#include<string>
#include<vector>
namespace Gorgon{
namespace Core
{
	/**
	 * Class that represents an String
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	24/01/2011
	 * @version	24/01/2011
	 * @details
	 * 			This class is like the same std::string class, but with more methods
	 */
	class String : public std::string
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2011
			 * @version	24/01/2011
			 */
			String();
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2011
			 * @version	24/01/2011
			 * @param	const String& pString, the string to be copied
			 */
			String(const String& pString);
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2011
			 * @version	24/01/2011
			 * @param	const std::string& pString, the string to be copied
			 */
			String(const std::string& pString);
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2011
			 * @version	24/01/2011
			 * @param	const char* pString, the string to be copied
			 */
			String(const char* pString);
			/**
			 * Method that cuts the string into substrings, based in a delimiter
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/01/2011
			 * @version	24/01/2011
			 * @param	const String& pDelimiter, the string the
			 * @return	std::vector<String>
			 */
			std::vector<String> explode(const String& pDelimiter) const;
	};
}}
