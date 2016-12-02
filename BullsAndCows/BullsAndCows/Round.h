// #pragma once
#ifndef ROUND_H
#define ROUND_H

#include "SecretCode.h"
#include "GuessCode.h"

class Round {
private: 
  unsigned int bulls;
  unsigned int cows;
  unsigned int round_number;
  SecretCode hidden;
public:
  Round(unsigned int round, SecretCode hidden_code);
  ~Round();
  void reset_bulls();
  unsigned int get_bulls();
  void reset_cows();
  void evaluate_guess_for_bulls(GuessCode guess);
  void evaluate_guess_for_cows(GuessCode guess);
  void play_one_round();
};

#endif