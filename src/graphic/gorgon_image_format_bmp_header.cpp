#include "graphic/gorgon_image_format_bmp_header.hpp"
#include "graphic/gorgon_image.hpp"

namespace Gorgon
{
	const int ImageFormatBmpHeader::mImageFormatBmpMagicNumber = 19778;

	ImageFormatBmpHeader::ImageFormatBmpHeader(){}

	ImageFormatBmpHeader::ImageFormatBmpHeader(Core::File& pFile)
	{
		load(pFile);
	}

	void ImageFormatBmpHeader::fill(const ImageFormatBmpInfoHeader& pInfoHeader)
	{
		mFileType		= ImageFormatBmpHeader::mImageFormatBmpMagicNumber;
		mFileSize		= pInfoHeader.getSizeOfBitmap() + pInfoHeader.getSize() + getSize();
		mReserved1		= 0;
		mReserved2		= 0;
		if(pInfoHeader.getBpp() <= 8)
		{
			mFileSize += 4 * pInfoHeader.getColorsUsed();
		}
		mBitmapOffset	= mFileSize - pInfoHeader.getSizeOfBitmap();
	}

	std::string ImageFormatBmpHeader::describe() const
	{
		std::stringstream out;
		out << "ImageFormatBmpHeader Descriptor"			<< std::endl;
		out << "fileType:     " << mFileType		<< std::endl;
		out << "fileSize:     " << mFileSize		<< std::endl;
		out << "bitmapOffset: " << mBitmapOffset	<< std::endl;
		return out.str();
	}

	void ImageFormatBmpHeader::save(Core::File& pFile) const
	{
		pFile.writeInt16(mFileType);
		pFile.writeInt32(mFileSize);
		pFile.writeInt16(mReserved1);
		pFile.writeInt16(mReserved2);
		pFile.writeInt32(mBitmapOffset);
	}

	void ImageFormatBmpHeader::load(Core::File& pFile)
	{
		mFileType		= pFile.readInt16();
		mFileSize		= pFile.readInt32();
		mReserved1		= pFile.readInt16();
		mReserved2		= pFile.readInt16();
		mBitmapOffset	= pFile.readInt32();
	}

	bool ImageFormatBmpHeader::isValid() const
	{
		if(mFileType != ImageFormatBmpHeader::mImageFormatBmpMagicNumber)
		{
			return false;
		}
		return true;
	}

	unsigned long ImageFormatBmpHeader::getSize() const
	{
		return 14;
	}

	unsigned long ImageFormatBmpHeader::getFileSize() const
	{
		return mFileSize;
	}

	unsigned long ImageFormatBmpHeader::getBitmapOffset() const
	{
		return mBitmapOffset;
	}

	void ImageFormatBmpHeader::setFileSize(const int& pSize)
	{
		mFileSize = pSize;
	}

	void ImageFormatBmpHeader::setBitmapOffset(const int& pOffset)
	{
		mBitmapOffset = pOffset;
	}
}
