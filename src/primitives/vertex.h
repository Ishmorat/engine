#pragma once

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

using glm::vec2;
using glm::vec3;

struct Vertex {
public:
	vec3 position;
	vec3 color;
	// vec2 texture;
	// vec3 normal;
public:
	Vertex(const vec3& position = { 0.0, 0.0, 0.0 }, const vec3& color = { 0.0, 0.0, 0.0 }/*, const vec3& normal = {0.0, 0.0, 0.0}*/ )
		: position(position), color(color)// , normal(normal)
	{}
};