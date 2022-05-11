#pragma once
#include <iostream>
#include "SDL.h"
#include "Rectangle.h"
#include <random>
#include "Timer.h"

class Pipes
{
public:
	Pipes();
	~Pipes();
	void Init(int y, bool direction);
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
};

