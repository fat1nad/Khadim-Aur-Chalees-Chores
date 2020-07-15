#include "TextureManager.h"
#include "Game.h"

//This class is used to load textures

SDL_Texture* TextureManager :: LoadTexture(const char* fileName)   //Static method to load texture
{
    SDL_Surface* tmpSurface;   //Temporary surface
    SDL_Texture* tex;   //Texture to be returned

    tmpSurface = IMG_Load(fileName);   //Loading surface from sprite sheet
    tex = SDL_CreateTextureFromSurface(Game :: renderer, tmpSurface);   //Converting surface to texture
    SDL_FreeSurface(tmpSurface);   //Freeing the temporary surface

    return tex;
}

