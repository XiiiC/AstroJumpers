// Project2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include "SDL.h"
#include "GameWorld.h"
#include "FileLogger.h"




using namespace std;


int main(int argc, char* argv[])
{

    
    GameWorld gameWorld1;
    GameWorld gameWorld2;

    IMG_Init(SDL_INIT_EVERYTHING);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;
    
    gameWorld1.Init();
    gameWorld1.Run();


    IMG_Quit();

   /* SDL_Window* window = SDL_CreateWindow("2D Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    
    
    
    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);


    SDL_RenderPresent(renderer);
    
    SDL_RenderPresent(renderer);
    */

    SDL_Quit();
    return 0;
}
