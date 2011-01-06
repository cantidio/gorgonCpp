#include "audio/gorgon_sound.hpp"

namespace Gorgon{
namespace Audio
{
	Sound::Sound
	(
		const std::string& soundLocation,
		const bool& bufferFirst,
		SoundSystem* system
	)
	{
		Core::LogRegister("Trying to open a Sound...");
		if(!system)	throw newSoundException("NULL SoundSystem passed.");

		sound = audiere::OpenSound
		(
			system->getDevice(),
			soundLocation.c_str(),
			!bufferFirst
		);

		if(!sound)	throw newSoundException("Opening Sound.");
		Core::LogRegister("Sucessfull.");
	}

	Sound::~Sound()
	{
		Core::LogRegister("Sound Closed...");
	//	if(sound)	delete sound;
	}

	bool Sound::isPlaying() const
	{
		if(sound)
		{
			return sound->isPlaying();
		}
		return false;
	}

	void Sound::play()
	{
		if(sound)
		{
			sound->play();
		}
	}

	void Sound::stop()
	{
		if(sound)
		{
			sound->stop();
		}
	}

	void Sound::reset()
	{
		if(sound)
		{
			sound->reset();
		}
	}

	void Sound::setPosition(const int& position)
	{
		if(sound)
		{
			sound->setPosition(position);
		}
	}

	int	Sound::getPosition() const
	{
		if(sound)
		{
			return sound->getPosition();
		}
		return 0;
	}

	void Sound::setVolume(const float& volume)
	{
		if(sound)
		{
			sound->setVolume(volume);
		}
	}

	float Sound::getVolume() const
	{
		if(sound)
		{
			return sound->getVolume();
		}
		return 0;
	}

	int Sound::getLength() const
	{
		if(sound)
		{
			return sound->getLength();
		}
		return 0;
	}
}}
