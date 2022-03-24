#pragma once
#include <iostream>
#include "SDL.h"

class Rectangle
{
public:
	Rectangle();
	~Rectangle();
	void Init();
	void Update(bool up, bool down, bool left, bool right);
	void Input(int whichKey);
	void Render(SDL_Renderer* aRenderer);
	SDL_Rect rect;
	int height, width, R, G, B;
};


