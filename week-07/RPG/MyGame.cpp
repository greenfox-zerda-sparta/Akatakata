#include <vector>

#include "MyGame.h"

std::vector<std::string> tiles = { "img/wall.bmp", "img/floor.bmp" };

std::vector<std::vector <int>> tileMap = {
{1,1,1,0,1,0,1,1,1,1},
{1,1,1,0,1,0,1,0,0,1},
{1,0,0,0,1,0,1,0,0,1},
{1,1,1,1,1,0,1,1,1,1},
{0,0,0,0,1,0,0,0,0,1},
{1,0,1,0,1,1,1,1,0,1},
{1,0,1,0,1,0,0,1,0,1},
{1,1,1,1,1,0,0,1,0,1},
{1,0,0,0,1,1,1,1,0,1},
{1,1,1,0,1,0,0,1,0,1}
};

MyGame::MyGame() {
}

void MyGame::init(GameContext& context) {
  context.load_file("img/floor.bmp");
  context.load_file("img/wall.bmp");
  context.load_file("img/hero-down.bmp");
}

std::vector<int> MyGame::hero_location() {
  return{ 0, 0 };
}


void MyGame::render(GameContext& context) {
  for (unsigned int i = 0; i < tileMap.size(); i++) {
    for (unsigned int j = 0; j < tileMap[i].size(); j++)
      if (tileMap[i][j] == 0) {
        context.draw_sprite("img/wall.bmp", j * 72, i * 72);
      } else {
        context.draw_sprite("img/floor.bmp", j * 72, i * 72);
      }
  }
  context.draw_sprite("img/hero-down.bmp", hero_location()[1] * 72, hero_location()[0] * 72);
  context.render(); 
}

MyGame::~MyGame() {
}

