//#pragma once
#ifndef ERRORLIST_H
#define ERRORLIST_H
#include <vector>
#include <string>

using namespace std;

class ErrorList
{
public:
  ErrorList();
  ~ErrorList();
  void read_from_file(string filename);
  void add_error(string err);
  string error_by_index(int index);
  int get_length();
private:
  vector<string> errors;
};
#endif
