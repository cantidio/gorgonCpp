#include <graphic/palette.hpp>
#include <graphic/exception.hpp>
#include <sstream>

namespace Gorgon{
namespace Graphic
{
	Palette::Palette()
	{
		mColors			= NULL;
		mColorNumber	= 0;
	}

	Palette::Palette(const int& pColorNumber)
	{
		try
		{
			mColorNumber	= pColorNumber;
			mColors			= new float[mColorNumber * 3];
		}
		catch(std::exception& exception)
		{
			std::stringstream out;
			out << "Palette::Palette(" << pColorNumber << "): Error, could not allocate memory for the colors.";
			raiseGraphicException( out.str() );
		}
	}

	Palette::Palette( const std::string& pPaletteName, const int& pColorNumber, const int& pJumpBytes)
	{
		try
		{
			mColorNumber	= pColorNumber;
			mColors			= new float[mColorNumber * 3];

			load(pPaletteName, pColorNumber, pJumpBytes);
		}
		catch(std::exception& exception)
		{
			std::stringstream out;
			out << "Palette::Palette(\"" << pPaletteName << "\", "<< pColorNumber << ", " << pJumpBytes << "): Error, could not allocate memory for the colors.";

			raiseGraphicException( out.str() );
		}
		catch(Core::Exception& exception)
		{
			std::stringstream out;
			out << "Palette::Palette(\"" << pPaletteName << "\", "<< pColorNumber << ", " << pJumpBytes << "): Error, could not allocate memory for the colors.";

			raiseGraphicExceptionE( out.str() , exception );
		}

	}

	Palette::Palette( Core::File& pFile, const int& pColorNumber, const int& pJumpBytes )
	{
		try
		{
			mColorNumber	= pColorNumber;
			mColors			= new float[ mColorNumber * 3 ];

			load( pFile, pColorNumber, pJumpBytes );
		}
		catch(std::exception& exception)
		{
			std::stringstream out;
			out << "Palette::Palette(" << (int)&pFile << ", " << pColorNumber << ", " << pJumpBytes << "): Error, could not allocate memory for the colors.";

			raiseGraphicException( out.str() );
		}
		catch(Core::Exception& exception)
		{
			std::stringstream out;
			out << "Palette::Palette(\"" << (int)&pFile << ", "<< pColorNumber << ", " << pJumpBytes << "): Error, could not allocate memory for the colors.";

			raiseGraphicExceptionE( out.str() , exception );
		}
	}

	Palette::~Palette()
	{
		if(mColors != NULL)
		{
			delete mColors;
		}
	}

	std::string Palette::describe() const
	{
		const int allColors = mColorNumber * 3 ;

		std::stringstream out;
		out << "Graphic::Palette::describe()"	<< std::endl;
		out << "ColorNumber: " << mColorNumber	<< std::endl;
		for(register int i = 0; i < allColors ; i += 3)
		{
			out << "[" << i << "]";
			out << " R: " << (int)(mColors[i + 0] * 255.0f);
			out << " G: " << (int)(mColors[i + 1] * 255.0f);
			out << " B: " << (int)(mColors[i + 2] * 255.0f);
			out << std::endl;
		}
		return out.str();
	}

	Palette* Palette::clone() const
	{
		Palette* aux = new Palette( mColorNumber );

		for(register int i = (mColorNumber * 3) - 1; i >= 0 ; --i)
		{
			aux->mColors[i] = mColors[i];
		}
		return aux;
	}

	void Palette::erase()
	{
		for(register int i = (mColorNumber * 3) - 1; i >= 0 ; --i)
		{
			mColors[i] = 0.0f;
		}
	}

	void Palette::set() const
	{
		printf("Graphic::Palette::set() this method dont do nothing;\n");
	}

	void Palette::inverse()
	{
		const int middle 	= (mColorNumber * 3) / 2;
		float colorComponent;

		for(register int i = 0, j = (mColorNumber * 3) - 3; i < middle; i+=3, j-=3)
		{
			colorComponent = mColors[i + 0];//red
			mColors[i + 0] = mColors[j + 0];
			mColors[j + 0] = colorComponent;

			colorComponent = mColors[i + 1];//green
			mColors[i + 1] = mColors[j + 1];
			mColors[j + 1] = colorComponent;

			colorComponent = mColors[i + 2];//blue
			mColors[i + 2] = mColors[j + 2];
			mColors[j + 2] = colorComponent;
		}
	}

	void Palette::swapRedForGreen()
	{
		float green;
		for(register int i = mColorNumber*3 - 1; i >= 0 ; i-=3)
		{
			green			= mColors[i + 1];
			mColors[i + 1]	= mColors[i + 0];
			mColors[i + 0] = green;
		}
	}

	void Palette::swapGreenForBlue()
	{
		float blue;
		for(register int i = mColorNumber*3 - 1; i >= 0 ; i-=3)
		{
			blue			= mColors[i + 2];
			mColors[i + 2]	= mColors[i + 1];
			mColors[i + 1]	= blue;
		}
	}

	void Palette::swapBlueForRed()
	{
		float red;
		for(register int i = mColorNumber*3 - 1; i >= 0 ; i-=3)
		{
			red				= mColors[i + 0];
			mColors[i + 0]	= mColors[i + 2];
			mColors[i + 2]	= red;
		}
	}

	void Palette::save( Core::File& pFile, const int& pColorNumber, const int& pJumpBytes ) const
	{
		unsigned char filler = 0;
		for(register int i = pColorNumber - 1; i >= 0; i--)
		{
			pFile.writeInt8(getRed(i)	* 255.0f);
			pFile.writeInt8(getGreen(i)	* 255.0f);
			pFile.writeInt8(getBlue(i)	* 255.0f);

			if(pJumpBytes > 0)
			{
				pFile.write( (char*)&filler, pJumpBytes );
			}
		}
	}

	void Palette::save( const std::string& pPaletteName, const int& pColorNumber, const int& pJumpBytes ) const
	{
		Core::File file(pPaletteName,std::ios::out | std::ios::binary);
		if(file.is_open())
		{
			save( file, pColorNumber, pJumpBytes );
		}
		else
		{
			throw Core::Exception("Unable to save palette: "+pPaletteName);
		}
	}

	void Palette::load( Core::File&	pFile, const int& pColorNumber, const int& pJumpBytes )
	{
		for( register int i = (pColorNumber * 3 - 3); i >= 0; i -= 3 )
		{
			mColors[i + 0] = pFile.readUnsignedInt8() / 255.0f ;
			mColors[i + 1] = pFile.readUnsignedInt8() / 255.0f ;
			mColors[i + 2] = pFile.readUnsignedInt8() / 255.0f ;

			if(pJumpBytes > 0)
			{
				pFile.ignore(pJumpBytes);
			}
		}
	}

	void Palette::load(const std::string& pPaletteName,const int& pColorNumber, const int& pJumpBytes )
	{
		Core::File file(pPaletteName,std::ios::in|std::ios::binary);
		if(file.is_open())
		{
			load( file, pColorNumber, pJumpBytes );
		}
		else
		{
			std::stringstream out;
			out << "Graphic::Palette::load(\"" << pPaletteName << "\", " << pColorNumber << ", " << pJumpBytes << "): Error, could not open the file for reading.";
			raiseGraphicException( out.str() );
		}
	}
}}

