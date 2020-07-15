#pragma once

#include "SDL.h"
#include "SDL_image.h"

class TextureManager
{
//This class is used to load textures

public:
    static SDL_Texture* LoadTexture(const char*);   //Static method to load texture
};
