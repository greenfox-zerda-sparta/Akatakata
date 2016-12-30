//#pragma once
#ifndef AMOBA_H
#define AMOBA_H
#include "SDL_Graphics.h"
#include "SDL_Textures.h"
#include "GamePlay.h"

class Amoba {
private:
  SDL_Graphics* graphics;
  SDL_Textures* textures;
  GamePlay* game;
  SDL_Event event;
  bool quit;
  int click_x;
  int click_y;
public:
  Amoba();
  ~Amoba();
  void make_new_game();
  bool is_click_on_board(int x, int y);
  void run();
  int get_click_x();
  int get_click_y();
};
#endif