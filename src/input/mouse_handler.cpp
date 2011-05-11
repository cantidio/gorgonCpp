#include <input/mouse_handler.hpp>
#include <input/mouse_base_null.hpp>
namespace Gorgon{
namespace Input
{
	MouseHandler* MouseHandler::mHandler = NULL;

	MouseHandler::MouseHandler(){}
	MouseHandler::~MouseHandler(){}
	MouseHandler& MouseHandler::get()
	{
		if(mHandler == NULL)
		{
			static MouseHandler handler;
			set(handler);
		}
		return *mHandler;
	}

	void MouseHandler::set(MouseHandler& pHandler)
	{
		//não se deleta o objeto de o mesmo não for NULL, pois os mesmos foram criados de maneira statica
		mHandler = &pHandler;
	}

	MouseBase* MouseHandler::getMouse() const
	{
		return new MouseBaseNull();
	}
}}
