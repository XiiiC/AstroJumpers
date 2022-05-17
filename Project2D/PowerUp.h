#pragma once
#include "SDL.h"
#include "Rectangle.h"
#include <random>
#include "Timer.h"
#include "SDL_image.h"


class PowerUp
{
	PowerUp();
	~PowerUp();
	void Init();
	void Update(SDL_Window* window);
	void Render(SDL_Renderer* aRenderer);
	void Offset();
	Rectangle pipe1;
	Rectangle pipe2;

	int height, width, R, G, B;
private:
	bool top;
	int speed;
	int offset;
	Timer timer;

	SDL_Rect dstRectPipe1;
	SDL_Rect dstRectPipe2;

	//Load in png
	SDL_Surface* surface = IMG_Load("content/pipe.png");
	SDL_Texture* pipe1texture;
	SDL_Texture* pipe2texture;
};

