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
#ifndef _GORGON_FONT_BASE_
#define _GORGON_FONT_BASE_
#include <string>
#include "font.hpp"

namespace Gorgon	{
namespace Core		{
	class File;
	class Point;
}
namespace Graphic
{
	class Color;
	/**
	 * Class that represents a Font implementation
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/05/2011
	 * @version	11/10/2011
	 * @ingroup	Graphic
	 */
	class FontBase
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/09/2011
			 * @version	14/09/2011
			 */
			FontBase();
			/**
			 * Virtual Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/10/2011
			 * @version	11/10/2011
			 */
			virtual ~FontBase();
			/**
			 * Method that returns the size of the font in pixels
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/09/2011
			 * @version	14/09/2011
			 * @return	int, the size of the font in pixels
			 */
			inline int getSize() const
			{
				return mSize;
			}
			/**
			 * Method that returns the height of the text line of the font
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/09/2011
			 * @version	14/09/2011
			 * @return	int, the height of the text line using the font
			 */
			inline int getLineHeight() const
			{
				return mLineHeight;
			}
			/**
			 * Method that returns the width of the text with the font
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/09/2011
			 * @version	14/09/2011
			 * @param	const std::string& pText, the text that will be used to calculate the width
			 * @return	int, the width of the text line using this font
			 */
			virtual int getTextWidth( const std::string& pText ) const = 0;
			/**
			 * Method that draws a text into the current display target
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/09/2011
			 * @version	14/09/2011
			 * @param	const Core::Point&		pPosition	, the position that the text will be drawn in the display
			 * @param	const Color&			pColor		, the color that the text will be drawn
			 * @param	const Font::Alignment	pAlignment	, the alignment of the text
			 * @param	const std::string&		pText		, the text that will be drawn
			 */
			virtual void drawText
			(
				const Core::Point&		pPosition,
				const Color&			pColor,
				const Font::Alignment&	pAlignment,
				const std::string&		pText
			) const = 0;
			/**
			 * Method that draws a text justified into the current display target
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/09/2011
			 * @version	14/09/2011
			 * @param	const Core::Point&		pPosition	, the position that the text will be drawn in the display
			 * @param	const int&				pLineWidth	, the width of the line, this will be used to justify the text
			 * @param	const Color&			pColor		, the color that the text will be drawn
			 * @param	const Font::Alignment	pAlignment	, the alignment of the text
			 * @param	const std::string&		pText		, the text that will be drawn
			 */
			virtual void drawTextJustified
			(
				const Core::Point&		pPosition,
				const int&				pLineWidth,
				const Color&			pColor,
				const Font::Alignment&	pAlignment,
				const std::string&		pText
			) const = 0;
			/**
			 * Method that loads a font file from a file previously opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/09/2011
			 * @version	14/09/2011
			 * @param	Core::File& pFile		, the file that contains the font to be loaded
			 * @param	const int	pSize		, the size which the font will be drawn
			 * @param	const int&	PDataLength	, the length of the font in the file
			 */
			//virtual void load( Core::File& pFile , const int& pSize, const int& pDataLength ) = 0;
			/**
			 * Method that loads a font file from a file previously opened
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/09/2011
			 * @version	14/09/2011
			 * @param	const std::string&	pFileName	, the file that contains the font to be loaded
			 * @param	const int			pSize		, the size which the font will be drawn
			 */
			virtual void load( const std::string& pFileName , const int& pSize ) = 0;
		protected:
			int mSize;			/**<< The size of the font in pixels*/
			int mLineHeight;	/**<< The height of one line of text in pixels*/
	};
}}
#endif
