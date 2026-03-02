#include "logger.hpp"
#include <cstdio>

const char *Logger::levelName[5] =
{
	"INFO",
	"WARNING",
	"ERROR",
	"DEBUG",
	"CRITICAL"
};

const char *Logger::levelBgColor[5] =
{
	BG_GREEN BLACK,
	BG_YELLOW BLACK,
	BG_RED WHITE,
	BG_CYAN BLACK,
	BG_MAGENTA WHITE
};

const char *Logger::levelMsgColor[5] =
{
	GREEN,
	YELLOW,
	RED,
	CYAN,
	MAGENTA
};

static std::string currentTime(void)
{
	char buf[64];
	std::time_t t = std::time(0);

	std::strftime(
		buf,
		sizeof(buf),
		"%a, %d %b %Y %H:%M:%S",
		std::localtime(&t)
	);
	return buf;
}

void Logger::logMessage(LogLevel level, const std::string &msg,
	const char *file, const char *func, int line)
{
	std::ofstream logFile("ircserver.log", std::ios::app);

	std::cout
		<< BLUE << "[" << currentTime() << "] " << RESET
		<< levelBgColor[level] << " " << levelName[level] << " " << RESET
		<< GRAY << "[" << file << ":" << func << ":" << line << "] " << RESET
		<< levelMsgColor[level] << msg << RESET
		<< std::endl;

	logFile
		<< "[" << currentTime() << "] "
		<< levelName[level]
		<< " [" << file << ":" << func << ":" << line << "] "
		<< msg << std::endl;
}
