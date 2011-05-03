#include <graphic/gorgon_animation_handler.hpp>

namespace Gorgon{
namespace Graphic
{
	AnimationHandler::AnimationHandler()
	{
		reset();
	}

	AnimationHandler::AnimationHandler(SpritePack& pSpritePack,AnimationPack& pAnimationPack)
	{
		setSpritePack(pSpritePack);
		setAnimationPack(pAnimationPack);
	}
	
	AnimationHandler::AnimationHandler(const AnimationHandler& pOrig)
	{
		setSpritePack(pOrig.getSpritePack());
		setAnimationPack(pOrig.getAnimationPack());

		mAnimationOn	= pOrig.mAnimationOn;
		mFrameOn		= pOrig.mFrameOn;
		mLoopOn			= pOrig.mLoopOn;
		mIsPaused		= pOrig.mIsPaused;
		mTimeOn			= pOrig.mTimeOn;
	}

	void AnimationHandler::setSpritePack(SpritePack& pSpritePack)
	{
		mSpritePack=&pSpritePack;
		reset();
	}

	void AnimationHandler::setAnimationPack(AnimationPack& pAnimationPack)
	{
		mAnimationPack=&pAnimationPack;
		reset();
	}

	SpritePack& AnimationHandler::getSpritePack() const
	{
		return *mSpritePack;
	}

	AnimationPack& AnimationHandler::getAnimationPack() const
	{
		return *mAnimationPack;
	}

	void AnimationHandler::describe() const
	{
		std::cout << "Gorgon AnimationHandler"			<< std::endl;
		std::cout << "AnimationOn: " << mAnimationOn	<< std::endl;
		std::cout << "FrameOn:     " << mFrameOn		<< std::endl;
		std::cout << "TimeOn:      " << mTimeOn			<< std::endl;
		std::cout << "LoopOn:      " << mLoopOn			<< std::endl;
	}

	void AnimationHandler::reset()
	{
		mAnimationOn	= 0;
		mFrameOn		= 0;
		mTimeOn			= 0;
		mLoopOn			= 0;
	}

	void AnimationHandler::pause()
	{
		mIsPaused = true;
	}

	void AnimationHandler::resume()
	{
		mIsPaused = false;
	}

	void AnimationHandler::jumpToFrame(const int& pFrameIndex)
	{
		if(pFrameIndex<(*mAnimationPack)[mAnimationOn].getSize())
		{
			mTimeOn		= 0;
			mLoopOn		= 0;
			mFrameOn	= pFrameIndex;
		}
		else
		{
			throw AnimationException("Unable to change frame due to incorrect index.");
		}
	}

	void AnimationHandler::jumpToFrame(const int& pFrameGroup,const int& pFrameIndex)
	{
		int i;
		/**
		 * @todo aqui pode ter uma falha de segmentaçao se for acessado sem colocar nada pro animation pack
		 */
		Animation& animation = (*mAnimationPack)[mAnimationOn];

		for(i=0; i<animation.getSize(); ++i)
		{
			if(animation[i].getGroup()==pFrameGroup && animation[i].getIndex()==pFrameIndex)
			{
				break;
			}
		}
		jumpToFrame(i);
	}

	void AnimationHandler::optimize()
	{
		mAnimationPack->optimize(*mSpritePack);
		reset();
	}

	int AnimationHandler::getFrameOn() const
	{
		return mFrameOn;
	}

	int AnimationHandler::getTimeOn() const
	{
		return mTimeOn;
	}

	int AnimationHandler::getAnimationOn() const
	{
		return mAnimationOn;
	}

	int AnimationHandler::getAnimationOnGroup() const
	{
		return (*mAnimationPack)[mAnimationOn].getGroup();
	}

	int AnimationHandler::getAnimationOnIndex() const
	{
		return (*mAnimationPack)[mAnimationOn].getIndex();
	}

	void AnimationHandler::changeAnimation(const int& pAnimationNumber,const bool& pForce)
	{
		if(mAnimationOn != pAnimationNumber || pForce)
		{
			if(pAnimationNumber < mAnimationPack->getSize())
			{
				reset();
				mAnimationOn = pAnimationNumber;
			}
			else
			{
				throw AnimationException("Unable to change Animation due to incorrect index.");
			}
		}
	}

	void AnimationHandler::changeAnimation
	(
		const int& pGroup,
		const int& pIndex,
		const bool& pForce
	)
	{
		int i;
		/**
		 * @todo substituir pela funćão de busca da classe animationpack
		 */
		for(i=0; i<mAnimationPack->getSize(); ++i)
		{
			if
			(
				(*mAnimationPack)[i].getGroup() == pGroup &&
				(*mAnimationPack)[i].getIndex() == pIndex
			)
			{
				break;
			}
		}
		changeAnimation(i,pForce);
	}

	bool AnimationHandler::isPlaying()
	{
		if
		(
			mFrameOn >= (*mAnimationPack)[mAnimationOn].getSize() - 1 &&
			mTimeOn >= (*mAnimationPack)[mAnimationOn][mFrameOn].getTime()

		)
		{
			return false;
		}
		return true;
	}

	void AnimationHandler::playByStep()
	{
		Animation&	animation	= (*mAnimationPack)[mAnimationOn];
		Frame&		frame		= animation[mFrameOn];

		if(frame.getTime() > 0)
		{
			++mTimeOn;

			if(frame.getTime() < mTimeOn)
			{
				++mFrameOn;
				mTimeOn = 0;
			}
			if(animation.getSize() <= mFrameOn + 1 )
			{
				if(animation.getLooping())
				{
					if(animation.getRepeatNumber() < 0)
					{
						mTimeOn		= 0;
						mFrameOn	= animation.getLoopFrame();
					}
					else if(mLoopOn < animation.getRepeatNumber())
					{
						++mLoopOn;
						mTimeOn		= 0;
						mFrameOn	= animation.getLoopFrame();
					}
					else
					{
						//onFinish();
					}
				}
			}
		}
	}
	
	const Sprite& AnimationHandler::getCurrentSprite() const
	{
		Animation&	animation	= (*mAnimationPack)[mAnimationOn];
		Frame& 		frame		= animation[mFrameOn];

		if(frame.getRealIndex()>=0)
		{
			return (*mSpritePack)[frame.getRealIndex()];
		}
		else
		{
			return mSpritePack->getSprite(frame.getGroup(),frame.getIndex());
		}
	}

	void AnimationHandler::draw
	(
		Sprite& pSprite,
		const int& pX,
		const int& pY,
		const Mirroring& pMirroring,
		const int& pAngle
	)
	{
		Frame& frame = (*mAnimationPack)[mAnimationOn][mFrameOn];
		pSprite.drawSpriteRotetedFlipped
		(
			getCurrentSprite(),
			frame.getXOffset()		+ pX,
			frame.getYOffset()		+ pY,
			frame.getAngle()		+ pAngle,
			frame.getMirroring()	+ pMirroring
		);
	}
	
	void AnimationHandler::drawTrans
	(
		Sprite& pSprite,
		const int& pX,
		const int& pY,
		const float& pTrans
	)
	{
		/**
		 * @todo concertar isso
		 */
		//Frame& frame = (*mAnimationPack)[mAnimationOn][mFrameOn];

		pSprite.drawSpriteTrans
		(
			getCurrentSprite(),
			pX,
			pY,
			pTrans
		);
	}
}}
