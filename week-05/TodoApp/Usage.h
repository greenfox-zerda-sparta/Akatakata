//#pragma once
#ifndef USAGE_H
#define USAGE_H
#include <string>
#include "Task.h"

class Usage
{
public:
  Usage(int argc, char* argv[], string filename, Task list);
  ~Usage();
  void show_main_menu(string filename);
  void start();
  void select_usage();
  void print_list();
  void append();
  void remove();
  void check();
  bool is_valid_selector();
  bool is_valid_append();
  bool is_valid_remove();
  bool is_valid_check();
private:
  int argc;
  char** argv;
  string filename;
  Task list;
};

#endif // !USAGE_H