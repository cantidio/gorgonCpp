#include <core/exception.hpp>
#include <iostream>
#include <sstream>

namespace Gorgon{
namespace Core
{
	inline void tab(std::stringstream& pStream, const int& pTabs)
	{
		for(int i = pTabs; i > 0; --i)
		{
			pStream << "\t";
		}
	}

	Exception::Exception(const Exception& pException)
	{
		mMessage	= pException.mMessage;
		mModule		= pException.mModule;
		mFile		= pException.mFile;
		mFunction	= pException.mFunction;
		mLine		= pException.mLine;
		mPrev		= (pException.mPrev != NULL) ? new Exception(*pException.mPrev) : NULL;
	}

	Exception::Exception
	(
		const std::string&	pMessage,
		const std::string&	pModule,
		const std::string&	pFile,
		const std::string&	pFunction,
		const int&			pLine
	)
	{
		mMessage	= pMessage;
		mModule		= pModule;
		mFile		= pFile;
		mFunction	= pFunction;
		mLine		= pLine;
		mPrev		= NULL;
	}

	Exception::Exception
	(
		const Exception&	pException,
		const std::string&	pMessage,
		const std::string& 	pModule,
		const std::string& 	pFile,
		const std::string& 	pFunction,
		const int& 			pLine
	)
	{
		mMessage	= pMessage;
		mModule		= pModule;
		mFile		= pFile;
		mFunction	= pFunction;
		mLine		= pLine;
		mPrev		= new Exception(pException);
	}

	Exception::~Exception()
	{
		if(mPrev != NULL)
		{
			delete mPrev;
		}
	}

	std::string Exception::what(const int& pTabs) const
	{
		std::stringstream out(std::stringstream::in|std::stringstream::out);
		out << std::endl;
		tab(out,pTabs);	out << "Exception in Gorgon::"	<< mModule	<< std::endl;
		tab(out,pTabs);	out << "On file:\t"				<< mFile 	<< std::endl;
		tab(out,pTabs);	out << "On line:\t"				<< mLine	<< std::endl;
		tab(out,pTabs);	out << "On function:\t"			<< mFunction<< std::endl;
		tab(out,pTabs);	out << "Message:\t"				<< mMessage	<< std::endl;
		if(mPrev != NULL)
		{
			out << mPrev->what(pTabs + 1);
		}
		return out.str();
	}

	std::string Exception::getMessage() const
	{
		return mMessage;
	}

	void Exception::writeInLog() const
	{
		logWrite(what());
	}
}}
