#include "../include/gorgon_image_loader_pcx.hpp"
#include <gorgon++/graphic/gorgon_image.hpp>

namespace Gorgon
{
	void ImageLoaderPcx::loadEncoded1BitData
	(
		Graphic::Image& pImage,
		ImageLoaderPcxHeader& pHeader,
		Core::File& pFile
	) const
	{
		unsigned int x,y,j;
		char value;
		int count;

		pImage.create
		(
			pHeader.getWidth(),
			pHeader.getHeight(),
			8
		);
		for (y = 0; y < pHeader.getHeight(); ++y)
		{
			x = 0;
			j = 0;
			while (j < pHeader.getBytesPerLine())
			{
				value = pFile.readInt8();
				if ((value & 0xc0) == 0xc0)//0b11000000
				{
					count = 0;
					count = value & 0x3f;
					value = pFile.readInt8();
					j+=2;
				}
				else
				{
					count = 1;
				}
				while (count > 0)
				{
					for(unsigned int i = 0; i < 8 && x < pImage.getWidth(); ++i,++x)
					{
						pImage.drawPixel(x,y,((value >> (7-i)) & 1));
					}
					if(x == pImage.getWidth())
					{
						break; 
					}
					--count;
				}
				if(x == pImage.getWidth())
				{
					break; 
				}
			}
		}
	}

	void ImageLoaderPcx::loadEncoded4BitData
	(
		Graphic::Image& pImage,
		ImageLoaderPcxHeader& pHeader,
		Core::File& pFile
	) const
	{
		int x,y,j;
		int count;
		char value;
		
		unsigned char color[pHeader.getBytesPerLine() * 32 + 1];
		int plane1 = 0;
		int plane2 = pHeader.getBytesPerLine() * 8;
		int plane3 = pHeader.getBytesPerLine() * 16;
		int plane4 = pHeader.getBytesPerLine() * 24;

		pImage.create
		(
			pHeader.getWidth(),
			pHeader.getHeight(),
			8
		);
		for (y = 0; y < pHeader.getHeight(); ++y)
		{
			x = 0;
			j = 0;
			while (x < pHeader.getBytesPerLine() * 32)
			{
				value = pFile.readInt8();
				if ((value & 0xc0) == 0xc0)
				{
					count = 0;
					count = value & 0x3f;
					value = pFile.readInt8();
				}
				else
				{
					count = 1;
				}
				while (count > 0)
				{
					for(int i = 0; i < 8 && x < pHeader.getBytesPerLine() * 32; ++i,++x)
					{
						color[x] = ((value >> (7-i)) & 1);
					}
					--count;
				}
			}
			for(x = 0; x < pImage.getWidth(); ++x)
			{
				/**
				 * @todo verificar little endian
				 */
				pImage.drawPixel
				(
					x,
					y,
					(
						(color[x + plane1] << 0) |
						(color[x + plane2] << 1) |
						(color[x + plane3] << 2) |
						(color[x + plane4] << 3)
					)
				);
			}
		}
	}

	void ImageLoaderPcx::loadEncoded8BitData
	(
		Graphic::Image& pImage,
		ImageLoaderPcxHeader& pHeader,
		Core::File& pFile
	) const
	{
		int x,y;
		int value;
		int count;

		pImage.create
		(
			pHeader.getWidth(),
			pHeader.getHeight(),
			8
		);

		for (y = 0; y < pHeader.getHeight(); ++y)
		{
			x = 0;
			while (x < pHeader.getBytesPerLine())
			{
				value = pFile.readInt8();
				if ((value & 0xc0) == 0xc0)
				{
					count = value & 0x3f;
					value = pFile.readInt8();
				}
				else
				{
					count = 1;
				}
				while (count > 0)
				{
					if (x < pImage.getWidth())
					{
						pImage.drawPixel(x,y,value);
					}
					++x;
					--count;
				}
			}
		}
	}

	void ImageLoaderPcx::loadEncoded24BitData
	(
		Graphic::Image& pImage,
		ImageLoaderPcxHeader& pHeader,
		Core::File& pFile
	) const
	{
		int x,y;
		int count;
		char value;
		unsigned char color[pHeader.getWidth() * 3 + 1];
		int r = 0;
		int g = pHeader.getBytesPerLine();
		int b = pHeader.getBytesPerLine() * 2;
		
		pImage.create
		(
			pHeader.getWidth(),
			pHeader.getHeight(),
			32
		);
		for (y = 0; y < pHeader.getHeight(); ++y)
		{
			x = 0;
			while (x < pHeader.getBytesPerLine()*3)
			{
				value = pFile.readInt8();
				if ((value & 0xc0) == 0xc0)
				{
					count = value & 0x3f;
					value = pFile.readInt8();
				}
				else
				{
					count = 1;
				}
				while (count > 0)
				{
					if (x < pImage.getWidth()*3)
					{
						color[x]=(int)value;
					}
					++x;
					--count;
				}
			}
			for(x = 0; x < pImage.getWidth(); ++x)
			{
				/**
				 * @todo verificar byte order
				 */
				pImage.drawPixel
				(
					x,
					y,
					(
						((color[x + b]) << 0) |
						((color[x + g]) << 8) |
						((color[x + r]) << 16)
					)
				);
			}
		}
	}

	void ImageLoaderPcx::loadEncodedData
	(
		Graphic::Image& pImage,
		ImageLoaderPcxHeader& pHeader,
		Core::File& pFile
	) const
	{
		switch(pHeader.getType())
		{
			case ImageLoaderPcx1Bit:	loadEncoded1BitData(pImage,pHeader,pFile);	break;
			case ImageLoaderPcx4Bit:	loadEncoded4BitData(pImage,pHeader,pFile);	break;
			case ImageLoaderPcx8Bit:	loadEncoded8BitData(pImage,pHeader,pFile);	break;
			case ImageLoaderPcx24Bit:	loadEncoded24BitData(pImage,pHeader,pFile); break;
			default:
				throw ImageLoaderPcxException("Unable to load ImageLoaderPcx due to unknown image compression.");
		}
	}

	void ImageLoaderPcx::loadPaletteData
	(
		Graphic::Image& pImage,
		ImageLoaderPcxHeader& pHeader,
		Core::File& pFile
	) const
	{
		if(pHeader.getType() == ImageLoaderPcx1Bit)
		{
			pImage.setPalette(new Graphic::Palette(),true);
			pImage.getPalette()->setColor(0,0,0,0);
			pImage.getPalette()->setColor(255,255,255,1);
		}
		else
		{
			if((int)pFile.readInt8() == 12)//we got a palette
			{
				pImage.setPalette(new Graphic::Palette(pFile),true);
				pImage.getPalette()->inverse();
			}
			else
			{
				pImage.setPalette(pHeader.getPalette(),true);
			}
		}
	}

	void ImageLoaderPcx::load(Graphic::Image& pImage,const std::string& pImageName) const
	{
		Core::File file(pImageName,std::ios::in | std::ios::binary);

		if(file.is_open())
		{
			load(pImage,file,0);
		}
		else
		{
			throw ImageLoaderPcxException("Unable to load ImageLoaderPcx: "+pImageName+".");
		}
	}

	void ImageLoaderPcx::load
	(
		Graphic::Image&	pImage,
		Core::File&		pFile,
		const int&		pSizeOfImage
	) const
	{
		ImageLoaderPcxHeader header;
		header.load(pFile);
		if(header.isValid())
		{
			loadEncodedData(pImage,header,pFile);
			loadPaletteData(pImage,header,pFile);
			pImage.updateBuffer();
		}
		else
		{
			throw ImageLoaderPcxException("Unable to load ImageLoaderPcx due to incorrect format.");
		}
	}

	void ImageLoaderPcx::saveEncoded4BitData
	(
		Graphic::Image& pImage,
		ImageLoaderPcxHeader& pHeader,
		Core::File& pFile
	) const
	{
		int		x,y,pixel,pixelBit,plane,count;
		char	value, savePixel;

		for (y = 0; y < pHeader.getHeight(); ++y)
		{
			count		= 0;
			savePixel	= 0;

			for(x = 0; x < pHeader.getBytesPerLine() * 32; x+=8)
			{
				plane = x/(pHeader.getBytesPerLine() * 8);
				for(pixel=value=0; value<8; ++value)//mount 1 byte data
				{
					pixelBit = pImage.getPixel(x + value-(plane * pHeader.getBytesPerLine() * 8),y,true);
					pixel	 = (pixel << 1) | ((pixelBit >> plane) & 1);
				}

				if (count==0)
				{
					count 		= 1;
					savePixel	= pixel;
				}
				else
				{
					if ((pixel != savePixel) || (count >= 0x3f))
					{
						if ((count > 1) || ((savePixel & 0xC0) == 0xC0))
						{
							count=(0xC0 | count);
							pFile.writeInt8(count);
						}
						pFile.writeInt8(savePixel);
						count 		= 1;
						savePixel 	= pixel;
					}
					else
					{
						count++;
					}
				}
			}
			if ((count > 1) || ((savePixel & 0xC0) == 0xC0))
			{
				count = (0xC0 | count);
				pFile.writeInt8(count);
			}
			pFile.writeInt8(savePixel);
		}
	}

	void ImageLoaderPcx::saveEncoded8BitData(Graphic::Image& pImage, Core::File& pFile) const
	{
		char	pixel;
		char	savePixel;
		int 	count;
		unsigned int x, y;

		for (y = 0; y < pImage.getHeight(); ++y)
		{
			count		= 0;
			savePixel	= 0;
			for (x = 0; x < pImage.getWidth() * 3; ++x)
			{
				pixel = pImage.getPixel(x,y,true);
				if (count == 0)
				{
					count 		= 1;
					savePixel	= pixel;
				}
				else
				{
					if ((pixel != savePixel) || (count >= 0x3f))
					{
						if ((count > 1) || ((savePixel & 0xC0) == 0xC0))
						{
							count = (0xC0 | count);
							pFile.writeInt8(count);
						}
						pFile.writeInt8(savePixel);
						count 		= 1;
						savePixel 	= pixel;
					}
					else
					{
						++count;
					}
				}
			}
			if ((count > 1) || ((savePixel & 0xC0) == 0xC0))
			{
				count = (0xC0 | count);
				pFile.writeInt8(count);
			}
			pFile.writeInt8(savePixel);
		}
	}

	void ImageLoaderPcx::saveEncoded24BitData(Graphic::Image& pImage, Core::File& pFile) const
	{
		int				pixel;
		char			savePixel;
		int 			count;
		unsigned int	x, y;

		for (y = 0; y < pImage.getHeight(); ++y)
		{
			count		= 0;
			savePixel	= 0;

			for (x = 0; x < pImage.getWidth() * 3; ++x)
			{
				pixel = 0;
				if (x < pImage.getWidth())
				{
					pixel = pImage.getPixel(x,y,true);
					pixel = (pixel >> 16) & 255;
				}
				else if (x < pImage.getWidth() * 2)
				{
					pixel = pImage.getPixel(x - pImage.getWidth(),y,true);
					pixel = (pixel >> 8) & 255;
				}
				else
				{
					pixel = pImage.getPixel(x - pImage.getWidth()*2,y,true);
					pixel = (pixel) & 255;
				}
				if (count == 0)
				{
					count 		= 1;
					savePixel	= 0;
					savePixel	= pixel;
				}
				else
				{
					if ((pixel != savePixel) || (count >= 0x3f))
					{
						if ((count > 1) || ((savePixel & 0xC0) == 0xC0))
						{
							count = (0xC0 | count);
							pFile.writeInt8(count);
						}
						pFile.writeInt8(savePixel);
						count 		= 1;
						savePixel 	= pixel;
					}
					else
					{
						count++;
					}
				}
			}
			if ((count > 1) || ((savePixel & 0xC0) == 0xC0))
			{
				count = (0xC0 | count);
				pFile.writeInt8(count);
			}
			pFile.writeInt8(savePixel);
		}
	}

	void ImageLoaderPcx::saveEncodedData
	(
		Graphic::Image& pImage,
		ImageLoaderPcxHeader& pHeader,
		Core::File& pFile
	) const
	{
		switch(pHeader.getType())
		{
			case ImageLoaderPcx1Bit:	//saveEncoded1BitData(pImage,pHeader,file);	break;
			case ImageLoaderPcx4Bit:	saveEncoded4BitData(pImage,pHeader,pFile);	break;
			case ImageLoaderPcx8Bit:	saveEncoded8BitData(pImage,pFile);			break;
			case ImageLoaderPcx24Bit:	saveEncoded24BitData(pImage,pFile);			break;
			default:
				throw ImageLoaderPcxException("Unable to save ImageLoaderPcx due to unknown image compression.");
		}
	}

	void ImageLoaderPcx::savePaletteData
	(
		Graphic::Image& pImage,
		ImageLoaderPcxHeader& pHeader,
		Core::File& pFile
	) const
	{
		/**
		 *@todo verificar a necessidade de se passar o pHeader
		 */
		if
		(
			pHeader.getBitsPerPixel()	== 8 &&
			pHeader.getNumBitPlanes()	== 1 &&
			pImage.getPalette()			!= NULL
		)
		{
			pFile.writeInt8(12);
			pImage.getPalette()->inverse();
			pImage.getPalette()->save(pFile);
			pImage.getPalette()->inverse();
		}
	}

	void ImageLoaderPcx::save(Graphic::Image& pImage,const std::string& pImageName) const
	{
		Core::File file(pImageName,std::ios::out | std::ios::binary);

		if(file.is_open())
		{
			save(pImage,file);
		}
		else
		{
			throw ImageLoaderPcxException("Unable to save ImageLoaderPcx: "+pImageName+".");
		}
	}

	void ImageLoaderPcx::save(Graphic::Image& pImage, Core::File& pFile) const
	{
		ImageLoaderPcxHeader header;
		header.fill(pImage);
		header.save(pFile);
		/*mHeader.fill(pImage);
		mHeader.save(pFile);*/
		saveEncodedData
		(
			pImage,
			header,
			pFile
		);
		savePaletteData
		(
			pImage,
			header,
			pFile
		);
	}
}
