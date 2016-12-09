#include <vector>
#include "Boss.h"

Boss::Boss(Area* _area) {
  area = _area;
  set_random_boss_loc();
}

Boss::~Boss() {
}

void Boss::set_random_boss_loc() {
  loc_x = rand() % 10;
  loc_y = rand() % 10;
  if (area->get_tileMap()[loc_x][loc_y] == 0 && (loc_x == 0 && loc_y == 0)) {
    set_random_boss_loc();
  } 
}