#include "Timer.h"

Timer::Timer()
{
	startTicks = 0;
};
void Timer::resetTicksTimer()
{
	startTicks = SDL_GetTicks(); // numbers of milliseconds since start of SDL program
	//printf("timer started! %i \n", startTicks);
}
void Timer::startPerformance()
{
	start = SDL_GetPerformanceCounter();
}
void Timer::endPerformance(std::string perform)
{
	end = SDL_GetPerformanceCounter();

	float secondsElapsed = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000;
	SDL_LogDebug(SDL_LOG_CATEGORY_TEST , "%s Time: %fms", perform, secondsElapsed);
}
int Timer::getTicks()
{
	//printf("getTicks! %i \n", SDL_GetTicks() - startTicks);
	return (SDL_GetTicks() - startTicks); //Return the current time minus the start time
}
bool Timer::GetTime(char* buffer, int buffersize)
{
	//Get the current time
	time_t currentTime =
		std::time(0);
	//Get time information from current time -- secs, mins, etc. and save into a struct
	struct tm* info = localtime(&currentTime);
	//Format the time to (day_num/month_num/year time)
	size_t written = strftime(buffer, buffersize, "%d/%m/%y %T", info);
	//And return the string
	return written != 0;
}