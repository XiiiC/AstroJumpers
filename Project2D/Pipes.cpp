#include "Pipes.h"


Pipes::Pipes()
{

}
Pipes::~Pipes()
{

}
void Pipes::Init(int y, bool direction, SDL_Renderer* renderer)
{
	pipe1.Init(-300, y, 700, 50, 85, 0, 0);
	pipe2.Init(500, y, 700, 50, 85, 0, 0);
	powerUp1.Init(-100,-100 , 50, 50, 0, 255, 0);
	powerUp2.Init(-100,-100 , 50, 50, 0, 255, 0);

	R = 0;
	G = 150;
	B = 0;
	top = direction;
	speed = 4;

	powered = false;

	//Convert to a texture
	pipe1texture = SDL_CreateTextureFromSurface(renderer, surface);
	pipe2texture = SDL_CreateTextureFromSurface(renderer, surface);
	powerUp1texture = SDL_CreateTextureFromSurface(renderer, powerUpSurface1);
	powerUp2texture = SDL_CreateTextureFromSurface(renderer, powerUpSurface2);

	//Free up the surface data from RAM
	SDL_FreeSurface(surface);
	SDL_FreeSurface(powerUpSurface1);
	SDL_FreeSurface(powerUpSurface2);
}

void Pipes::Update(SDL_Window* window)
{
	dstRectPipe1 = { pipe1.rect.x, pipe1.rect.y, 700, 50 };
	dstRectPipe2 = { pipe2.rect.x, pipe2.rect.y, 700, 50 };

	if(!powered)
		PowerUpSetup();
		powered = true;

	if (top)
	{
		if (powered)
		{
			powered = false;
			powerUp1.rect.y = -100;
			powerUp1.rect.x = -100;
			powerUp2.rect.y = -100;
			powerUp2.rect.x = -100;

		}
		if (pipe2.rect.x < 500)
		{
			Offset();
			pipe1.rect.x += offset;
			pipe2.rect.x += offset;
		}
		if (pipe2.rect.x >= 500)
		{
			Offset();
			pipe1.rect.x -= offset;
			pipe2.rect.x -= offset;
		}
		pipe1.rect.y = 800;
		pipe2.rect.y = 800;

	
	}
	if (!top)
	{
		pipe1.rect.y -= speed;
		pipe2.rect.y -= speed;
		if (powered)
		{

			powerUp1.rect.y -= speed;
			dstRectPowerUp1 = { powerUp1.rect.x, powerUp1.rect.y , 45, 45 };


			powerUp2.rect.y -= speed;
			dstRectPowerUp2 = { powerUp2.rect.x, powerUp2.rect.y , 45, 45 };

			powered = false;
		}
	}

	if (pipe1.rect.y < 0)
	{
		top = true;
	}

	if (pipe1.rect.y > 750)
	{
		top = false;
	}
}

void Pipes::Render(SDL_Renderer* renderer)
{


	SDL_RenderCopy(renderer, powerUp1texture, NULL, &dstRectPowerUp1);
	SDL_RenderCopy(renderer, powerUp2texture, NULL, &dstRectPowerUp2);


	SDL_RenderCopy(renderer, pipe1texture, NULL, &dstRectPipe1);
	SDL_RenderCopy(renderer, pipe2texture, NULL, &dstRectPipe2);

	SDL_RenderPresent(renderer);
}

void Pipes::Offset()
{
	char timestr[32];
	timer.GetTime(timestr, 32);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(350, 600);
	offset = distr(gen);
	SDL_Log("[%s] [Offset Change] %i", timestr, offset);
}

void Pipes::PowerUpSetup()
{
	int x;
	char timestr[32];
	timer.GetTime(timestr, 32);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, 2000);
	x = distr(gen);
	if (x <= 4)
	{
		if (x % 2 == 0)
		{
			power = PickPower();
			if (power) 
			{
				powerUp1.rect.x = 700;
 				powerUp1.rect.y = pipe2.rect.y - 100;
			}
			else if (!power)
			{
				powerUp2.rect.x = 700;
				powerUp2.rect.y = pipe1.rect.y - 100;
			}
			powered = true;
		}
		else if (x % 2 == 1)
		{
			if (power)
			{
				powerUp1.rect.x = 100;
				powerUp1.rect.y = pipe1.rect.y - 100;
			}
			else if (!power)
			{
				powerUp2.rect.x = 100;
				powerUp2.rect.y = pipe1.rect.y - 100;
			}
			powered = true;
		}
	}
}
bool Pipes::PickPower()
{
	int x;
	char timestr[32];
	timer.GetTime(timestr, 32);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, 2);
	x = distr(gen);
	SDL_Log("%i CHECK HERE", x);
	if (x == 1)
	{
		
		return true;
	}
	else if (x == 2)
	{
		return false;
	}
	return false;
	
}

void Pipes::PickedUp()
{
	powerUp1.rect.x = -100;
	powerUp1.rect.y = -100;
	powerUp2.rect.x = -100;
	powerUp2.rect.y = -100;
	powered = false;
}

