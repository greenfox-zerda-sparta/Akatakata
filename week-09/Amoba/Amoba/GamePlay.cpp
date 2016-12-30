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

void GamePlay::render(SDL_Textures& textures) {
  for (unsigned int row = 0; row < BOARD_SIZE; row++) {
    for (unsigned int col = 0; col < BOARD_SIZE; col++) {
      switch (board->get_tilemap()[row][col]) {
      case 0:
        textures.render_sprite("img/panel_beigeLight.bmp", col * TILE_SIZE, row * TILE_SIZE);
        break;
      case 1:
        textures.render_sprite("img/circle.bmp", col * TILE_SIZE, row * TILE_SIZE);
        break;
      case 2:
        textures.render_sprite("img/ex.bmp", col * TILE_SIZE, row * TILE_SIZE);
        break;
      }
    }
  }
  if (gameover == true) {
    is_red_turn ? textures.render_sprite("img/circle.bmp", 600, 100) : textures.render_sprite("img/ex.bmp", 600, 100);
    textures.render_text("WINS", 635, 103);
    textures.render_text("Press R to play again.", 590, 150);
    textures.render_text("Press ESC to quit.", 590, 172);
  } 
  textures.render_text("Current player: ", 590, 40);
  textures.render();
}

void GamePlay::show_next_player(SDL_Textures& textures, std::string filename) {
  textures.render_sprite(filename, 725, 36);
}

void GamePlay::place_stone_on_board(SDL_Textures& textures, int x, int y) {
  if (board->get_tilemap()[y][x] != 0) { 
    // do nothing
  } else {
    if (is_red_turn == true) {
      board->set_tile(y, x, 1);
      is_win(x, y);
      is_gameover();
      if (!gameover) {
        show_next_player(textures, "img/ex.bmp");
        is_red_turn = false;
      }
    } else {
      board->set_tile(y, x, 2);
      is_win(x, y);
      is_gameover();
      if (!gameover) {
        show_next_player(textures, "img/circle.bmp");
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
