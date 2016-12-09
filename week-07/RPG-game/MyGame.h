// #pragma once
#ifndef MYGAME_H
#define MYGAME_H
#include <vector>
#include "game-engine2.h"
#include "Area.h"
#include "Hero.h"
#include "Skeleton.h"
#include "Boss.h"

class MyGame : public Game {
protected:
  Area* area;
  Hero* hero;
  Boss* boss;
  std::vector<Skeleton*> skeletons;
  int skeleton_count;
  int keypress_count;
public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
};

#endif