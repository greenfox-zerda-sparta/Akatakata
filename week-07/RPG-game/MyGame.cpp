//#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "MyGame.h"

MyGame::MyGame() {
  area = new Area;
  hero_loc = { 0, 0 };
  hero_image = "img/hero-down.bmp";
  skeleton_count = 3;
  std::srand(std::time(0));
  set_skeleton_loc_random();
  set_random_boss_loc();
}

void MyGame::init(GameContext& context) {
  context.load_file("img/floor.bmp");
  context.load_file("img/wall.bmp");
  context.load_file("img/hero-down.bmp");
  context.load_file("img/hero-up.bmp");
  context.load_file("img/hero-left.bmp");
  context.load_file("img/hero-right.bmp");
  context.load_file("img/skeleton.bmp");
  context.load_file("img/boss.bmp");
}

void MyGame::set_hero_loc(int x, int y) {
  // checking for map boundaries
  if (x > area->get_map_width() - 1) {
    x = area->get_map_width() - 1;
  } else if (x < 0) {
    x = 0;
  }
  if (y > area->get_map_height() - 1) {
    y = area->get_map_height() - 1;
  } else if (y < 0) {
    y = 0;
  }

  // checking for walls
  if (area->get_tileMap()[x][y] == 0) {
    // empty line for "do nothing"
  } else {
    hero_loc = { x, y };
  }
}

std::vector<int> MyGame::get_hero_location() {
  return hero_loc;
}

void MyGame::set_hero_image(std::string changed_image) {
  hero_image = changed_image;
}

void MyGame::set_skeleton_loc_random() { 
  for (int i = 1; i <= skeleton_count; i++) {
    int x_loc = rand() % 10;
    int y_loc = rand() % 10;
    if (area->get_tileMap()[y_loc][x_loc] == 0 || (x_loc == 0 && y_loc == 0)) {
      i -= 1;
    } else if (area->get_tileMap()[y_loc][x_loc] == 1) {
      skeleton_loc.push_back(x_loc);
      skeleton_loc.push_back(y_loc);
    }
  }
}

void MyGame::set_random_boss_loc() {
  int x_loc = rand() % 10;
  int y_loc = rand() % 10;
  if (area->get_tileMap()[y_loc][x_loc] == 1 && (x_loc != 0 && y_loc != 0)) {
    boss_loc.push_back(x_loc);
    boss_loc.push_back(y_loc);
  } else {
    set_random_boss_loc();
  }
}

void MyGame::render(GameContext& context) {
  for (int i = 0; i < area->get_tileMap().size(); i++) {
    for (int j = 0; j < area->get_tileMap()[i].size(); j++)
      if (area->get_tileMap()[i][j] == 0) {
        context.draw_sprite("img/wall.bmp", j * 72, i * 72);
      } else {
        context.draw_sprite("img/floor.bmp", j * 72, i * 72);
      }
  }
  for (int i = 0; i < skeleton_count * 2; i += 2) {
    context.draw_sprite("img/skeleton.bmp", skeleton_loc[i] * 72, skeleton_loc[i + 1] * 72);
  }
  context.draw_sprite("img/boss.bmp", boss_loc[0] * 72, boss_loc[1] * 72);
  context.draw_sprite(hero_image, get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  if (context.was_key_pressed(ARROW_DOWN)) {
    set_hero_loc(get_hero_location()[0] + 1, get_hero_location()[1]);
    set_hero_image("img/hero-down.bmp");
    context.draw_sprite(hero_image, get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  }
  if (context.was_key_pressed(ARROW_UP)) {
    set_hero_loc(get_hero_location()[0] - 1, get_hero_location()[1]);
    set_hero_image("img/hero-up.bmp");
    context.draw_sprite(hero_image, get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  }
  if (context.was_key_pressed(ARROW_RIGHT)) {
    set_hero_loc(get_hero_location()[0], get_hero_location()[1] + 1);
    set_hero_image("img/hero-right.bmp");
    context.draw_sprite(hero_image, get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  }
  if (context.was_key_pressed(ARROW_LEFT)) {
    set_hero_loc(get_hero_location()[0], get_hero_location()[1] - 1);
    set_hero_image("img/hero-left.bmp");
    context.draw_sprite(hero_image, get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  }
  context.render();
}

void MyGame::move(GameContext& context) {
  if (context.was_key_pressed(ARROW_DOWN)) {

    set_hero_loc(get_hero_location()[0], get_hero_location()[1 + 1]);
  }
  context.draw_sprite("img/hero-down.bmp", get_hero_location()[1] * 72, get_hero_location()[0] * 72);
  context.render();
}

MyGame::~MyGame() {
  delete area;
}
