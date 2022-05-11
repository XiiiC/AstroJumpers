#pragma once
#pragma warning(disable : 4996)
#include <fstream>
#include <iostream>
#include "SDL.h"

class FileLogger
{
public:
	//FileLogger(const std::string& logFilePath);
	FileLogger();
	~FileLogger(void);
	//The “callback” function
	static void LogCB(void* userdata, int category, SDL_LogPriority priority, const char* message);
	void LogData(void* userdata, int category, SDL_LogPriority priority, const char* message);
	bool Timestamp(char* buffer, int buffersize);
	void CloseLog();
private:
	std::ofstream logFile;
};

