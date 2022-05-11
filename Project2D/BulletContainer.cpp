#include "BulletContainer.h"

BulletContainer::BulletContainer()
{

}

void BulletContainer::Init(int eY, int eX, int eNum, int ttl)
{
	x = eX;
	y = eY;
	num = eNum;
	rect.x = x;
	rect.y = y;
	rect.w = 20;
	rect.h = 20;
	for (int i = 0; i < num; i++)
	{
		int posX = x;
		int posY = y;
		Add(posX, posY);
	}
	this->ttl = ttl;
}

void BulletContainer::Add(int x, int y)
{
	Bullet* bullet = new Bullet();
	bullet->SetColour(255, 0, 0);
	bullet->velocity.x = 0;
	bullet->velocity.y = 0;
	bullet->Init(x, y, 3, 25);
	this->bulletList.push_back(bullet);
}

void BulletContainer::Input(int fire)
{
}

void BulletContainer::Update()
{
	for (auto& element : bulletList)
	{
		element->Update();
		if (element->velocity.x > 0)
		{
			element->lifeCounter++;
		}
		else
		{
			element->x = x;
			element->y = y;
		}
		if (element->lifeCounter > ttl)
		{
			element->lifeCounter = 0;
			element->x = x;
			element->y = y;
			element->velocity.x = 0;
		}
	}

	rect.x = x;
	rect.y = y;
}

void BulletContainer::Render(SDL_Renderer* renderer)
{
	// render controller for debugging
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rect);

	for (auto& element : bulletList)
	{
		if (element->velocity.x != 0)
		{
			element->Render(renderer);
		}
	}

}

void BulletContainer::Shoot()
{
	int i = 0;
	bool notFound = true;
	while ((i < bulletList.size()) && (notFound))
	{
		if (bulletList[i]->velocity.x = 0)
		{
			bulletList[i]->x = x;
			bulletList[i]->y = y;
			bulletList[i]->lifeCounter = 0;
			bulletList[i]->velocity.x = 10;
			notFound = false;
		}
		i++;
	}
}
