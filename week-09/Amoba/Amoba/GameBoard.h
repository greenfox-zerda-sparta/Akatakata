// #pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <string>
#include <vector>

#define BOARD_SIZE 19

class GameBoard  {
  int board_size;
  int red_stone_id;
  int black_stone_id;
  int empty_tile_id;
  std::vector<std::vector<int>> tilemap;
public:
  GameBoard();
  ~GameBoard();
  std::vector<std::vector<int>> get_tilemap();
  void set_tile(int x, int y, int stone_id);
  int get_red_stone_id();
  int get_black_stone_id();
};
#endif

