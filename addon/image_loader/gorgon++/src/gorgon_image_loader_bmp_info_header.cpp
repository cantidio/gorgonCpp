#include "../include/gorgon_image_loader_bmp_info_header.hpp"
#include <gorgon++/graphic/gorgon_image.hpp>

namespace Gorgon
{
	
	ImageLoaderBmpInfoHeader::ImageLoaderBmpInfoHeader(){}

	ImageLoaderBmpInfoHeader::ImageLoaderBmpInfoHeader(Core::File& pFile)
	{
		load(pFile);
	}

	void ImageLoaderBmpInfoHeader::fill(const Graphic::Image& pImage)
	{
		int filler;
		mSize					= 40;
		mWidth					= pImage.getWidth();
		mHeight					= pImage.getHeight();
		mCompression			= BI_RGB;
		mPlanes					= 1;//MDAR
		mHorizontalResolution	= 0xB12;
		mVerticalResolution		= 0xB12;
		mBitsPerPixel			= pImage.getColorDepth();
		mColorsUsed				= pImage.getColorNumber();

		if(mBitsPerPixel == 8)
		{
			if(mColorsUsed <= 2)
			{
				mBitsPerPixel = 1;
			}
			else if(mColorsUsed <= 16)
			{
				mBitsPerPixel = 4;
			}
		}
		switch(mBitsPerPixel)
		{
			case 1:
				filler			= (32-((getWidth())%32))%32;
				mSizeOfBitmap	= (getWidth()+filler)*getHeight()/8;
				break;
			case 4:
				filler			= (getWidth()%2==0) ? (4-(getWidth()/2)%4)%4 : (4-(getWidth()/2 +1)%4)%4;
				mSizeOfBitmap	= (getWidth()+filler)*getHeight()/2;
				break;
			case 8:
				filler			= (4-((getWidth())%4))%4;
				mSizeOfBitmap	= (getWidth()+filler)*getHeight();
				break;
			case 15:
			case 16:
			case 24:
				mBitsPerPixel	= 24;
				filler			= (4-((getWidth()*3)%4))%4;
				mColorsUsed		= 0;
				mSizeOfBitmap	= (getWidth()*3 + filler)*getHeight();
				break;
			case 32:
				mColorsUsed		= 0;
				mSizeOfBitmap	= (getWidth()*4)*getHeight();
				break;
		}
		mColorsImportant = mColorsUsed;
	}

	std::string ImageLoaderBmpInfoHeader::describe() const
	{
		std::stringstream out;
		out << "ImageLoaderBmpInfoHeader Descriptor"	<< std::endl;
		out << "size:                 "			<< mSize					<< std::endl;
		out << "width:                "			<< mWidth					<< std::endl;
		out << "height:               "			<< mHeight					<< std::endl;
		out << "planes:               "			<< mPlanes					<< std::endl;
		out << "bitsPerPixel:         "			<< mBitsPerPixel			<< std::endl;
		out << "compression:          "			<< mCompression				<< std::endl;
		out << "sizeOfBitmap:         "			<< mSizeOfBitmap			<< std::endl;
		out << "horizontalResolution: "			<< mHorizontalResolution	<< std::endl;
		out << "verticalResolution:   "			<< mVerticalResolution		<< std::endl;
		out << "colorsUsed:           "			<< mColorsUsed				<< std::endl;
		out << "colorsImportant:      "			<< mColorsImportant			<< std::endl;
		return out.str();
	}

	void ImageLoaderBmpInfoHeader::save(Core::File& pFile) const
	{
		pFile.writeInt32(mSize);
		pFile.writeInt32(mWidth);
		pFile.writeInt32(mHeight);
		pFile.writeInt16(mPlanes);
		pFile.writeInt16(mBitsPerPixel);
		pFile.writeInt32(mCompression);
		pFile.writeInt32(mSizeOfBitmap);
		pFile.writeInt32(mHorizontalResolution);
		pFile.writeInt32(mVerticalResolution);
		pFile.writeInt32(mColorsUsed);
		pFile.writeInt32(mColorsImportant);
	}

	void ImageLoaderBmpInfoHeader::load(Core::File& pFile)
	{
		mSize					= pFile.readInt32();
		mWidth					= pFile.readInt32();
		mHeight					= pFile.readInt32();
		mPlanes					= pFile.readInt16();
		mBitsPerPixel			= pFile.readInt16();
		mCompression			= pFile.readInt32();
		mSizeOfBitmap			= pFile.readInt32();
		mHorizontalResolution	= pFile.readInt32();
		mVerticalResolution		= pFile.readInt32();
		mColorsUsed				= pFile.readInt32();
		mColorsImportant		= pFile.readInt32();
	}

	unsigned long ImageLoaderBmpInfoHeader::getSize() const
	{
		return mSize;
	}

	unsigned long ImageLoaderBmpInfoHeader::getWidth() const
	{
		return mWidth;
	}

	unsigned long ImageLoaderBmpInfoHeader::getHeight() const
	{
		return mHeight;
	}

	unsigned short ImageLoaderBmpInfoHeader::getPlanes() const
	{
		return mPlanes;
	}

	unsigned short ImageLoaderBmpInfoHeader::getBpp() const
	{
		return mBitsPerPixel;
	}

	unsigned long ImageLoaderBmpInfoHeader::getCompression() const
	{
		/*Compression indicates the type of encoding method used to compress
		 * the bitmap data. 0 indicates that the data is uncompressed;
		 * 1 indicates that the 8-bit RLE algorithm was used;
		 * 2 indicates that the 4-bit RLE algorithm was used;
		 * 3 indicates that bitfields encoding was used.
		 * If the bitmap contains 16 or 32 bits per pixel,
		 * then only a Compression value of 3 is supported and the
		 * RedMask, GreenMask, and BlueMask fields will be present following
		 * the header in place of a color palette. If Compression is a value
		 * other than 3, then the file is identical to a Windows 3.x BMP file.
		 */
		return mCompression;
	}

	unsigned long ImageLoaderBmpInfoHeader::getSizeOfBitmap() const
	{
		return mSizeOfBitmap;
	}

	unsigned long ImageLoaderBmpInfoHeader::getHorizontalResolution() const
	{
		return mHorizontalResolution;
	}

	unsigned long ImageLoaderBmpInfoHeader::getVerticalResolution() const
	{
		return mVerticalResolution;
	}

	unsigned long ImageLoaderBmpInfoHeader::getColorsUsed() const
	{
		if(mColorsUsed == 0)
		{
			if(getBpp() >= 16)
			{
				return 1 << getBpp();
			}
			else
			{
				return 0;// /?
			}
		}
		return mColorsUsed;
	}

	unsigned long ImageLoaderBmpInfoHeader::getColorsImportant() const
	{
		return mColorsImportant;
	}

	unsigned int ImageLoaderBmpInfoHeader::getVersion() const
	{
		switch(mSize)
		{
			case 12:	return OS2_1;		//OS/2 1.x BMP
			case 40:	return Windows_3;	//Windows 3.x BMP and Windows NT BMP
			case 64:	return OS2_2;		//Windows 3.x BMP and Windows NT BMP
			case 108:	return Windows_4;	//Windows 4.x BMP
			default:	
				/**
				 * @todo lançar exceptions aki?
				 */
				return 0;// ?
		}
	}
}

