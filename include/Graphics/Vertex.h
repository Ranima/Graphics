#pragma once

#include "glm\glm\glm.hpp"

struct Vertex
{
	glm::vec4 position;
	glm::vec4 color;
	glm::vec2 texcoord;
	glm::vec4 normal;
};