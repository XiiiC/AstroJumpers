// Project2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "SDL.h"
#include "Rectangle.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;
    
    SDL_Window* window = SDL_CreateWindow("2D Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    
    
    
    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    Rectangle sqr = Rectangle(20, 20, 100, 100);
    SDL_RenderDrawRect(renderer, &sqr.r);
    sqr.GameLoop(window, renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(4000);
    return 0;
}

