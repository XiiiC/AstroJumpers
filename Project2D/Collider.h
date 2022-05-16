#pragma once
#include "SDL.h"
class Collider
{
public:
	virtual bool CheckCollision(SDL_Rect a, SDL_Rect b);
};

class AABB : Collider
{
	virtual bool CheckCollision(SDL_Rect a, SDL_Rect b);
};

