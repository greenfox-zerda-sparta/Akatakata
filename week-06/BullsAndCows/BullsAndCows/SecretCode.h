// #pragma once
#ifndef SECRETCODE_H
#define SECRETCODE_H

#include "Code.h"

class SecretCode : public Code {
public:
  SecretCode();
  ~SecretCode();
  void generate_hidden_code(int code_length);
  std::string get_hidden_code();
  void print_formatted_hidden_code();
  unsigned int get_code_length();
};
#endif
