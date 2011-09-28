#include <core/file.hpp>
#include <core/zlib.hpp>

namespace Gorgon{
namespace Core
{
	File::File()
	{}

	File::File(const std::string& pFileName,std::ios_base::openmode pMode) : std::fstream(pFileName.c_str(),pMode)
	{}

	File::~File()
	{
		close();
	}

	long File::getSize()
	{
		std::streampos pos;
		long length;
		pos		= tellg();
		seekg(0,std::ios::end);
		length	= tellg();
		seekg(pos);
		return length;
	}

	void File::writeInt8(const char& pInt8)
	{
		write((char*)&pInt8,1);
	}

	void File::writeInt16(const short& pInt16)
	{
		write((char*)&pInt16,2);
	}

	void File::writeInt32(const int& pInt32)
	{
		write((char*)&pInt32,4);
	}

	void File::writeInt64(const long& pInt64)
	{
		write((char*)&pInt64,8);
	}

	void File::writeFloat(const float& pFloat)
	{
		write((char*)&pFloat,sizeof(float));
	}

	void File::writeDouble(const double& pDouble)
	{
		write((char*)&pDouble,sizeof(double));
	}

	void File::writeBool(const bool& pBool)
	{
		write((char*)&pBool,sizeof(bool));
	}

	void File::writeString(const std::string& pString)
	{
		write(pString.c_str(),pString.length());
	}

	void File::writeCharString(const char* pString, const int& pStringSize)
	{
		write(pString,pStringSize);
	}

	char File::readInt8()
	{
		char value = 0;
		read((char*)&value,1);
		return value;
	}

	unsigned char File::readUnsignedInt8()
	{
		unsigned char value = 0;
		read((char*)&value,1);
		return value;
	}

	short File::readInt16()
	{
		short value = 0;
		read((char*)&value,2);
		return value;
	}

	unsigned short File::readUnsignedInt16()
	{
		unsigned short value = 0;
		read((char*)&value,2);
		return value;
	}

	int File::readInt32()
	{
		int value = 0;
		read((char*)&value,4);
		return value;
	}

	unsigned int File::readUnsignedInt32()
	{
		unsigned int value = 0;
		read((char*)&value,4);
		return value;
	}

	long File::readInt64()
	{
		long value = 0;
		read((char*)&value,8);
		return value;
	}

	unsigned long File::readUnsignedInt64()
	{
		unsigned long value = 0;
		read((char*)&value,8);
		return value;
	}

	float File::readFloat()
	{
		float value = 0;
		read((char*)&value,sizeof(float));
		return value;
	}

	double File::readDouble()
	{
		double value = 0;
		read((char*)&value,sizeof(double));
		return value;
	}

	bool File::readBool()
	{
		bool value;
		read((char*)&value,sizeof(bool));
		return value;
	}

	/*const char* File::readCharString(const int& pStringSize)
	{
		char* value;
		value = new char[pStringSize + 1];
		read(value,pStringSize);
		value[pStringSize] = '\0';
		return aa";
	}*/

	std::string File::readString(const int& pStringSize)
	{
		char value[pStringSize + 1];
		read(value,pStringSize);
		value[pStringSize] = '\0';
		return std::string(value);
	}

	void File::readInt8(char& pInt8)
	{
		pInt8 = 0;
		read((char*)&pInt8,1);
	}

	void File::readUnsignedInt8(unsigned char& pInt8)
	{
		pInt8 = 0;
		read((char*)&pInt8,1);
	}

	void File::readInt16(short& pInt16)
	{
		pInt16 = 0;
		read((char*)&pInt16,2);
	}

	void File::readUnsignedInt16(unsigned short& pInt16)
	{
		pInt16 = 0;
		read((char*)&pInt16,2);
	}

	void File::readInt32(int& pInt32)
	{
		pInt32 = 0;
		read((char*)&pInt32,4);
	}

	void File::readUnsignedInt32(unsigned int& pInt32)
	{
		pInt32 = 0;
		read((char*)&pInt32,4);
	}

	void File::readInt64(long& pInt64)
	{
		pInt64 = 0;
		read((char*)&pInt64,8);
	}

	void File::readUnsignedInt64(unsigned long& pInt64)
	{
		pInt64 = 0;
		read((char*)&pInt64,8);
	}

	void File::readFloat(float& pFloat)
	{
		pFloat = 0;
		read((char*)&pFloat,sizeof(float));
	}

	void File::readDouble(double& pDouble)
	{
		pDouble = 0;
		read((char*)&pDouble,sizeof(double));
	}

	void File::readBool(bool& pBool)
	{
		read((char*)&pBool,sizeof(bool));
	}

	void File::readString(std::string& pString,const int& pStringSize)
	{
		pString = readString(pStringSize);
	}

	void File::readCharString(char*& pString,const int& pStringSize)
	{
		read(pString,pStringSize);
		pString[pStringSize] = '\0';
	}

	bool File::extensionIs(const std::string& pFileName,const std::string& pExtension)
	{
		return pFileName.substr
		(
			pFileName.length() - pExtension.length(),
			pFileName.length() - 1
		) == pExtension;
	}

	void File::compressZlib()
	{
		/*std::stringstream a;
		std::stringstream b;
		Zlib::passBuffer(*this,a);//copy this to "a"
		Zlib::compress(a,b,7);
		Zlib::passBuffer(a,*this);//copy "a" to this
	*/}

	void File::decompressZlib()
	{
/*		std::stringstream a;
		std::stringstream b;
		Zlib::passBuffer(*this,a);//copy this to "a"
		Zlib::decompress(a,b);
		Zlib::passBuffer(a,*this);//copy "a" to this
	*/}
}}
