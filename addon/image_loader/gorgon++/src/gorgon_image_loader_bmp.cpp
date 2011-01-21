#include "../include/gorgon_image_loader_bmp.hpp"
#include <gorgon++/graphic/gorgon_image.hpp>

namespace Gorgon
{
	/**
	 * @todo verificar as comparações de little endian de leitura e escrita dos dados
	 */
	
	void ImageLoaderBmp::loadPalette
	(
		Image& pImage,
		ImageLoaderBmpHeader& pHeader,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		int nCol;
		if(pInfoHeader.getVersion() == OS2_1)
		{
			nCol			= (pHeader.getBitmapOffset() - 26) / 3;
			pImage.mPalette	= new Palette(pFile,nCol,0);
		}
		else if(pInfoHeader.getVersion() == Windows_3 && pInfoHeader.getCompression() != BI_BITFIELDS)
		{
			nCol			= (pHeader.getBitmapOffset() - 54) / 4;
			pImage.mPalette	= new Palette(pFile,nCol,1);
		}
		if(pImage.getPalette())
		{
			pImage.getPalette()->switchBlueForRed();
			pImage.getPalette()->inverse(nCol);
		}
	}

	void ImageLoaderBmp::loadUncompressed1BitData
	(
		Image& pImage,
		ImageLoaderBmpHeader& pHeader,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		unsigned char b[32];
		unsigned long pixels;
		int x, y, j, k;

		pImage.create(pInfoHeader.getWidth(),pInfoHeader.getHeight(),8);
		loadPalette(pImage,pHeader,pInfoHeader,pFile);
		for(y = pInfoHeader.getHeight()-1; y >= 0; --y)
		{
			for (x=0; x < pInfoHeader.getWidth(); ++x)
			{
				j = x % 32;
				if (j == 0)
				{
					pixels = pFile.readInt32();
					for (k = 0; k < 32; ++k)
					{
						b[31-k]	= (char)(pixels & 1);
						pixels	= pixels >> 1;
					}
				}
				/**
				 * @todo	Verificar se esse problema naum é causado por bytes little endian/big endian
				 * @details
				 *			Em modo monocromático os dados são guardados em conjuntos de
				 * 32 em 32, sendo que os 8 primeiros bits são na verdade os
				 * 8 últimos bits desse conjunto de 32, e os próximos 8 bits
				 * são os 8 antes dos 8 últimos e assim sucessitivamente O.o,
				 * não sei pq eles complicam as coisas aff
				 */
				k = ( (int)(j / 8) + 1) * 8;
				pImage.drawPixel
				(
					x,
					y,
					b[32-k+(j%8)]
				);
			}
		}
	}

	void ImageLoaderBmp::loadUncompressed4BitData
	(
		Image& pImage,
		ImageLoaderBmpHeader& pHeader,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		unsigned char b[8];
		unsigned long pixels = 0;
		int x, y, j, k;
		int temp;

		pImage.create(pInfoHeader.getWidth(),pInfoHeader.getHeight(),8);
		loadPalette(pImage,pHeader,pInfoHeader,pFile);
		for(y = pInfoHeader.getHeight() - 1; y >= 0; --y)
		{
			for(x = 0; x < pInfoHeader.getWidth(); ++x)
			{
				j = x % 8;
				if (j == 0)
				{
					pixels = pFile.readInt32();
					for (k = 0; k < 4; k++)
					{
						/**
						 * @todo verificar byte order
						 */
						temp		= pixels & 255;
						b[k*2+1]	= temp & 15;
						temp		= temp >> 4;
						b[k*2]		= temp & 15;
						pixels		= pixels >> 8;
					}
				}
				pImage.drawPixel(x,y,b[j]);
			}
		}
	}

	void ImageLoaderBmp::loadUncompressed8BitData
	(
		Image& pImage,
		ImageLoaderBmpHeader& pHeader,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		int x, y;
		unsigned char m;
		int filler = (4 - ( pInfoHeader.getWidth() % 4 ) ) % 4;

		pImage.create(pInfoHeader.getWidth(),pInfoHeader.getHeight(),8);
		loadPalette(pImage,pHeader,pInfoHeader,pFile);
		for(y = pInfoHeader.getHeight() - 1; y >= 0; --y)
		{
			for (x = 0; x < pInfoHeader.getWidth(); ++x)
			{
				m = pFile.readInt8();
				pImage.drawPixel(x,y,m);
			}
			pFile.ignore(filler);
		}
	}

	void ImageLoaderBmp::loadUncompressed24BitData
	(
		Image& pImage,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		int x, y;
		unsigned char r,g,b;
		int filler = (4 - ((pInfoHeader.getWidth() * 3) % 4)) % 4;
		
		pImage.create(pInfoHeader.getWidth(),pInfoHeader.getHeight(),32);
		for(y = pInfoHeader.getHeight() - 1; y >= 0; --y)
		{
			for (x = 0; x < pInfoHeader.getWidth(); ++x)
			{
				/**
				 * @todo tentar colocar isso direto no metodo abaixo
				 */
				r = pFile.readInt8();
				g = pFile.readInt8();
				b = pFile.readInt8();
				/**
				 * @todo verificar byte order
				 */
				pImage.drawPixel
				(
					x,
					y,
					(
						(r << 0) |
						(g << 8) |
						(b << 16)
					)
				);
			}
			pFile.ignore(filler);
		}
	}

	void ImageLoaderBmp::loadUncompressed32BitData
	(
		Image& pImage,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		int x,y;
		unsigned char r,g,b,a;
		pImage.create(pInfoHeader.getWidth(),pInfoHeader.getHeight(),32);
		for(y = pInfoHeader.getHeight() - 1; y >= 0; --y)
		{
			for(x = 0; x < pInfoHeader.getWidth(); ++x)
			{
				/*
				 * @todo tentar colocar isso direto no método abaixo
				 */
				r = pFile.readInt8();
				g = pFile.readInt8();
				b = pFile.readInt8();
				a = pFile.readInt8();
				/*
				 * @todo verificar byte order
				 */
				pImage.drawPixel
				(
					x,
					y,
					(
						(r << 0)	|
						(g << 8)	|
						(b << 16)	|
						(a << 24)
					)
				);
			}
		}
	}

	void ImageLoaderBmp::loadUncompressedData
	(
		Image& pImage,
		ImageLoaderBmpHeader& pHeader,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		switch(pInfoHeader.getBpp())
		{
			case 1:		loadUncompressed1BitData(pImage,pHeader,pInfoHeader,pFile);	break;
			case 4:		loadUncompressed4BitData(pImage,pHeader,pInfoHeader,pFile);	break;
			case 8:		loadUncompressed8BitData(pImage,pHeader,pInfoHeader,pFile);	break;
			case 16:	throw ImageLoaderBmpException("Unable to load ImageLoaderBmp with 16 bpp yet."); break;
			case 24:	loadUncompressed24BitData(pImage,pInfoHeader,pFile);		break;
			case 32:	loadUncompressed32BitData(pImage,pInfoHeader,pFile);		break;
		}
		pImage.updateBuffer();
	}

	void ImageLoaderBmp::loadRLE8CompressedData(Image& pImage,Core::File& pFile) const		{}
	void ImageLoaderBmp::loadRLE4CompressedData(Image& pImage,Core::File& pFile) const		{}
	void ImageLoaderBmp::loadBitFieldsCompressedData(Image& pImage,Core::File& pFile)	const	{}

	void ImageLoaderBmp::load
	(
		Image&		pImage,
		Core::File&	pFile,
		const int&	pSizeOfImage
	) const
	{
		pImage.mImgLinked	= false;
		ImageLoaderBmpHeader		header;
		ImageLoaderBmpInfoHeader	infoHeader;
		header.load(pFile);//carrega o header
		if(header.isValid())
		{
			infoHeader.load(pFile);//carrega o info header
			if(infoHeader.getVersion() != 3)
			{
				throw ImageLoaderBmpException("Unable to load ImageLoaderBmp diferent than 3.x. Until now.");
			}
			switch(infoHeader.getCompression())
			{
				case BI_RGB:		loadUncompressedData(pImage,header,infoHeader,pFile);			break;/*
				case BI_RLE8:		loadRLE8CompressedData(pImage,pFile);		break;
				case BI_RLE4:		loadRLE4CompressedData(pImage,pFile);		break;
				case BI_BITFIELDS:	loadBitFieldsCompressedData(pImage,pFile);	break;*/
				default:
					throw ImageLoaderBmpException("Unable to load ImageLoaderBmp due to unknown compression.");
			}
		}
		else
		{
			throw ImageLoaderBmpException("Unable to load ImageLoaderBmp due to incorrect format.");
		}
	}

	void ImageLoaderBmp::load(Image& pImage,const std::string& pImageName) const
	{
		Core::File file(pImageName,std::ios::in | std::ios::binary);

		if(file.is_open())
		{
			load(pImage,file,0);
		}
		else
		{
			throw ImageLoaderBmpException("Unable to load ImageLoaderBmp: "+pImageName+".");
		}
	}

	void ImageLoaderBmp::savePalette
	(
		Image& pImage,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		int			nCol= pInfoHeader.getColorsUsed();
		Palette*	pal	= pImage.getPalette()->copy();
		pal->switchBlueForRed();
		pal->inverse(nCol);
		if(pInfoHeader.getVersion() == OS2_1)
		{
			pal->save(pFile,nCol,0);
		}
		else if(pInfoHeader.getVersion() == Windows_3 && pInfoHeader.getCompression() != BI_BITFIELDS)
		{
			pal->save(pFile,nCol,1);
		}
		delete pal;
	}

	void ImageLoaderBmp::saveUncompressed1BitData
	(
		Image& pImage,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		unsigned long pixel;
		int x, y, j, k;
		int aux;

		for(y = pInfoHeader.getHeight()-1; y >= 0; --y)
		{
			for (x = 0; x < pInfoHeader.getWidth(); x+=32)
			{
				for(j = pixel = 0; j < 32; ++j)
				{
					k		= ((int)(j/8)+1)*8;
					aux		= pImage.getPixel
					(
						x + ( 32 - k + (j%8)),
						y,
						true
					);
					if(aux == -1)
					{
						aux = 0;
					}
					pixel	= (pixel << 1) | aux;
				}
				/**
				 * @todo verificar isso
				 * @todo imagens bmp quando salvam em 1 bit não estão salvando
				 * corretamente, talvez seja o problema de little endian ou big endian???
				 */
//				std::cout << " 1bit: " << pixel << std::endl;
				pFile.writeInt32(pixel);
				//pFile->write((char*)&pixel,4);
			}
		}
	}
	/**
	 * @todo esse método não está salvando corretamente, tem que reorganizar a paleta de cores
	 */
	void ImageLoaderBmp::saveUncompressed4BitData
	(
		Image& pImage,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		int x, y;
		char pixel1;
		char pixel2;
		char pixels;
		int filler = (pImage.getWidth() % 2 == 0) ? (4 - (pImage.getWidth() / 2) % 4) % 4 : (4 - (pImage.getWidth() / 2 + 1) %4 ) % 4;

		for(y = pInfoHeader.getHeight() - 1; y >= 0; --y)
		{
			for(x = 0; x < pInfoHeader.getWidth(); x+=2)
			{
				pixels = 0;
				pixel1 = pImage.getPixel(x,y,true);
				if(x+1 < pInfoHeader.getWidth())
				{
					pixel2 = pImage.getPixel(x+1,y,true);
					pixels = ((pixel1 << 4) | (pixel2 ));
				}
				else
				{
					pixels = ((pixel1 << 4));
				}
				//pFile->write(&pixels,1);
				pFile.writeInt8(pixels);
			}
			pFile.write((char*)&filler,filler);
		}
	}

	void ImageLoaderBmp::saveUncompressed8BitData
	(
		Image& pImage,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		int x, y;
		char pixel;
		int filler = (4 - ((pImage.getWidth()) % 4)) % 4;

		for(y = pInfoHeader.getHeight() - 1; y >= 0; --y)
		{
			for (x = 0; x < pInfoHeader.getWidth(); ++x)
			{
				/**
				 * @todo verificar se é realmente necessário o casting de char ali
				 */
				pixel = (char)pImage.getPixel(x,y,true);
				//pFile->write(&pixel,1);
				pFile.writeInt8(pixel);
			}
			/**
			 * bmp só aceita conjunto de 4 em 4 bytes, por isso completamos
			 * oq falta
			 */
			pFile.write((char*)&filler,filler);
		}
	}

	void ImageLoaderBmp::saveUncompressed24BitData(Image& pImage, Core::File& pFile) const
	{
		int x, y;
		int pixel;
		int filler = (4 - ((pImage.getWidth() * 3) % 4)) % 4;

		for(y = pImage.getHeight() - 1; y >= 0; --y)
		{
			for (x = 0; x < pImage.getWidth(); ++x)
			{
				pixel = pImage.getPixel(x,y,true);
				pFile.writeInt8((pixel >> 0)	& 0xFF);
				pFile.writeInt8((pixel >> 8)	& 0xFF);
				pFile.writeInt8((pixel >> 16)	& 0xFF);
			}
			pFile.write((char*)&filler,filler);
		}
	}

	void ImageLoaderBmp::saveUncompressed32BitData(Image& pImage, Core::File& pFile) const
	{
		int x, y;
		int pixel;

		for(y = pImage.getHeight() - 1; y >= 0; --y)
		{
			for (x = 0; x < pImage.getWidth(); ++x)
			{
				pixel = pImage.getPixel(x,y,true);
				/**
				 * @todo verificar littleendian ou big enddian aki
				 */
				pFile.writeInt8((pixel >> 0)	& 0xFF);
				pFile.writeInt8((pixel >> 8)	& 0xFF);
				pFile.writeInt8((pixel >> 16)	& 0xFF);
				pFile.writeInt8((pixel >> 24)	& 0xFF);
			}
		}
	}

	void ImageLoaderBmp::saveUncompressedData
	(
		Image& pImage,
		ImageLoaderBmpInfoHeader& pInfoHeader,
		Core::File& pFile
	) const
	{
		switch(pInfoHeader.getBpp())
		{
			case 1:
				savePalette(pImage,pInfoHeader,pFile);
				saveUncompressed1BitData(pImage,pInfoHeader,pFile);
				break;
			case 4:
				savePalette(pImage,pInfoHeader,pFile);
				saveUncompressed4BitData(pImage,pInfoHeader,pFile);
				break;
			case 8:
				savePalette(pImage,pInfoHeader,pFile);
				saveUncompressed8BitData(pImage,pInfoHeader,pFile);
				break;
			case 24:
				saveUncompressed24BitData(pImage,pFile);
				break;
			case 32:
				saveUncompressed32BitData(pImage,pFile);
				break;
		}
	}

	void ImageLoaderBmp::save(Image& pImage,const std::string& pImageName) const
	{
		Core::File file(pImageName,std::ios::out | std::ios::binary);

		if(file.is_open())
		{
			save(pImage,file);
		}
		else
		{
			throw ImageLoaderBmpException("Unable to save ImageLoaderBmp: "+pImageName+".");
		}
	}

	void ImageLoaderBmp::save(Image& pImage, Core::File& pFile) const
	{
		ImageLoaderBmpHeader		header;
		ImageLoaderBmpInfoHeader	infoHeader;
		infoHeader.fill(pImage);
		header.fill(infoHeader);
		header.save(pFile);//salva o header
		infoHeader.save(pFile);//salva o info header

		switch(infoHeader.getCompression())
		{
			case BI_RGB: 		saveUncompressedData(pImage,infoHeader,pFile);			break;
			/*case BI_RLE8:		saveRLE8CompressedData(pImage,file);		break;
			case BI_RLE4:		saveRLE4CompressedData(pImage,file);		break;
			case BI_BITFIELDS:	saveBitFieldsCompressedData(pImage,file);	break;*/
			default:
				throw ImageLoaderBmpException("Unable to save ImageLoaderBmp due to unknown compression.");
		}
	}
}
