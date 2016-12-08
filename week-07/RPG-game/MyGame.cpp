#include <cstdlib>
#include <iostream>
#include "MyGame.h"

MyGame::MyGame() {
  area = new Area;
  hero = new Hero(area);
  boss = new Boss(area);
  skeleton_count = 3;
  for (int i = 0; i < 3; i++) {
    skeletons.push_back(new Skeleton(area));
  }
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

void MyGame::render(GameContext& context) {
  //Map
  for (unsigned int row = 0; row < area->get_tileMap().size(); row++) {
    for (unsigned int col = 0; col < area->get_tileMap()[row].size(); col++)
      if (area->get_tileMap()[row][col] == 0) {
        context.draw_sprite("img/wall.bmp", col * 72, row * 72);
      } else {
        context.draw_sprite("img/floor.bmp", col * 72, row * 72);
      }
  }

  //Skeletons
 for (int i = 0; i < 3; i++) {
    context.draw_sprite("img/skeleton.bmp", skeletons[i]->get_loc_y() * 72, skeletons[i]->get_loc_x() * 72);
  }
 
  //Boss
  context.draw_sprite("img/boss.bmp", boss->get_loc_y() * 72, boss->get_loc_x() * 72);
  SDL_Delay(2000);
  boss->random_move();

  //Hero
  context.draw_sprite(hero->get_hero_image(), hero->get_loc_y() * 72, hero->get_loc_x() * 72);

  //Moving the hero
  if (context.was_key_pressed(ARROW_DOWN)) {
    hero->set_hero_loc(hero->get_loc_x() + 1, hero->get_loc_y());
    hero->set_hero_image("img/hero-down.bmp");
  }
  if (context.was_key_pressed(ARROW_UP)) {
    hero->set_hero_loc(hero->get_loc_x() - 1, hero->get_loc_y());
    hero->set_hero_image("img/hero-up.bmp");
  }
  if (context.was_key_pressed(ARROW_RIGHT)) {
    hero->set_hero_loc(hero->get_loc_x(), hero->get_loc_y() + 1);
    hero->set_hero_image("img/hero-right.bmp");
  }
  if (context.was_key_pressed(ARROW_LEFT)) {
    hero->set_hero_loc(hero->get_loc_x(), hero->get_loc_y() - 1);
    hero->set_hero_image("img/hero-left.bmp");
  }
  context.render();
}

MyGame::~MyGame() {
  delete hero;
  delete area;
  for (int i = 0; i < 3; i++) {
    delete skeletons[i];
  }
}
