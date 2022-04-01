#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Init(int x, int y, bool direction)
{
	rect.x = x;
	rect.y = y;
	rect.w = 50;
	rect.h = 50;
	R = 100;
	G = 100;
	B = 100;
	right = direction;
	speed = 5;
}

void Enemy::Update(SDL_Window* window)
{
	
	if (right)
	{
		rect.x+=speed;
	}
	if (!right)
	{
		rect.x-=speed;
	}

	if (rect.x < 0)
	{
		right = true;
	}

	if (rect.x > 750)
	{
		right = false;
	}
}

void Enemy::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, R, G, B, 255);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

