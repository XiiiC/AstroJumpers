#pragma once
#include <vector>
#include <iostream>
#include "SDL.h"

using namespace std;

class BulletContainer
{
public:
	BulletContainer();
	~BulletContainer();
	void Init(int eY, int eX, int eNum, int TTL);
	void Add(int x, int y);
	void Input(int fire);


};

