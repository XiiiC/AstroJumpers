#include "FileLogger.h"

//FileLogger::FileLogger(const std::string& logFilePath)
FileLogger::FileLogger()
{
	char timestr[32];
	Timestamp(timestr, 32);
	const std::string path = "content/logs/game-log.txt";
	// open log file..
	logFile.open(path.c_str());
	// and redirect SDL Log messages
	SDL_LogSetOutputFunction(&FileLogger::LogCB, (void *)this);
}

FileLogger::~FileLogger(void)
{
}

void FileLogger::LogCB(void* userdata, int category, SDL_LogPriority priority, const char* message)
{
	FileLogger* ptr = (FileLogger*)userdata;
	if (ptr)
	{
		ptr->LogData(userdata, category, priority, message);
	}
}

void FileLogger::LogData(void* userdata, int category, SDL_LogPriority priority, const char* message)
{
	//Print the message to the console (as normal)
	std::cout << message << std::endl;
	//Write this line to the log file
	logFile << message << std::endl;

}
bool FileLogger::Timestamp(char* buffer, int buffersize)
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
void FileLogger::CloseLog()
{
	logFile.close();
}
