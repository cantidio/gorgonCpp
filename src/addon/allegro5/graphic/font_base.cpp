#include <addon/allegro5/graphic/font_base.hpp>
#include <addon/allegro5/graphic/common.hpp>
#include <core/file.hpp>
#include <sstream>

namespace Gorgon	{
namespace Allegro5	{
namespace Graphic
{
	FontBase::FontBase()
	{
		mFont = NULL;
	}

	FontBase::~FontBase()
	{
		if( mFont != NULL )
		{
			al_destroy_font( mFont );
		}
	}

	void FontBase::load( const std::string& pFileName, const int& pSize )
	{
		const int flags = al_get_new_bitmap_flags();
		al_set_new_bitmap_flags( ALLEGRO_VIDEO_BITMAP );

		mFont = al_load_font( pFileName.c_str(), pSize, 0 );
		drawText( Gorgon::Core::Point(-100,-100), Gorgon::Graphic::Color(0,0,0,0), Gorgon::Graphic::Font::AlignLeft,"A");
		/**@todo is this right?*/

		al_set_new_bitmap_flags( flags );

		if( mFont )
		{
			mSize		= pSize;
			mLineHeight	= al_get_font_line_height( mFont );
		}
		else
		{
			mSize		= 0;
			mLineHeight	= 0;

			std::stringstream out;
			out << "FontBase::load( \"" << pFileName << "\", " << pSize << " ): Error while loading the font, is this really a valid font?";
			raiseGraphicException( out.str() );
		}
	}
	/*void FontBase::load( Core::File& pFile , const int& pSize, const int& pDataLength )
	{
		ALLEGRO_FILE*	fake_file		= NULL;
		unsigned char*	data			= NULL;
		try
		{
			data = new unsigned char[pDataLength];
			pFile.read( (char*)data, pDataLength );
			fake_file = al_open_memfile( (void*) data, pDataLength, "rb" );

			//mFont = al_load_ttf_font_f( fake_file, pSize, 0 ); //try loading a ttf font first
			//if( !mFont ) //if the font isn't a ttf one, try loading a bitmap font
			//{
			//	al_fseek( fake_file, 0, ALLEGRO_SEEK_SET );		//return the file position to its start
			mFont = al_load_font_f( fake_file, pSize, 0 );	//load the font
			//}
			al_fclose( fake_file );		//close the file
			delete data;				//delete the data
			if( mFont )
			{
				mSize		= pSize;
				mLineHeight	= al_get_font_line_height( mFont );
			}
			else
			{
				std::stringstream out;
				out << "FontBase::load(" << &pFile << ", " pSize, ", " << pDataLength << "): Error while loading the font, is this really a valid font?";
				raiseGraphicException( out.str() );
			}
		}
		catch( std::exception& e )
		{
			std::stringstream out;
			out << "FontBase::load(" << &pFile << ", " pSize << ", " << pDataLength << "): Error in loading the font, couldn't allocate memory for it.";
			raiseGraphicException( out.str() );
		}
	}*/

	int FontBase::getTextWidth( const std::string& pText ) const
	{
		return ( mFont != NULL ) ? al_get_text_width( mFont, pText.c_str() ) : 0;
	}

	void FontBase::drawText
	(
		const Gorgon::Core::Point&				pPosition,
		const Gorgon::Graphic::Color&			pColor,
		const Gorgon::Graphic::Font::Alignment&	pAlignment,
		const std::string&						pText
	) const
	{
		if( mFont != NULL )
		{
			al_draw_text
			(
				mFont,
				gorgonColort2AllegroColor( pColor ),
				pPosition.getX(),
				pPosition.getY(),
				gorgonFontAlignment2AllegroAlignment( pAlignment ),
				pText.c_str()
			);
		}
	}

	void FontBase::drawTextJustified
	(
		const Gorgon::Core::Point&				pPosition,
		const int&								pLineWidth,
		const Gorgon::Graphic::Color&			pColor,
		const Gorgon::Graphic::Font::Alignment&	pAlignment,
		const std::string&						pText
	) const
	{
		if( mFont != NULL )
		{
			al_draw_justified_text
			(
				mFont,
				gorgonColort2AllegroColor( pColor ),
				pPosition.getX(),
				pPosition.getX() + pLineWidth,
				pPosition.getY(),
				0,
				gorgonFontAlignment2AllegroAlignment( pAlignment ),
				pText.c_str()
			);
		}
	}
}}}
