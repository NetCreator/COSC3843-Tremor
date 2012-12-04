#include <iostream>

#include "engine.h"

using namespace std;

int main(int argc, char **argv) {
	Shakes::Engine myEngine;
		
	myEngine.setWidth(640);
	myEngine.setHeight(480);
	myEngine.setWindowTitle("Hello, world!");
	
	myEngine.initialize();
	
	myEngine.run();
}