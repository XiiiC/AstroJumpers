#pragma once
#include "SDL.h"
#include <iostream>
#include <string>
#include "Timer.h"

#define MAX_KEYS (256)
bool gKeys[MAX_KEYS];

using namespace std;

class Rectangle
{
public:
	SDL_Rect r;
	Rectangle(int x, int y, int w, int h);
	void GameLoop(SDL_Window* window, SDL_Renderer* renderer);
	void Input();
	void Update();
	void Render(SDL_Renderer* renderer);
private:
	Timer aTimer;
	const int DELTA_TIME = 50;
	bool done = false;
	bool left = false;
	bool right = true;
	int x, y;
	Uint32 buttons;
};

