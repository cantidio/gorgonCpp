#include "audio/sound_exception.hpp"

namespace Gorgon{
namespace Audio
{
	
	SoundException::SoundException
	(
		const std::string& message,
		const std::string& file,
		const std::string& function,
		const int& line
	) : Exception(message,"Sound",file,function,line){}
}}
