// #pragma once
#ifndef SKELETON_H
#define SKELETON_H
#include "Area.h"

class Skeleton {
private:
  int loc_x;
  int loc_y;
  Area* area;
public:
  Skeleton(Area* area);
  ~Skeleton();
  void set_skeleton_loc_random_for_map();
  int get_loc_x();
  int get_loc_y();
};

#endif