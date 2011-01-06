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
 *  Copyright (C) 2008-2010  Gorgon Team
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
#ifndef _GORGON_PHYSICS_
#define _GORGON_PHYSICS_
/**
 * @defgroup	Physics
 *
 * @author		Cantidio Oliveira Fontes
 * @since		03/10/2010
 * @version		07/10/2010
 * @details
 *				Module that deals with the game physics, for that it uses the
 *				Chipmunk lib
 */
#include "shape_segment.hpp"
#include "shape_polygon.hpp"
#include "shape_circle.hpp"
#include "shape_box.hpp"
#include "space.hpp"
#include "body.hpp"
#include "constraint.hpp"
#include "constraint_joint_pin.hpp"
#include "constraint_joint_slide.hpp"
#include "constraint_joint_groove.hpp"
#include "constraint_spring_damped.hpp"
#include "constraint_spring_damped_rotary.hpp"

namespace Gorgon
{
	/**
	 * @namespace Gorgon::Physics
	 * 
	 * @author	Cantidio Oliveira Fontes
	 * @since	03/10/2010
	 * @version	05/10/2010
	 * @ingroup	Physics
	 * @details	
	 * 			Namespace that holds all Physics related classes
	 */
	 namespace Physics
	 {
	 	/**
	 	 * Function that initiates the physics module
	 	 * 
	 	 * @author	Cantidio Oliveira Fontes
	 	 * @since	05/10/2010
	 	 * @version	05/10/2010
	 	 */
	 	inline void init()
	 	{
	 		cpInitChipmunk();
	 	}
	 }
}
#endif
