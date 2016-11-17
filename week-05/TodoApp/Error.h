// #pragma once
#ifndef Error_H
#define Error_H
#include "ErrorList.h"

class Error : public ErrorList {
public:
  Error();
  ~Error();
  string find_argument_error(int number, char* _input[], Task list);
  string find_nothing_to_add_error(int number, char* _input[], Task list);
  string find_no_index_error_remove(int number, char* _input[], Task list);
  string find_isdigit_error_remove(int number, char* _input[], Task list);
  string find_out_of_bound_error_remove(int number, char* _input[], Task list);
  string find_no_index_error_check(int number, char* _input[], Task list);
  string find_isdigit_error_check(int number, char* _input[], Task list);
  string find_out_of_bound_error_check(int number, char* _input[], Task list);
  string check_for_errors(int number, char* _input[], Task list);
};
#endif
