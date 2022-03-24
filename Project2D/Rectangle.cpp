#include "Rectangle.h"

Rectangle::Rectangle()
{

}

Rectangle::~Rectangle()
{

}
void Rectangle::Init() 
{
	rect.x = 70;
	rect.y = 70;
	rect.w = 20;
	rect.h = 20;
	R = 255;
	G = 0;
	B = 0;
}

void Rectangle::Input(int whichKey)
{

}

void Rectangle::Update(bool up, bool down, bool left, bool right)
{
	if (up)
		rect.y-=5;
	if (down)
		rect.y+=5;
	if (left)
		rect.x-=5;
	if (right)
		rect.x+=5;
}

void Rectangle::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, R, G, B, 255);
	SDL_RenderDrawRect(renderer,&rect);
}
