#include "vector2.h"

std::ostream &operator<<(std::ostream &os, Vector2 const &vector) {
	return os <<  "{" << vector.x << "," << vector.y << "}";
}