// #############################################################################
// # Project:       Shakes Game Engine
// # File:          Entity.h
// # Author:        SpenSer Bray
// # Purpose:       The entity class is an interface for an implementation of
// #           a game entity. A game entity is compromised of a handful of
// #           parts. Usually this includes a few data elements, a graphic
// #           element, and some functional elements. Read the comments below
// #           for specific examples of these.
// # Status:        INCOMPLETE
// # Todo:        * FLESH OUT INTERFACE
// #              * Pass copy of whatever reference Entity::update() might need
// # Created:       11.22.2012:1508
// # Last Modified: 12.3.2012:1923
// #############################################################################

#ifndef __SHAKES_ENTITY
#define __SHAKES_ENTITY

namespace Shakes
{
	class Entity
	{
		// OBJECT MEMBER DECLARATION --
		private:
			int x, y; // position element
		
		// OBJECT METHODS --
		public:
		// -- CONSTRUCTOR/DECONSTRUCTOR
			virtual Engine(void);
			virtual ~Engine(void);
		
		// -- GENERAL
			virtual void update(void) = 0; // Updates the object this entity represents.
			virtual void draw(void) = 0;   // Draws this entity using OpenGL
	}
}

#endif