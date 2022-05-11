#pragma once

#include "SDL.h"
#include <iostream>


class Rectangle
{
public:
	SDL_Rect rect;

	Rectangle();
	~Rectangle();

	void Init(int x, int y, int w, int h, int r, int b, int g);
	void Update();
	void Render(SDL_Renderer* renderer);
private:
	int R, B, G;

};

