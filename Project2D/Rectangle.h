#pragma once
#include <iostream>
#include "SDL.h"

class Rectangle
{
public:
	Rectangle();
	~Rectangle();
	void Init();
	void Update();
	void Input(int whichKey);
	void Render(SDL_Renderer* aRenderer);
	SDL_Rect rect;
	int x, y, height, width, R, G, B;
};


