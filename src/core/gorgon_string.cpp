#include <core/gorgon_string.hpp>
namespace Gorgon{
namespace Core
{
	String::String() {}
	String::String(const String& pString) : std::string(pString) {}
	String::String(const std::string& pString) : std::string(pString) {}
	String::String(const char* pString) : std::string(pString) {}

	std::vector<String> String::explode(const String& pDelimiter) const
	{
		std::vector<String>		pieces;
		std::string::size_type	lastPos = find_first_not_of(pDelimiter, 0);
		std::string::size_type	pos     = find_first_of(pDelimiter, lastPos);

		while (std::string::npos != pos || std::string::npos != lastPos)
		{
			pieces.push_back(String(substr(lastPos, pos - lastPos)));
			lastPos	= find_first_not_of(pDelimiter, pos);
			pos		= find_first_of(pDelimiter, lastPos);
		}
		return pieces;
	}
}}
