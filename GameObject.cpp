#include <iostream>

#include "GameObject.h"
#include "Game.h"

using namespace std;

//This class represents every game object

GameObject :: GameObject()
{}


GameObject :: GameObject(const char* textureSheet, int sX, int sY, int sH, int sW, int x, int y, int h, int w)
{
    objTexture = TextureManager :: LoadTexture(textureSheet);   //Loading texture for GameObject using its sprite sheet

    //Assigning height and width to source rectangle
    srcR.h = sH;
    srcR.w = sW;
    //Setting position of source rectangle
    SetSrcRPos(sX, sY);

    //Setting position, height and width of the GameObject in the game
    this -> x = x;
    this -> y = y;
    this -> h = h;
    this -> w = w;
}


GameObject :: ~GameObject()
{}


void GameObject :: Update()   //Method to update GameObject
{}


void GameObject :: Render()   //Method to render GameObject
{
    //Creating destination rectangle for GameObject, repetitively, every time render is called
    SDL_Rect destR;
    destR.x  = x;
    destR.y = y;
    destR.h = h;
    destR.w = w;

    SDL_RenderCopy(Game :: renderer, objTexture, &srcR, &destR);   //Copying GameObject texture to renderer
}


bool GameObject :: CollisionDetection(GameObject* player, int cX, int cY, int cH, int cW)   //Method to detect collision between player and this GameObject
{
    int collision = true;   //Bool value for collision detection set to true by default

    //Sides of the player needed for collision
    int pLowerSide = (player -> GetY()) + (player -> GetH());
    int pLeftSide = (player -> GetX());
    int pRightSide = (player -> GetX()) + (player -> GetW());

    //Sides of the part of GameObject needed for collision
    int gOUpperSide = cY;
    int gOLowerSide = cY + cH;
    int gOLeftSide = cX;
    int gORightSide = cX + cW;


    //Conditions to check if player is not colliding with GameObject
    if(pLowerSide < gOUpperSide)   //If player's lower side is above GameObject's collision part's upper side
    {
        collision = false;
    }

    if(pLowerSide > gOLowerSide)   //If player's lower side is below GameObject's collision part's lower side
    {
        collision = false;
    }

    if(pRightSide < gOLeftSide)   //If player's right side is at the left of GameObject's collision part's left side
    {
        collision = false;
    }

    if(pLeftSide > gORightSide)   //If player's left side is at the right of GameObject's collision part's right side
    {
        collision = false;
    }

    return collision;
}

SDL_Rect GameObject :: GetSrcR()   //Get property for source rectangle
{
    return srcR;
}


void GameObject :: SetSrcRPos(int sX, int sY)   //Set property for source rectangle position
{
    srcR.x = sX;
    srcR.y = sY;
}

int GameObject :: GetX()   //Get property for x coordinate of the GameObject
{
    return x;
}

int GameObject :: GetY()   //Get property for y coordinate of the GameObject
{
    return y;
}

void GameObject :: SetX(int x)   //Set property for x coordinate of the GameObject
{
    this -> x = x;
}

void GameObject :: SetY(int y)   //Set property for y coordinate of the GameObject
{
    this -> y = y;

}

int GameObject :: GetH()   //Get property for height of the GameObject
{
    return h;
}

int GameObject :: GetW()   //Get property for width of the GameObject
{
    return w;
}


///factory
///singleton
///operator over-loaders
///abstract class - Done
