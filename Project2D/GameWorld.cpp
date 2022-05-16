#include "GameWorld.h"


void GameWorld::Init()
{

	window = SDL_CreateWindow("Hardijs Raubiskis; CGP2015M Game Programming; 25113420; AstroJumpers", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);


	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (IMG_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_SYSTEM, "Image Initialisation Failed.");
	}


	plyr1.Init(renderer);

	pipes1.Init(0, false, renderer);
	pipes2.Init(200, false, renderer);
	pipes3.Init(400, false, renderer);
	pipes4.Init(600, false, renderer);

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	//Free up the surface data from RAM
	SDL_FreeSurface(surface);
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
		//SDL_RenderDrawRect(renderer, &plyr1.rect);
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
		SDL_Keycode keyPressed = _event.key.keysym.sym;
		char timestr[32];
		GetTime(timestr, 32);


		if (_event.type == SDL_QUIT)
			done = true;
		if (_event.type == SDL_KEYDOWN && _event.key.repeat == NULL)
		{
			switch (_event.key.keysym.sym) {
			case SDLK_ESCAPE:
				done = true;
				break;
			case MOVE_UP:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				up = true;
				break;
			case MOVE_DOWN:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				down = true;
				break;
			case MOVE_LEFT:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				left = true;
				break;
			case MOVE_RIGHT:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				right = true;
				break;
			case SHOOT:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				shoot = true;
			}
		}
		if (_event.type == SDL_KEYUP && _event.key.repeat == NULL)
		{
			switch (_event.key.keysym.sym) {
			case SDLK_ESCAPE:
				done = true;
				break;
			case MOVE_UP:
				SDL_Log("[%s] [KEY UP] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				up = false;
				break;
			case MOVE_DOWN:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				down = false;
				break;
			case MOVE_LEFT:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				left = false;
				break;
			case MOVE_RIGHT:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				right = false;
				break;
			case SHOOT:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				shoot = false;
			}
		}
	}

}

void GameWorld::Update()
{
	char timestr[32];
	GetTime(timestr, 32);

	if (collisions.CheckCollision(plyr1.rect, pipes1.pipe1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);

	}
	if (collisions.CheckCollision(plyr1.rect, pipes1.pipe2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);

	}
	if (collisions.CheckCollision(plyr1.rect, pipes2.pipe1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);

	}
	if (collisions.CheckCollision(plyr1.rect, pipes2.pipe2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);

	}
	if (collisions.CheckCollision(plyr1.rect, pipes3.pipe1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);

	}
	if (collisions.CheckCollision(plyr1.rect, pipes3.pipe2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);

	}
	if (collisions.CheckCollision(plyr1.rect, pipes4.pipe1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);

	}
	if (collisions.CheckCollision(plyr1.rect, pipes4.pipe2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);

	}

	plyr1.Update(up,down,left,right);

	pipes1.Update(window);
	pipes2.Update(window);
	pipes3.Update(window);
	pipes4.Update(window);

	 //Add end game condition

}

void GameWorld::Render()
{
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	plyr1.Render(renderer);


	pipes1.Render(renderer);
	pipes2.Render(renderer);
	pipes3.Render(renderer);
	pipes4.Render(renderer);

}
bool GameWorld::GetTime(char* buffer, int buffersize) 
{
	//Get the current time
	time_t currentTime =
		std::time(0);
	//Get time information from current time -- secs, mins, etc. and save into a struct
		struct tm* info = localtime(&currentTime);
	//Format the time to (day_num/month_num/year time)
	size_t written = strftime(buffer, buffersize, "%d/%m/%y %T", info);
	//And return the string
	return written != 0;
}

void GameWorld::Quit()
{
	IMG_Quit();
}
