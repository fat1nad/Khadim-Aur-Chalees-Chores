#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include "BasicUnit.h"
#include "TextureManager.h"
#include "Player.h"
#include "Furniture.h"

class Game : public BasicUnit
{
//This class represents the main game

private:
    bool isRunning;   //Bool value to check if the game is running
    SDL_Window* window;   //Window

    SDL_Texture* mapTex;   //Map texture

    Furniture* furniture;   //Furniture

    Player* player;   //Player

public:
    static SDL_Renderer* renderer;   //Static renderer

    Game();
    ~Game();

    void Init(const char*, int, int, int, int, bool);   //Method to initialize game

    void HandleEvents();   //Method to handle events
    void Update();   //Method to update game
    void Render();   //Method to render game
    void Clean();   //Method to destroy and delete all objects

    bool Running();   //Get property for isRunning
};
