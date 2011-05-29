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
#ifndef _GORGON_GRAPHIC_COLOR_
#define	_GORGON_GRAPHIC_COLOR_
#include <string>

namespace Gorgon{
namespace Graphic
{
	/**
	 * Class that represents a color
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/05/2009
	 * @version	29/05/2011
	 * @ingroup	Graphic
	 */
	class Color
	{
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 */
			Color();
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const float& pRed	, the value of the red component of the color
			 * @param	const float& pGreen	, the value of the green component of the color
			 * @param	const float& pBlue	, the value of the blue component of the color
			 * @param	const float& pAlpha	, the value of the alpha component of the color
			 * @details
			 *			the range of the component are from 0.0, to 1.0
			 */
			Color
			(
				const float& pRed,
				const float& pGreen,
				const float& pBlue,
				const float& pAlpha = 0
			);
			/**
			 * Copy Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const Color& pColor, source color object
			 */
			Color(const Color& pColor);
			/**
			 * Method that describes the color components in the color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @return	std::string
			 */
			std::string describe();
			/**
			 * Method that sets the red component of the color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const int& pRed, value of the red component of the color
			 */
			inline void setRed(const float& pRed)
			{
				mRed = (pRed > 1.0) ? 1.0 : ( (pRed < 0.0) ? 0.0 : pRed);
			}
			/**
			 * Method that sets the green component of the color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const int& pGreen, the value of the green component of the color
			 */
			inline void setGreen(const float& pGreen)
			{
				mGreen = (pGreen > 1.0) ? 1.0 : ( (pGreen < 0.0) ? 0.0 : pGreen);
			}
			/**
			 * Method that sets the blue component of the color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const int& pBlue, value of the blue component of the color
			 */
			inline void setBlue(const float& pBlue)
			{
				mBlue = (pBlue > 1.0) ? 1.0 : ( (pBlue < 0.0) ? 0.0 : pBlue);
			}
			/**
			 * Method that sets the alpha component of the color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const int& pAlpha, value of the alpha component of the color
			 */
			inline void setAlpha(const float& pAlpha)
			{
				mAlpha = (pAlpha > 1.0) ? 1.0 : ( (pAlpha < 0.0) ? 0.0 : pAlpha);
			}
			/**
			 * Method that sets the components of the color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const float& pRed	, valor do componente vermelho da cor
			 * @param	const float& pGreen	, valor do componente verde da cor
			 * @param	const float& pBlue	, valor do componente azul da cor
			 * @param	const float& pAlpha	, valor do componente alpha da cor
			 */
			inline void set( const float& pRed, const float& pGreen, const float& pBlue, const float& pAlpha )
			{
				mRed   = (pRed   > 1.0) ? 1.0 : ( (pRed   < 0.0) ? 0.0 : pRed   );
				mGreen = (pGreen > 1.0) ? 1.0 : ( (pGreen < 0.0) ? 0.0 : pGreen );
				mBlue  = (pBlue  > 1.0) ? 1.0 : ( (pBlue  < 0.0) ? 0.0 : pBlue  );
				mAlpha = (pAlpha > 1.0) ? 1.0 : ( (pAlpha < 0.0) ? 0.0 : pAlpha );
			}
			/**
			 * Method that returns the red component of the color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @return	int
			 */
			inline float getRed() const
			{
				return mRed;
			}
			/**
			 * Method that returns the green component of the color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @return	int
			 */
			inline int getGreen() const
			{
				return mGreen;
			}
			/**
			 * Method that returns the blue component of the color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @return	int
			 */
			inline int getBlue() const
			{
				return mBlue;
			}
			/**
			 * Method that returns the alpha component of the color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @return	int
			 */
			inline int getAlpha() const
			{
				return mAlpha;
			}
			/**
			 * Operator that adds this color components with the color components of the requested color and returns another color with the result
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const Color& pColor, color to add
			 * @return	Color
			 */
			Color operator +(const Color& pColor) const;
			/**
			 * Operator that adds the color components of the object with the requested color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const Color& pColor, color to add
			 */
			void operator +=(const Color& pColor);
			/**
			 * Operator that subtracts this color components with the color components of the requested color and returns another color with the result
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const Color& pColor, color to subtract
			 * @return	Color
			 */
			Color operator -(const Color& pColor) const;
			/**
			 * Operator that subtracts the color components of the object with the requested color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const Color& pColor, color to sub
			 */
			void operator -=(const Color& pColor);
			/**
			 * Operator that divides this color components with the color components of the requested color and returns another color with the result
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const Color& pColor, color to divide
			 * @return	Color
			 */
			Color operator /(const Color& pValue) const;
			/**
			 * Operator that divides the color components of the object with the requested color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @param	const Color& pColor, color to divide
			 */
			 void operator /=(const Color& pValue);
			/**
			 * Operator that multiplies this color components with the color components of the requested color and returns another color with the result
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2009
			 * @version	29/05/2011
			 * @param	const Color& pColor, color to multiply
			 * @return	Color
			 */
			Color operator *(const Color& pValue) const;
			/**
			 * Operator that multiplies the color components of the object with the requested color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @param	const Color& pColor, color to multiply
			 */
			 void operator *=(const Color& pValue);
			/**
			 * Operator that returns ture if two colors have the same color components
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/06/2009
			 * @version	25/06/2009
			 * @param	const Color& pColor, color to be tested
			 * @return	bool
			 */
			bool operator ==(const Color& pColor) const;
			/**
			 * Operator that returns ture if two colors don't have the same color components
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/06/2009
			 * @version	25/06/2009
			 * @param	const Color& pColor, color to be tested
			 * @return	bool
			 */
			bool operator !=(const Color& pColor) const;
		protected:
			float mRed;		/**<< The red component of the color*/
			float mGreen;	/**<< The green component of the color*/
			float mBlue;	/**<< The blue component of the color*/
			float mAlpha;	/**<< The aplpha component of the color*/
	};
}}
#endif
