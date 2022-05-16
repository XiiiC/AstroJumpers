#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}
void Player::Init(SDL_Renderer* renderer)
{
	rect.x = 500;
	rect.y = 500;
	rect.w = 32;
	rect.h = 32;
	R = 100;
	G = 0;
	B = 255;
	speed = 1;
	velocity.x = 0;
	velocity.y = 0;
	offset = 0.8f;

	//Convert to a texture
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	//Free up the surface data from RAM
	SDL_FreeSurface(surface);
}


void Player::Update(bool& up, bool& down, bool& left, bool& right)
{
	srcRect = { 32, 0, 32, 32 };
	dstRect = { rect.x, rect.y, 32, 32 };

	if (up)
	{
		velocity.y = -20;
		srcRect = { 96, 0, 32, 32 };
		up = false;
	}
	if (down)
	{
		velocity.y = 20;
		down = false;
		srcRect = { 32, 0, 32, 32 };
	}
		velocity.y += 2;
	if (rect.y > 750)
	{
		velocity.y = -velocity.y * offset; //Rigid Wall
		//velocity.y -= 10; //Jelly Wall
	}
	if (rect.y < 0)
	{
		velocity.y = 20;
	}
	if (rect.x < 0)
	{
		velocity.x = -velocity.x * offset;
	}
	if (rect.x > 750)
	{
		velocity.x = -velocity.x * offset;
	}
	if (left)
	{
		velocity.x -= speed;
		srcRect = { 0, 0, 32, 32 };
	}
	if (right)
	{
		velocity.x += speed;
		srcRect = { 64, 0, 32, 32 };
	}
	rect.x = rect.x + velocity.x;
	rect.y = rect.y + velocity.y;

}

void Player::Render(SDL_Renderer* renderer)
{


	SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
	
	//SDL_SetRenderDrawColor(renderer, R, G, B, 255);
	//SDL_RenderFillRect(renderer, &rect);
	//SDL_RenderDrawRect(renderer, &rect);
	//SDL_RenderCopy(renderer, playerTexture, &spriteRect,&dstRect);

	SDL_RenderPresent(renderer);
}
