#pragma once
#include "SDL.h"
#include "Timer.h"
#include "Player.h"
#include "Enemy.h"
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
	Player plyr1;
	Enemy enmy1;
	Enemy enmy2;
	Enemy enmy3;
	Enemy enmy4;
	Enemy enmy5;
	Enemy enmy6;

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

