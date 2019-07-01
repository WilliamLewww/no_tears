#include "src/engine.h"
#include <iostream>

Engine engine;

int main(void) {
	engine.initialize();
	engine.start();
	engine.quit();
	
	return 0;
}