#include <ctime>
#include <cstdlib>
#include "Skeleton.h"
#include "Area.h"

Skeleton::Skeleton(Area* _area) {
  area = _area;
  set_skeleton_loc_random_for_map();
}

Skeleton::~Skeleton() {
}

void Skeleton::set_skeleton_loc_random_for_map() {
  int x_loc = rand() % 10;
  int y_loc = rand() % 10;
  if (area->get_tileMap()[y_loc][x_loc] == 0 || (x_loc == 0 && y_loc == 0)) {
    set_skeleton_loc_random_for_map();
  } else if (area->get_tileMap()[y_loc][x_loc] == 1) {
    skeleton_loc.push_back(x_loc);
    skeleton_loc.push_back(y_loc);
  };
}

std::vector<int> Skeleton::get_skeleton_loc() {
  return skeleton_loc;
}