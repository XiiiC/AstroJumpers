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
	R = 100;
	G = 0;
	B = 255;
	speed = 3;
	velocity.x = 0;
	velocity.y = 0;
	offset = 0.7f;
	SDL_Surface* playerSprite = IMG_Load("content/PlayerSpriteSheet.png");
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
		velocity.x -= speed;
	if (right)
		velocity.x += speed;
	rect.x = rect.x + velocity.x;
	rect.y = rect.y + velocity.y;

}

void Player::Render(SDL_Renderer* renderer)
{
	SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(renderer, playerSprite);
	SDL_FreeSurface(playerSprite);
	//SDL_SetRenderDrawColor(renderer, R, G, B, 255);
	//SDL_RenderFillRect(renderer, &rect);
	SDL_Rect spriteRect = { 0,0,32,32 };
	SDL_Rect dstRect = { rect.x, rect.y, 32, 32 };
	SDL_RenderCopy(renderer, playerTexture, &spriteRect,&dstRect);

	SDL_RenderPresent(renderer);
}
