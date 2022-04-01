#include "GameWorld.h"


void GameWorld::Init()
{
	window = SDL_CreateWindow("2D Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	plyr1.Init();
	enmy1.Init(250, 250, true);
	enmy2.Init(300, 300, true);
	enmy3.Init(650, 250, false);
	enmy4.Init(100, 300, true);
	enmy5.Init(700, 350, false);
	enmy6.Init(200, 350, true);
}

void GameWorld::Run()
{
	while (!done)
	{
		//use home made timer provided by Olivier
		aTimer.resetTicksTimer(); // resets a frame timer to zero

	   //merge of render and update, as example.
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		//clear the screen
		SDL_RenderClear(renderer);
		Input();
		Update();
		Render();
		//move square that was created previously in lecture

		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderDrawRect(renderer, &plyr1.rect);
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
			case MOVE_UP:
				printf(">> W DOWN \n");
				up = true;
				break;
			case MOVE_DOWN:
				printf(">> S DOWN \n");
				down = true;
				break;
			case MOVE_LEFT:
				printf(">> A DOWN \n");
				left = true;
				break;
			case MOVE_RIGHT:
				printf(">> D DOWN \n");
				right = true;
				break;
			}
		}
		if (_event.type == SDL_KEYUP && _event.key.repeat == NULL)
		{
			switch (_event.key.keysym.sym) {
			case SDLK_ESCAPE:
				done = true;
				break;
			case MOVE_UP:
				printf(">> W UP \n");
				up = false;
				break;
			case MOVE_DOWN:
				printf(">> S UP \n");
				down = false;
				break;
			case MOVE_LEFT:
				printf(">> A UP \n");
				left = false;
				break;
			case MOVE_RIGHT:
				printf(">> D UP \n");
				right = false;
				break;
			}
		}
	}
	SDL_PumpEvents();  // make sure we have the latest mouse state.
	if (_event.type == SDL_MOUSEMOTION)
	{
		buttons = SDL_GetMouseState(&x, &y);
		system("cls");
		SDL_Log("Mouse cursor is at %d, %d", x, y);
	}
}

void GameWorld::Update()
{
	plyr1.Update(up,down,left,right);
	enmy1.Update(window);
	enmy2.Update(window);
	enmy3.Update(window);
	enmy4.Update(window);
	enmy5.Update(window);
	enmy6.Update(window);
}

void GameWorld::Render()
{
	plyr1.Render(renderer);
	enmy1.Render(renderer);
	enmy2.Render(renderer);
	enmy3.Render(renderer);
	enmy4.Render(renderer);
	enmy5.Render(renderer);
	enmy6.Render(renderer);
}

void GameWorld::Quit()
{
}
