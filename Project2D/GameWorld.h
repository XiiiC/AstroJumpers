#pragma once
#include "SDL.h"
#include "Timer.h"
#include "Rectangle.h"
#include <iostream>
#include <string>

using namespace std;

#define MAX_KEYS (256)
#define MOVE_UP 'w'
#define MOVE_LEFT 'a'
#define MOVE_DOWN 's'
#define MOVE_RIGHT 'd'

class GameWorld
{

public:

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event _event;

	SDL_Rect r;
	Rectangle sqr1;
	Rectangle sqr2;

	int x, y;
	Uint32 buttons;

	bool gKeys[MAX_KEYS];

	void Init();
	void Run();
	void Input();
	void Update();
	void Render();
	void Quit();
private:
	Timer aTimer;
	const int DELTA_TIME = 50;
	bool done = false;
	bool up, down, left, right;

};

