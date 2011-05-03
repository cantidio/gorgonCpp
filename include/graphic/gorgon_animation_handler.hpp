/*
 *
 *    __     ___   _ __    __     ___     ___
 *  /'_ `\  / __`\/\`'__\/'_ `\  / __`\ /' _ `\
 * /\ \L\ \/\ \L\ \ \ \//\ \L\ \/\ \L\ \/\ \/\ \
 * \ \____ \ \____/\ \_\\ \____ \ \____/\ \_\ \_\
 *  \/___L\ \/___/  \/_/ \/___L\ \/___/  \/_/\/_/
 *    /\____/              /\____/
 *    \_/__/               \_/__/
 *
 *  Copyright (C) 2008-2011  Cantidio Oliveira Fontes
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */
#ifndef _GORGON_ANIMATION_HANDLER_
#define _GORGON_ANIMATION_HANDLER_
#include "gorgon_animationpack.hpp"
#include "gorgon_spritepack.hpp"
#include "gorgon_mirroring.hpp"

namespace Gorgon{
namespace Graphic
{
	/**
	 * Classe que representa o manipulador de animações
	 *
	 * @author	Cantidio Oliveira Fontes
	 * @since	15/10/2008
	 * @version	09/06/2009
	 * @ingroup	Graphic
	 */
	class AnimationHandler
	{
		private:
			/**
			 * A animaçao que está tocando atualmente
			 */
			int mAnimationOn;
			/**
			 * Tempo atual que o frame atual está sendo exibida
			 */
			int	mTimeOn;
			/**
			 * Frame atual sendo exibido
			 */
			int mFrameOn;
			/**
			 * Número de vezes que a animação repetiu
			 */
			int	mLoopOn;
			/**
			 * Verdadeiro se a animação está pausada
			 */
			bool mIsPaused;
			/**
			 * Ponteiro para o pacote de sprites da animação
			 */
			SpritePack*	mSpritePack;
			/**
			 * Ponteiro para o pacote de animações
			 */
			AnimationPack* mAnimationPack;
		public:
			/**
			 * Método Construtor da Classe AnimationHandler
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	27/05/2008
			 */
			AnimationHandler();
			/**
			 * Método Construtor da Classe AnimationHandler
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @param	SpritePack&		pSpritePack		, pacote de sprites
			 * @param	AnimationPack&	pAnimationPack	, pacote de animações
			 */
			AnimationHandler(SpritePack& pSpritePack,AnimationPack& pAnimationPack);
			/**
			 * Método Construtor de Copia
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @param	const AnimationHandler& pOrig , objeto original
			 */
			AnimationHandler(const AnimationHandler& pOrig);
			/**
			 * Método para setar o SpritePack
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @param	SpritePack& pSpritePack,novo SpritePack
			 */
			void setSpritePack(SpritePack& pSpritePack);
			/**
			 * Método para setar o AnimationPack
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @param	AnimationPack& pAnimationPack,novo AnimationPack
			 */
			void setAnimationPack(AnimationPack& pAnimationPack);
			/**
			 * Método para retornar o SpritePack
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/03/2009
			 * @version	27/05/2009
			 * @return	SpritePack&
			 */
			SpritePack& getSpritePack() const;
			/**
			 * Método para retornar o AnimationPack
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	18/03/2009
			 * @version	27/05/2009
			 * @return	AnimationPack&
			 */
			AnimationPack& getAnimationPack() const;
			/**
			 * Método para descrever o estado das variáveis de classe
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 */
			void describe() const;
			/**
			 * Método que reinicia as animações
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	27/05/2009
			 */
			void reset();
			/**
			 * Método para pausar a execução da animação
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/02/2009
			 * @version	27/05/2009
			 */
			void pause();
			/**
			 * Método para continuar a execução da animação se pausada
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/02/2009
			 * @version	27/05/2009
			 */
			void resume();
			/**
			 * Método para pular para o frame indicado na animação
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/02/2009
			 * @version	27/05/2009
			 * @param	const int& pFrameIndex, índice real do frame na animação atual
			 */
			void jumpToFrame(const int& pFrameIndex);
			/**
			 * Método para pausar a execução da animação
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	27/02/2009
			 * @version	27/05/2009
			 * @param	const int& pFrameGroup, grupo do frame a pular
			 * @param	const int& pFrameIndex, índice do frame a pular
			 */
			void jumpToFrame(const int& pFrameGroup,const int& pFrameIndex);
			/**
			 * Método para otimizar a animação
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	27/05/2008
			 * @details
			 *			Esse método é muito importante para otimizar a execução das animações, ele acha os índices verdadeiros dos sprites
			 * no spritePack e atualiza-os no animationPack, para acesso direto
			 */
			void optimize();
			/**
			 * Método para retornar em qual frame a animação atual está
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	23/10/2008
			 * @version	27/05/2009
			 * @return	const int&
			 */
			int getFrameOn() const;
			/**
			 * Método que retorna o tempo atual do frame da animação
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	27/05/2009
			 * @return	int
			 */
			int getTimeOn() const;
			/**
			 * Método que retorna a animacao que está sendo executada no momento
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	27/05/2009
			 * @return	int, número da animação que está sendo executada
			 */
			int getAnimationOn() const;
			/**
			 * Método para retornar o grupo da animação que está tocando
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	27/05/2009
			 * @return	const int&
			 */
			int getAnimationOnGroup() const;
			/**
			 * Método para retornar o índice da animação que está tocando
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	26/02/2009
			 * @version	27/05/2009
			 * @return	int
			 */
			int getAnimationOnIndex() const;
			/**
			 * Método para mudar a animação a ser executada
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	27/05/2009
			 * @param	const int& pAnimationNumber, número da animação a ser mudada
			 * @param	const bool& pForce, se verdadeiro sempre muda a animação e reseta os contadores,
			 * se não só muda se a animação for diferente da animação atual
			 */
			void changeAnimation(const int& pAnimationNumber,const bool& pForce=false);
			/**
			 * Método para mudar a animação a ser executada
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @param	const int& pGroup, grupo da nova animação a tocar
			 * @param	const int& pIndex, índice da nova animação a tocar
			 * @param	const bool& pForce, se verdadeiro sempre muda a animação e reseta os contadores,
			 * se não só muda se a animação for diferente da animação atual
			 */
			void changeAnimation
			(
				const int& pGroup,
				const int& pIndex,
				const bool& pForce=false
			);
			/**
			 * Método para saber se a animação está tocando
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	15/10/2008
			 * @version	09/06/2009
			 * @return	bool
			 */
			bool isPlaying();
			/**
			 * Método que roda um passo da animação
			 *
			 * @author	Cantídio Oliveira Fontes
			 * @since	24/02/2009
			 * @version	09/06/2009
			 */
			void playByStep();
			/**
			 * Método que retorna o sprite do frame corrente na animação
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	27/05/2009
			 * @return	const Sprite&
			 */
			const Sprite& getCurrentSprite() const;
			/**
			 * Método que desenha a animação em um sprite de destino
			 *
			 * @author	Cantidio Oliveira Fontes
			 * @since	25/02/2009
			 * @version	03/05/2011
			 * @param	Sprite& pSprite				, sprite onde a animação será desenhada
			 * @param	const Point& pPosition		, posição que a animação será desenhada
			 * @param	const Mirroring& pMirroring	, espelhamento a ser usado para desenhar a animação
			 * @param	const int& pAngle			, angulo a ser usado para desenhar a animação
			 */
			void draw
			(
				Sprite& pSprite,
				const Point& pPosition,
				const Mirroring& pMirroring=Mirroring::Normal,
				const int& pAngle=0
			);
			void drawTrans
			(
				Sprite& pSprite,
				const Point& pPosition,
				const float& pTrans = 0.5
			);
			//virtual void onFinish();//?
	};
}}
#endif
