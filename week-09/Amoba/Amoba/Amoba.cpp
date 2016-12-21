#include "Amoba.h"

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
    SDL_WaitEvent(&event);
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
    }
    game->render(*environment);
  }
}