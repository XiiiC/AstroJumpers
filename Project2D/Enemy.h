#pragma once
#include <iostream>
#include "SDL.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	void Init(int x, int y, bool direction);
	void Update(SDL_Window* window);
	void Render(SDL_Renderer* aRenderer);
	SDL_Rect rect;
	int height, width, R, G, B;
private:
	bool right;
	int speed;
};

