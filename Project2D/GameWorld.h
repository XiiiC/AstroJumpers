#pragma once
#pragma warning(disable : 4996)
#include "SDL.h"
#include "Timer.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <ctime>
#include <string>
#include "Rectangle.h"
#include "Pipes.h"
#include "FileLogger.h"
#include "Collider.h"

using namespace std;

#define MAX_KEYS (256)
#define MOVE_UP 'w'
#define MOVE_LEFT 'a'
#define MOVE_DOWN 's'
#define MOVE_RIGHT 'd'
#define SHOOT 'g'


class GameWorld
{

public:

	FileLogger logger;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event _event;

	SDL_Rect r;

	Player plyr1;

	Pipes pipes1;
	Pipes pipes2;
	Pipes pipes3;
	Pipes pipes4;

	int x, y;
	Uint32 buttons;

	bool gKeys[MAX_KEYS];


	void Init();
	void Run();
	void Input();
	void Update();
	void Render();
	bool GetTime(char* buffer, int buffersize);
	void Quit();
private:
	Timer aTimer;
	const int DELTA_TIME = 50;
	bool done = false;
	bool up, down, left, right, shoot;

	SDL_Surface* surface = IMG_Load("content/space.png");
	SDL_Texture* texture;



};

