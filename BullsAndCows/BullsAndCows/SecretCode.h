// #pragma once
#ifndef SECRETCODE_H
#define SECRETCODE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm> 
#include <ctime>

#include "Code.h"

class SecretCode : public Code {
private:
  std::string hidden_code;
public:
  SecretCode();
  ~SecretCode();
  void generate_hidden_code(int code_length);
  std::string get_hidden_code();
  void print_formatted_hidden_code();
  unsigned int get_code_length();
};
#endif
