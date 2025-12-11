#pragma once

#include "../buffer/vbo.h"
#include "../buffer/ebo.h"
#include "../buffer/vao.h"
#include "../shader/shader_program.h"

class Mesh {
private:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    VAO                 vao;
    VBO                 vbo;
    EBO                 ebo;
    vec3                aabb_min;
    vec3                aabb_max;
    bool                loaded;
    // Material* material;
    // mat4 matrix;
private:
    void clear();
public:
    Mesh();
    Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices, const vec3& aabb_min = vec3(0.0, 0.0, 0.0), const vec3& aabb_max = vec3(1.0, 1.0, 1.0)/*, Material* material */);
    void load(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
    void draw(ShaderProgram& sp);
    void bind_textures(ShaderProgram& shader);
    void unbind_textures(ShaderProgram& shader);
    ~Mesh();
};