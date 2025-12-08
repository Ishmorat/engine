#pragma once

#include "texture.h"
#include <unordered_map>
#include <string>

namespace {
    // std::unordered_map<GLuint, std::string> material_name;               // ToDo : material names table 
}

struct Material {
public:
    GLuint  id;
    vec2    uv_scale;
    GLfloat metallic;
    GLfloat opacity;
    GLfloat volume;
    std::vector<Texture*> textures;
public:
    Material(GLuint id, std::vector<Texture*>& textures)
        : id      { id         }
        , uv_scale{ vec2(1.0f) }
        , metallic{ 0.0f       }
        , opacity { 1.0f       }
        , volume  { 0.0f       }
        , textures{ textures   }
    {}
};