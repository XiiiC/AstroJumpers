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
	powerUp1.Init(0,0 , 32, 32, 0, 255, 0);
	powerUp2.Init(32,32 , 32, 32, 0, 255, 0);
	R = 0;
	G = 150;
	B = 0;
	top = direction;
	speed = 4;

	//Convert to a texture
	pipe1texture = SDL_CreateTextureFromSurface(renderer, surface);
	pipe2texture = SDL_CreateTextureFromSurface(renderer, surface);
	//Free up the surface data from RAM
	SDL_FreeSurface(surface);
}

void Pipes::Update(SDL_Window* window)
{
	dstRectPipe1 = { pipe1.rect.x, pipe1.rect.y, 700, 50 };
	dstRectPipe2 = { pipe2.rect.x, pipe2.rect.y, 700, 50 };
	if (top)
	{
		
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

	SDL_RenderCopy(renderer, pipe1texture, NULL, &dstRectPipe1);
	SDL_RenderCopy(renderer, pipe1texture, NULL, &dstRectPipe2);

	powerUp1.Render(renderer);
	powerUp2.Render(renderer);
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

