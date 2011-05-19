#include <graphic/animation_handler.hpp>
#include <graphic/exception.hpp>
#include <sstream>

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

	Core::String AnimationHandler::describe() const
	{
		std::stringstream out;
		out << "Gorgon::Graphic::AnimationHandler"	<< std::endl;
		out << "AnimationOn: " << mAnimationOn		<< std::endl;
		out << "FrameOn:     " << mFrameOn			<< std::endl;
		out << "TimeOn:      " << mTimeOn			<< std::endl;
		out << "LoopOn:      " << mLoopOn			<< std::endl;

		return Core::String(out.str());
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
		if(mAnimationPack != NULL)
		{
			if(pFrameIndex < (*mAnimationPack)[mAnimationOn].getSize())
			{
				mTimeOn		= 0;
				mLoopOn		= 0;
				mFrameOn	= pFrameIndex;
			}
			/*else
			{
				throw AnimationException("Unable to change frame due to incorrect index.");
			}*/
		}
		else
		{
			std::stringstream out;
			out << "AnimationHandler::JumpToFrame(" << pFrameIndex << "): Error animationpack is NULL.";
			raiseGraphicException(out.str());
		}
	}

	void AnimationHandler::jumpToFrame(const int& pFrameGroup,const int& pFrameIndex)
	{
		if(mAnimationPack != NULL)
		{
			register int i;
			Animation& animation = (*mAnimationPack)[mAnimationOn];

			for(i = 0; i < animation.getSize(); ++i)
			{
				if(animation[i].getGroup() == pFrameGroup && animation[i].getIndex() == pFrameIndex)
				{
					break;
				}
			}
			jumpToFrame(i);
		}
		else
		{
			std::stringstream out;
			out << "AnimationHandler::JumpToFrame(" << pFrameGroup << "," << pFrameIndex << "): Error animationpack is NULL.";
			raiseGraphicException(out.str());
		}
	}

	void AnimationHandler::optimize()
	{
		if(mAnimationPack != NULL)
		{
			if(mSpritePack != NULL)
			{
				mAnimationPack->optimize(*mSpritePack);
				reset();
			}
			else
			{
				raiseGraphicException("AnimationHandler::optimize(): Error spritepack is NULL.");
			}
		}
		else
		{
			raiseGraphicException("AnimationHandler::optimize(): Error animationpack is NULL.");
		}
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
		if(mAnimationPack != NULL)
		{
			return (*mAnimationPack)[mAnimationOn].getGroup();
		}
		return -1;
	}

	int AnimationHandler::getAnimationOnIndex() const
	{
		if(mAnimationPack != NULL)
		{
			return (*mAnimationPack)[mAnimationOn].getIndex();
		}
		return -1;
	}

	void AnimationHandler::changeAnimation(const int& pAnimationNumber, const bool& pForce)
	{
		if(mAnimationPack != NULL)
		{
			if(mAnimationOn != pAnimationNumber || pForce)
			{
				if(pAnimationNumber < mAnimationPack->getSize())
				{
					reset();
					mAnimationOn = pAnimationNumber;
				}
				/*else
				{
					throw AnimationException("Unable to change Animation due to incorrect index.");
				}*/
			}
		}
		else
		{
			std::stringstream out;
			out << "AnimationHandler::changeAnimation(" << pAnimationNumber << "," << (pForce ? "true" : "false") << "): Error animationpack is NULL.";
			raiseGraphicException(out.str());
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
		if(mAnimationPack != NULL)
		{
			changeAnimation( mAnimationPack->getAnimationRealIndex(pGroup, pIndex), pForce);
		}
		else
		{
			std::stringstream out;
			out << "AnimationHandler::changeAnimation(" << pGroup << "," << pIndex << "," << (pForce ? "true" : "false") << "): Error animationpack is NULL.";
			raiseGraphicException(out.str());
		}
	}

	bool AnimationHandler::isPlaying()
	{
		if(mAnimationPack != NULL)
		{
			if
			(
				mFrameOn	>= (*mAnimationPack)[mAnimationOn].getSize() - 1 &&
				mTimeOn		>= (*mAnimationPack)[mAnimationOn][mFrameOn].getTime()
			)
			{
				return false;
			}
			return true;
		}
		return false;
	}

	void AnimationHandler::playByStep()
	{
		if(mAnimationPack != NULL)
		{
			Animation&		animation	= (*mAnimationPack)[mAnimationOn];
			AnimationFrame&	frame		= animation[mFrameOn];

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
		else
		{
			raiseGraphicException("AnimationHandler::playByStep(): Error animationpack is NULL.");
		}
	}
	
	const Sprite& AnimationHandler::getCurrentSprite() const
	{
		if(mAnimationPack != NULL)
		{
			Animation&		animation	= (*mAnimationPack)[mAnimationOn];
			AnimationFrame& frame		= animation[mFrameOn];

			if(mSpritePack != NULL)
			{
				if(frame.getRealIndex() >= 0)
				{
					return (*mSpritePack)[frame.getRealIndex()];
				}
				else
				{
					return mSpritePack->getSprite(frame.getGroup(),frame.getIndex());
				}
			}
			else
			{
				raiseGraphicException("AnimationHandler::getCurrentSprite(): Error spritepack is NULL.");
			}
		}
		else
		{
			raiseGraphicException("AnimationHandler::getCurrentSprite(): Error animationpack is NULL.");
		}
	}

	void AnimationHandler::draw
	(
		Sprite& pSprite,
		const Core::Point& pPosition,
		const Mirroring& pMirroring,
		const int& pAngle
	)
	{
		if(mAnimationPack != NULL)
		{
			try
			{
				AnimationFrame& frame = (*mAnimationPack)[mAnimationOn][mFrameOn];
				pSprite.drawSpriteRotatedFlipped
				(
					getCurrentSprite(),
					frame.getOffset()		+ pPosition,
					frame.getAngle()		+ pAngle,
					frame.getMirroring()	+ pMirroring
				);
			}
			catch(Core::Exception& exception)
			{
				std::stringstream out;
				out << "AnimationHandler::draw(" << (int)&pSprite << ",Core::Point(" << pPosition.getX() << "," << pPosition.getY() << ")," << pMirroring.getType() << "," << pAngle << "): Error while drawing.";
				raiseGraphicExceptionE(out.str(),exception);
			}
		}
		else
		{
			std::stringstream out;
			out << "AnimationHandler::draw(" << (int)&pSprite << ",Core::Point(" << pPosition.getX() << "," << pPosition.getY() << ")," << pMirroring.getType() << "," << pAngle << "): Error animationpack is NULL.";
			raiseGraphicException(out.str());
		}

	}
	
	void AnimationHandler::drawTrans
	(
		Sprite& pSprite,
		const Core::Point& pPosition,
		const Mirroring& pMirroring,
		const float& pTrans
	)
	{
		if(mAnimationPack != NULL)
		{
			try
			{
				AnimationFrame& frame = (*mAnimationPack)[mAnimationOn][mFrameOn];
				/**
				 * @todo concertar isso, poder colocar o angulo também
				 */
				pSprite.drawSpriteTransFlipped
				(
					getCurrentSprite(),
					frame.getOffset() + pPosition,
					pTrans,
					frame.getMirroring() + pMirroring
				);
			}
			catch(Core::Exception& exception)
			{
				std::stringstream out;
				out << "AnimationHandler::drawTrans(" << (int)&pSprite << ",Core::Point(" << pPosition.getX() << "," << pPosition.getY() << ")," << pMirroring.getType() << "): Error while drawing.";
				raiseGraphicExceptionE(out.str(),exception);
			}
		}
		else
		{
			std::stringstream out;
			out << "AnimationHandler::drawTrans(" << (int)&pSprite << ",Core::Point(" << pPosition.getX() << "," << pPosition.getY() << ")," << pMirroring.getType() << "): Error animationpack is NULL.";
			raiseGraphicException(out.str());
		}
	}

}}
