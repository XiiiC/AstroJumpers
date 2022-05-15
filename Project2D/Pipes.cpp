#include "Pipes.h"


Pipes::Pipes()
{

}
Pipes::~Pipes()
{

}
void Pipes::Init(int y, bool direction)
{
	pipe1.Init(-300, y, 700, 50, 85, 0, 0);
	pipe2.Init(500, y, 700, 50, 85, 0, 0);
	R = 0;
	G = 150;
	B = 0;
	top = direction;
	speed = 5;
}

void Pipes::Update(SDL_Window* window)
{

	if (top)
	{
		Offset();
		if (pipe2.rect.x < 500)
		{
			pipe1.rect.x += offset;
			pipe2.rect.x += offset;
		}
		if (pipe2.rect.x >= 500)
		{
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
	pipe1.Render(renderer);
	pipe2.Render(renderer);

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

