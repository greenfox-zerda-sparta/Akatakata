//#pragma once
#ifndef AMOBA_H
#define AMOBA_H
#include "SDL_Graphics.h"
#include "GamePlay.h"

class Amoba {
private:
  SDL_Graphics* environment;
  MainGame* game;
  SDL_Event event;
  bool quit;
  int click_x;
  int click_y;
public:
  Amoba();
  ~Amoba();
  void run();
  int get_click_x();
  int get_click_y();
};
#endif