#include <iostream>

#include "Game.h"

//This class represents the main game

using namespace std;

SDL_Renderer* Game :: renderer = nullptr;   //Static renderer

Game :: Game()
{}

Game :: ~Game()
{}

void Game :: Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen)   //Method to initialize game
{
    int flag = 0;   //If fullScreen is set to false

    if(fullScreen)   //If fullScreen is set to true
    {
        flag = SDL_WINDOW_FULLSCREEN;
    }

    if(!SDL_Init(SDL_INIT_EVERYTHING))   //If all SDL subsystems have been initialized
    {
        cout << "All subsystems initialized successfully." << endl;

        window = SDL_CreateWindow(title, xPos, yPos, width, height, flag);   //Creating window
        if(window)   //If window has been successfully created
        {
            cout << "Window created successfully." << endl;

            renderer = SDL_CreateRenderer(window, -1, 0);   //Creating renderer
            if(renderer)   //If renderer has been successfully created
            {

                mapTex = TextureManager :: LoadTexture("Map.png");   //Loading map texture

                cout << "Renderer created successfully." << endl;

                isRunning = true;   //The game is now running after all relevant initializations
            }
        }

        furniture = new Furniture();   //Creating furniture

        player = new Player("Player.png", 27, 64, 32, 18, 373, 576, 96, 54);   //Creating player
//        24, 64, 32, 24, 364, 576, 96, 72
    }
    else
    {
        cout << "All subsystems failed to initialize." << endl;

        isRunning = false;   //If all the relevant initializations could not be done then the game cannot run
    }
}


void Game :: HandleEvents()   //Method to handle events
{
    SDL_Event event;
    SDL_PollEvent(&event);

    player -> HandleInput(event, furniture);   //Handle input for the player with respect to the furniture

    switch (event.type)
    {
        case SDL_QUIT:   //If window is closed; crossed out from top left
            isRunning = false;   //Game is not running
            break;
        default:
            break;
    }
}


void Game :: Update()   //Method to update game
{}


void Game :: Render()   //Method to render game
{
    SDL_RenderClear(renderer);   //Clearing up objects that were copied to the renderer

    SDL_RenderCopy(renderer, mapTex, NULL, NULL);   //Copying map texture to renderer
    furniture -> Render(player);   //Copying furniture and player textures to renderer/ Rendering furniture with respect to the player

    SDL_RenderPresent(renderer);   //Presenting everything copied to the renderer
}


void Game :: Clean()   //Method to destroy and delete all objects
{
    delete player;
    delete furniture;

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();   //Quitting the game

    cout << "Cleaned Successfully." << endl;
}


bool Game :: Running()   //Get property for isRunning
{
    return isRunning;
}
