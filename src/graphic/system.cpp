#include <graphic/system.hpp>
#include <graphic/image_base.hpp>
#include <graphic/image.hpp>
#include <graphic/exception.hpp>
#include <core/log.hpp>

namespace Gorgon{
namespace Graphic
{
	System* System::mSingleton = NULL;

	System::System()
	{
		mTargetImage = NULL;
	}
	System::~System()	{}

	System& System::get()
	{
		return *mSingleton;
	}

	void System::set( System* pSystem )
	{
		if( mSingleton != NULL )
		{
			delete mSingleton;
		}
		mSingleton = pSystem;
		if( mSingleton == NULL )
		{
			raiseGraphicException("Graphic::System::set(pSystem): Error, a NULL Graphic System was passed.");
		}
		Core::logWriteFormatted("Gorgon::Graphic::System::set(%p): Successful.\n",pSystem);
	}

	void System::halt()
	{
		if( mSingleton != NULL )
		{
			delete mSingleton;
			mSingleton = NULL;
			Core::logWriteFormatted( "Gorgon::Graphic::System::halt(): %p, Successful.\n", mSingleton );
		}
		else
		{
			Core::logWrite(std::string("Gorgon::Graphic::System::halt(): There wasn't any Graphic System to be halted."));
		}
	}

	void System::setTargetImage( Image& pImage )
	{
		mTargetImage = &pImage;
		pImage.applyAsTarget();
	}

	Image* System::getTargetImage()
	{
		return mTargetImage;
	}
}}
