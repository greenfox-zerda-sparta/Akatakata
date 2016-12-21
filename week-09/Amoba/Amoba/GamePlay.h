// #pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "MainGame.h"
#include "GameBoard.h"

class GamePlay : public MainGame {
private:
  GameBoard* board; 
  bool is_red_turn;
public:
  GamePlay();
  ~GamePlay();
  virtual void init(SDL_Graphics& environment);
  virtual void render(SDL_Graphics& environment);
  void place_stone_on_board(int x, int y);
  GameBoard* get_board();
};
#endif
