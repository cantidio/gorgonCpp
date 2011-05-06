#include "core/gorgon_log.hpp"
#include <time.h>
#include <iostream>
namespace Gorgon{
namespace Core
{
	Log* Log::mSingleton = NULL;

	Log::Log(const std::string& pLogFileName,const bool& pAppend)
	{
		mAppend		= pAppend;
		if(mAppend)
		{
			mFile.open(pLogFileName.c_str(),std::fstream::out | std::fstream::app);
		}
		else
		{
			mFile.open(pLogFileName.c_str(),std::fstream::out);
		}
	}

	Log::~Log()
	{
		mFile.close();
	}

	void Log::init(const std::string& pLogFileName,const bool& pAppend)
	{
		if(mSingleton == NULL)
		{
			static Log log(pLogFileName,pAppend);
			mSingleton = &log;
		}
	}
	
	Log& Log::get()
	{
		init();
		return *mSingleton;
	}

	void Log::writeTimeStamp()
	{
		char		st[23];
		time_t 		rawtime;
		struct tm*	timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(st,22,"[%Y-%m-%d %X]",timeinfo);
		mFile << st << "\t";
	}

	void Log::write(const std::string& message,const bool& newLine,const bool& pWriteTimeStamp)
	{
		if(mFile.is_open())
		{
			if(pWriteTimeStamp) writeTimeStamp();
			mFile << message;
			if(newLine)
			{
				mFile << std::endl;
			}
		}
	}

	void Log::write(const long& number,const bool& newLine,const bool& pWriteTimeStamp)
	{
		if(mFile.is_open())
		{
			if(pWriteTimeStamp) writeTimeStamp();
			mFile << number;
			if(newLine)
			{
				mFile << std::endl;
			}
		}
	}

	void Log::write(const double& number,const bool& newLine,const bool& pWriteTimeStamp)
	{
		if(mFile.is_open())
		{
			if(pWriteTimeStamp) writeTimeStamp();
			mFile << number;
			if(newLine)
			{
				mFile << std::endl;
			}
		}
	}

	void Log::write(const bool& boolean,const bool& newLine,const bool& pWriteTimeStamp)
	{
		if(mFile.is_open())
		{
			if(pWriteTimeStamp) writeTimeStamp();
			if(boolean)
			{
				mFile << "True";
			}
			else
			{
				mFile << "False";
			}
			if(newLine)
			{
				mFile << std::endl;
			}
		}
	}

	void Log::writeFormatted(const char* text,va_list& ap)
	{
		char buf[512];
		vsnprintf(buf,sizeof(buf),text,ap);
		write(std::string(buf),false);
	}

	void Log::writeFormatted(const char* text,...)
	{
		va_list ap;
		va_start(ap,text);
		writeFormatted(text,ap);
		va_end(ap);
	}
}}
