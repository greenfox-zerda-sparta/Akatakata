// #pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "MainGame.h"
#include "GameBoard.h"

class GamePlay : public MainGame {
private:
  GameBoard* board; 
  bool is_red_turn;
  bool gameover;
public:
  GamePlay();
  ~GamePlay();
  virtual void init(SDL_Graphics& environment);
  virtual void render(SDL_Graphics& environment);
  void place_stone_on_board(SDL_Graphics& environment, int x, int y);
  void change_current_player(SDL_Graphics& environment, std::string filename);
  GameBoard* get_board();
  bool GamePlay::is_win(int x, int y);
  bool is_win_horizontal(int x, int y);
  bool is_win_vertical(int x, int y);
  bool is_win_diagonal1(int x, int y);
  bool is_win_diagonal2(int x, int y);
  virtual bool is_gameover();
};
#endif
