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
	void Init();
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

	SDL_Surface* playerSprite;
	SDL_Texture* playerTexture;

};


