#include "tilesheet.hpp"
namespace Gorgon{
namespace Addon
{
	TileSheet::TileSheet
	(
		const Graphic::Image&	pImageSheet,
		const int&				pWidth,
		const int&				pHeight,
		const int&				pJumpPixels
	)
	{
		int group,index;
		unsigned int j,i;
		for(group = 0, j = pJumpPixels; j < pImageSheet.getHeight(); j += pHeight + pJumpPixels,++group)
		{
			for(index = 0, i = pJumpPixels; i < pImageSheet.getWidth(); i += pWidth + pJumpPixels,++index)
			{
				add
				(
					Graphic::Sprite
					(
						Graphic::Image
						(
							pWidth,
							pHeight,
							pImageSheet.getColorDepth()
						),
						group,
						index
					)
				);
				(*this)[getSize()-1].clear();
				(*this)[getSize()-1].blitImage(pImageSheet,Core::Point(0,0),Core::Point(i,j),pWidth,pHeight);
			}
		}
		mPalLinked = false;
		if(pImageSheet.getPalette())
		{
			mGlobalPalette	= pImageSheet.getPalette()->copy();
		}
		else
		{
			mGlobalPalette	= new Graphic::Palette(255,0,255);
		}
		applyGlobalPalette();
	}
}}
