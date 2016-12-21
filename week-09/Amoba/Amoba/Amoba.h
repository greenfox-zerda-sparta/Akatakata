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
public:
  Amoba();
  ~Amoba();
  void run();
};
#endif
