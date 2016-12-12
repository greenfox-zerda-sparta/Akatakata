#include <vector>
#include <cstdlib>
#include "Skeleton.h"
#include "Area.h"

Skeleton::Skeleton(Area* _area) {
  area = _area;
  set_skeleton_loc_random_for_map();
  level = 1;
  HP = 2 * level * (rand() % 6 + 1);
  DP = (level / 2) * (rand() % 6 + 1);
  SP = level * (rand() % 6 + 1);
}

Skeleton::~Skeleton() {
}

void Skeleton::set_skeleton_loc_random_for_map() {
  loc_x = rand() % 10;
  loc_y = rand() % 10;
  if (area->get_tileMap()[loc_x][loc_y] == 0 || (loc_x == 0 && loc_y == 0)) {
    set_skeleton_loc_random_for_map();
  }
}
