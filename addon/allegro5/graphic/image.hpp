#ifndef _GORGON_IMAGE_ALLEGRO_
#define _GORGON_IMAGE_ALLEGRO_
namespace Gorgon{
namespace Addon
{
	class ImageAllegro
	{
		public:
			ImageAllegro(int pWidth, int pHeight);
			~ImageAllegro();
			int getWidth();
			int getHeight();
	};
}}
#endif
