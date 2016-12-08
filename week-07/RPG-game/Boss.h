// #pragma once
#ifndef BOSS_H
#define BOSS_H
#include "Area.h"

class Boss {
private:
  int loc_x;
  int loc_y;
  Area* area;
public:
  Boss(Area* area);
  ~Boss();
  int get_loc_x();
  int get_loc_y();
  void set_random_boss_loc();
};
#endif
