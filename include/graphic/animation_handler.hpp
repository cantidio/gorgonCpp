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
#ifndef _GORGON_ANIMATION_HANDLER_
#define _GORGON_ANIMATION_HANDLER_
#include "../core/string.hpp"
#include "animationpack.hpp"
#include "spritepack.hpp"
#include "mirroring.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Class that represents the animationHandler
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	15/10/2008
	 * @version	09/06/2009
	 * @ingroup	Graphic
	 */
	class AnimationHandler
	{
		private:
			int mAnimationOn;				/**<< The index of the animation playing*/
			int	mTimeOn;					/**<< Actual time of the current frame*/
			int mFrameOn;					/**<< Current frame of the current animation*/
			int	mLoopOn;					/**<< Number of loops the current animação passed throught*/
			bool mIsPaused;					/**<< True if the animation if paused*/
			SpritePack*	mSpritePack;		/**<< Pointer to the spritepack of the handler*/
			AnimationPack* mAnimationPack;	/**<< Pointer to the animationpack of the handler*/
		public:
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	27/05/2008
			 */
			AnimationHandler();
			/**
			 * Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @param	SpritePack&		pSpritePack		, reference to the spritepack of the handler
			 * @param	AnimationPack&	pAnimationPack	, reference to the animationpack of the handler
			 */
			AnimationHandler(SpritePack& pSpritePack,AnimationPack& pAnimationPack);
			/**
			 * Copy Constructor
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @param	const AnimationHandler& pOrig , original obj
			 */
			AnimationHandler(const AnimationHandler& pOrig);
			/**
			 * Method that sets the spritepack of the handler
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @param	SpritePack& pSpritePack, the spritepack to be used in the handler
			 */
			void setSpritePack(SpritePack& pSpritePack);
			/**
			 * Method that sets the animationpack of the handler
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @param	AnimationPack& pAnimationPack, the animationpack to be used in the handler
			 */
			void setAnimationPack(AnimationPack& pAnimationPack);
			/**
			 * Method that returns the reference to the spritepack of the handler
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/03/2009
			 * @version	27/05/2009
			 * @return	SpritePack&
			 */
			SpritePack& getSpritePack() const;
			/**
			 * Method htat returns the reference to the animationpack of the handler
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/03/2009
			 * @version	27/05/2009
			 * @return	AnimationPack&
			 */
			AnimationPack& getAnimationPack() const;
			/**
			 * Method that describes the animationhandler
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @return	Core::String
			 */
			Core::String describe() const;
			/**
			 * Method that resets the animation being played
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	27/05/2009
			 */
			void reset();
			/**
			 * Method that pauses the animation
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/02/2009
			 * @version	27/05/2009
			 */
			void pause();
			/**
			 * Method that resumes the animation if it were paused previously
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/02/2009
			 * @version	27/05/2009
			 */
			void resume();
			/**
			 * Method that jumps to the requested frame of the current animation
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/02/2009
			 * @version	27/05/2009
			 * @param	const int& pFrameIndex, the real index of the frame in the current animation
			 * @details
			 * 			This method will try to change to the requested frame, if the frame isn't found, then it will do nothing
			 */
			void jumpToFrame(const int& pFrameIndex);
			/**
			 * Method that jumps to the requested frame of the current animation
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/02/2009
			 * @version	27/05/2009
			 * @param	const int& pFrameGroup, group of the frame
			 * @param	const int& pFrameIndex, index of the frame
			 *  @details
			 * 			This method will try to change to the requested frame, if the frame isn't found, then it will do nothing
			 */
			void jumpToFrame(const int& pFrameGroup,const int& pFrameIndex);
			/**
			 * Method that optimizes the animationhandler frame access throught finding the correct indexes of the frames in the spritepack
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	27/05/2008
			 * @details
			 * 			This method is very important to optimize the animation logic time, it finds the real index of the sprites
			 * in the spritepack and update their values into the animationpack, for direct access. Run it, every timeyou change something
			 * into the animationpack or the spritepack
			 */
			void optimize();
			/**
			 * Method that returns the index of the current frame in the animation
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/10/2008
			 * @version	27/05/2009
			 * @return	const int&
			 */
			int getFrameOn() const;
			/**
			 * Method that returns the current time of the current frame of the animation
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	27/05/2009
			 * @return	int
			 */
			int getTimeOn() const;
			/**
			 * Method that returns the index of the current animation
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	27/05/2009
			 * @return	int
			 */
			int getAnimationOn() const;
			/**
			 * Method that returns the group of the current animation
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	27/05/2009
			 * @return	int
			 */
			int getAnimationOnGroup() const;
			/**
			 * Method that returns the index of the current animation
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	27/05/2009
			 * @return	int
			 */
			int getAnimationOnIndex() const;
			/**
			 * Method that chances the animation playing
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	27/05/2009
			 * @param	const int&	pAnimationNumber	, index of the animation to play
			 * @param	const bool&	pForce				, if true his method will reset the timers and changes to the animation even if the requested animation is already playing,
			 * if false, the method will just change the animation if the requested animation isn't playing
			 */
			void changeAnimation(const int& pAnimationNumber,const bool& pForce=false);
			/**
			 * Method that changes the animation playing
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @param	const int& pGroup	, the group of the requested animation
			 * @param	const int& pIndex	, the index of the requested animation
			 * @param	const bool& pForce	, if true his method will reset the timers and changes to the animation even if the requested animation is already playing,
			 * if false, the method will just change the animation if the requested animation isn't playing
			 */
			void changeAnimation
			(
				const int& pGroup,
				const int& pIndex,
				const bool& pForce=false
			);
			/**
			 * Method that returns true if the animation is still playing
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	09/06/2009
			 * @return	bool
			 */
			bool isPlaying();
			/**
			 * Method that executes one step of the animation
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	09/06/2009
			 * @todo	rename this method, maybe runStep, playStep, logic,...
			 */
			void playByStep();
			/**
			 * Method that returns the current sprite of the current frame of the current animation
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @return	const Sprite&
			 */
			const Sprite& getCurrentSprite() const;
			/**
			 * Method that draws the animation current frame into a sprite
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	03/05/2011
			 * @param	Sprite& pSprite				, sprite where the current frame will be drawn
			 * @param	const Point& pPosition		, position where the frame will be drawn in the sprite
			 * @param	const Mirroring& pMirroring	, mirroring of the animation
			 * @param	const int& pAngle			, angle of the animation
			 */
			void draw
			(
				Sprite& pSprite,
				const Core::Point& pPosition,
				const Mirroring& pMirroring=Mirroring::Normal,
				const int& pAngle=0
			);

			void drawTrans
			(
				Sprite& pSprite,
				const Core::Point& pPosition,
				const Mirroring& pMirroring=Mirroring::Normal,
				const float& pTrans = 0.5
			);
			//virtual void onFinish();//?
	};
}}
#endif
