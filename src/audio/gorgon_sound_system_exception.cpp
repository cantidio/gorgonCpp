#include "audio/gorgon_sound_system_exception.hpp"

namespace Gorgon{
namespace Audio
{
	SoundSystemException::SoundSystemException
	(
		const std::string& message,
		const std::string& file,
		const std::string& function,
		const int& line
	) : Exception(message,"SoundSystem",file,function,line){}
}}
