// #pragma once
#ifndef AREA_H
#define AREA_H

#include <vector>

class Area {
private:
  std::vector<std::vector <bool>> tileMap;
  int map_width;
  int map_height;
public:
  Area();
  ~Area();
  std::vector<std::vector <bool>> get_tileMap();
  int get_map_width();
  int get_map_height();
};
#endif
