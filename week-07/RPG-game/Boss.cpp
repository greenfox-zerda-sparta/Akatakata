#include <vector>
#include "Boss.h"

Boss::Boss(Area* _area) {
  area = _area;
  set_random_boss_loc();
}

Boss::~Boss() {
}

int Boss::get_loc_x() {
  return loc_x;
}

int Boss::get_loc_y() {
  return loc_y;
}

void Boss::set_random_boss_loc() {
  loc_x = rand() % 10;
  loc_y = rand() % 10;
  if (area->get_tileMap()[loc_y][loc_x] == 0 && (loc_x == 0 && loc_y == 0)) {
    set_random_boss_loc();
  } 
}