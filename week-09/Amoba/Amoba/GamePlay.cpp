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
  environment.create_sprite_from_file("img/panel_beigeLight.bmp");
  environment.create_sprite_from_file("img/circle.bmp");
  environment.create_sprite_from_file("img/ex.bmp");
  environment.create_text_texture("Current player: ", 18);
  environment.create_text_texture("WINS", 20);
  environment.create_text_texture("Press R to play again.", 18);
  environment.create_text_texture("Press ESC to quit.", 18);
}

void GamePlay::render(SDL_Graphics& environment) {
  for (unsigned int row = 0; row < 19; row++) {
    for (unsigned int col = 0; col < 19; col++) {
      switch (board->get_tilemap()[row][col]) {
      case 0:
        environment.render_sprite("img/panel_beigeLight.bmp", col * 30, row * 30);
        break;
      case 1:
        environment.render_sprite("img/circle.bmp", col * 30, row * 30);
        break;
      case 2:
        environment.render_sprite("img/ex.bmp", col * 30, row * 30);
        break;
      }
    }
  }
  if (gameover == true) {
    is_red_turn ? environment.render_sprite("img/circle.bmp", 600, 100) : environment.render_sprite("img/ex.bmp", 600, 100);
    environment.render_text("WINS", 635, 103);
    environment.render_text("Press R to play again.", 590, 150);
    environment.render_text("Press ESC to quit.", 590, 172);
  } 
  environment.render_text("Current player: ", 590, 40);
  environment.render();
}

void GamePlay::show_next_player(SDL_Graphics& environment, std::string filename) {
  environment.render_sprite(filename, 725, 36);
}

void GamePlay::place_stone_on_board(SDL_Graphics& environment, int x, int y) {
  if (board->get_tilemap()[y][x] != 0) { 
    // error message ?
  } else {
    if (is_red_turn == true) {
      board->set_tile(y, x, 1);
      is_win(x, y);
      is_gameover();
      if (!gameover) {
        show_next_player(environment, "img/ex.bmp");
        is_red_turn = false;
      }
    } else {
      board->set_tile(y, x, 2);
      is_win(x, y);
      is_gameover();
      if (!gameover) {
        show_next_player(environment, "img/circle.bmp");
        is_red_turn = true;
      }
    }
  }
}

bool GamePlay::is_win(int x, int y) {
  if (is_winner(x, y, 1, 0) || is_winner(x, y, 0, 1) || is_winner(x, y, 1, 1) || is_winner(x, y, 1, -1)) {
    gameover = true;
    return true;
  } else {
    return false;
  }
}

bool GamePlay::is_gameover() {
  return gameover;
}

bool GamePlay::is_winner(int x, int y, int x_step, int y_step) {
  int count_marks = 0;
  for (int i = -4; i < 5; i++) {
    int Y = y + i * y_step;
    int X = x + i * x_step;
    if (Y < 0 || X < 0 || Y > 18 || X > 18) {
      continue;
    }
    if (board->get_tilemap()[Y][X] == board->get_tilemap()[y][x]) {
      count_marks++;
    } else {
      count_marks = 0;
    }
    if (count_marks >= 5) {
      return true;
    }
  }
  return false;
}
