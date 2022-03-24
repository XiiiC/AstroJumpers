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
	rect.w = 100;
	rect.h = 100;
	R = 255;
	G = 0;
	B = 0;
}

void Rectangle::Input(int whichKey)
{
	switch(whichKey)
	{
	case 'w': 
		printf("Square: W is pressed \n"); 
		break;
	

	}


}

void Rectangle::Update()
{

}

void Rectangle::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor
	(renderer, R, G, B, 255);
	SDL_RenderDrawRect(renderer,&rect);
}
