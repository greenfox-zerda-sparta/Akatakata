// #pragma once
#ifndef HERO_H
#define HERO_H
#include <string>
#include "Area.h"

class Hero {
private:
  //std::vector<int> hero_loc;
  int loc_x;
  int loc_y;
  std::string hero_image;
public:
  Hero();
  ~Hero();
  void set_hero_loc(Area* area, int x, int y);
  int get_loc_x();
  int get_loc_y();
  std::string get_hero_image();
  void set_hero_image(std::string changed_image);
};

#endif
