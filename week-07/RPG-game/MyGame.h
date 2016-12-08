// #pragma once
#ifndef MYGAME_H
#define MYGAME_H
#include <vector>
#include "game-engine2.h"
#include "Area.h"
#include "Hero.h"
#include "Skeleton.h"

class MyGame : public Game {
protected:
  Area* area;
  Hero* hero;
  std::vector<Skeleton*> skeletons;
//  Skeleton* skeleton1;
 // Skeleton* skeleton2;
 // Skeleton* skeleton3;
  int skeleton_count;
  std::vector<int> boss_loc;
public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
  void set_random_boss_loc();
};

#endif