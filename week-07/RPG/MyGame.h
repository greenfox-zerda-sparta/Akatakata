// #pragma once
#ifndef MYGAME_H
#define MYGAME_H
#include <vector>
#include "game-engine2.h"

class MyGame : public Game {
protected:
  int map_width;
  int map_height;
  std::vector<int> hero_loc;
  std::vector<int> skeleton_loc;
  std::vector<int> boss_loc;
  std::string hero_image;
  int skeleton_count;

public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
  void set_hero_loc(int x, int y);
  std::vector<int> get_hero_location();
  void move(GameContext& context);
  void set_hero_image(std::string changed_image);
  void set_skeleton_loc_random();
  void set_random_boss_loc();
};

#endif
