// #pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "MainMessage.h"
#include "SecretCode.h"
#include "GuessCode.h"

class Gameplay {
private:
  unsigned int bulls;
  unsigned int cows;
  unsigned int round;
public:
  Gameplay();
  ~Gameplay();
  void start_game();
  void reset_bulls();
  void reset_cows();
  void reset_round();
  void evaluate_guess_for_bulls(SecretCode hidden, GuessCode guess);
  void evaluate_guess_for_cows(SecretCode hidden, GuessCode guess);
  bool is_winner();
  void play_one_round(SecretCode hidden);
  void end_game(SecretCode hidden);
  void ask_for_new_game();
  void gameflow(SecretCode hidden);
};

#endif