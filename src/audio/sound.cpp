#include "audio/sound.hpp"
#include "core/string.hpp"
namespace Gorgon{
namespace Audio
{
	Sound::Sound
	(
		const std::string& pSoundLocation,
		const bool& pBufferFirst,
		SoundSystem* pSystem
	)
	{
		Core::logWriteFormatted
		(
			Core::String("Gorgon::Audio::Sound::Sound(\"%s\",%s,%d): "),
			pSoundLocation.c_str(),
			(pBufferFirst ? "true" : "false"),
			(int)pSystem
		);
		if(!pSystem)
		{
			Core::logWrite(Core::String("Error No SoundSystem passed."),true,false);
			throw newSoundException("NULL SoundSystem passed.");
		}

		sound = audiere::OpenSound
		(
			pSystem->getDevice(),
			pSoundLocation.c_str(),
			!pBufferFirst
		);

		if(!sound)	throw newSoundException("Opening Sound.");
		Core::logWrite("Sucessfull.",true,false);
	}

	Sound::~Sound()
	{
		Core::logWrite(Core::String("Gorgon::Audio::Sound::~Sound()\n"));
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
