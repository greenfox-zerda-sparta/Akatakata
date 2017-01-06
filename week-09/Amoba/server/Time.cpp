#include "Time.h"

Time::Time() {}



std::string Time::GetCurrentTime() {
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d %X ", &tstruct);
  return buf;
}

std::string Time::GetTimeFileFormat() {
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d %H-%M-%S", &tstruct);
  return buf;
}