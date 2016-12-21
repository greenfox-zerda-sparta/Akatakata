#include "GamePlay.h"
#include <iostream>

GamePlay::GamePlay() {
  board = new GameBoard;
  is_red_turn = true;
}

GamePlay::~GamePlay() {
  delete board;
}

void GamePlay::init(SDL_Graphics& environment) {
  environment.load_file("img/panel_beigeLight.bmp");
  environment.load_file("img/circle.bmp");
  environment.load_file("img/ex.bmp");
}

void GamePlay::render(SDL_Graphics& environment) {
  for (unsigned int row = 0; row < 19; row++) {
    for (unsigned int col = 0; col < 19; col++) {
      if (board->get_tilemap()[row][col] == 0) {
        environment.draw_sprite("img/panel_beigeLight.bmp", col * 30, row * 30);
      }
      if (board->get_tilemap()[row][col] == 1) {
        environment.draw_sprite("img/circle.bmp", col * 30, row * 30);
      }
      if (board->get_tilemap()[row][col] == 2) {
        environment.draw_sprite("img/ex.bmp", col * 30, row * 30);
      }
    }
  }
  environment.render();
}

void GamePlay::place_stone_on_board(int x, int y) {
  if (is_red_turn == true) {
    board->set_tile(y, x, 1);
    std::cout << board->get_tilemap()[y][x] << std::endl;
    is_red_turn = false;
  } else {
    board->set_tile(y, x, 2);
    std::cout << board->get_tilemap()[y][x] << std::endl;
    is_red_turn = true;
  }
}

GameBoard* GamePlay::get_board() {
  return board;
}