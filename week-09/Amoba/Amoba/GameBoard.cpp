#include "GameBoard.h"

GameBoard::GameBoard() {
  red_stone_id = 1;
  blac_stone_id = 2;
  empty_tile_id = 0;
  tilemap = std::vector<std::vector<int>> (BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));;
  tile_src = "img/panel_beigeLight.bmp";
}

GameBoard::~GameBoard() {
}

std::vector<std::vector<int>> GameBoard::get_tilemap() {
  return tilemap;
}

std::string GameBoard::get_tile_src() {
  return tile_src;
}

void GameBoard::set_tile(int x, int y, int stone_id) {
  tilemap[x][y] = stone_id;
}

