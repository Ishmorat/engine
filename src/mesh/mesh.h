#pragma once

#include "../buffer/vbo.h"
#include "../buffer/ebo.h"
#include "../buffer/vao.h"
#include "../shader/shader_program.h"

class Mesh {
private:
    VAO                 vao;
    VBO                 vbo;
    EBO                 ebo;
    vec3                aabb_min;
    vec3                aabb_max;
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    // Material* material;
    // mat4 matrix;
private:
    void init();
public:
    Mesh();
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, vec3 aabb_min = vec3(0.0, 0.0, 0.0), vec3 aabb_max = vec3(1.0, 1.0, 1.0)/*, Material* material */);
    void draw(ShaderProgram& sp);
    void bind_textures(ShaderProgram& shader);
    void unbind_textures(ShaderProgram& shader);
    ~Mesh();
};