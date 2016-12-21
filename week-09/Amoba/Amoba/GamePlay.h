// #pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "MainGame.h"
#include "Amoba.h"

class GamePlay : public MainGame {
public:
  GamePlay();
  ~GamePlay();
  virtual void init(SDL_Graphics& environment);
  virtual void render(SDL_Graphics& environment);
};
#endif
