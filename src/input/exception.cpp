#include <input/exception.hpp>

namespace Gorgon{
namespace Input
{
	Exception::Exception
	(
		const std::string&	pMessage,
		const std::string&	pFile,
		const std::string&	pFunction,
		const int&			pLine
	) : Core::Exception(pMessage,"Input",pFile,pFunction,pLine) {}

	Exception::Exception
	(
		const Core::Exception&	pException,
		const std::string&		pMessage,
		const std::string&		pFile,
		const std::string&		pFunction,
		const int& 				pLine
	) : Core::Exception(pException,pMessage,"Input",pFile,pFunction,pLine) {}
}}
