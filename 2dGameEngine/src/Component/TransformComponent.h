#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include <glm/glm.hpp>

struct TransformCoponent {
	glm::vec2 position;
	glm::vec2 scale;
	double rotation;
};

#endif