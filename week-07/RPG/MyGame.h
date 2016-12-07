// #pragma once
#ifndef MYGAME_H
#define MYGAME_H
#include <vector>
#include "game-engine2.h"

class MyGame : public Game {
protected:
  std::vector<int> hero_loc;
  int map_width;
  int map_height;
  std::string hero_image;
public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
  void set_hero_loc(int x, int y);
  std::vector<int> get_hero_location();
  void move(GameContext& context);
  void set_hero_image(std::string changed_image);
};

#endif
