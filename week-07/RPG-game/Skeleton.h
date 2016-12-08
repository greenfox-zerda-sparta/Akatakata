// #pragma once
#ifndef SKELETON_H
#define SKELETON_H
#include "Character.h"
#include "Area.h"

class Skeleton : public Character {
private:
public:
  Skeleton(Area* _area);
  ~Skeleton();
  void set_skeleton_loc_random_for_map();
};

#endif