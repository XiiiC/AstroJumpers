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
	rect.y = 700;
	rect.w = 20;
	rect.h = 20;
	R = 255;
	G = 0;
	B = 0;
	speed = 5;
}


void Player::Update(bool up, bool down, bool left, bool right)
{
	if (up)
		rect.y-=speed;
	if (down)
		rect.y+=speed;
	if (left)
		rect.x-=speed;
	if (right)
		rect.x+=speed;
}

void Player::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, R, G, B, 255);
	SDL_RenderDrawRect(renderer,&rect);
	SDL_RenderPresent(renderer);
}
