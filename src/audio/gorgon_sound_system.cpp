#include "audio/gorgon_sound_system.hpp"

namespace Gorgon{
namespace Audio
{
	SoundSystem* SoundSystem::lastSystem = NULL;

	SoundSystem::SoundSystem(const std::string device_name)
	{
		Core::LogRegister("Trying to open a Sound Device %s",device_name.c_str());
		device		= audiere::OpenDevice(device_name.c_str());
		if(!device)	throw newSoundSystemException("Opening Device.");
		Core::LogRegister("Sucessfull.");
		lastSystem	= this;
	}

	SoundSystem::~SoundSystem()
	{
		Core::LogRegister("SoundSystem Closed...");
		//delete device;
	}

	audiere::AudioDevicePtr SoundSystem::getDevice() const
	{
		return device;
	}
}}
