#include "mesh.h"

Mesh::Mesh() {}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, vec3 aabb_min, vec3 aabb_max/*, Material* material */)
    : vertices{ std::move(vertices) }
    , indices { std::move(indices ) }
    , aabb_min{ aabb_min            }
    , aabb_max{ aabb_max            }
{
    init();
}

void Mesh::draw(ShaderProgram& sp) {
    // ToDo : texture bind 
    // ToDo : params bind 

    sp.use();

    vao.bind();
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    vao.unbind();
}

void Mesh::init() {
    // bind buffers
    vao.bind();
    vbo.bind();
    ebo.bind();

    // set data
    vbo.set_data(vertices);
    ebo.set_data(indices);

    // set attributes 
    vao.set_attribs();

    // unbind buffers
    vbo.unbind();
    vao.unbind();
}

Mesh::~Mesh() {}