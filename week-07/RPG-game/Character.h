//#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Area.h"

class Character {
protected:
  int loc_x;
  int loc_y;
  Area* area;
public:
  Character();
  ~Character();
  int get_loc_x();
  int get_loc_y();
  void random_move();
  virtual void set_loc(int x, int y);
};

#endif

