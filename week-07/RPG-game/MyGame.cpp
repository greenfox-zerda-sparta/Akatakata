#include <ctime>
#include <cstdlib>
#include <iostream>

#include "MyGame.h"

MyGame::MyGame() {
  area = new Area;
  hero = new Hero;
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
  context.draw_sprite(hero->get_hero_image(), hero->get_hero_location()[1] * 72, hero->get_hero_location()[0] * 72);
  if (context.was_key_pressed(ARROW_DOWN)) {
    hero->set_hero_loc(area, hero->get_hero_location()[0] + 1, hero->get_hero_location()[1]);
    hero->set_hero_image("img/hero-down.bmp");
    context.draw_sprite(hero->get_hero_image(), hero->get_hero_location()[1] * 72, hero->get_hero_location()[0] * 72);
  }
  if (context.was_key_pressed(ARROW_UP)) {
    hero->set_hero_loc(area, hero->get_hero_location()[0] - 1, hero->get_hero_location()[1]);
    hero->set_hero_image("img/hero-up.bmp");
    context.draw_sprite(hero->get_hero_image(), hero->get_hero_location()[1] * 72, hero->get_hero_location()[0] * 72);
  }
  if (context.was_key_pressed(ARROW_RIGHT)) {
    hero->set_hero_loc(area, hero->get_hero_location()[0], hero->get_hero_location()[1] + 1);
    hero->set_hero_image("img/hero-right.bmp");
    context.draw_sprite(hero->get_hero_image(), hero->get_hero_location()[1] * 72, hero->get_hero_location()[0] * 72);
  }
  if (context.was_key_pressed(ARROW_LEFT)) {
    hero->set_hero_loc(area, hero->get_hero_location()[0], hero->get_hero_location()[1] - 1);
    hero->set_hero_image("img/hero-left.bmp");
    context.draw_sprite(hero->get_hero_image(), hero->get_hero_location()[1] * 72, hero->get_hero_location()[0] * 72);
  }
  context.render();
}

MyGame::~MyGame() {
  delete hero;
  delete area;
}
