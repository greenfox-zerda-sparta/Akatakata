// #pragma once
#ifndef BOSS_H
#define BOSS_H
#include "Character.h"
#include "Area.h"

class Boss : public Character {
private:
public:
  Boss(Area* _area);
  ~Boss();
  void set_random_boss_loc();
};
#endif
