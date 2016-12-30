// #pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <string>
#include <vector>

#define BOARD_SIZE 19

class GameBoard  {
  std::string tile_src;
  std::string red_stone_src;
  std::string black_src;
  int board_size;
  int red_stone_id;
  int blac_stone_id;
  int empty_tile_id;
  std::vector<std::vector<int>> tilemap;
public:
  GameBoard();
  ~GameBoard();
  std::vector<std::vector<int>> get_tilemap();
  std::string get_tile_src();
  void set_tile(int x, int y, int stone_id);
};
#endif

