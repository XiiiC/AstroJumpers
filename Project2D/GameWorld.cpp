#include "GameWorld.h"


void GameWorld::Init(SDL_Window* window, SDL_Renderer* renderer)
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		printf("Warning: Audio has not been found! \n");
	}
	else
	{
		SOUND_jumper = Mix_LoadWAV("content/jump.wav");

		SOUND_backMusic = Mix_LoadMUS("content/backgroundMusic.mp3");
		//Mix_VolumeChunk(SOUND_back, 32); //The Volume of this sound (0-255)
		Mix_VolumeMusic(8); //The volume for the music (0-255)
	}


	textColour.r = 170;
	textColour.g = 0;
	textColour.b = 0;

	score = 0;
	scoreMultiplier = 1;

	maxGameTime = 60.0f;
	curGameTime = 0.0f;

	timedUp = false;
	borderless = SDL_FALSE;

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
	StartScreen(window, renderer);
}

void GameWorld::StartScreen(SDL_Window* window, SDL_Renderer* renderer)
{

	ScreenText TitleText(window, "content/Quantico/Quantico-Bold.ttf", 64);
	ScreenText StartText(window, "content/Quantico/Quantico-Bold.ttf", 32);
	ScreenText ControlsText(window, "content/Quantico/Quantico-Bold.ttf", 32);

	bool start = true;

	std::stringstream title;
	std::stringstream controls;
	std::stringstream starts;
	char timestr[32];
	aTimer.GetTime(timestr, 32);

	title << "AstroJumpers";
	starts << "Press J to start, or ESC to close the game";
	controls << "W - Jump\tA - Left\tS - Down\tD - Right\tP - Performance Logging\tL - Fullscreen borderless\t";
	TitleText.setText(title.str().c_str(), 400, 40, true, 48, 170, 0, 0);
	ControlsText.setText(controls.str().c_str(), 400, 600, true, 16, 170, 0, 0);
	StartText.setText(starts.str().c_str(), 400, 300, true, 28, 170, 0, 0);
	
	while (start)
	{
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		TitleText.render();
		StartText.render();
		ControlsText.render();
		SDL_RenderPresent(renderer);
		SDL_Keycode keyPressed = _event.key.keysym.sym;
		while (SDL_PollEvent(&_event))
		{
			
			if (_event.type == SDL_KEYDOWN && _event.key.repeat == NULL)
			{
				switch (_event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					Quit();
					break;
				case START:
					SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
					start = false;
					Run(window, renderer);
					break;
				case PERF:
					SDL_Log("[%s] [KEY UP] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
					perf = !perf;
					SDL_Log("[%s] [PERF TOGGLE] time %d; char %b;", timestr, _event.key.timestamp, perf);
				case BOR:

					if (borderless == true)
					{
						borderless = false;
						//SDL_SetWindowBordered(window, SDL_FALSE);
						SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					}
					else if (borderless == false)
					{
						borderless = true;
						//SDL_SetWindowBordered(window, SDL_TRUE);
						SDL_SetWindowFullscreen(window, 0);
					}
				}
			}
		}
	}

}
void GameWorld::EndScreen(SDL_Window* window, SDL_Renderer* renderer)
{
	bool end = true;

	ScreenText ScoreText(window, "content/Quantico/Quantico-Bold.ttf", 64);
	ScreenText ControlsText(window, "content/Quantico/Quantico-Bold.ttf", 32);

	std::stringstream scoreText;
	std::stringstream controls;
	char timestr[32];
	aTimer.GetTime(timestr, 32);

	scoreText << "Score: " << score;
	controls << "Press R to return to menu, or ESC to close the game";
	ScoreText.setText(scoreText.str().c_str(), 400, 40, true, 48, 170, 0, 0);
	ControlsText.setText(controls.str().c_str(), 400, 600, true, 20, 170, 0, 0);

	while (end)
	{
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		ScoreText.render();
		ControlsText.render();
		SDL_RenderPresent(renderer);
		SDL_Keycode keyPressed = _event.key.keysym.sym;
		while (SDL_PollEvent(&_event))
		{

			if (_event.type == SDL_KEYDOWN && _event.key.repeat == NULL)
			{
				switch (_event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					Quit();
					break;
				case END:
					SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
					end = false;
					break;
				case PERF:
					SDL_Log("[%s] [KEY UP] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
					perf = !perf;
					SDL_Log("[%s] [PERF TOGGLE] time %d; char %b;", timestr, _event.key.timestamp, perf);
				case BOR:

					if (borderless == true)
					{
						borderless = false;
						//SDL_SetWindowBordered(window, SDL_FALSE);
						SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					}
					else if (borderless == false)
					{
						borderless = true;
						//SDL_SetWindowBordered(window, SDL_TRUE);
						SDL_SetWindowFullscreen(window, 0);
					}
				}
			}
		}
	}
}


void GameWorld::Run(SDL_Window* window, SDL_Renderer* renderer)
{

	ScreenText CountDownTimer(window, "content/Quantico/Quantico-Bold.ttf", 64);

	while (!done)
	{
		if (score >= 20000 && !timedUp)
		{
			maxGameTime += 15;
			timedUp = true;
		}
		//add the amount of time that one frame takes every frame
		curGameTime += DELTA_TIME/1000;
		score += curGameTime + (plyr1.rect.y / 100) * scoreMultiplier;
		//use home made timer provided by Olivier
		aTimer.resetTicksTimer(); // resets a frame timer to zero

	   //merge of render and update, as example.
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		//clear the screen
		SDL_RenderClear(renderer);
		Input(window);
		Update(window);
		Render(renderer);

		std::stringstream timestr;
		timestr << "Countdown: " << round(maxGameTime - curGameTime);
		CountDownTimer.setText(timestr.str().c_str(), 400, 40, true, 48, 255, 255, 255);
		CountDownTimer.render();

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
	EndScreen(window, renderer);
}

void GameWorld::Input(SDL_Window* window)
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
				Quit();
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
			case BOR:
				SDL_Log("[%s] [KEY DOWN] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				
				SDL_Log("[%s] [BORDER TOGGLE] time %d; char %b;", timestr, _event.key.timestamp, borderless);
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
				SDL_Log("[%s] [KEY UP] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				down = false;
				break;
			case MOVE_LEFT:
				SDL_Log("[%s] [KEY UP] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				left = false;
				break;
			case MOVE_RIGHT:
				SDL_Log("[%s] [KEY UP] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				right = false;
				break;
			case SHOOT:
				SDL_Log("[%s] [KEY UP] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
				shoot = false;
			case PERF:
				SDL_Log("[%s] [KEY UP] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
			case BOR:

				if (borderless == true)
				{
					borderless = false;
					//SDL_SetWindowBordered(window, SDL_FALSE);
					SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP);
				}
				else if (borderless == false)
				{
					borderless = true;
					//SDL_SetWindowBordered(window, SDL_TRUE);
					SDL_SetWindowFullscreen(window, 0);
				}


				SDL_Log("[%s] [KEY UP] time %d; code %d; char %s;", timestr, _event.key.timestamp, keyPressed, SDL_GetKeyName(keyPressed));
			}
			
		}
	}
	if(perf)
		performanceTimer.endPerformance("Input");

}

void GameWorld::Update(SDL_Window* window)
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
	if (collisions.CheckCollision(plyr1.rect, pipes1.powerUp1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, PowerUp", timestr, _event.key.timestamp);
		//double score till the end of the game
		pipes1.PickedUp();
		scoreMultiplier++;
		SDL_Log("[%s] [GAME EVENT] time %d; Score Multiplier %i", timestr, _event.key.timestamp, scoreMultiplier);
	}
	if (collisions.CheckCollision(plyr1.rect, pipes1.powerUp2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, PowerUp", timestr, _event.key.timestamp);
		//add flat score value
		pipes1.PickedUp();
		score += 5000;
		SDL_Log("[%s] [GAME EVENT] time %d; Score Multiplier %i", timestr, _event.key.timestamp, scoreMultiplier);
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
	if (collisions.CheckCollision(plyr1.rect, pipes2.powerUp1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, PowerUp", timestr, _event.key.timestamp);
		//double score till the end of the game
		pipes2.PickedUp();
		scoreMultiplier++;
		SDL_Log("[%s] [GAME EVENT] time %d; Score Multiplier %i", timestr, _event.key.timestamp, scoreMultiplier);
	}
	if (collisions.CheckCollision(plyr1.rect, pipes2.powerUp2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, PowerUp", timestr, _event.key.timestamp);
		//add flat score value
		pipes2.PickedUp();
		score += 5000;
		SDL_Log("[%s] [GAME EVENT] time %d; Score Multiplier %i", timestr, _event.key.timestamp, scoreMultiplier);
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
	if (collisions.CheckCollision(plyr1.rect, pipes3.powerUp1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, PowerUp", timestr, _event.key.timestamp);
		//double score till the end of the game
		pipes3.PickedUp();
		scoreMultiplier++;
		SDL_Log("[%s] [GAME EVENT] time %d; Score Multiplier %i", timestr, _event.key.timestamp, scoreMultiplier);
	}
	if (collisions.CheckCollision(plyr1.rect, pipes3.powerUp2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, PowerUp", timestr, _event.key.timestamp);
		//add flat score value
		pipes3.PickedUp();
		score += 5000;
		SDL_Log("[%s] [GAME EVENT] time %d; Score Multiplier %i", timestr, _event.key.timestamp, scoreMultiplier);
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
	if (collisions.CheckCollision(plyr1.rect, pipes4.powerUp1.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, PowerUp", timestr, _event.key.timestamp);
		//double score till the end of the game
		pipes4.PickedUp();
		scoreMultiplier++;
		SDL_Log("[%s] [GAME EVENT] time %d; Score Multiplier %i", timestr, _event.key.timestamp, scoreMultiplier);
	}
	if (collisions.CheckCollision(plyr1.rect, pipes4.powerUp2.rect))
	{
		SDL_Log("[%s] [COLLISION] time %d; Player, PowerUp", timestr, _event.key.timestamp);
		//add flat score value
		pipes4.PickedUp();
		score += 5000;
		SDL_Log("[%s] [GAME EVENT] time %d; Score Multiplier %i", timestr, _event.key.timestamp, scoreMultiplier);
	}


	plyr1.Update(up,down,left,right);

	pipes1.Update(window);
	pipes2.Update(window);
	pipes3.Update(window);
	pipes4.Update(window);

	if(perf)
		performanceTimer.endPerformance("Update");
}

void GameWorld::Render(SDL_Renderer* renderer)
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
	SDL_Quit();
	exit(0);
}

