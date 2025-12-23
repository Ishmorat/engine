#pragma once

#include "texture.h"
#include <unordered_map>
#include <string>

namespace {
    // std::unordered_map<GLuint, std::string> material_name;               // ToDo : material names table 
}

struct Material {
public:
    uint  id;
    vec2  uv_scale;
    float metallic;
    float opacity;
    float volume;
    std::vector<Texture*> textures;
public:
    Material(uint id, std::vector<Texture*>& textures)
        : id      { id         }
        , uv_scale{ vec2(1.0f) }
        , metallic{ 0.0f       }
        , opacity { 1.0f       }
        , volume  { 0.0f       }
        , textures{ textures   }
    {}
};