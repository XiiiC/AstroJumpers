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
}

void Bullet::Render()
{

}
void Bullet::SetColour(int r, int g, int b)
{
	R = r;
	G = g;
	B = b;
}
