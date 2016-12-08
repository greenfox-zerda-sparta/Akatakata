// #pragma once
#ifndef MYGAME_H
#define MYGAME_H
#include <vector>
#include "game-engine2.h"
#include "Area.h"
#include "Hero.h"

class MyGame : public Game {
protected:
  Area* area;
  Hero* hero;
  std::vector<int> skeleton_loc;
  std::vector<int> boss_loc;
  int skeleton_count;
public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
  void set_skeleton_loc_random();
  void set_random_boss_loc();
};

#endif