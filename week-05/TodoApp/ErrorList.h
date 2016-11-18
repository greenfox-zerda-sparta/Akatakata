//#pragma once
#ifndef ERRORLIST_H
#define ERRORLIST_H
#include <vector>
#include <string>

using namespace std;

class ErrorList {
public:
  ErrorList();
  ~ErrorList();
  void check_for_errors(int number, char* _input[], Task list);
  string find_argument_error(int number, char* _input[], Task list);
  string find_nothing_to_add_error(int number, char* _input[], Task list);
  string find_no_index_error_remove(int number, char* _input[], Task list);
  string find_isdigit_error_remove(int number, char* _input[], Task list);
  string find_out_of_bound_error_remove(int number, char* _input[], Task list);
  string find_no_index_error_check(int number, char* _input[], Task list);
  string find_isdigit_error_check(int number, char* _input[], Task list);
  string find_out_of_bound_error_check(int number, char* _input[], Task list);
};
#endif