#include <addon/spritepack/spritesheet.hpp>

namespace Gorgon{
namespace Addon
{
	int SpriteSheet::getSpriteInSpriteSheet
	(
		Graphic::Image&			pImage,
		const Core::Point&		pPosition,
		const int&				pGroup,
		const int&				pIndex,
		const Graphic::Color&	pBGCol
	)
	{
		int i,j,width = 0,height = 0;
		for(i = pPosition.getY(); i < pImage.getHeight(); ++i)
		{
			for(j = pPosition.getX(); j < pImage.getWidth(); ++j)
			{
				if( pImage.getPixel( Core::Point(j,i)) == pBGCol || j == (pImage.getWidth() - 1) )
				{
					if(j - pPosition.getX() > width)
					{
						width = j - pPosition.getX();
					}
					break;
				}
			}
			if(j == pPosition.getX())
			{
				break;
			}
		}
		height = i - pPosition.getY();
		if(height < 1 || width < 1)
		{
			return 1;
		}
		/*Graphic::Sprite sprite(Graphic::Image(width,height,pImage.getBpp()),pGroup,pIndex);
		sprite.setAsTarget();
		pImage.draw(Core::Point(0,0))

		sprite.blitImage(pImage,Core::Point(0,0), pPosition, width, height);
		sprite.updateBuffer();
		if(!sprite.isEmpty())
		{
			add(sprite);
		}
		pImage.drawRectangle
		(
			pPosition,
			pPosition + Core::Point(width,height),
			pBGCol,
			true
		);*/
		return width;
	}

	SpriteSheet::SpriteSheet
	(
		const Graphic::Image& pImageSheet,
		const Graphic::Color& pBackgroundColor
	)
	{
		int group, index;
		//int x, y;
		Core::Point pos;
		Graphic::Image imageSheet = pImageSheet;

		for(pos.setY(0), group = 0; pos.getY() < imageSheet.getHeight(); pos.addY(1))
		{
			for(pos.setX(0), index = 0; pos.getX() < imageSheet.getWidth(); pos.addX(1))
			{
				if(imageSheet.getPixel(pos) != pBackgroundColor)
				{
					const int offset = getSpriteInSpriteSheet
					(
						imageSheet,
						pos,
						group,
						index,
						pBackgroundColor
					);
					pos.addX( offset - 1 );
					++index;
				}
			}
			if(index != 0)
			{
				++group;
			}
		}
		mPalLinked = false;
		if(imageSheet.getPalette())
		{
			mGlobalPalette	= imageSheet.getPalette()->clone();
		}
		else
		{
			mGlobalPalette	= new Graphic::Palette();
		}
		applyGlobalPalette();
	}
}}
