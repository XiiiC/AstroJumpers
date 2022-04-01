#pragma once
#include <vector>
#include <iostream>
#include "SDL.h"
#include "Bullet.h"

using namespace std;

class BulletContainer
{
public:
	BulletContainer();
	~BulletContainer();
	void Init(int eY, int eX, int eNum, int ttl);
	void Add(int x, int y);
	void Input(int fire);
	void Update();
	void Render(SDL_Renderer* renderer);

	vector<Bullet*> bulletList;

	void Shoot(); // if able shoots a bullet forwards
	int x, y, num; // pos and max bullet spawn
	int ttl; // lifetimeof bullets
	SDL_Rect rect;

};

