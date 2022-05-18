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

	SDL_Texture* pipe1texture;
	SDL_Texture* pipe2texture;

	SDL_Texture* powerUp1texture;
	SDL_Texture* powerUp2texture;

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



};

