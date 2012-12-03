// #############################################################################
// # Project:       Shakes Game Engine
// # File:          Engine.h
// # Author:        SpenSer Bray
// # Purpose:       Is composed of the main element of the game engine.
// #       This is the point of access of the game, where the whole game will
// #       interface to the engine.
// # Status:        INCOMPLETE
// # Todo:        * FINISH METHOD DECLARATIONS
// # Created:       11.22.2012:1508
// # Last Modified: 12.3.2012:1503
// #############################################################################

#ifndef __SHAKES_ENGINE
#define __SHAKES_ENGINE

#include <iostream>
#include <string>
#include <sstream>

namespace Shakes {
	class Engine
	{
		// CLASS MEMBER DECLARATION --
		public:
		// -- ENGINE INFORMATION
			static const std::string NAME;   // = "Shakes"
			static const short int MAJORVERSION = 0;
			static const short int MINORVERSION = 2;
			static const short int REVISION     = 1;
		
		// -- ENGINE STATES
			enum State { STATE_PAUSE, STATE_GAME, STATE_MENU, STATE_QUIT };
		
		// OBJECT MEMBER DECLARATION --
		private:
			State state;
		
		// OBJECT METHODS --
		public:
		// -- CONSTRUCTOR/DECONSTRUCTOR
			Engine(void);
			Engine(State initialState);
			~Engine(void);
		
		private:
		// -- GENERAL
			//bool glInitialize(void);
			bool initialize(void);
			bool uninitialize(void);
		
		public:
			int run(void);
		
		// -- ACCESSOR METHODS
			std::string getFancyName(void);
		
		// -- DEBUG
			std::string getEngineStateDump(void);
	};
}

#endif