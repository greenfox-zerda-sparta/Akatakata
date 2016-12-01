// #pragma once
#ifndef SECRETCODE_H
#define SECRETCODE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm> 
#include <ctime>

class SecretCode {
private:
  std::string container;
  std::string hidden_code;
  unsigned int code_length;
public:
  SecretCode();
  ~SecretCode();
  void generate_hidden_code(int code_length);
  std::string get_hidden_code();
  void print_formatted_hidden_code();
};
#endif
