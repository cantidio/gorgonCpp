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
#ifndef _GORGON_ANIMATION_
#define _GORGON_ANIMATION_
#include <string>
#include <vector>
#include "animation_frame.hpp"
#include "animation_header.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Class that represents an animation definition
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	13/08/2008
	 * @version	18/05/2011
	 * @ingroup	Graphic
	 */
	class Animation
	{
		private:
			AnimationHeader mHeader;			/**<< Header of the animation file*/
			static AnimationFrame mNotFound;	/**<< Frame that is returned when some unkown frame is requested*/
			std::vector<AnimationFrame> mFrame;	/**<< Vector that stores the animation frames*/
			int	mGroup;							/**<< Animation Group*/
			int	mIndex;							/**<< Animation Index*/
			bool mLooping;						/**<< True if this animation has a loop*/
			int	mLoopFrame;						/**<< Frame Index that the animation loops*/
			int mRepeatNumber;					/**<< number of times this animation will repeat*/
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 */
			Animation();
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @param	const int&	group		, animation group
			 * @param	const int&	index		, animation index
			 * @param	const bool&	looping		, true if this animation loops
			 * @param	const int&	loopFrame	, index of the frame that starts the animation's loop
			 * @param	const int&	repeatNumber, number of times this animation will repeat, if -1 it will repeat forever
			 */
			Animation
			(
				const int&	pGroup,
				const int&	pIndex,
				const bool&	pLooping		= false,
				const int&	pLoopFrame		= 0,
				const int&	pRepeatNumber	= -1
			);
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	Core::File& pFile, previously opened file
			 * @details
			 * 			This method opens the animation stored in the file
			 */
			Animation(Core::File& pFile);
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @param	const std::string& fileName, name of the file to be open
			 */
			Animation(const std::string& pFileName);
			/**
			 * Destructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 */
			~Animation();
			/**
			 * Method that finds the real index of all animation frames given a spritepack
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	24/02/2009
			 * @param	const SpritePack& spritePack, reference to the spritepack
			 */
			void optimize(const SpritePack& pSpritePack);
			/**
			 * Method that describes the atributes of the animation
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	18/06/2009
			 * @return	std::string
			 */
			std::string describe();
			/**
			 * Method that returns que index of the first frame of the animation with the given group and frame
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	02/03/2009
			 * @param	const int& group	, group of the frame
			 * @param	const int& index	, index of the frame
			 * @details
			 * 			This method will try to find the index of the frame requested, if it fails it will return -1
			 */
			int getFrameRealIndex(const int& pGroup, const int& pIndex);
			/**
			 * Method to insert a frame into the animation
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const AnimationFrame& pFrame, the frame to be inserted
			 */
			void add(const AnimationFrame& pFrame);
			/**
			 * Method to insert a frame into the animation in the given position
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	21/06/2009
			 * @param	const AnimationFrame&	pFrame	, the frame be be inserted
			 * @param	const int&				pPos	, the position that the frame will be inserted
			 */
			void add(const AnimationFrame& pFrame,const int& pPos);
			/**
			 * Method that removes a frame from the animation
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	06/01/2011
			 * @param	const int& pos, the index of the frame in the animation
			 * @details
			 * 			This method removes the frame with the given index, if the index is out of bounds,
			 * index < 0 or index > totalFrames, this method will do nothing
			 */
			void remove(const int& pPos);
			/**
			 * Method that removes a frame from the animation given its group and index
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	02/03/2009
			 * @param	const int& pos		, the group of the frame
			 * @param	const int& pIndex	, the index of the frame
			 * @details
			 * 			This method removes the frame that matches the search(group,index)
			 * if the frame couldn't be found, this method do nothing
			 */
			void remove(const int& pGroup,const int& pIndex);
			/**
			 * Method that returns the number of frames of the animation
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	int
			 */
			int	getSize() const;
			/**
			 * Method that returns the group of the animation
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	int
			 */
			int getGroup() const;
			/**
			 * Method that returns the index of the animation
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	int
			 */
			int getIndex() const;
			/**
			 * Method that returns if the animation loops
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	25/02/2009
			 * @return	bool
			 */
			bool getLooping() const;
			/**
			 * Method that returns the index of the frame that starts the animation loop
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	25/02/2009
			 * @return	int
			 */
			int getLoopFrame() const;
			/**
			 * Method that returns the number of loops of the animation
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	int
			 * @details -1 means that this animation will loop forever, if the loop is true
			 */
			int getRepeatNumber() const;
			/**
			 * Method that sets the group of the animation
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009n
			 * @param	const int& pGroup, group of the animation
			 */
			void setGroup(const int& pGroup);
			/**
			 * Method that sets the index of the a-nimation
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @param	const int& pIndex, index of the animation
			 */
			void setIndex(const int& pIndex);
			/**
			 * Method that sets if the animation has a loop or not
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	24/02/2009
			 * @param	const bool& pLooping, true if the animation has a loop
			 */
			void setLooping(const bool& pLooping);
			/**
			 * Method that sets which frame the animation will start its loop
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	24/02/2009
			 * @param	const int& pLoopFrame, frame that starts the animation loop
			 */
			void setLoopFrame(const int& pLoopFrame);
			/**
			 * Method that sets the number of times the animation will repeat
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	24/02/2009
			 * @param	const int& pRepeatNumber, the number of times the animation will repeat
			 * @details
			 * 			if the pRepeatNumber is -1, then the animation will loop forever, if the loop is true
			 */
			void setRepeatNumber(const int& pRepeatNumber);
			/**
			 * Method that saves the animation in a previously opened file
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, file to save the animation
			 */	
			void save(Core::File& pFile);
			/**
			 * Method that saves the animation into a file of the given name
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	21/06/2009
			 * @param	const std::string& pFileName, the name of the file that the animation will be saved
			 */	
			void save(const std::string& pFileName);
			/**
			 * Method that loads the animation from a file previously opened
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, the file that holds the animation
			 */
			void load(Core::File& pFile);
			/**
			 * Method that loads the animation from a file
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const std::string& pFileName, the name of the file that contains the animation
			 */
			void load(const std::string& pFileName);
			/**
			 * Operator to acess some frame given its index
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	06/01/2011
			 * @param	const nt& pPos, the index of the frame will want the acess
			 * @return	AnimationFrame&
			 *
			 */
			AnimationFrame& operator [](const int& pPos);
			/**
			 * Operator to acess some frame given its index
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/06/2009
			 * @version	06/01/2011
			 * @param	const int& pPos, the index of the frame will want the acess
			 * @return	AnimationFrame&
			 */
			const AnimationFrame& operator [](const int& pPos) const;
	};
}}
#endif
