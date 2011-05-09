#include <input/joystick_handler.hpp>
#include <input/joystick_base_null.hpp>
namespace Gorgon{
namespace Input
{
	JoystickHandler* JoystickHandler::mHandler = NULL;

	JoystickHandler::JoystickHandler(){}
	JoystickHandler::~JoystickHandler(){}
	JoystickHandler& JoystickHandler::get()
	{
		if(mHandler == NULL)
		{
			static JoystickHandler handler;
			set(handler);
		}
		return *mHandler;
	}

	void JoystickHandler::set(JoystickHandler& pHandler)
	{
		//não se deleta o objeto de o mesmo não for NULL, pois os mesmos foram criados de maneira statica
		mHandler = &pHandler;
	}

	JoystickBase* JoystickHandler::getJoystick(const int& pIndex) const
	{
		return new JoystickBaseNull(pIndex);
	}

	int JoystickHandler::getJoystickNumber() const
	{
		return 0;
	}
}}
