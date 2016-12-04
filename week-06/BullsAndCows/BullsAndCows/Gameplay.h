// #pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "MainMessage.h"
#include "SecretCode.h"
#include "GuessCode.h"

class Gameplay {
private:
  unsigned int round_counter;
  bool is_winner;
public:
  Gameplay();
  ~Gameplay();
  void start_game();
  void gameflow(SecretCode hidden);
  bool check_winner(SecretCode hidden, unsigned int guessed_bulls);
  void set_is_winner(bool win_or_not);
  void end_game(SecretCode hidden);
  void ask_for_new_game();
  void reset_round_counter();
};

#endif