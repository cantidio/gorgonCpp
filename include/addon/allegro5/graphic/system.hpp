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
#ifndef _GORGON_GRAPHIC_ADDON_SYSTEM_
#define _GORGON_GRAPHIC_ADDON_SYSTEM_
#include "../../../graphic/system.hpp"

namespace Gorgon	{
namespace Graphic	{	class DisplayBase;	}
namespace Allegro5	{
namespace Graphic
{
	/**
	 * Class that represents the Graphic System
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	27/05/2011
	 * @version	03/06/2011
	 */
	class System : public Gorgon::Graphic::System
	{
		public:
			/**
			 * Method that sets the GraphicSystem
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 * @param	System& pSystem, the graphic system
			 */
			static void set();
			/**
			 * Method that returns an instance of the current ImageBase
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 * @return	Gorgon::Graphic::ImageBase*
			 */
			virtual Gorgon::Graphic::ImageBase* getImage() const;
			/**
			 * Method that returns an instance of the font
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	14/09/2011
			 * @version	14/09/2011
			 * @return	Gorgon::Graphic::FontBase*, an instance of the implementation of the font using the current addon backend
			 */
			virtual Gorgon::Graphic::FontBase* getFont() const;
			/**
			 * Method that returns an instance of the display
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	29/05/2011
			 * @version	29/05/2011
			 * @param	const std::string&	pWindowTitle , the title of the display's window
			 * @param	const int&			pWidth       , the width of the display
			 * @param	const int&			pHeight      , the height of the display
			 * @param	const bool&			pFullScreen  , if the display will begin in fullscreen
			 * @param	const bool&			pResizeable  , if the display is resizeable
			 * @return	Gorgon::Graphic::DisplayBase*
			 */
			virtual Gorgon::Graphic::DisplayBase* getDisplay
			(
				const std::string& pWindowTitle,
				const int& pWidth,
				const int& pHeight,
				const bool& pFullScreen = false,
				const bool& pResizeable = false
			) const;
			/**
			 * Method that draws a pixel into the current target bitmap
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 * @param	const Gorgon::Core::Point&		pPosition	, the position of the pixel
			 * @param	const Gorgon::Graphic::Color&	pColor		, the color of the pixel
			 */
			virtual void drawPixel( const Gorgon::Core::Point& pPosition, const Gorgon::Graphic:: Color& pColor );
			/**
			 * Method that draws a line into the current target bitmap
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2011
			 * @version	03/06/2011
			 * @param	const Gorgon::Core::Point&		pPointA		, the first point of the line
			 * @param	const Gorgon::Core::Point&		pPointB		, the second point of the line
			 * @param	const Gorgon::Graphic::Color&	pColor		, the color of the line
			 * @param	const float&					pThickness	, the thickness of the line
			 */
			virtual void drawLine
			(
				const Gorgon::Core::Point&		pPointA,
				const Gorgon::Core::Point&		pPointB,
				const Gorgon::Graphic::Color&	pColor,
				const float& pThickness = 1.0f
			);
			/**
			 * Method that draws a triangle into the current target bitmap
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2011
			 * @version	03/06/2011
			 * @param	const Gorgon::Core::Point&		pPointA		, the first point of the triangle
			 * @param	const Gorgon::Core::Point&		pPointB		, the second point of the triangle
			 * @param	const Gorgon::Core::Point&		pPointC		, the third point of the triangle
			 * @param	const Gorgon::Graphic::Color&	pColor		, the color of the triangle
			 * @param	const float&					pThickness	, the thickness of the triangle
			 */
			virtual void drawTriangle
			(
				const Gorgon::Core::Point&		pPointA,
				const Gorgon::Core::Point&		pPointB,
				const Gorgon::Core::Point&		pPointC,
				const Gorgon::Graphic::Color&	pColor,
				const float&					pThickness = 1.0f
			);
			/**
			 * Method that draws a triangle into the current target bitmap, filled with color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2011
			 * @version	03/06/2011
			 * @param	const Gorgon::Core::Point&		pPointA		, the first point of the triangle
			 * @param	const Gorgon::Core::Point&		pPointB		, the second point of the triangle
			 * @param	const Gorgon::Core::Point&		pPointC		, the third point of the triangle
			 * @param	const Gorgon::Graphic::Color&	pColor		, the color of the triangle
			 */
			virtual void drawTriangleFilled
			(
				const Gorgon::Core::Point&		pPointA,
				const Gorgon::Core::Point&		pPointB,
				const Gorgon::Core::Point&		pPointC,
				const Gorgon::Graphic::Color&	pColor
			);
			/**
			 * Method that draws a rectangle into the current target bitmap
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2011
			 * @version	03/06/2011
			 * @param	const Gorgon::Core::Point&		pPointA		, the first point of the diagonal of the rectangle
			 * @param	const Gorgon::Core::Point&		pPointB		, the second point of the diagonal of the rectangle
			 * @param	const Gorgon::Graphic::Color&	pColor		, the color of the rectangle
			 * @param	const float&					pThickness	, the thickness of the rectangle
			 */
			virtual void drawRectangle
			(
				const Gorgon::Core::Point&		pPointA,
				const Gorgon::Core::Point&		pPointB,
				const Gorgon::Graphic::Color&	pColor,
				const float&					pThickness = 1.0f
			);
			/**
			 * Method that draws a rectangle into the current target bitmap, filled with color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2011
			 * @version	03/06/2011
			 * @param	const Gorgon::Core::Point&		pPointA		, the first point of the diagonal of the rectangle
			 * @param	const Gorgon::Core::Point&		pPointB		, the second point of the diagonal of the rectangle
			 * @param	const Gorgon::Graphic::Color&	pColor		, the color of the rectangle
			 */
			virtual void drawRectangleFilled
			(
				const Gorgon::Core::Point&		pPointA,
				const Gorgon::Core::Point&		pPointB,
				const Gorgon::Graphic::Color&	pColor
			);
			/**
			 * Method that draws a circle into the current target bitmap
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2011
			 * @version	03/06/2011
			 * @param	const Gorgon::Core::Point&		pPosition	, the position of the circle
			 * @param	const float&					pRadius		, the radius of the circle
			 * @param	const Gorgon::Graphic::Color&	pColor		, the color of the circle
			 * @param	const float&					pThickness	, the thickness of the circle
			 */
			virtual void drawCircle
			(
				const Gorgon::Core::Point&		pPosition,
				const float&					pRadius,
				const Gorgon::Graphic::Color&	pColor,
				const float&					pThickness = 1.0f
			);
			/**
			 * Method that draws a circle into the current target bitmap, filled with color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2011
			 * @version	03/06/2011
			 * @param	const Gorgon::Core::Point&		pPosition	, the position of the circle
			 * @param	const float&					pRadius		, the radius of the circle
			 * @param	const Gorgon::Graphic::Color&	pColor		, the color of the circle
			 */
			virtual void drawCircleFilled
			(
				const Gorgon::Core::Point&		pPosition,
				const float&					pRadius,
				const Gorgon::Graphic::Color&	pColor
			);
			/**
			 * Method that draws an ellipse into the current target bitmap
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2011
			 * @version	03/06/2011
			 * @param	const Gorgon::Core::Point&		pPosition	, the position of the ellipse
			 * @param	const float&					pRadiusX	, the horizontal radius of the ellipse
			 * @param	const float&					pRadiusY	, the vertical radius of the ellipse
			 * @param	const Gorgon::Graphic::Color&	pColor		, the color of the ellipse
			 * @param	const float&					pThickness	, the thickness of the ellipse
			 */
			virtual void drawEllipse
			(
				const Gorgon::Core::Point&		pPosition,
				const float&					pRadiusX,
				const float&					pRadiusY,
				const Gorgon::Graphic::Color&	pColor,
				const float&					pThickness = 1.0f
			);
			/**
			 * Method that draws an ellipse into the current target bitmap, filled with color
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/06/2011
			 * @version	03/06/2011
			 * @param	const Gorgon::Core::Point&		pPosition	, the position of the ellipse
			 * @param	const float&					pRadiusX	, the horizontal radius of the ellipse
			 * @param	const float&					pRadiusY	, the vertical radius of the ellipse
			 * @param	const Gorgon::Graphic::Color&	pColor		, the color of the ellipse
			 */
			virtual void drawEllipseFilled
			(
				const Gorgon::Core::Point&		pPosition,
				const float&					pRadiusX,
				const float&					pRadiusY,
				const Gorgon::Graphic::Color&	pColor
			);
		protected:
			/**
			 * Protected Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 */
			System();
			/**
			 * Protected Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/05/2011
			 * @version	27/05/2011
			 */
			virtual ~System();
	};
}}}
#endif
