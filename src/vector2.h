#pragma once
#include <ostream>

struct Vector2 {
	float x = 0.0f;
	float y = 0.0f;
};

std::ostream &operator<<(std::ostream &os, Vector2 const &vector);