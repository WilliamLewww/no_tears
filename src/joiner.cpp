#include "joiner.h"

void Joiner::initialize() {
	int color[4] = {255,255,255,255};
	rectangle = new RectangleGL({0,0}, 25, 25, color);
}

void Joiner::update() {

}

void Joiner::render() {
	rectangle->render();
}