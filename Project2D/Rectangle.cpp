#include "Rectangle.h"

Rectangle::Rectangle()
{

}

Rectangle::~Rectangle()
{

}

void Rectangle::Init(int x, int y, int w, int h, int r, int b, int g)
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	R = r;
	B = b;
	G = g;
}

void Rectangle::Update()
{

}

void Rectangle::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, R, G, B, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}
