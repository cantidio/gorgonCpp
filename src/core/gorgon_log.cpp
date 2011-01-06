#include "core/gorgon_log.hpp"
#include <time.h>

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
	{}

	void Log::init(const std::string& pLogFileName,const bool& pAppend)
	{
		if(mSingleton == NULL)
		{
			mSingleton = new Log(pLogFileName,pAppend);
		}
	}

	void Log::halt()
	{
		if(mSingleton)
		{
			delete mSingleton;
			mSingleton = NULL;
		}
	}
	
	Log& Log::get()
	{
		init();
		return *mSingleton;
	}

	void Log::RegisterTimeStamp()
	{
		char		st[23];
		time_t 		rawtime;
		struct tm*	timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(st,22,"[%Y-%m-%d %X]",timeinfo);
		mFile << st << "\t";
	}

	void Log::Register(const std::string& message,const bool& newLine)
	{
		if(mFile.is_open())
		{
			RegisterTimeStamp();
			mFile << message;
			if(newLine)
			{
				mFile << std::endl;
			}
		}
	}

	void Log::Register(const long& number,const bool& newLine)
	{
		if(mFile.is_open())
		{
			RegisterTimeStamp();
			mFile << number;
			if(newLine)
			{
				mFile << std::endl;
			}
		}
	}

	void Log::Register(const double& number,const bool& newLine)
	{
		if(mFile.is_open())
		{
			RegisterTimeStamp();
			mFile << number;
			if(newLine)
			{
				mFile << std::endl;
			}
		}
	}

	void Log::Register(const bool& boolean,const bool& newLine)
	{
		if(mFile.is_open())
		{
			RegisterTimeStamp();
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

	void Log::RegisterFormated(const char* text,va_list& ap)
	{
		char buf[512];
		vsnprintf(buf,sizeof(buf),text,ap);
		Register(std::string(buf));
	}

	void Log::RegisterFormated(const char* text,...)
	{
		va_list ap;
		va_start(ap,text);
		RegisterFormated(text,ap);
		va_end(ap);
	}
}}
