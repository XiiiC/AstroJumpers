#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h)
{
	
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
}
void Rectangle::GameLoop(SDL_Window* window, SDL_Renderer* renderer)
{
	while (!done)
	{
		//use home made timer provided by Olivier
		aTimer.resetTicksTimer(); // resets a frame timer to zero

	   //merge of render and update, as example.
		SDL_SetRenderDrawColor(renderer, 0, 0, 20, SDL_ALPHA_OPAQUE);
		//clear the screen
		SDL_RenderClear(renderer);
		Input();
		Update();
		Render(renderer);
		//move square that was created previously in lecture
		
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderDrawRect(renderer, &r);
		//then present all to the screen
		SDL_RenderPresent(renderer);
		//end parts of render&update
		// if less time has passed than allocated block, wait difference
		if (aTimer.getTicks() < DELTA_TIME)
		{
			SDL_Delay(DELTA_TIME - aTimer.getTicks());
		}
	}

}

void Rectangle::Input()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event))
	{
		if (_event.type == SDL_QUIT)
			done = true;
		if (_event.type == SDL_KEYDOWN && _event.key.repeat == NULL)
		{
			switch (_event.key.keysym.sym) {
			case SDLK_ESCAPE:
				done = true;
				break;
			case SDLK_w:
				printf("W has been pressed \n");
				break;
			}
		}
		//SDL_PumpEvents();  // make sure we have the latest mouse state.
		if (_event.type == SDL_MOUSEMOTION)
		{
			buttons = SDL_GetMouseState(&x, &y);
			system("cls");
			SDL_Log("Mouse cursor is at %d, %d", x, y);
		}
	}

}

void Rectangle::Update()
{
	if (r.x > 800)
	{
		left = true;
		right = false;
	}
	if (r.x < 0)
	{
		right = true;
		left = false;
	}
	if (right)
	{
		r.x++;
	}
	if (left)
	{
		r.x--;
	}
	

}

void Rectangle::Render(SDL_Renderer* renderer)
{
}
