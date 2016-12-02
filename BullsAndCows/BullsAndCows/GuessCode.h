// #pragma once
#ifndef GUESSCODE_H
#define GUESSCODE_H
#include <string>

#include "Code.h"

class GuessCode :  public Code {
private: 
  std::string guess_code;
public:
  GuessCode(std::string input);
  ~GuessCode();
  std::string get_guess_code();
};

#endif