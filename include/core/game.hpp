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
 *  Copyright (C) 2008-2009  Gorgon Team
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
#ifndef _GORGON_GAME_
#define	_GORGON_GAME_

namespace Gorgon
{
	class Game
	{
		private:
			int mFramePerSeconds;
			static int mFrame;
			static int mFrameCounter;
			bool	mIsRunning;
		protected:
			void setFramePerSeconds(const int& pFramePerSeconds)
			{
				mFramePerSeconds = pFramePerSeconds;
			}
			void start()
			{
				mIsRunning = true;
			}

			void stop()
			{
				mIsRunning = false;
			}
		public:
			Game();
			~Game();
			static int getFrame() const
			{
				return mFrame;
			}
			static int getFrameCounter() const
			{
				return mFrameCounter;
			}

			bool run()
			{
				while(mIsRunning)
				{
					while(mFrame-- >= 0 && ++mFrameCounter)
					{
						if(	!logic() || !render() )
						{
							return false;
						}
					}
				}
				return true;
			}
			virtual bool logic()	= 0;
			virtual bool render()	= 0;
	};
}
#endif
