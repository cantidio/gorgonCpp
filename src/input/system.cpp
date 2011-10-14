#include <input/system.hpp>
#include <input/exception.hpp>
#include <input/mouse_base_null.hpp>
#include <input/keyboard_base_null.hpp>
#include <input/joystick_base_null.hpp>
#include <core/log.hpp>

namespace Gorgon{
namespace Input
{
	System* System::mSingleton = NULL;
	System::System()
	{
		Core::logWrite(std::string("Input::System::System(): Successful. This is a NULL System."));
	}

	System::~System()
	{
		Core::logWrite(std::string("Input::System::~System(): Successful."));
	}

	System& System::get()
	{
		if(mSingleton == NULL)
		{
			mSingleton = new System();
		}
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
			raiseInputException("Gorgon::Input::System::set(pSystem): Error, a NULL Input System was passed.");
		}
		Core::logWriteFormatted("Gorgon::Input::System::set( %p ): Successful.\n", mSingleton );
	}

	void System::halt()
	{
		if( mSingleton != NULL )
		{
			delete mSingleton;
			mSingleton = NULL;
			Core::logWriteFormatted( "Gorgon::Input::System::halt(): %p, Successful.\n", mSingleton );
		}
		else
		{
			Core::logWrite(std::string("Gorgon::Input::System::halt(): There wasn't any Input System to be halted."));
		}
	}

	KeyboardBase* System::getKeyboard() const
	{
		return new KeyboardBaseNull();
	}

	MouseBase* System::getMouse() const
	{
		return new MouseBaseNull();
	}

	JoystickBase* System::getJoystick( const int& pIndex ) const
	{
		return new JoystickBaseNull( pIndex );
	}

	int System::getJoystickNumber() const
	{
		return 0;
	}

}}
