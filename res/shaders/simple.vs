#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec4 vsColor;

uniform mat4 trans;

void main() {
    gl_Position = trans * vec4(position, 1.0);
    vsColor = vec4(color, 1.0);
}