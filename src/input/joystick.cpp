#include <input/system.hpp>
#include <input/joystick.hpp>
#include <input/joystick_base.hpp>

namespace Gorgon{
namespace Input
{
	Joystick::Joystick(const int& pIndex)
	{
		mJoystick = System::get().getJoystick(pIndex);
	}

	void Joystick::update()
	{
		mJoystick->update();
	}
	
	bool Joystick::isOpened() const
	{
		return mJoystick->isOpened();
	}
	
	std::string Joystick::getName() const
	{
		return mJoystick->getName();
	}
	
	int Joystick::getIndex() const
	{
		return mJoystick->getIndex();
	}
	
	int Joystick::getButtonNumber() const
	{
		return mJoystick->getButtonNumber();
	}
	
	int Joystick::getStickNumber() const
	{
		return mJoystick->getStickNumber();
	}
	
	Stick Joystick::getStick(const int& pStick) const
	{
		return mJoystick->getStick(pStick);
	}
	
	float Joystick::getButton(const int& pButton) const
	{
		return mJoystick->getButton(pButton);
	}
}}