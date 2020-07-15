#include <iostream>

#include "Player.h"

//This class represents the main player

using namespace std;

Player :: Player()
{}


Player :: Player(const char* textureSheet, int sX, int sY, int sH, int sW, int dX, int dY, int dH, int dW)
: GameObject(textureSheet, sX, sY, sH, sW, dX, dY, dH, dW)
{}


Player :: ~Player()
{}


void Player :: Update()   //Method to update player
{}


void Player :: HandleInput(SDL_Event& even, Furniture* furniture)   //Method to handle input for Player
{
    if (even.type == SDL_KEYDOWN)   //if a key is pressed
    {
        //Changing source rectangle's x for walking animation between 3, 27 and 51; refer to sprite sheet for better understanding
        SetSrcRPos(GetSrcR().x + 24, GetSrcR().y);
        if (GetSrcR().x > 51)
        {
            SetSrcRPos(3, GetSrcR().y);
        }

        switch (even.key.keysym.sym)
        {
            case SDLK_UP:   //If up arrow key is pressed

                SetSrcRPos(GetSrcR().x, 0);   //Visualizing direction change by changing source rectangle's y; refer to sprite sheet for better understanding

                SetY(GetY() - 8);   //Changing y coordinate of player

                if(furniture -> CollisionDetection(this))   //However if player is colliding with the furniture
                {
                    SetY(GetY() + 8);   //Reversing change in y coordinate
                }

                break;

            case SDLK_RIGHT:   //If right arrow key is pressed

                SetSrcRPos(GetSrcR().x, 32);   //Visualizing direction change by changing source rectangle's y; refer to sprite sheet for better understanding

                SetX(GetX() + 8);   //Changing x coordinate of player

                if(furniture -> CollisionDetection(this))   //However if player is colliding with the furniture
                {
                    SetX(GetX() - 8);    //Reversing change in x coordinate
                }

                break;

            case SDLK_DOWN:   //If down arrow key is pressed

                SetSrcRPos(GetSrcR().x, 64);   //Visualizing direction change by changing source rectangle's y; refer to sprite sheet for better understanding

                SetY(GetY() + 8);   //Changing y coordinate of player

                if(furniture -> CollisionDetection(this))   //However if player is colliding with the furniture
                {
                    SetY(GetY() - 8);    //Reversing change in y coordinate
                }

                break;

            case SDLK_LEFT:   //If left arrow key is pressed

                SetSrcRPos(GetSrcR().x, 96);   //Visualizing direction change by changing source rectangle's y; refer to sprite sheet for better understanding

                SetX(GetX() - 8);   //Changing x coordinate of player

                if(furniture -> CollisionDetection(this))   //However if player is colliding with the furniture
                {
                    SetX(GetX() + 8);    //Reversing change in x coordinate
                }

                break;

            default:
                break;
        }
    }
}


