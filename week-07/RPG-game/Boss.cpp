#include <vector>
#include "Boss.h"

Boss::Boss(Area* _area) {
  area = _area;
  set_random_boss_loc();
  level = rand() % 3 + 2;
  max_HP = 2 * level * (rand() % 6 + 1) + (rand() % 6 + 1);
  max_DP = (level / 2) * (rand() % 6 + 1) + (rand() % 6 + 1) / 2;
  max_SP = level * (rand() % 6 + 1) + level;
  HP = max_HP;
  SP = max_SP;
  DP = max_DP;
}

Boss::~Boss() {
}

void Boss::set_random_boss_loc() {
  loc_x = rand() % 10;
  loc_y = rand() % 10;
  if (area->get_tileMap()[loc_x][loc_y] == 0 || (loc_x == 0 && loc_y == 0)) {
    set_random_boss_loc();
  } 
}