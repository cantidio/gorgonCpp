#include <addon/spritepack/spritesheet_auto.hpp>

namespace Gorgon{
namespace Addon
{
	/**
	 * Método para informar se o vetor possui a posição pesquisada
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	29/09/2009
	 * @version	29/09/2009
	 * @param	const std::vector<Core::Point>&	pVector , vetor a realizar a pesquisa
	 * @param	const Core::Point&				pPoint	, ponto a pesquisar
	 * @return	bool
	 */
	bool positionInVector(const std::vector<Core::Point>& pVector,const Core::Point& pPoint)
	{
		for(register int i = pVector.size() - 1; i > -1; --i)
		{
			if(pVector[i] == pPoint)
			{
				return true;
			}
		}
		return false;
	}

	void SpriteSheetAuto::findImageLimits
	(
		const Graphic::Image&		pImage,
		std::vector<Core::Point>&	pPositions,
		Core::Point&				pInit,
		Core::Point&				pEnd,
		const Graphic::Color&		pTransparentColor
	)
	{
		Core::Point current = pPositions[pPositions.size() - 1];//pixel atual
		if(current.getX() < pInit.getX())	pInit.setX(current.getX());
		if(current.getX() > pEnd.getX())	pEnd.setX(current.getX());
		if(current.getY() > pEnd.getY())	pEnd.setY(current.getY());
/*
		if //cima
		(
			current.getY() - 1  > pInit.getY()
			&& pImage.getColor(current.getX(), current.getY() - 1) != pTransparentColor
			&& !positionInVector(pPositions,Core::Point(current.getX(),current.getY() - 1))
		)
		{
//			printf("cima\n");
			pPositions.push_back(Core::Point(current.getX(),current.getY()-1));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //baixo
		(
			current.getY() + 1  < pImage.getHeight()
			&& pImage.getColor(current.getX(), current.getY() + 1) != pTransparentColor
			&& !positionInVector(pPositions,Core::Point(current.getX(),current.getY() + 1))
		)
		{
//			printf("baixo\n");
			pPositions.push_back(Core::Point(current.getX(),current.getY() + 1));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //direita
		(
			current.getX() + 1  < pImage.getWidth()
			&& pImage.getColor(current.getX() + 1, current.getY()) != pTransparentColor
			&& !positionInVector(pPositions,Core::Point(current.getX() + 1,current.getY()))
		)
		{
//			printf("direita\n");
			pPositions.push_back(Core::Point(current.getX() + 1,current.getY()));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //esquerda
		(
			current.getX() - 1  > -1
			&& pImage.getColor(current.getX() - 1, current.getY()) != pTransparentColor
			&& !positionInVector(pPositions,Core::Point(current.getX() - 1,current.getY()))
		)
		{
//			printf("esquerda\n");
			pPositions.push_back(Core::Point(current.getX() - 1,current.getY()));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //esquerda cima
		(
			current.getY() - 1 > pInit.getY()
			&& current.getX() - 1 > -1
			&& pImage.getColor(current.getX() - 1, current.getY() - 1) != pTransparentColor
			&& !positionInVector(pPositions,Core::Point(current.getX() - 1,current.getY() - 1))
		)
		{
//			printf("esquerda-cima\n");
			pPositions.push_back(Core::Point(current.getX() - 1,current.getY() - 1));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //esquerda baixo
		(
			current.getY() + 1 < pImage.getHeight()
			&& current.getX() - 1 > -1
			&& pImage.getColor(current.getX() - 1, current.getY() + 1) != pTransparentColor
			&& !positionInVector(pPositions,Core::Point(current.getX() - 1,current.getY() + 1))
		)
		{
//			printf("esquerda-baixo\n");
			pPositions.push_back(Core::Point(current.getX() - 1,current.getY() + 1));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //direita cima
		(
			current.getY() - 1 > pInit.getY()
			&& current.getX() + 1 < pImage.getWidth()
			&& pImage.getColor(current + Core::Point(1,-1) ) != pTransparentColor
			&& !positionInVector(pPositions,current + Core::Point(1,-1) )
		)
		{
//			printf("direita-cima\n");
			pPositions.push_back( current + Core::Point(1,-1) );
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}
		if //direita baixo
		(
			current.getY() + 1 < pImage.getHeight()
			&& current.getX() + 1 < pImage.getWidth()
			&& pImage.getPixel(current + Core::Point(1,1)) != pTransparentColor
			&& !positionInVector(pPositions, current + Core::Point(1,1))
		)
		{
//			printf("direita-baixo\n");
			pPositions.push_back(Core::Point(current.getX() + 1,current.getY() + 1));
			findImageLimits(pImage,pPositions,pInit,pEnd,pTransparentColor);
		}*/
	}

	SpriteSheetAuto::SpriteSheetAuto(const Graphic::Image pImageSheet,const Graphic::Color& pTransparentColor)
	{
		std::vector<Core::Point> positions;
		Core::Point pos,init,end;
		int width, height;
		Graphic::Image imageSheet = pImageSheet;
		for(pos.setY(0); pos.getY() < imageSheet.getHeight(); pos.addY(1))
		{
			for(pos.setX(0); pos.getX() < imageSheet.getWidth(); pos.addX(1))
			{
				if(imageSheet.getPixel(pos) != pTransparentColor)
				{
					init = end = pos;
					positions.clear();
					positions.push_back(init);
					findImageLimits
					(
						imageSheet,
						positions,
						init,
						end,
						pTransparentColor
					);
					width	= end.getX() - init.getX() + 1;
					height	= end.getY() - init.getY() + 1;
					add
					(
						Graphic::Sprite
						(
							Graphic::Image
							(
								width,
								height,
								imageSheet.getBpp()
							),
							0,
							0
						)
					);/*
					(*this)[getSize() - 1].blitImage(imageSheet,Core::Point(0,0),init,width,height);
					(*this)[getSize() - 1].updateBuffer();


					imageSheet.drawRectangle
					(
						init,
						init + Core::Point(width, height),
						pTransparentColor,
						true
					);*/
				}
			}
		}
	}
}}
