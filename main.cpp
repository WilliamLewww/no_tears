#include "src/engine.h"

Engine engine;

int main(void) {
    engine.initialize();
    engine.start();
    engine.quit();
    
    return 0;
}