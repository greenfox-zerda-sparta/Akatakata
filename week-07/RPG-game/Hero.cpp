#include <vector>
#include "Hero.h"
#include "Area.h"

Hero::Hero(Area* _area) {
  area = _area;
  loc_x = 0;
  loc_y = 0;
  hero_image = "img/hero-down.bmp";
}

Hero::~Hero() {
}

void Hero::set_hero_loc(int x, int y) {
  // checking for map boundaries
  if (x > area->get_map_width() - 1) {
    x = area->get_map_width() - 1;
  } else if (x < 0) {
    x = 0;
  }
  if (y > area->get_map_height() - 1) {
    y = area->get_map_height() - 1;
  } else if (y < 0) {
    y = 0;
  }
  // checking for walls
  if (area->get_tileMap()[x][y] == 0) {
    // empty line for "do nothing"
  } else {
    loc_x = x;
    loc_y = y;
  }
}

std::string Hero::get_hero_image() {
  return hero_image;
}
void Hero::set_hero_image(std::string changed_image) {
  hero_image = changed_image;
}