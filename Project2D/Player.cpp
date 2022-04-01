#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}
void Player::Init() 
{
	rect.x = 400;
	rect.y = 400;
	rect.w = 20;
	rect.h = 20;
	R = 255;
	G = 0;
	B = 255;
	speed = 1;
	velocity.x = 0;
	velocity.y = 0;
}


void Player::Update(bool& up, bool& down, bool& left, bool& right)
{
	if (up)
		velocity.y = -20;
	up = false;
	velocity.y += 2;
	if (rect.y >= 500)
	{
		velocity.y = -5;
	}
	if (rect.y <= 100)
	{
		velocity.y = 10;
	}
	if (rect.x <= 100)
	{
		velocity.x = 5;
	}
	if (rect.x >= 700)
	{
		velocity.x = -5;
	}
	if (left)
		velocity.x -= speed;
	if (right)
		velocity.x += speed;
	rect.x = rect.x + velocity.x;
	rect.y = rect.y + velocity.y;

}

void Player::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, R, G, B, 255);
	SDL_RenderDrawRect(renderer,&rect);
	SDL_RenderPresent(renderer);
}
