#include "Bullet.h"

Bullet::Bullet()
{

}
Bullet::~Bullet()
{
	
}
void Bullet::Init(int x, int y, int num, int TTL)
{
	rect.x = x;
	rect.y = y;
	rect.w = 10;
	rect.h = 10;
	speed = 5;
	velocity.x = 0;
	velocity.y = 0;
	ttl = TTL;
}

void Bullet::Update()
{
	rect.x = x;
	rect.y = y;
	rect.h = h;
	rect.w = w;
	// finally update the x/y according to velocity
	x = x + velocity.x;
	y = y + velocity.y;

	velocity.y = velocity.y + 1;
	if (y >= 500)
	{
		velocity.y = -15;
	}
	if (x <= 0) {
		velocity.y = 5;
	}
	if (x >= 700)
	{
		velocity.y = -5;
	}
	// finally update the x/y according to velocity
	x = x + velocity.x;
	y = y + velocity.y;
}

void Bullet::Render(SDL_Renderer* renderer)
{

}
void Bullet::SetColour(int r, int g, int b)
{
	R = r;
	G = g;
	B = b;
}
