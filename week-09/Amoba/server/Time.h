#ifndef TIME_H
#define TIME_H
#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <string>
#include "SDL_net.h"

class Time {
public:
	Time();
	std::string GetCurrentTime();
  std::string GetTimeFileFormat();
};
#endif

