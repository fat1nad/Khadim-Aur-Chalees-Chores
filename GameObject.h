#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include "BasicUnit.h"
#include "TextureManager.h"

class GameObject : public BasicUnit
{
//This class represents every game object

private:
    SDL_Texture* objTexture;   //GameObject texture
    SDL_Rect srcR;   //Source rectangle to determine part of the sprite sheet for the GameObject

    int x;
    int y;
    int h;
    int w;

    int lowerSide;
    int upperSide;
    int leftSide;
    int rightSide;

public:
    GameObject();
    GameObject(const char*, int, int, int, int, int, int, int, int);
    virtual ~GameObject();

    virtual void Update();   //Method to update GameObject
    virtual void Render();   //Method to render GameObject
    virtual bool CollisionDetection(GameObject*, int, int, int, int);

    SDL_Rect GetSrcR();   //Get property for source rectangle
    void SetSrcRPos(int, int);   //Set property for source rectangle position

    int GetX();   //Get property for x coordinate of GameObject
    int GetY();   //Get property for y coordinate of GameObject
    void SetX(int);   //Set property for x coordinate of GameObject
    void SetY(int);   //Set property for y coordinate of GameObject
    int GetH();   //Get property for height of GameObject
    int GetW();   //Get property for width of GameObject
};
