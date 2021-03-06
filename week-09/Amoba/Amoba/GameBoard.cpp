#include "GameBoard.h"

GameBoard::GameBoard() {
  red_stone_id = 1;
  black_stone_id = 2;
  empty_tile_id = 0;
  tilemap = std::vector<std::vector<int>> (BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));
}

GameBoard::~GameBoard() {
}

std::vector<std::vector<int>> GameBoard::get_tilemap() {
  return tilemap;
}

void GameBoard::set_tile(int x, int y, int stone_id) {
  tilemap[x][y] = stone_id;
}

int GameBoard::get_red_stone_id() {
  return red_stone_id;
}

int GameBoard::get_black_stone_id() {
  return black_stone_id;
}
