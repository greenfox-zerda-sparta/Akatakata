// #pragma once
#ifndef HERO_H
#define HERO_H
#include <string>
#include "Character.h"
#include "Area.h"

class Hero :public Character {
private:
  std::string hero_image;
public:
  Hero(Area* _area);
  ~Hero();
  void set_hero_loc(int x, int y);
  std::string get_hero_image();
  void set_hero_image(std::string changed_image);
};

#endif
