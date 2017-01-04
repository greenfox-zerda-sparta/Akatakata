//#pragma once
#ifndef AMOBA_H
#define AMOBA_H
#include "SDL_Textures.h"
#include "GamePlay.h"
#include "ClientSocket.h"

class Amoba {
private:
  SDL_Textures* textures;
  GamePlay* game;
  SDL_Event event;
  ClientSocket* cs;
  bool quit;
  int click_x;
  int click_y;
public:
  Amoba();
  ~Amoba();
  void make_new_game();
  bool is_click_on_board(int x, int y);
  void run();
};
#endif