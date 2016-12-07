#include <vector>
#include <iostream>

#include "MyGame.h"

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
  hero_loc = { 0, 0 };
}

void MyGame::init(GameContext& context) {
  context.load_file("img/floor.bmp");
  context.load_file("img/wall.bmp");
  context.load_file("img/hero-down.bmp");
}

void MyGame::set_hero_loc(int x, int y) {
  hero_loc = { x, y };
}

std::vector<int> MyGame::get_hero_location() {
  return hero_loc;
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
  context.draw_sprite("img/hero-down.bmp", get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  if (context.was_key_pressed(ARROW_DOWN)) {
    std::cout << "arrow-down\n";
    set_hero_loc(get_hero_location()[0] + 1, get_hero_location()[1]);
    context.draw_sprite("hero-down.bmp", get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  }
  if (context.was_key_pressed(ARROW_UP)) {
    std::cout << "arrow-up\n";
    set_hero_loc(get_hero_location()[0] - 1, get_hero_location()[1]);
    context.draw_sprite("hero-down.bmp", get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  }
  if (context.was_key_pressed(ARROW_RIGHT)) {
    std::cout << "arrow-up\n";
    set_hero_loc(get_hero_location()[0], get_hero_location()[1] + 1);
    context.draw_sprite("hero-down.bmp", get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  }
  if (context.was_key_pressed(ARROW_LEFT)) {
    std::cout << "arrow-up\n";
    set_hero_loc(get_hero_location()[0], get_hero_location()[1] - 1);
    context.draw_sprite("hero-down.bmp", get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  }
  context.render(); 
}

void MyGame::move(GameContext& context) {
  if (context.was_key_pressed(ARROW_DOWN)) {
    std::cout << "arrow-down\n";
    set_hero_loc(get_hero_location()[0], get_hero_location()[1 + 1]);
  }
  context.draw_sprite("img/hero-down.bmp", get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  context.render();
}

MyGame::~MyGame() {
}

