#include "GamePlay.h"


GamePlay::GamePlay() {
}


GamePlay::~GamePlay() {
}

void GamePlay::init(SDL_Graphics& environment) {
  environment.load_file("img/panel_beigeLight.bmp");
}

void GamePlay::render(SDL_Graphics& environment) {
  for (unsigned int row = 0; row < 19; row++) {
    for (unsigned int col = 0; col < 19; col++) {
      environment.draw_sprite("img/panel_beigeLight.bmp", col * 30, row * 30);
    }
  }
  environment.render();
}