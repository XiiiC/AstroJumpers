#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <SDL.h>
#include<ctime>

class Timer
{
private:
	int startTicks; // SDL time when the timer started
public:
	Timer();
	//SDL timer stuff
	void resetTicksTimer(); // resets timer to zero
	int getTicks(); // returns how much time has passed since timer has been reset
	bool GetTime(char* buffer, int buffersize);
};

