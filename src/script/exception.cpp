#include <script/exception.hpp>

namespace Gorgon{
namespace Script
{
	Exception::Exception
	(
		const std::string&	pMessage,
		const std::string&	pFile,
		const std::string&	pFunction,
		const int&			pLine
	) : Core::Exception(pMessage,"Script",pFile,pFunction,pLine) {}

	Exception::Exception
	(
		const Core::Exception&	pException,
		const std::string&		pMessage,
		const std::string&		pFile,
		const std::string&		pFunction,
		const int& 					pLine
	) : Core::Exception(pException,pMessage,"Script",pFile,pFunction,pLine) {}
}}
