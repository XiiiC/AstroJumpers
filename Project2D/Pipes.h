#pragma once
#include <iostream>
#include "SDL.h"
#include "Rectangle.h"
#include <random>
#include "Timer.h"
#include "SDL_image.h"

class Pipes
{
public:
	Pipes();
	~Pipes();
	void Init(int y, bool direction, SDL_Renderer* renderer);
	void Update(SDL_Window* window);
	void Render(SDL_Renderer* aRenderer);
	void Offset();
	void PowerUpSetup();
	bool PickPower();
	void PickedUp();
	Rectangle pipe1;
	Rectangle pipe2;

	Rectangle powerUp1;
	Rectangle powerUp2;

	int height, width, R, G, B;
private:
	bool top, power, powered;
	int speed;
	int offset;
	Timer timer;

	SDL_Rect dstRectPipe1;
	SDL_Rect dstRectPipe2;

	SDL_Rect dstRectPowerUp1;
	SDL_Rect dstRectPowerUp2;

	//Load in png
	SDL_Surface* surface = IMG_Load("content/pipe.png");
	SDL_Surface* powerUpSurface1 = IMG_Load("content/scoreUp.png");
	SDL_Surface* powerUpSurface2 = IMG_Load("content/plusScore.png");
	SDL_Texture* pipe1texture;
	SDL_Texture* pipe2texture;

	SDL_Texture* powerUp1texture;
	SDL_Texture* powerUp2texture;

};

