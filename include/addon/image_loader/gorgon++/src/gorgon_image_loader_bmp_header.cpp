#include "../include/gorgon_image_loader_bmp_header.hpp"
#include <gorgon++/graphic/image.hpp>
#include <gorgon++/graphic/exception.hpp>

namespace Gorgon
{
	const int ImageLoaderBmpHeader::mImageLoaderBmpMagicNumber = 19778;

	ImageLoaderBmpHeader::ImageLoaderBmpHeader(){}

	ImageLoaderBmpHeader::ImageLoaderBmpHeader(Core::File& pFile)
	{
		load(pFile);
	}

	void ImageLoaderBmpHeader::fill(const ImageLoaderBmpInfoHeader& pInfoHeader)
	{
		mFileType		= ImageLoaderBmpHeader::mImageLoaderBmpMagicNumber;
		mFileSize		= pInfoHeader.getSizeOfBitmap() + pInfoHeader.getSize() + getSize();
		mReserved1		= 0;
		mReserved2		= 0;
		if(pInfoHeader.getBpp() <= 8)
		{
			mFileSize += 4 * pInfoHeader.getColorsUsed();
		}
		mBitmapOffset	= mFileSize - pInfoHeader.getSizeOfBitmap();
	}

	std::string ImageLoaderBmpHeader::describe() const
	{
		std::stringstream out;
		out << "ImageLoaderBmpHeader Descriptor"			<< std::endl;
		out << "fileType:     " << mFileType		<< std::endl;
		out << "fileSize:     " << mFileSize		<< std::endl;
		out << "bitmapOffset: " << mBitmapOffset	<< std::endl;
		return out.str();
	}

	void ImageLoaderBmpHeader::save(Core::File& pFile) const
	{
		pFile.writeInt16(mFileType);
		pFile.writeInt32(mFileSize);
		pFile.writeInt16(mReserved1);
		pFile.writeInt16(mReserved2);
		pFile.writeInt32(mBitmapOffset);
	}

	void ImageLoaderBmpHeader::load(Core::File& pFile)
	{
		mFileType		= pFile.readInt16();
		mFileSize		= pFile.readInt32();
		mReserved1		= pFile.readInt16();
		mReserved2		= pFile.readInt16();
		mBitmapOffset	= pFile.readInt32();
	}

	bool ImageLoaderBmpHeader::isValid() const
	{
		if(mFileType != ImageLoaderBmpHeader::mImageLoaderBmpMagicNumber)
		{
			return false;
		}
		return true;
	}

	unsigned long ImageLoaderBmpHeader::getSize() const
	{
		return 14;
	}

	unsigned long ImageLoaderBmpHeader::getFileSize() const
	{
		return mFileSize;
	}

	unsigned long ImageLoaderBmpHeader::getBitmapOffset() const
	{
		return mBitmapOffset;
	}

	void ImageLoaderBmpHeader::setFileSize(const int& pSize)
	{
		mFileSize = pSize;
	}

	void ImageLoaderBmpHeader::setBitmapOffset(const int& pOffset)
	{
		mBitmapOffset = pOffset;
	}
}
