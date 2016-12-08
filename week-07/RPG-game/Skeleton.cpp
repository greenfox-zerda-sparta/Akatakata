#include <vector>
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
  loc_x = rand() % 10;
  loc_y = rand() % 10;
  if (area->get_tileMap()[loc_y][loc_x] == 0 || (loc_x == 0 && loc_y == 0)) {
    set_skeleton_loc_random_for_map();
  }/* else if (area->get_tileMap()[y_loc][x_loc] == 1) {
    loc_x = x_loc;
    loc_y = y_loc;
  };*/
}

int Skeleton::get_loc_x() {
  return loc_x;
}

int Skeleton::get_loc_y() {
  return loc_y;
}