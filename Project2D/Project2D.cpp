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


    SDL_Window* window = SDL_CreateWindow("Hardijs Raubiskis; CGP2015M Game Programming; 25113420; AstroJumpers", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);


    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear"); SDL_RenderSetLogicalSize(renderer, 800, 800);




    while (true)
    {
        if (IMG_Init(SDL_INIT_EVERYTHING) < 0)
        {
            SDL_LogCritical(SDL_LOG_CATEGORY_SYSTEM, "Image Initialisation Failed.");
        }
        GameWorld gameWorld1;

        IMG_Init(SDL_INIT_EVERYTHING);

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
            return 1;

        gameWorld1.Init(window, renderer);
        IMG_Quit();
    }


 

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
