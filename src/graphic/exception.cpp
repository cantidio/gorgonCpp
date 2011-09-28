#include <graphic/exception.hpp>

namespace Gorgon{
namespace Graphic
{
	Exception::Exception
	(
		const std::string&	pMessage,
		const std::string&	pFile,
		const std::string&	pFunction,
		const int&			pLine
	) : Core::Exception(pMessage,"Graphic",pFile,pFunction,pLine) {}

	Exception::Exception
	(
		const Core::Exception&	pException,
		const std::string&		pMessage,
		const std::string&		pFile,
		const std::string&		pFunction,
		const int& 				pLine
	) : Core::Exception(pException,pMessage,"Graphic",pFile,pFunction,pLine) {}
}}
