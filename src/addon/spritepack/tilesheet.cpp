#include "tilesheet.hpp"
#include <gorgon++/graphic/system.hpp>

namespace Gorgon  {
namespace Graphic {
namespace Addon
{
	TileSheet::TileSheet
	(
		const Image&	pImageSheet,
		const int&		pWidth,
		const int&		pHeight,
		const int&		pJumpPixels
	)
	{
		register int group,index;
		register int j,i;
		Image* aux = System::get().getTargetImage();

		for( group = 0, j = pJumpPixels; j < pImageSheet.getHeight(); j += pHeight + pJumpPixels, ++group )
		{
			for( index = 0, i = pJumpPixels; i < pImageSheet.getWidth(); i += pWidth + pJumpPixels, ++index )
			{
				add
				(
					Sprite
					(
						Image( pWidth, pHeight ),
						group,
						index
					)
				);

				(*this)[ getSize() - 1 ].clear( Color(0, 0, 0, 0) );

				System::get().setTargetImage( (*this)[ getSize() - 1 ] );
				pImageSheet.blit( Core::Point(0,0), Core::Point(i,j), pWidth, pHeight );
			}
		}

		System::get().setTargetImage( *aux );
		mPalLinked = false;
		if(pImageSheet.getPalette())
		{
			mGlobalPalette	= pImageSheet.getPalette()->clone();
		}
		else
		{
			mGlobalPalette	= new Palette();
		}
		applyGlobalPalette();
	}
}}}
