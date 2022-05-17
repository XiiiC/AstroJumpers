#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <SDL.h>
#include <ctime>
#include <string>

class Timer
{
private:
	int startTicks; // SDL time when the timer started
	Uint64 start;
	Uint64 end;
public:
	Timer();
	//SDL timer stuff
	void resetTicksTimer(); // resets timer to zero
	void startPerformance();
	void endPerformance(std::string perform);
	int getTicks(); // returns how much time has passed since timer has been reset
	bool GetTime(char* buffer, int buffersize);
};

