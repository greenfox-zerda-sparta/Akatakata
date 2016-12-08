#include <ctime>
#include <cstdlib>
#include <iostream>

#include "MyGame.h"

MyGame::MyGame() {
  area = new Area;
  hero = new Hero;
  skeleton_count = 3;
  for (int i = 0; i < 3; i++) {
    skeletons.push_back(new Skeleton(area));
  }
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
    context.draw_sprite("img/skeleton.bmp", skeletons[i]->get_skeleton_loc()[0] * 72, skeletons[i]->get_skeleton_loc()[1] * 72);
  }
 
  //Boss
  context.draw_sprite("img/boss.bmp", boss_loc[0] * 72, boss_loc[1] * 72);

  //Hero
  context.draw_sprite(hero->get_hero_image(), hero->get_loc_y() * 72, hero->get_loc_x() * 72);

  //Moving the hero
  if (context.was_key_pressed(ARROW_DOWN)) {
    hero->set_hero_loc(area, hero->get_loc_x() + 1, hero->get_loc_y());
    hero->set_hero_image("img/hero-down.bmp");
    context.draw_sprite(hero->get_hero_image(), hero->get_loc_y() * 72, hero->get_loc_x() * 72);
  }
  if (context.was_key_pressed(ARROW_UP)) {
    hero->set_hero_loc(area, hero->get_loc_x() - 1, hero->get_loc_y());
    hero->set_hero_image("img/hero-up.bmp");
    context.draw_sprite(hero->get_hero_image(), hero->get_loc_y() * 72, hero->get_loc_x() * 72);
  }
  if (context.was_key_pressed(ARROW_RIGHT)) {
    hero->set_hero_loc(area, hero->get_loc_x(), hero->get_loc_y() + 1);
    hero->set_hero_image("img/hero-right.bmp");
    context.draw_sprite(hero->get_hero_image(), hero->get_loc_y() * 72, hero->get_loc_x() * 72);
  }
  if (context.was_key_pressed(ARROW_LEFT)) {
    hero->set_hero_loc(area, hero->get_loc_x(), hero->get_loc_y() - 1);
    hero->set_hero_image("img/hero-left.bmp");
    context.draw_sprite(hero->get_hero_image(), hero->get_loc_y() * 72, hero->get_loc_x() * 72);
  }
  context.render();
}

MyGame::~MyGame() {
  delete hero;
  delete area;
  for (int i = 0; i < 3; i++) {
    delete skeletons[i];
  }
//delete skeleton1;
//  delete skeleton2;
//  delete skeleton3;
}
