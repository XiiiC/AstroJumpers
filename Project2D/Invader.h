#pragma once
#include "SDL.h"
#include "Timer.h"
using namespace std;
class Invader
{
public:
	SDL_Rect r;
	Invader(int x, int y, int w, int h);
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
};

