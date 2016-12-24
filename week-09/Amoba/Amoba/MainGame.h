// #pragma once
#ifndef MAINGAME_H
#define MAINGAME_H
#include "SDL_Graphics.h"

class MainGame {
public:
  virtual void init(SDL_Graphics& environment) = 0;
  virtual void render(SDL_Graphics& environment) = 0;
  virtual void place_stone_on_board(SDL_Graphics& environment, int x, int y) = 0;
  virtual bool is_gameover() = 0;
};
#endif
