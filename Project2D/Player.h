#pragma once
#include <iostream>
#include "SDL.h"
#include "Vector2D.h"
#include "SDL_image.h"

class Player
{
public:
	Player();
	~Player();
	void Init(SDL_Renderer* renderer);
	void Update(bool& up, bool& down, bool& left, bool& right);
	void Render(SDL_Renderer* aRenderer);
	SDL_Rect rect;
	int height, width, R, G, B;
private:
	int speed;
	float offset;
	Vector2D velocity;


	SDL_Rect srcRect;
	SDL_Rect dstRect;

	//Load in png
	SDL_Surface* surface = IMG_Load("content/PlayerSpriteSheet.png");
	SDL_Texture* texture;

};


