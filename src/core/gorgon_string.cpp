#include <core/gorgon_string.hpp>
#include <stdlib.h>

namespace Gorgon{
namespace Core
{
	String::String() {}
	String::String(const String& pString)		: std::string(pString) {}
	String::String(const std::string& pString)	: std::string(pString) {}
	String::String(const char* pString)			: std::string(pString) {}

	String& String::toLower()
	{
		for(register int i = length() - 1; i >= 0; --i)
		{
			 (*this)[i] = tolower( (*this)[i] );
		}
		return *this;
	}

	String& String::toUpper()
	{
		for(register int i = length() - 1; i >= 0; --i)
		{
			 (*this)[i] = toupper( (*this)[i] );
		}
		return *this;
	}

	int String::toInt() const
	{
		return atoi(c_str());
	}

	long int String::toLongInt() const
	{
		return atol(c_str());
	}

	double String::toDouble() const
	{
		return atof(c_str());
	}

	String& String::replace(const String& pOld, const String& pNew)
	{
		size_t pos = find(pOld);
		while( pos != npos)
		{
			std::string::replace(pos, pOld.length(), pNew);
			pos += pNew.length();
			pos = find(pOld, pos);
		}
		return *this;
	}

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
