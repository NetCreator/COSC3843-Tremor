// #############################################################################
// # Project:       Shakes Game Engine
// # File:          2DSprite.h
// # Author:        SpenSer Bray
// # Purpose:       Implement the Entity interface to provide a simple sprite
// #           object full of nice neat functions to be overidden. Also
// #           dragons, unicorns, and pretty butterflies.
// # Status:        INCOMPLETE
// # Todo:        * Implmement resource manager into sprite loading
// #              * Add z-buffer value (essentially just the z-axis)
// #              * Support resource.asset loading
// # Created:       12.6.2012:1100
// # Last Modified: 12.6.2012:1100
// #############################################################################

#ifndef __SHAKES_2DSPRITE
#define __SHAKES_2DSPRITE

#include "entity.h"

namespace Shakes
{
	class 2DSprite: protected Shakes::Entity
	{
		// OBJECT MEMBER DECLARATION --
		// OBJECT METHODS --
		public:
		// -- CONSTRUCTOR/DECONSTRUCTOR
			virtual 2DSprite(void);
			virtual ~2DSprite(void);
		
		// -- GENERAL
			virtual void update(void);
			virtual void draw(void);
		
		// -- ACCESSOR METHODS
			void setX(int x) { this->x = x; }
			void setY(int y) { this->y = y; }
			void setPosition(int x, int y) { this->x = x; this->y = y; }
			
			int getX(void) { return this->x; }
			int getY(void) { return this->y; }			
	}
}