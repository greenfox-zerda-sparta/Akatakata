//#pragma once
#ifndef USAGE_H
#define USAGE_H
#include <string>
#include "Task.h"

class Usage
{
public:
  Usage();
  ~Usage();
  void show_main_menu(string filename);
  bool is_valid_selector(int argc, char* argv[], string filename, Task list);
  void print_list(int argc, char* argv[], string filename, Task list);
  void append(int argc, char* argv[], string filename, Task list);
  void remove(int argc, char* argv[], string filename, Task list);
  void check(int argc, char* argv[], string filename, Task list);
private:

};

#endif // !USAGE_H