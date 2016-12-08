// #pragma once
#ifndef SKELETON_H
#define SKELETON_H
#include <vector>
#include "Area.h"

class Skeleton {
private:
  std::vector<int> skeleton_loc;
  Area* area;
public:
  Skeleton(Area* area);
  ~Skeleton();
  void set_skeleton_loc_random_for_map();
  std::vector<int> get_skeleton_loc();
};

#endif