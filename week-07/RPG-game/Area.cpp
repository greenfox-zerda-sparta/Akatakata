#include "Area.h"

Area::Area() {
  tileMap = {
    { 1, 1, 1, 0, 1, 0, 1, 1, 1, 1 },
    { 1, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
    { 1, 1, 1, 1, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 1, 1, 1, 1, 0, 1 },
    { 1, 1, 1, 0, 1, 0, 0, 1, 1, 1 }
  };
  map_width = 10;
  map_height = 10;
}

Area::~Area() {
}

std::vector<std::vector <bool>> Area::get_tileMap() {
  return tileMap;
}

int Area::get_map_width() {
  return map_width;
}

int Area::get_map_height() {
  return map_height;
}
