//#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Area.h"

class Character {
protected:
  int loc_x;
  int loc_y;
  Area* area;
  int HP;
  int DP;
  int SP;
  int level;
  int max_HP;
  int max_DP;
  int max_SP;
public:
  Character();
  ~Character();
  int get_loc_x();
  int get_loc_y();
  void random_move();
  bool is_valid_loc(int x, int y);
  virtual void set_loc(int x, int y);
  virtual void set_HP(int HP_change);
};

#endif

