#pragma once

#include "SDL.h"
#include "Vector2D.h"

class Bullet
{
public:
	Bullet();
	~Bullet();
	void Init(int x, int y, int num, int TTL);
	void Update();
	void Render(SDL_Renderer* renderer);
	void SetColour(int r, int g, int b);
	SDL_Rect rect;
	int R, G, B;
	int x, y, h, w;
	int speed;
	Vector2D velocity;
	int ttl;
	int lifeCounter;
};

