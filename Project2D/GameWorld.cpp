#include "GameWorld.h"


void GameWorld::Init()
{
	window = SDL_CreateWindow("2D Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void GameWorld::Run()
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
		Render();
		//move square that was created previously in lecture

		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
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

void GameWorld::Input()
{
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

void GameWorld::Update()
{

}

void GameWorld::Render()
{

}

void GameWorld::Quit()
{
}
