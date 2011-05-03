#include <graphic/gorgon_palette.hpp>

namespace Gorgon{
namespace Graphic
{
	Palette::Palette()
	{
		erase();
	}

	Palette::Palette
	(
		const int& pRed,
		const int& pGreen,
		const int& pBlue
	)
	{
		for(int i = 0; i < 256; ++i)
		{
			setRed(pRed,i);
			setGreen(pGreen,i);
			setBlue(pBlue,i);
		}
	}

	Palette::Palette(const std::string& pPaletteName)
	{
		erase();
		load(pPaletteName,256);
	}

	Palette::Palette
	(
		Core::File&	pFile,
		const int&	pColorNumber,
		const int&	pJumpBytes
	)
	{
		erase();
		load
		(
			pFile,
			pColorNumber,
			pJumpBytes
		);
	}

	Palette::~Palette()
	{
		erase();
	}

	std::string Palette::describe() const
	{
		std::stringstream out;
		out << "Palette Descriptor\n";
		for(int i=0; i<256; ++i)
		{
			out << i << "\tr:" << (int)mPal[i].r << "\tg: " << (int)mPal[i].g << "\tb: " << (int)mPal[i].b << "\n";
		}
		return out.str();
	}

	Palette* Palette::copy() const
	{
		Palette* aux;
		aux = new Palette();

		for(int i = 0; i < 256; ++i)
		{
			aux->setColor
			(
				getRed(i),
				getGreen(i),
				getBlue(i),
				i
			);
		}
		return aux;
	}

	void Palette::erase()
	{
		for(int i=0; i<256; i++)
		{
			mPal2[i].r = mPal[i].r = 0;
			mPal2[i].g = mPal[i].g = 0;
			mPal2[i].b = mPal[i].b = 0;
		}
	}

	void Palette::set() const
	{
		set_palette(mPal2);
	}

	void Palette::get()
	{
		get_palette(mPal2);

		for(int i = 0; i < 256; ++i)
		{
			mPal[i].r = mPal2[i].r * 4;
			mPal[i].g = mPal2[i].g * 4;
			mPal[i].b = mPal2[i].b * 4;
		}
	}

	void Palette::inverse(const int& pColorNumber)
	{
		RGB aux;
		for(int i=0, j = pColorNumber-1; i <= (pColorNumber/2)-1; ++i,--j)
		{
			aux			= mPal[i];
			mPal[i]		= mPal[j];
			mPal[j]		= aux;
			aux			= mPal2[i];
			mPal2[i]	= mPal2[j];
			mPal2[j]	= aux;
		}
	}

	void Palette::switchBlueForRed()
	{
		unsigned char red;
		for(int i = 0; i < 256; ++i)
		{
			red = getRed(i);
			setRed(getBlue(i),i);
			setBlue(red,i);
		}
	}

	void Palette::switchBlueForGreen()
	{
		unsigned char green;
		for(int i = 0; i < 256; ++i)
		{
			green = getGreen(i);
			setGreen(getBlue(i),i);
			setBlue(green,i);
		}
	}

	void Palette::switchRedForGreen()
	{
		unsigned char green;
		for(int i = 0; i < 256; ++i)
		{
			green = getGreen(i);
			setGreen(getRed(i),i);
			setRed(green,i);
		}
	}

	int Palette::getColor(const int& pPos) const
	{
		if(pPos<256)
			return makecol
			(
				mPal[pPos].r,
				mPal[pPos].g,
				mPal[pPos].b
			);
		else
	 		return 0xFF00FF;// makecol(255,0,255);
	}

	int Palette::getRed(const int& pPos) const
	{
		if(pPos < 256)
		{
			return mPal[pPos].r;
		}
		else
		{
			/**
			 * @todo	retornar excessão ?
			 */
			return 0;
		}
	}

	int Palette::getGreen(const int& pPos) const
	{
		if(pPos < 256)
		{
			return mPal[pPos].g;
		}
		else
		{
			/**
			 * @todo	retornar excessão ?
			 */
			return 0;
		}
	}

	int Palette::getBlue(const int& pPos) const
	{
		if(pPos < 256)
		{
			return mPal[pPos].b;
		}
		else
		{
			/**
			 * @todo	retornar excessão ?
			 */
			return 0;
		}
	}

	void Palette::setColor
	(
		const int& pRed,
		const int& pGreen,
		const int& pBlue,
		const int& pPos
	)
	{
		setRed(pRed, pPos);
		setGreen(pGreen, pPos);
		setBlue(pBlue, pPos);
	}

	void Palette::setRed(const int& pRed,const int& pPos)
	{
		if(pPos < 256 && pPos >= 0)
		{
			mPal[pPos].r	= pRed;
			mPal2[pPos].r	= pRed/4;
		}
	}

	void Palette::setGreen(const int& pGreen,const int& pPos)
	{
		if(pPos < 256 && pPos >= 0)
		{
			mPal[pPos].g	= pGreen;
			mPal2[pPos].g	= pGreen/4;
		}
	}

	void Palette::setBlue(const int& pBlue,const int& pPos)
	{
		if(pPos < 256 && pPos >= 0)
		{
			mPal[pPos].b	= pBlue;
			mPal2[pPos].b	= pBlue/4;
		}
	}

	void Palette::save
	(
		Core::File&	pFile,
		const int&	pColorNumber,
		const int&	pJumpBytes
	) const
	{
		unsigned char filler = 0;
		for(int i = pColorNumber -1; i >= 0; i--)
		{
			pFile.writeInt8(getRed(i));
			pFile.writeInt8(getGreen(i));
			pFile.writeInt8(getBlue(i));

			if(pJumpBytes > 0)
			{
				pFile.write( (char*)&filler, pJumpBytes );
			}
		}
	}

	void Palette::save(const std::string& pPaletteName, const int& pColorNumber) const
	{
		Core::File file(pPaletteName,std::ios::out | std::ios::binary);
		if(file.is_open())
		{
			save
			(
				file,
				pColorNumber,
				0
			);
		}
		else
		{
			throw Core::Exception("Unable to save palette: "+pPaletteName);
		}
	}

	void Palette::load
	(
		Core::File&	pFile,
		const int&	pColorNumber,
		const int&	pJumpBytes
	)
	{
		for(int i = (pColorNumber-1); i >= 0; --i)
		{
			setRed	(pFile.readUnsignedInt8(), i);
			setGreen(pFile.readUnsignedInt8(), i);
			setBlue	(pFile.readUnsignedInt8(), i);
			if(pJumpBytes > 0)
			{
				pFile.ignore(pJumpBytes);
			}
		}
	}

	void Palette::load(const std::string& pPaletteName,const int& pColorNumber)
	{
		Core::File file(pPaletteName,std::ios::in|std::ios::binary);
		if(file.is_open())
		{
			load
			(
				file,
				pColorNumber,
				0
			);
		}
		else
		{
			throw Core::Exception("Unable to load palette: "+pPaletteName+".");
		}
		
	}
}}
