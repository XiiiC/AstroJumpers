#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}
void Player::Init() 
{
	rect.x = 500;
	rect.y = 500;
	rect.w = 20;
	rect.h = 20;
	R = 255;
	G = 0;
	B = 255;
	speed = 3;
	velocity.x = 0;
	velocity.y = 0;
	offset = 1.0f;
}


void Player::Update(bool& up, bool& down, bool& left, bool& right)
{
	if (up)
		velocity.y = -20;
		up = false;
		if (down)
			velocity.y = 20;
			down = false;
	velocity.y += 2;
	if (rect.y > (1080 - rect.h))
	{
		velocity.y = -velocity.y * offset; //Rigid Wall
		//velocity.y -= 10; //Jelly Wall
	}
	if (rect.y < 0)
	{
		velocity.y = 20;
	}
	if (rect.x < 480)
	{
		velocity.x = -velocity.x * offset;
	}
	if (rect.x > 1440)
	{
		velocity.x = -velocity.x * offset;
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
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}
