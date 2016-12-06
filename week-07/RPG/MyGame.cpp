#include "MyGame.h"

MyGame::MyGame() {
}

void MyGame::init(GameContext& context) {
  context.load_file("img/floor.bmp");
}

void MyGame::render(GameContext& context) {
  for (int x = 0; x <= rows * 72; x += 72) {
    for (int y = 0; y <= cols * 72; y += 72) {
      context.draw_sprite("img/floor.bmp", x, y);
    }
  }
  context.render();
}

MyGame::~MyGame() {
}
