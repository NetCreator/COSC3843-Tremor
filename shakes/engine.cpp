// #############################################################################
// # Project:       Shakes Game Engine
// # File:          Engine.cpp
// # Author:        SpenSer Bray
// # Purpose:       The implementation of the Shakes game engine.
// # Status:        INCOMPLETE
// # Todo:          FINISH METHOD IMPLEMENTATIONS
// # Created:       11.22.2012:1518
// # Last Modified: 12.3.2012:1923
// #############################################################################

#include "engine.h"

// ##### STATIC CONST TYPE INITIALIZATION #####
const std::string Shakes::Engine::NAME = "Shakes";

// ##### CONSTRUCTORS #####
Shakes::Engine::Engine(void): state(Shakes::Engine::STATE_MENU), windowTitle(this->getFancyName()), windowWidth(640), windowHeight(480)
{
	std::cout << Shakes::Engine::NAME << " INITIALIZED" << std::endl
	          << this->getEngineStateDump() << std::endl;
}

Shakes::Engine::Engine(Shakes::Engine::State initialState): state(initialState)
{
	std::cout << Shakes::Engine::NAME << " INITIALIZED" << std::endl
	          << this->getEngineStateDump() << std::endl;
}

// ##### DECONSTRUCTOR #####
Shakes::Engine::~Engine(void)
{
	std::cout << Shakes::Engine::NAME << " SHUTTING DOWN" << std::endl;
	
	this->uninitialize();
}

// ##### OBJECT METHODS #####
/* Initializes any required bits of the engine.
 *
 * params: none
 * returns: successful or not (true/false)
 */
bool Shakes::Engine::initialize(void)
{
	std::cout << Shakes::Engine::NAME << " INITIALIZED" << std::endl;
	
	this->glInitialize();
	
	return true;
}

/* Do all the required OpenGL initialization.
 * Note that this does not actually instansiate the instances yet,
 *  but merely initializes some basic values.
 *
 * NOTE: HEAVILY INCOMPLETE
 *
 * params: none
 * returns: successful or not (true/false)
 */
bool Shakes::Engine::glInitialize(void)
{
	//INITIALIZE GLUT AND WINDOW --
	//int passcode = 0;
	//glutInit(&passcode, NULL);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(this->windowWidth, this->windowHeight);
	glutCreateWindow(this->windowTitle.c_str());
	
	//SETUP GL FUNCTIONS --
	glViewport(0, 0, this->windowWidth, this->windowHeight);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	
	//REGISTER GL CALLBACKS --
	glutIdleFunc(Shakes::Engine::glIdle);
	glutDisplayFunc(Shakes::Engine::glDisplay);
	
	return true;
}

/* Uninitializes any required areas of the engine.
 * Unallocates any heap-based storage.
 *
 * params: none
 * returns: successful or not (true/false)
 */
bool Shakes::Engine::uninitialize(void)
{
	std::cout << Shakes::Engine::NAME << " UNINITIALIZED" << std::endl;
	
	return true;
}

/* Starts the game/engine. Control should entirely be passed
 *  from the calling strand and should never need to be yeilded.
 * Even upon exit.
 *
 * params: none
 * returns: runcode
 */
int Shakes::Engine::run(void)
{
	//Start GLUT!
	glutMainLoop();
	
	return 0;
}

/* Builds the engine's fancy name.
 * The fancy name includes name, version, and revision.
 * 
 * params: none
 * returns: fancy name
 */
std::string Shakes::Engine::getFancyName(void)
{
	std::stringstream fancyName;
	
	fancyName << Shakes::Engine::NAME << ": v" << Engine::MAJORVERSION << "." << Engine::MINORVERSION << "." << Engine::REVISION;
	
	return fancyName.str();
}

/* Builds a string with various information about the
 *  current engine state. Should only be used for debugging
 *  or error handling.
 *
 * params: none
 * returns: Engine state in the form of a string.
 */
std::string Shakes::Engine::getEngineStateDump(void)
{
	std::stringstream stateDump;
	
	stateDump << this->getFancyName() << std::endl
	          << "\t+ internal state: " << this->state << std::endl;
	
	return stateDump.str();
}

/* The idle callback function for GLUT, currently
 *  only requests a redraw.
 *
 * params: none
 * returns: none
 */
void Shakes::Engine::glIdle(void)
{
	glutPostRedisplay();
}

/* The display callback function for GLUT, draws
 *  whatever is needed to the screen.
 *
 * params: none
 * returns: none
 */
void Shakes::Engine::glDisplay(void)
{
	Shakes::Engine::State temp;
	
	temp = Shakes::Engine::STATE_MENU;
	switch(temp) {
		case Shakes::Engine::STATE_MENU:
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glTranslatef(0, 5.0, 0);
			glutStrokeCharacter(GLUT_STROKE_ROMAN, 'D');
			glPopMatrix();
			break;
		
		default: break;
	}
}