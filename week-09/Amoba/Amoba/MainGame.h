// #pragma once
#ifndef MAINGAME_H
#define MAINGAME_H
#include "SDL_Graphics.h"

class MainGame {
public:
  virtual void init(SDL_Graphics& enivronment) = 0;
  virtual void render(SDL_Graphics& enivronment) = 0;
};
#endif
