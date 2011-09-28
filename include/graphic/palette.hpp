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
#ifndef _GORGON_PALETTE_
#define _GORGON_PALETTE_
#include "../core/file.hpp"
#include "color.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Class that represents a color palette
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	07/08/2008
	 * @version	06/08/2009
	 * @ingroup	Graphic
	 */
	class Palette
	{
		public:
			/**
			 * Constructor
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	08/08/2008
			 */
			Palette();
			/**
			 * Constructor
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	08/08/2008
			 * @param	const int& pColorNumber, the number of colors that this palette will hold, the default is 256
			 */
			Palette(const int& pColorNumber);
			/**
			 * Constructor
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	14/08/2008
			 * @param	const std::string&	pPaletteName, name of the palette file
			 * @param	const int&			ṕColors		, number of colors of the palette, default=256
			 * @param	const int&			pJumpBytes	, the number of bytes to skip after each color, default = 0
			 */
			Palette
			(
				const std::string&	pPaletteName,
				const int&			pColorNumber	= 256,
				const int&			pJumpBytes		= 0
			);
			/**
			 * Constructor
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	17/02/2009
			 * @param	File&		pFile			, the file that contains the data of the palette
			 * @param	const int&	pColorNumber	, number of colors of the palette, default = 256
			 * @param	const int&	pJumpBytes		, the number of bytes to skipafter each color, default = 0
			 */
			Palette
			(
				Core::File&	pFile,
				const int&	pColorNumber	= 256,
				const int&	pJumpBytes		= 0
			);
			/**
			 * Destructor
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 */
			~Palette();
			/**
			 * Method that describes all the colors in this palette
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @return	std::string
			 */
			std::string describe() const;
			/**
			 * Method that creates a copy of this palette and returns it
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @return	Palette*
			 */
			Palette* clone() const;
			/**
			 * Method that erases all colors in this palette, put black (0,0,0)
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	07/08/2008
			 * @version	21/01/2009
			 */
			void erase();
			/**
			 * Método para aplicar a palheta
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 */
			void set() const;
			/**
			 * Method that inverse all the colors position in the palette
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	18/02/2009
			 */
			void inverse();
			/**
			 * Method that swaps the green component for the red component in the palette
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 */
			void swapRedForGreen();
			/**
			 * Method that swaps the blue component for the green component in the palette
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 */
			void swapGreenForBlue();
			/**
			 * Method that swaps the blue component for the red component in the palette
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	17/02/2009
			 * @version	17/02/2009
			 */
			void swapBlueForRed();
			/**
			 * Method that returns a color from the palette
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	29/05/2011
			 * @param	const int& pPos, the position of the color
			 * @return	Color
			 */
			inline Color getColor(const int& pPos) const
			{
				return (pPos < mColorNumber) ? Color(mColors[pPos], mColors[pPos+1], mColors[pPos+2], 1.0f) : Color(0.0f,0.0f,0.0f,0.0f);
			}
			/**
			 * Method that returns the red component a color in the palette
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	const int& pPos, the position of the color
			 * @return	float
			 */
			inline float getRed(const int& pPos) const
			{
				return (pPos < mColorNumber) ? mColors[pPos] : 0.0f;
			}
			/**
			 * Method that returns the green component a color in the palette
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	const int& pPos, the position of the color
			 * @return	float
			 */
			inline float getGreen(const int& pPos) const
			{
				return (pPos < mColorNumber) ? mColors[pPos+1] : 0.0f;
			}
			/**
			 * Method that returns the blue component a color in the palette
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	const int& pPos, the position of the color
			 * @return	float
			 */
			inline float getBlue(const int& pPos)	const
			{
				return (pPos < mColorNumber) ? mColors[pPos+2] : 0.0f;
			}
			/**
			 * Method that sets the red component of a color in the palette
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	const float&	pRed , value of the red component of the desired color
			 * @param	const int&		pPos , the position of the color in the palette
			 */
			inline void setRed(const float& pRed, const int& pPos)
			{
				if(pPos < mColorNumber)
			 	{
			 		mColors[pPos] = pRed;
			 	}
			}
			/**
			 * Method that sets the green component of a color in the palette
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	const float&	pGreen	, value of the green component of the desired color
			 * @param	const int&		pPos	, the position of the color in the palette
			 */
			inline void setGreen(const float& pGreen, const int& pPos)
			{
				if(pPos < mColorNumber)
			 	{
			 		mColors[pPos + 1] = pGreen;
			 	}
			}
			/**
			 * Method that sets the blue component of a color in the palette
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2008
			 * @param	const float&	pBlue	, value of the blue component of the desired color
			 * @param	const int&		pPos	, the position of the color in the palette
			 */
			inline void setBlue(const float& pBlue,const int& pPos)
			{
				if(pPos < mColorNumber)
			 	{
			 		mColors[pPos + 2] = pBlue;
			 	}
			}
			/**
			 * Method that sets a color into some position in the palette
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2011
			 * @param	const Color&	pColor	, the desired color
			 * @param	const int&		pPos	, the position of the color in the palette
			 */
			 inline void setColor(const Color& pColor, const int& pPos)
			 {
			 	if(pPos < mColorNumber)
			 	{
			 		setRed   ( pColor.getRed()   , pPos);
			 		setGreen ( pColor.getGreen() , pPos);
			 		setBlue  ( pColor.getBlue()  , pPos);
			 	}
			 }
			/**
			 * Method that sets a color into some position in the palette
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	08/08/2011
			 * @param	const float&	pRed	, value of the red component
			 * @param	const float&	pGreen	, value of the green component
			 * @param	const float&	pBlue	, value of the blue component
			 * @param	const int&		pPos	, the position of the color in the palette
			 */
			inline void setColor
			(
				const float&	pRed,
				const float&	pGreen,
				const float&	pBlue,
				const int&		pPos
			)
			{
				if(pPos < mColorNumber)
			 	{
			 		setRed   ( pRed   , pPos);
			 		setGreen ( pGreen , pPos);
			 		setBlue  ( pBlue  , pPos);
			 	}
			}
			/**
			 * Method that saves the palette in a previously opened file
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since 	30/04/2008
			 * @version 17/02/2008
			 * @param 	Core::File&	pFile			, the file to save the palette
			 * @param	const int&	pColorNumber	, the number of colors of the palette, default = 256
			 * @param	const int&	pJumpBytes		, number of bytes to put after each color, default = 0
			 */
			void save( Core::File& pFile, const int& pColorNumber = 256, const int&	pJumpBytes = 0 ) const;
			/**
			 * Method that saves the palette in a file
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since 	30/04/2008
			 * @version 17/02/2008
			 * @param 	const std::string&	pPaletteName	, the name of the palette file
			 * @param	const int&			pColorNumber	, the number of colors of the palette, default = 256
			 * @param	const int&			pJumpBytes		, number of bytes to put after each color, default = 0
			 */
			void save( const std::string& pPaletteName, const int& pColorNumber = 256, const int& pJumpBytes = 0 ) const;
			/**
			 * Method that loads a color palette from a previously opened file
			 *
			 * @author 	Cantidio Oliveira Fontes
			 * @since 	29/04/2008
			 * @version	06/08/2009
			 * @param	File&		pFile			, arquivo já aberto
			 * @param	const int&	pColorNumber	, the number of colors of the palette, default = 256
			 * @param	const int&	pJumpBytes		, number of bytes to skip after each color, default = 0
			 */
			void load
			(
				Core::File&	pFile,
				const int&	pColorNumber	= 256,
				const int&	pJumpBytes		= 0
			);
			/**
			 * Method that loads a color palette from a file
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	08/08/2008
			 * @version	17/02/2009
			 * @param	const std::string&	pPaletteName	, the name of the palette file to load
			 * @param	const int&			pColorNumber	, the number of colors of the palette, default = 256
			 * @param	const int&			pJumpBytes		, number of bytes to skip after each color, default = 0
			 */
			void load
			(
				const std::string&	pPaletteName,
				const int&			pColorNumber	= 256,
				const int&			pJumpBytes		= 0
			);
		protected:
			float*	mColors;		/** << vector with the colors of the palete, this goes 3 on 3, each 3 positions store one color(RGB) 0-1 */
			int		mColorNumber;	/**<< The number of colors that this palette stores*/
	};
}}
#endif
