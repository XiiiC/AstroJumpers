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
#include "SDL_mixer.h"
#include "ScreenText.h"
#include <sstream>

using namespace std;

#define MAX_KEYS (256)
#define MOVE_UP 'w'
#define MOVE_LEFT 'a'
#define MOVE_DOWN 's'
#define MOVE_RIGHT 'd'
#define SHOOT 'g'
#define PERF 'p'
#define BOR 'l'
#define START 'j'
#define END 'r'


class GameWorld
{

public:

	FileLogger logger;
	SDL_Event _event;

	Collider collisions;

	//SDL_Rect r;

	Player plyr1;

	Pipes pipes1;
	Pipes pipes2;
	Pipes pipes3;
	Pipes pipes4;

	int x, y;
	Uint32 buttons;

	bool gKeys[MAX_KEYS];

	float maxGameTime;
	float curGameTime;

	void Init(SDL_Window* window, SDL_Renderer* renderer);
	void StartScreen(SDL_Window* window, SDL_Renderer* renderer);
	void Run(SDL_Window* window, SDL_Renderer* renderer);
	void EndScreen(SDL_Window* window, SDL_Renderer* renderer);
	void Input(SDL_Window* window);
	void Update(SDL_Window* window);
	void Render(SDL_Renderer* renderer);
	void Quit();
private:

	SDL_Color textColour;
	Timer aTimer;
	const float DELTA_TIME = 33.33f;
	bool done = false;
	bool up, down, left, right, shoot, perf, timedUp;

	bool borderless;

	int score;
	int scoreMultiplier;

	SDL_Surface* surface = IMG_Load("content/space.png");
	SDL_Texture* texture;

	Mix_Music* SOUND_backMusic = NULL;
	Mix_Music* SOUND_jump = NULL;

	Mix_Chunk* SOUND_back = NULL;
	Mix_Chunk* SOUND_jumper = NULL;




};

