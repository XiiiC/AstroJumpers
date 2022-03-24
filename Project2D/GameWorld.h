#pragma once
#include "SDL.h"
#include <iostream>
#include <string>

using namespace std;

class GameWorld
{
	GameWorld();
	void GameLoop();
	void Input();
	void Update();
	void Render();
};

