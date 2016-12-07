// #pragma once
#ifndef MYGAME_H
#define MYGAME_H
#include "game-engine2.h"

class MyGame : public Game {
protected:
  int tileMapWidth = 8;
  int tileMapHeight = 8;
public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
};

#endif
