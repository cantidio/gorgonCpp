#include "audio/sound_system.hpp"
#include "core/string.hpp"
namespace Gorgon{
namespace Audio
{
	SoundSystem* SoundSystem::lastSystem = NULL;

	SoundSystem::SoundSystem(const std::string device_name)
	{
		Core::logWriteFormatted(Core::String("Gorgon::Audio::SoundSystem::SoundSystem(\"%s\"): "), device_name.c_str());
		device		= audiere::OpenDevice(device_name.c_str());
		if(!device)
		{
			Core::logWrite(Core::String("Error could not open the audio device."),true,false);
			throw newSoundSystemException("Opening Device.");
		}
		Core::logWrite(Core::String("Sucessfull.\n"),true,false);
		lastSystem	= this;
	}

	SoundSystem::~SoundSystem()
	{
		Core::logWrite(Core::String("Gorgon::Audio::SoundSystem::~SoundSystem()\n"));
		//delete device;
	}

	audiere::AudioDevicePtr SoundSystem::getDevice() const
	{
		return device;
	}
}}
