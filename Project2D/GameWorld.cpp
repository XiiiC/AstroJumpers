#include "GameWorld.h"


void GameWorld::Init()
{

	window = SDL_CreateWindow("Hardijs Raubiskis; CGP2015M Game Programming; 25113420; AstroJumpers", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);


	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (IMG_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_SYSTEM, "Image Initialisation Failed.");
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		printf("Warning: Audio has not been found! \n");
	}
	else
	{
		SOUND_jumper = Mix_LoadWAV("content/jump.wav");
			//("content/jump.wav");
		SOUND_backMusic = Mix_LoadMUS("content/backgroundMusic.mp3");
		//Mix_VolumeChunk(SOUND_back, 32); //The Volume of this sound (0-255)
		Mix_VolumeMusic(8); //The volume for the music (0-255)
	}


	maxGameTime = 60.0f;
	curGameTime = 0.0f;

	plyr1.Init(renderer);

	pipes1.Init(0, false, renderer);
	pipes2.Init(200, false, renderer);
	pipes3.Init(400, false, renderer);
	pipes4.Init(600, false, renderer);

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	//Free up the surface data from RAM
	SDL_FreeSurface(surface);

	Mix_PlayChannel(-1, SOUND_back, 0);

	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(SOUND_backMusic, -1);
	}

}

void GameWorld::Run()
{

	while (!done)
	{
		//add the amount of time that one frame takes every frame
		curGameTime += 0.0333f;
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
		//end parts of render&updatece
		if (aTimer.getTicks() < DELTA_TIME)
		{
			SDL_Delay(DELTA_TIME - aTimer.getTicks());
		}
		if (curGameTime >= maxGameTime)
		{
			done = true;
		}
	}
}

void GameWorld::Input()
{
	Timer performanceTimer;
	performanceTimer.startPerformance();

	while (SDL_PollEvent(&_event))
	{
		SDL_Keycode keyPressed = _event.key.keysym.sym;
		char timestr[32];
		aTimer.GetTime(timestr, 32);

		


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
				Mix_PlayChannel(1,SOUND_jumper, 0);
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
			case PERF:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				perf = !perf;
				SDL_Log("[%s] [PERF TOGGLE] time %d; char %b;", timestr, _event.key.timestamp, perf);
			}
		}
		if (_event.type == SDL_KEYUP && _event.key.repeat == NULL)
		{
			switch (_event.key.keysym.sym) 
			{
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
			case PERF:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
			}
		}
	}
	if(perf)
		performanceTimer.endPerformance("Input");

}

void GameWorld::Update()
{
	Timer performanceTimer;
	performanceTimer.startPerformance();

	char timestr[32];
	aTimer.GetTime(timestr, 32);

	if (collisions.CheckCollision(plyr1.rect, pipes1.pipe1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);
		done = true;

	}
	if (collisions.CheckCollision(plyr1.rect, pipes1.pipe2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);
		done = true;
	}
	if (collisions.CheckCollision(plyr1.rect, pipes2.pipe1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);
		done = true;
	}
	if (collisions.CheckCollision(plyr1.rect, pipes2.pipe2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);
		done = true;
	}
	if (collisions.CheckCollision(plyr1.rect, pipes3.pipe1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);
		done = true;
	}
	if (collisions.CheckCollision(plyr1.rect, pipes3.pipe2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);
		done = true;
	}
	if (collisions.CheckCollision(plyr1.rect, pipes4.pipe1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);
		done = true;
	}
	if (collisions.CheckCollision(plyr1.rect, pipes4.pipe2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, Pipe", timestr, _event.key.timestamp);
		done = true;
	}

	plyr1.Update(up,down,left,right);

	pipes1.Update(window);
	pipes2.Update(window);
	pipes3.Update(window);
	pipes4.Update(window);

	if(perf)
		performanceTimer.endPerformance("Update");
}

void GameWorld::Render()
{
	Timer performanceTimer;
	performanceTimer.startPerformance();
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	plyr1.Render(renderer);


	pipes1.Render(renderer);
	pipes2.Render(renderer);
	pipes3.Render(renderer);
	pipes4.Render(renderer);
	if(perf)
		performanceTimer.endPerformance("Render");
}

void GameWorld::Quit()
{
	IMG_Quit();
}
