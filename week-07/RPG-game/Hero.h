// #pragma once
#ifndef HERO_H
#define HERO_H
#include <string>
#include <vector>
#include "Area.h"

class Hero {
private:
  std::vector<int> hero_loc;
  std::string hero_image;
public:
  Hero();
  ~Hero();
  void set_hero_loc(Area* area, int x, int y);
  std::vector<int> get_hero_location();
  std::string get_hero_image();
  void set_hero_image(std::string changed_image);
};

#endif
