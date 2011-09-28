#include <graphic/font.hpp>
#include <graphic/font_base.hpp>
#include <graphic/system.hpp>
#include <core/file.hpp>

namespace Gorgon{
namespace Graphic
{
	Font::Font()
	{
		mFont = System::get().getFont();
	}

	Font::Font( const std::string& pFontName, const int& pSize )
	{
		mFont = System::get().getFont();
		load( pFontName, pSize );
	}


	Font::~Font()
	{
		delete mFont;
	}

	void Font::load( const std::string& pFileName, const int& pSize )
	{
		/**@todo put exception here */
		/*
		Core::File file( pFileName, std::ios::in | std::ios::binary );

		if( file.is_open() )
		{
			load( file, pSize, file.getSize() );
		}
		file.close();*/
		mFont->load( pFileName, pSize );
	}

	/*void Font::load( Core::File& pFile , const int& pSize, const int& pDataLength )
	{
		mFont->load( pFile, pSize, pDataLength );
	}*/

	int Font::getLineHeight() const
	{
		return mFont->getLineHeight();
	}

	int Font::getTextWidth( const std::string& pText ) const
	{
		return mFont->getTextWidth( pText );
	}

	void Font::drawText
	(
		const Core::Point&		pPosition,
		const Color&			pColor,
		const Font::Alignment&	pAlignment,
		const std::string&		pText
	) const
	{
		mFont->drawText
		(
			pPosition,
			pColor,
			pAlignment,
			pText
		);
	}

	void Font::drawTextJustified
	(
		const Core::Point&		pPosition,
		const int&				pLineWidth,
		const Color&			pColor,
		const Font::Alignment&	pAlignment,
		const std::string&		pText
	) const
	{
		mFont->drawTextJustified
		(
			pPosition,
			pLineWidth,
			pColor,
			pAlignment,
			pText
		);
	}
}}
