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
#ifndef _GORGON_ANIMATION_PACK_
#define _GORGON_ANIMATION_PACK_
#include <vector>
#include <fstream>
#include "animation.hpp"
#include "animationpack_header.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Class that represents an animationpack
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	13/08/2008
	 * @version	21/06/2009
	 * @ingroup	Graphic
	 */
	class AnimationPack
	{
		private:
			AnimationPackHeader mHeader;		/**<< Header of the animationpack file*/
			static Animation mNotFound;			/**<< empty animation that is returned when some unknown animation is requested*/
			std::vector<Animation> mAnimation;	/**Vector that stores the animations*/
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 */
			AnimationPack();
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, arquivo já aberto
			 */
			AnimationPack(Core::File& pFile);
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @param	const std::string& pFileName, nome do arquivo a ser aberto para carregar os dados
			 */
			AnimationPack(const std::string& pFileName);
			/**
			 * Destructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 */
			~AnimationPack();
			/**
			 * Method that optimizes the animations in the animationpack
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @param	const SpritePack*& pSpritePack, the spritepack that will map tha frames of the animations
			 */
			void optimize(const SpritePack& pSpritePack);
			/**
			 * Method that describes the animationpack
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	Core::String
			 */
			std::string describe();
			/**
			 * Method that returns the number of animations in the pack
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	int
			 */
			int getSize();
			/**
			 * Method that removes all animations in the animationpack
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	24/02/2009
			 * @return	int
			 */
			void clear();
			/**
			 * Method that returns the index of the first animation that meets the requested parameters
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2008
			 * @version	02/03/2009
			 * @param	const int& pGroup, animation group
			 * @param	const int& pIndex, animation index
			 * @return	int
			 * @details
			 * 			This method tries to find the animation requested, if not found, it returns -1
			 */
			int getAnimationRealIndex(const int& pGroup, const int& pIndex);
			/**
			 * Method that inserts a animation into the package
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const Animation& pAnimation, animation to be inserted into the animationpack
			 */
			void add(const Animation& pAnimation);
			/**
			 * Method that inserts a animation into the package into a given position
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	02/03/2008
			 * @version	21/06/2009
			 * @param	const Animation&	pAnimation	, animation to be inserted into the package
			 * @param	const int&			pPos		, position to insert the animation into the package
			 */
			void add(const Animation& pAnimation, const int& pPos);
			/**
			 * Method that removes an animation from the animationpack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	21/06/2009
			 * @param	const int& pPos, position(index) of the animation to remove
			 * @details
			 * 			This method tries to remove the animation requested, if the animation couldn't be found
			 * it does nothing
			 */
			void remove(const int& pPos);
			/**
			 * Method that removes an animation from the animationpack
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	02/03/2009
			 * @version	02/03/2009
			 * @param	const int& pGroup, group of the animation to remove
			 * @param	const int& pIndex, index of the animation to remove
			 * @details
			 * 			This method tries to remove the animation requested, if the animation couldn't be found
			 * it does nothing. If there is more than one animation with the group and index requested, this method
			 * will remove just the first occurence
			 */
			void remove(const int& pGroup,const int& pIndex);
			/**
			 * Method that saves the animationpack into a file previously opened
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, the file handler that will recive the animationpack data
			 */
			void save(Core::File& pFile);
			/**
			 * Method that saves the animationpack into a file with the given name
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	std::string pFileName, name of the file that will store the animationpack data
			 */
			void save(const std::string& pFileName);
			/**
			 * Method that loads the animationpack data from a previously opened file
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	File& pFile, file that holds the animationpack data
			 */
			void load(Core::File& pFile);
			/**
			 * Method that loads the animationpack from a file
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	std::string pFileName, name of the file that contains the animationpack data
			 */
			void load(const std::string& pFileName);
			/**
			 * Operator to access an animation by its index
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const int& pPos, index of the animation in the animationpack
			 * @return	Animation&
			 * @details
			 * 			If the animation you trying to access is out of bounds this method
			 * will return an empty animation
			 */
			Animation& operator [](const int& pPos);
			/**
			 * Operator to access an animation by its group and index
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	13/08/2008
			 * @version	21/06/2009
			 * @param	const int& pGroup, group of the desired animation
			 * @param	const int& pIndex, index of the desired animation
			 * @return	Animation&
			 * @details
			 *			This method will search the entire animationpack for this animation, if the animation couldn't be found
			 * it will return an empty animation
			 */
			Animation& operator ()(const int& pGroup,const int& pIndex);
	};
}}
#endif
