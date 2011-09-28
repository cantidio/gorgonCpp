#include "core/file_header.hpp"

namespace Gorgon{
namespace Core
{
	const int FileHeader::mGorgonMagicNumber=0x676f47fa;

	void FileHeader::save(File& pFile)
	{
		pFile.writeInt32(mGorgonMagicNumber);
	}

	void FileHeader::load(File& pFile)
	{
		mMyGorgonMagicNumber = pFile.readInt32();
	}

	bool FileHeader::isValid() const
	{
		if(mMyGorgonMagicNumber != mGorgonMagicNumber)
		{
			return false;
		}
		return true;
	}

	void FileHeader::returnFilePosition(File& pFile,const int& pPos)
	{
		pFile.seekg(-pPos,std::ios_base::cur);
	}
}}
