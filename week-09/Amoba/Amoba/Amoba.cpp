#include <iostream>
#include "Amoba.h"

Amoba::Amoba() {
  graphics = new SDL_Graphics();
  game = new GamePlay();
  textures = new SDL_Textures;
  textures->make_textures();
  SDL_Event event;
  quit = false;
}

Amoba::~Amoba() {
  delete game;
  delete graphics;
  delete textures;
}

void Amoba::make_new_game() {
  delete game;
  delete graphics;
  delete textures;
  graphics = new SDL_Graphics();
  game = new GamePlay();
  textures = new SDL_Textures;
  textures->make_textures();
}

bool Amoba::is_click_on_board(int x, int y) {
  int board_edge = BOARD_SIZE * textures->get_tile_size();
  return (x < board_edge && y < board_edge);
}

void Amoba::run() {
  while (!quit) {
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    case SDL_MOUSEBUTTONDOWN:
      if ((is_click_on_board(event.button.x, event.button.y)) && game->is_gameover() == 0) {
        game->place_stone_on_board(*textures, event.button.x / 30, event.button.y / 30);
        break;
      }
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        quit = true;
        break;
      case SDLK_r:
        if (game->is_gameover()) {
          make_new_game();
          break;
        }
      }
    }
    game->render(*textures);
  }
}

int Amoba::get_click_x() {
  return click_x;
}
int Amoba::get_click_y() {
  return click_y;
}