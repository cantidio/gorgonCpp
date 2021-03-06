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
#ifndef _GORGON_INPUT_JOYSTICK_STICK_
#define _GORGON_INPUT_JOYSTICK_STICK_

namespace Gorgon{
namespace Input
{
	/**
	 * Classe que representa um stick do joystick
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	04/05/2011
	 * @version	04/05/2011
	 * @ingroup	Input
	 */
	class Stick
	{
		protected:
			int		mAxesNumber;	/**<< var that holds the number of axes of this stick */
			float	mAxes[4];		/**<< var that holds the value of the axes of this stick*/
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @param	const int& pAxesNumber, number of axes of the stick
			 */
			Stick(const int& pAxesNumber)
			{
				mAxesNumber = (pAxesNumber < 4) ? pAxesNumber : 4;
				//mAxes		= new float[mAxesNumber];
			}
			Stick(const Stick& pStick)
			{
				*this = pStick;
			}
			/**
			 * Destructor
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 */
			virtual ~Stick()
			{
				//if(mAxes != NULL)
				//{
				//	delete mAxes;
				//}
			}
			/**
			 * Method that returns the number of axes of the stick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @return	int
			 */
			inline int getAxesNumber() const
			{
				return mAxesNumber;
			}
			/**
			 * Method that returns the value of an axis of the stick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @param	const int& pAxis, the index of the axis
			 * @return	float
			 */
			inline float getAxis(const int& pAxis) const
			{
				return (pAxis < mAxesNumber) ? mAxes[pAxis] : 0;
			}
			/**
			 * Method that sets the value of an axis of the stick
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	04/05/2011
			 * @version	04/05/2011
			 * @param	const int&		pAxis , the index of the axis
			 * @param	const float&	pValue, the new value of the axis
			 */
			inline void setAxis(const int& pAxis, const float pValue)
			{
				if(pAxis < mAxesNumber) mAxes[pAxis] = pValue;
			}
			/**
			 * Operator =
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	11/05/2011
			 * @version	11/05/2011
			 * @param	const Stick& pStick, original stick
			 */
			Stick& operator =(const Stick& pStick)
			{
				//if(mAxes != NULL) delete mAxes;
				mAxesNumber = pStick.mAxesNumber;
				//mAxes		= new float[mAxesNumber];

				for(register int i = 0; i < mAxesNumber; ++i)
				{
					mAxes[i] = pStick.mAxes[i];
				}
				return *this;
			}
	};
}}
#endif


