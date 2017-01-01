#include "GamePlay.h"
#include <iostream>
#include <algorithm>

GamePlay::GamePlay() {
  board = new GameBoard;
  is_red_turn = true;
  gameover = false;
  marks_to_win = 5;
}

GamePlay::~GamePlay() {
  delete board;
}

void GamePlay::render(SDL_Textures& textures) {
  for (unsigned int row = 0; row < BOARD_SIZE; row++) {
    for (unsigned int col = 0; col < BOARD_SIZE; col++) {
      switch (board->get_tilemap()[row][col]) {
      case 0:
        textures.render_sprite("tile", col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE);
        break;
      case 1:
        textures.render_sprite("red stone", col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE);
        break;
      case 2:
        textures.render_sprite("black stone", col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE);
        break;
      }
    }
  }
  if (gameover == true) {
    is_red_turn ? textures.render_sprite("red stone", 620, 100, TILE_SIZE, TILE_SIZE) : textures.render_sprite("black stone", 620, 100, TILE_SIZE, TILE_SIZE);
    textures.render_text("show winner", 655, 103);
    textures.render_sprite("tile", 615, 190, 110, 40);
    textures.render_sprite("tile", 640, 250, 60, 40);
    textures.render_text_button("button play again", 630, 200, 110, 40);
    textures.render_text_button("button exit", 655, 260, 60, 40);
  } 
  textures.render_text("show player", 590, 40);
  textures.render();
}

void GamePlay::show_next_player(SDL_Textures& textures, std::string name) {
  textures.render_sprite(name, 725, 36, TILE_SIZE, TILE_SIZE);
}

void GamePlay::place_stone_on_board(SDL_Textures& textures, int x, int y) {
  if (board->get_tilemap()[y][x] == 0) {
    if (is_red_turn == true) {
      board->set_tile(y, x, board->get_red_stone_id());
      is_win(x, y);
      is_gameover();
      if (!gameover) {
        show_next_player(textures, "black stone");
        is_red_turn = false;
      }
    } else {
      board->set_tile(y, x, board->get_black_stone_id());
      is_win(x, y);
      is_gameover();
      if (!gameover) {
        show_next_player(textures, "red stone");
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
  for (int i = 0 - (marks_to_win - 1); i < marks_to_win; i++) {
    int Y = y + i * y_step;
    int X = x + i * x_step;
    if (Y < 0 || X < 0 || Y > BOARD_SIZE - 1 || X > BOARD_SIZE -1) {
      continue;
    }
    if (board->get_tilemap()[Y][X] == board->get_tilemap()[y][x]) {
      count_marks++;
    } else {
      count_marks = 0;
    }
    if (count_marks >= marks_to_win) {
      return true;
    }
  }
  return false;
}
