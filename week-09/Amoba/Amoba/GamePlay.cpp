#include "GamePlay.h"
#include <iostream>
#include <algorithm>

GamePlay::GamePlay() {
  board = new GameBoard;
  is_red_turn = true;
  gameover = false;
}

GamePlay::~GamePlay() {
  delete board;
}

void GamePlay::init(SDL_Graphics& environment) {
  environment.load_file("img/panel_beigeLight.bmp");
  environment.load_file("img/circle.bmp");
  environment.load_file("img/ex.bmp");
  environment.create_text_texture("Current player: ", 18);
}

void GamePlay::render(SDL_Graphics& environment) {
  for (unsigned int row = 0; row < 19; row++) {
    for (unsigned int col = 0; col < 19; col++) {
      switch (board->get_tilemap()[row][col]) {
      case 0:
        environment.draw_sprite("img/panel_beigeLight.bmp", col * 30, row * 30);
        break;
      case 1:
        environment.draw_sprite("img/circle.bmp", col * 30, row * 30);
        break;
      case 2:
        environment.draw_sprite("img/ex.bmp", col * 30, row * 30);
        break;
      }
    }
  }
  environment.draw_text("Current player: ", 600, 40);
  environment.render();
}

void GamePlay::change_current_player(SDL_Graphics& environment, std::string filename) {
  environment.draw_sprite(filename, 725, 36);
}

void GamePlay::place_stone_on_board(SDL_Graphics& environment, int x, int y) {
  if (board->get_tilemap()[y][x] != 0) { 
    // error message ?
  } else {
    if (is_red_turn == true) {
      board->set_tile(y, x, 1);
      change_current_player(environment, "img/ex.bmp");
      is_red_turn = false;
      is_win(x, y);
      is_gameover();
    } else {
      board->set_tile(y, x, 2);
      change_current_player(environment, "img/circle.bmp");
      is_red_turn = true;
      is_win(x, y);
      is_gameover();
    }
  }
}

GameBoard* GamePlay::get_board() {
  return board;
}

bool GamePlay::is_win_horizontal(int x, int y) {
  for (unsigned int col = 0; col < board->get_tilemap().size() - 4; col++) {
    for (unsigned int row = 0; row < board->get_tilemap().size(); row++) {
      if (board->get_tilemap()[row][col] != 0) {
        if (board->get_tilemap()[row][col] == board->get_tilemap()[row][col + 1] &&
            board->get_tilemap()[row][col] == board->get_tilemap()[row][col + 2] &&
            board->get_tilemap()[row][col] == board->get_tilemap()[row][col + 3] &&
            board->get_tilemap()[row][col] == board->get_tilemap()[row][col + 4]) {
          return true;
        }
      }
    }
  }
  return false;
}

bool GamePlay::is_win_vertical(int x, int y) {
  for (unsigned int col = 0; col < board->get_tilemap().size(); col++) {
    for (unsigned int row = 0; row < board->get_tilemap().size() - 4; row++) {
      if (board->get_tilemap()[row][col] != 0) {
        if (board->get_tilemap()[row][col] == board->get_tilemap()[row + 1][col] &&
          board->get_tilemap()[row][col] == board->get_tilemap()[row + 2][col] &&
          board->get_tilemap()[row][col] == board->get_tilemap()[row + 3][col] &&
          board->get_tilemap()[row][col] == board->get_tilemap()[row + 4][col]) {
          return true;
        }
      }
    }
  }
  return false;
}

bool GamePlay::is_win_diagonal1(int x, int y) {
  for (unsigned int col = 0; col < board->get_tilemap().size() - 4; col++) {
    for (unsigned int row = 0; row < board->get_tilemap().size() - 4; row++) {
      if (board->get_tilemap()[row][col] != 0) {
        if (board->get_tilemap()[row][col] == board->get_tilemap()[row + 1][col + 1] &&
          board->get_tilemap()[row][col] == board->get_tilemap()[row + 2][col + 2] &&
          board->get_tilemap()[row][col] == board->get_tilemap()[row + 3][col + 3] &&
          board->get_tilemap()[row][col] == board->get_tilemap()[row + 4][col + 4]) {
          return true;
        }
      }
    }
  }
  return false;
}

/*
bool GamePlay::is_win_diagonal2(int x, int y) {
  for (unsigned int col = board->get_tilemap().size() - 1; col > 3; col++) {
    for (unsigned int row = board->get_tilemap().size() - 1; row > 3; row++) {
      if (board->get_tilemap()[row][col] != 0) {
        if (board->get_tilemap()[row][col] == board->get_tilemap()[row - 1][col - 1] &&
          board->get_tilemap()[row][col] == board->get_tilemap()[row - 2][col - 2] &&
          board->get_tilemap()[row][col] == board->get_tilemap()[row - 3][col - 3] &&
          board->get_tilemap()[row][col] == board->get_tilemap()[row - 4][col - 4]) {
          return true;
        }
      }
    }
  }
  return false;
}
*/

bool GamePlay::is_win(int x, int y) {
  if (is_win_horizontal(x, y) || is_win_vertical(x, y) || is_win_diagonal1(x, y)) {
 // if (is_win_h(x, y)) {
    std::cout << "WIN" << std::endl;
    gameover = 1;
    return true;
  }
  return false;
}

bool GamePlay::is_gameover() {
  if (gameover == 1) {
    return true;
  }
  return false;
}
/*
bool GamePlay::is_win_h(int x, int y) {
  std::vector<int> sample1(5, 1);
  for (int i = 0; i < 5; i++) {
    if (x - i > -1 && x + i < 19) {
      std::vector<int> to_check(board->get_tilemap()[x - i][y], )
      return std::equal(board->get_tilemap()[x - i][y], board->get_tilemap()[x - i + 4][y], sample1.begin());
    }
    if (y - i > -1 && y + i < 19) {
      return std::equal(board->get_tilemap()[x][y - i], board->get_tilemap()[x][y - i + 4], sample1.begin());
    }
  }
  return false;
}*/