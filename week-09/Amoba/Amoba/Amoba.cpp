#include <iostream>
#include "Amoba.h"

#define X click_x
#define Y click_y

Amoba::Amoba() {
  environment = new SDL_Graphics();
  game = new GamePlay();
  game->init(*environment);
  SDL_Event event;
  quit = false;
}

Amoba::~Amoba() {
  delete game;
  delete environment;
}

void Amoba::run() {
  while (!quit) {
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        quit = true;
        break;
      }
    case SDL_MOUSEBUTTONDOWN:
      if (event.button.button == SDL_BUTTON_LEFT) {
      //  environment->set_click_x(event.button.x / 30);
     //   environment->set_click_y(event.button.y / 30);
        if (event.button.x < 570 && event.button.y < 570) {
          click_x = event.button.x / 30;
          click_y = event.button.y / 30;
          game->place_stone_on_board(click_x, click_y);
          std::cout << "amoba class click: row: " << click_y << " col: " << click_x << std::endl;
          break;
        }
      }
    }
    game->render(*environment);
  }
}

int Amoba::get_click_x() {
  return click_x;
}
int Amoba::get_click_y() {
  return click_y;
}