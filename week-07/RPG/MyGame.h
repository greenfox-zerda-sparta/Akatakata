// #pragma once
#ifndef MYGAME_H
#define MYGAME_H
#include "game-engine2.h"

class MyGame : public Game {
protected:
  int rows = 10;
  int cols = 10;
public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
};

#endif
