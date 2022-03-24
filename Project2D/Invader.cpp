#include "Invader.h"

Invader::Invader(int x, int y, int w, int h)
{

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
}
void Invader::GameLoop(SDL_Window* window, SDL_Renderer* renderer)
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

void Invader::Input()
{

}

void Invader::Update()
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

void Invader::Render(SDL_Renderer* renderer)
{
}
