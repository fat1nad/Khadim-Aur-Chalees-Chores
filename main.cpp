#include <iostream>

#include "Game.h"

using namespace std;

int main(int argv, char** args)
{
    const int FPS = 60;   //60 FPS
    const int frameDelay = 1000/FPS;   //Time for one frame; thousand milliseconds divided by FPS
    Uint32 frameStart;   //Time lapsed since the game started in milliseconds
    int frameTime;   //Time it took for the game to HandleEvents, Update and Render once, in milliseconds

    Game* game = new Game();

    game -> Init("Khadim Aur Chalees Chores", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 672, false);   //Initializing Game

    while(game -> Running())   //If the game is running
    {
        frameStart = SDL_GetTicks();   //Time lapsed since the game started in milliseconds

        game -> HandleEvents();   //Handling events like taking input
        game -> Update();   //updating all the game objects after handling the events
        game -> Render();   //Visualizing what has been updated

        frameTime = SDL_GetTicks() - frameStart;   //Time it took for the game to HandleEvents, Update and Render once, in milliseconds
        if(frameTime < frameDelay)   //If all methods were called and run in less time than the frameTime
        {
            SDL_Delay(frameDelay - frameTime);   //Creating enough delay before the iteration ends so that it lasts for the entire frameTime
        }
    }

    game -> Clean();   //Destroying and deleting all objects

    return 0;
}
