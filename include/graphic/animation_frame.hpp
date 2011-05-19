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
#ifndef _GORGON_FRAME_
#define _GORGON_FRAME_
#include "../core/file.hpp"
#include "../core/point.hpp"
#include "spritepack.hpp"
#include "mirroring.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Class that represents an animation frame
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	12/08/2008
	 * @version	21/06/2009
	 * @ingroup	Graphic
	 * @todo	os offsets não estão funcionando
	 */
	class AnimationFrame
	{
		private:
			int mGroup;				/**<< Group of the frame's sprite*/
			int mIndex;				/**<< Index of the frame's sprite*/
			int mRealIndex;			/**<< The real index of the frame's sprite in the spritepack*/
			int mTime;				/**<< Time that this frame will be displayed*/
			Core::Point mOffset;	/**<< Offset of the frame*/
			Mirroring mMirroring;	/**<< Mirroring of the frame's sprite*/
			int mAngle;				/**<< Angle of the frame's sprite*/
			//int transparence;
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	23/02/2009
			 */
			AnimationFrame();
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	03/05/2011
			 * @param	const int&			pGroup		, group of the frame's sprite
			 * @param	const int&			pIndex		, index of the frame's sprite
			 * @param	const int& 			pTime		, time that the frame will be displayed
			 * @param	const Mirroring&	pMirroring	, mirroring of the frame's sprite
			 * @param	const int&			pAngle		, angle of the frame's sprite
			 * @param	const Point&		pOffset		, offset of the frame's sprite
			 */
			AnimationFrame
			(
				const int&			pGroup,
				const int&			pIndex,
				const int&			pTime,
				const Mirroring&	pMirroring	= Mirroring::Normal,
				const int&			pAngle		= 0,
				const Core::Point&	pOffset		= Core::Point(0,0)
			);
			/**
			 * Constructor that reveies the frame information from a previously opened file
			 *
			 * @author Cantidio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, file that contains the frame information
			 */
			AnimationFrame(Core::File& pFile);
			/**
			 * Method that describes the frame
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	std::string
			 */
 			std::string describe() const;
			/**
			 * Method that returns the group of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/08/2008
			 * @return	int
			 */
			int getGroup() const;
			/**
			 * Method that returns the index of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/08/2008
			 * @return	int
			 */
			int getIndex() const;
			/**
			 * Method that returns the realIndex of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/08/2008
			 * @return	int
			 * @details
			 * 			The real index of a frame's sprite, is its position into it's spritepack.
			 * @example
			 * 			SpritePack		a("ta.gsp");
			 * 			AnimatinPack	b("b.gap");
			 * 			int index = b[0][0].getRealIndex();
			 * 			a[index] ...
			 */
			int getRealIndex() const;
			/**
			 * Method that returns the offset of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	03/05/2011
			 * @return	Core::Point
			 */
			Core::Point getOffset() const;
			/**
			 * Method that returns the time that this frame is displayed
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/08/2008
			 * @return	int
			 */
			int getTime() const;
			/**
			 * Method that returns the mirroring of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	27/02/2009
			 * @return	Mirroring
			 */
			Mirroring getMirroring() const;
			/**
			 * Method that returns the angle of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	13/08/2008
			 * @return	int
			 */
			int getAngle() const;
			/**
			 * Method that sets the group of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pGroup, group of the frame's sprite
			 */
			void setGroup(const int& pGroup);
			/**
			 * Method that sets the index of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pIndex, index of the frame's sprite
			 */
			void setIndex(const int& pIndex);
			/**
			 * Method that sets the real index of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	23/02/2009
			 * @param	const int& pIndex, the real index of the frame's sprite
			 * @see		getRealIndex
			 */
			void setRealIndex(const int& pIndex);
			/**
			 * Method that sets the time the frame's sprite is displayed
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pTime, the time this frame is displayed
			 */
			void setTime(const int& pTime);
			/**
			 * Method that sets the offset of the frame's sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	03/05/2011
			 * @version	03/05/2011
			 * @param	const Core::Point& pOffset, offset of the frame's sprite
			 */
			void setOffset(const Core::Point& pOffset);
			/**
			 * Method that sets the XOffset of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pXOffset, the horizontal offset of the frame's sprite
			 */
			void setXOffset(const int& pXOffset);
			/**
			 * Method that sets the YOffset of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pYOffset, the vertical offset of the frame's sprite
			 */
			void setYOffset(const int& pYOffset);
			/**
			 * Method that sets the mirroring of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const Mirroring& pMirroring, the mirroring of the frame's sprite
			 */
			void setMirroring(const Mirroring& pMirroring);
			/**
			 * Method that sets the angle of the frame's sprite
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/02/2009
			 * @version	23/02/2009
			 * @param	const int& pAngle, angle of the frame's sprite
			 */
			void setAngle(const int& pAngle);
			/**
			 * Method that optimizes the frame operations by finding its real index
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	23/02/2009
			 * @param	const SpritePack& pSpritePack, the spritepack of the frame
			 * @see		getRealIndex setRealIndex
			 * @details
			 * 			This method search the given spritepack by the sprite described in the frame by its group and index,
			 * When it finds the sprite it get the sprite real index and stores it into the frame
			 */
			void optimize(const SpritePack& pSpritePack);
			/**
			 * Method that loads the frame from a previously opened file
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	21/06/2009
			 * @param	Core::File& pFile, the file that contains the frame data
			 */
			void load(Core::File& pFile);
			/**
			 * Method that saves the frame data into a previously opened file
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	12/08/2008
			 * @version	21/06/2009
			 * @param	Core::File& pFile, the file that the frame data will be written
			 */
			void save(Core::File& pFile);
	};
}}
#endif
