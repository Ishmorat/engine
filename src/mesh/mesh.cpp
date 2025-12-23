#include "mesh.h"

void Mesh::clear() {
    vao.unbind();
    vbo.unbind();
    ebo.unbind();

    vao.clear();
    vbo.clear();
    ebo.clear();

    loaded = false;
}

Mesh::Mesh()
    : aabb_min{ vec3(0.0f, 0.0f, 0.0f) }
    , aabb_max{ vec3(0.0f, 0.0f, 0.0f) }
    , loaded  { false                  }
{}

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<uint>& indices, const vec3& aabb_min, const vec3& aabb_max/*, Material* material */)
    : aabb_min{ aabb_min }
    , aabb_max{ aabb_max }
    , loaded  { false    }
{
    load(vertices, indices);
}

void Mesh::load(const std::vector<Vertex>& vertices_, const std::vector<uint>& indices_) {
    if (vertices_.empty() || indices_.empty()) return;
    if (loaded) clear();

    // copy data 
    vertices = vertices_;
    indices = indices_;

    // create buffers 
    vao.create();
    vbo.create();
    ebo.create();

    // bind buffers 
    vao.bind();
    vbo.bind();
    ebo.bind();

    // set data 
    vbo.set_data(vertices);
    ebo.set_data(indices);

    // set attributes 
    vao.set_attribs();

    // unbind buffe
    vbo.unbind();
    vao.unbind();

    // set loaded 
    loaded = true;
}

void Mesh::draw(ShaderProgram& sp) {
    // ToDo : texture bind 
    // ToDo : params bind 

    sp.use();

    vao.bind();
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    vao.unbind();
}

Mesh::~Mesh() {}