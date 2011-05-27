#include <allegro5/allegro.h>
#include <gorgon++/graphic/exception.hpp>
#include <gorgon++/core/log.hpp>
#include "system.hpp"
#include "image_base.hpp"

namespace Gorgon	{
namespace Graphic	{
namespace Addon
{
	System::System()
	{
		if(!al_init())
		{
			Core::logWrite(Core::String("Gorgon::Graphic::Addon::System::System(): Error, could not initialize allegro5 lib."));
			raiseGraphicException("System::System(): Error when initializing allegro5 lib.");
		}
		Core::logWrite(Core::String("Gorgon::Graphic::Addon::System::System(): Successful."));
	}
	
	System::~System()
	{
		Core::logWrite(Core::String("Gorgon::Graphic::Addon::System::~System(): Successful."));
	}

	void System::set()
	{
		Graphic::System::set( new System() );
	}

	Graphic::ImageBase* System::getImage() const
	{
		return new ImageBase();
	}

}}}