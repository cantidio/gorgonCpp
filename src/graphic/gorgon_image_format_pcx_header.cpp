#include "graphic/gorgon_image_format_pcx_header.hpp"
#include "graphic/gorgon_image.hpp"

namespace Gorgon
{

	ImageFormatPcxHeader::ImageFormatPcxHeader()
	{
		mPalette = new Palette();
	}

	ImageFormatPcxHeader::~ImageFormatPcxHeader()
	{
		delete mPalette;
	}

	int ImageFormatPcxHeader::getType() const
	{
		switch(getNumBitPlanes())
		{
			case 1:
				switch(getBitsPerPixel())
				{
					case 1: return ImageFormatPcx1Bit;
					case 8:	return ImageFormatPcx8Bit;
				}
				break;
			case 3:
				return ImageFormatPcx24Bit;
				break;
			case 4:
				return ImageFormatPcx4Bit;
				break;
			default:
				return -1;
		}
	}

	void ImageFormatPcxHeader::fill(const Image& pImage)
	{
		mXStart			= 0;
		mYStart			= 0;
		mXEnd			= pImage.getWidth() - 1;
		mYEnd			= pImage.getHeight() - 1;
		mHRes			= 320;
		mVRes			= 200;
		mPaletteType	= 1;

		if(pImage.getColorDepth() == 8 && pImage.getColorNumber() < 17)
		{
			mBitsPerPixel	= 1;
			mNumBitPlanes	= 4;
			mBytesPerLine	= (getWidth() % 2 == 0) ? getWidth()/8 : getWidth()/8+1;
			delete mPalette;
			mPalette 		= pImage.getPalette()->copy();
		}
		else
		{
			mBitsPerPixel	= 8;
			mNumBitPlanes	= (pImage.getColorDepth() == 8) ? 1 : 3;
			mBytesPerLine	= pImage.getWidth();
		}
	}

	std::string ImageFormatPcxHeader::describe() const
	{
		std::stringstream out;
		out << "PcxHeader Descriptor"	<< std::endl;
		out << "identifier:   " << (int)mIdentifier				<< std::endl;
		out << "version:      " << (int)mVersion				<< std::endl;
		out << "Encoding:     " << (int)mEncoding				<< std::endl;
		out << "BitsPerPixel: " << getBitsPerPixel()			<< std::endl;
		out << "xStart:       " << mXStart						<< std::endl;
		out << "yStart:       " << mYStart						<< std::endl;
		out << "xEnd:         " << mXEnd						<< std::endl;
		out << "yEnd:         " << mYEnd						<< std::endl;
		out << "hRes:         " << mHRes						<< std::endl;
		out << "vRes:         " << mVRes						<< std::endl;
		out << "numBitPlanes: " << (unsigned int)mNumBitPlanes	<< std::endl;
		out << "bytesPerLine: " << (int)mBytesPerLine			<< std::endl;
		out << "paletteType:  " << (int)mPaletteType			<< std::endl;
		return out.str();
	}
	
	int ImageFormatPcxHeader::getWidth() const
	{
		return mXEnd - mXStart + 1;
	}

	int ImageFormatPcxHeader::getHeight() const
	{
		return mYEnd - mYStart + 1;
	}

	int ImageFormatPcxHeader::getBitsPerPixel() const
	{
		return (int)mBitsPerPixel;
	}

	int ImageFormatPcxHeader::getNumBitPlanes() const
	{
		return (int)mNumBitPlanes;
	}

	int ImageFormatPcxHeader::getBytesPerLine() const
	{
		return (int)mBytesPerLine;
	}

	Palette* ImageFormatPcxHeader::getPalette() const
	{
		return mPalette->copy();
	}

	void ImageFormatPcxHeader::save(Core::File& pFile) const
	{
		pFile.put(0x0A);//10
		pFile.put(5);
		pFile.put(1);
		pFile.put(mBitsPerPixel);
		pFile.write((char*)&mXStart,	sizeof(short));
		pFile.write((char*)&mYStart,	sizeof(short));
		pFile.write((char*)&mXEnd,		sizeof(short));
		pFile.write((char*)&mYEnd,		sizeof(short));
		pFile.write((char*)&mHRes,		sizeof(short));//320
		pFile.write((char*)&mVRes,		sizeof(short));//200
		
		mPalette->inverse(16);
		mPalette->save(pFile,16);
		mPalette->inverse(16);
		
		pFile.put(0);
		pFile.put(mNumBitPlanes);
		pFile.write((char*)&mBytesPerLine,sizeof(short));
		pFile.write((char*)&mPaletteType, sizeof(short));
		pFile.write("Pcx image saved using Gorgon Api.",58);
	}

	void ImageFormatPcxHeader::load(Core::File& pFile)
	{
		mIdentifier		= pFile.readInt8();
		mVersion		= pFile.readInt8();
		mEncoding		= pFile.readInt8();
		mBitsPerPixel	= pFile.readInt8();
		mXStart			= pFile.readInt16();
		mYStart			= pFile.readInt16();
		mXEnd			= pFile.readInt16();
		mYEnd			= pFile.readInt16();
		mHRes			= pFile.readInt16();
		mVRes			= pFile.readInt16();
		mPalette->load(pFile,16);
		mPalette->inverse(16);
		pFile.ignore(1);
		mNumBitPlanes	= pFile.readInt8();
		mBytesPerLine	= pFile.readInt16();
		mPaletteType	= pFile.readInt16();
		pFile.ignore(58);
	}

	bool ImageFormatPcxHeader::isValid() const
	{
		if(mIdentifier != 0x0A)
		{
			return false;
		}
		return true;
	}

	long ImageFormatPcxHeader::getImageSize() const
	{
		return getNumBitPlanes() * getBytesPerLine() * getHeight() + 128;
	}
}
