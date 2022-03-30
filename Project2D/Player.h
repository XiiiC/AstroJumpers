#pragma once
#include <iostream>
#include "SDL.h"

class Player
{
public:
	Player();
	~Player();
	void Init();
	void Update(bool up, bool down, bool left, bool right);
	void Render(SDL_Renderer* aRenderer);
	SDL_Rect rect;
	int height, width, R, G, B;
private:
	int speed;
};


