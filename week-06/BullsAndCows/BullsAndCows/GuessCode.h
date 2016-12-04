// #pragma once
#ifndef GUESSCODE_H
#define GUESSCODE_H

#include <string>
#include "Code.h"

class GuessCode :  public Code {
public:
  GuessCode();
  ~GuessCode();
  void set_code(std::string code_text);
  std::string get_guess_code();
};

#endif