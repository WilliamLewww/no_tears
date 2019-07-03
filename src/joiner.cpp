#include "joiner.h"

void Joiner::initialize(Geometry* geometry) {
	int color[4] = {255,255,255,255};
	rectangle = new RectangleGL(geometry, {0,0}, 25, 25, color);
}

void Joiner::update() {

}

void Joiner::render() {
	rectangle->render();
}