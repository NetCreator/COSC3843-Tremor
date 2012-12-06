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
// #              * Implmement resource manager into sprite loading
// # Created:       11.22.2012:1508
// # Last Modified: 12.3.2012:1923
// #############################################################################

#ifndef __SHAKES_ENTITY
#define __SHAKES_ENTITY

#include <string>

namespace Shakes
{
	class Entity
	{
		// OBJECT MEMBER DECLARATION --
		private:
			int x, y, z;             // position element
			
			std::string graphicName; // graphic element file name (w/ extension w/o path)
			std::string graphicPath; // graphic element path (w/o file name) 
		
		// OBJECT METHODS --
		public:
		// -- CONSTRUCTOR/DECONSTRUCTOR
			virtual Entity(void): x(0), y(0), z(0);
			virtual ~Entity(void);
		
		// -- GENERAL
			virtual void update(void) = 0;                          // Updates the object this entity represents.
			virtual void draw(void) = 0;                            // Draws this entity using OpenGL
			
			virtual void loadGraphic(std::string fullFilePath) = 0; // Loads the graphic uses the full path, including name and extension.
		
		// -- ACCESSOR METHODS
			void setX(int x) { this->x = x; }
			void setY(int y) { this->y = y; }
			void setZ(int z) { this->z = z; }
			void setPosition(int x, int y, int z) { this->x = x; this->y = y; this->z = z; }
	}
}

#endif