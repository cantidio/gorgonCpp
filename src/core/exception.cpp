#include "core/exception.hpp"

namespace Gorgon{
namespace Core
{
	Exception::Exception
	(
		const std::string& message,
		const std::string& module,
		const std::string& file,
		const std::string& function,
		const int& line
	)
	{
		this->message	= message;
		this->module	= module;
		this->file		= file;
		this->function	= function;
		this->line		= line;
		logWrite(what());
	}

	std::string Exception::what() const
	{
		std::stringstream out(std::stringstream::in|std::stringstream::out);
		out << "\n\tException in Gorgon"	<< module	<< std::endl;
		out << "\tOn file:\t"				<< file 	<< std::endl;
		out << "\tOn line:\t"				<< line		<< std::endl;
		out << "\tOn function:\t"			<< function	<< std::endl;
		out << "\tMessage:\t"				<< message	<< std::endl;
		return out.str();
	}

	std::string Exception::getMessage() const
	{
		return message;
	}
}}
