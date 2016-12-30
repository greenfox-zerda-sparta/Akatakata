// #pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "SDL_Graphics.h"
#include "SDL_Textures.h"
#include "GameBoard.h"

class GamePlay {
private:
  GameBoard* board; 
  bool is_red_turn;
  bool gameover;
  int board_size;
public:
  GamePlay();
  ~GamePlay();
  virtual void render(SDL_Textures& textures);
  void place_stone_on_board(SDL_Textures& textures, int x, int y);
  void show_next_player(SDL_Textures& textures, std::string filename);
  bool GamePlay::is_win(int x, int y);
  virtual bool is_gameover();
  bool is_winner(int x, int y, int x_step, int y_step);
};
#endif
