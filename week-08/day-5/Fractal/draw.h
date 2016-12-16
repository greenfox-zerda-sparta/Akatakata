// #pragma once
#include <SDL.h>
#include <math.h>

#ifndef _DRAW_
#define _DRAW_

#define PI 3.14159265

class draw {
public:
  draw(int x = 0, int y = 0, double direction = 0, int count = 0)
    : X(x), Y(y), Direction(direction), count(0) {};
  ~draw();
  void TurnTo(double direction); //Turn to the exact ° direction
  void TurnBy(double direction); //Turn by the ° you gave
  void MoveTo(int x, int y); //Move to the coordinates you gave
  void MoveBy(int distance); //Move by the distance you gave, in the direction you set before
  void DrawTo(SDL_Renderer* &renderer, int x, int y); //Draw a line to the coordinates you gave on SDL_Renderer
  void DrawBy(SDL_Renderer* &renderer, int distance); //Draw a line by the distance you gave, in the direction you set before on SDL_Renderer
  int getXComponent(int distance); //Get the X component of moving in a set direction
  int getYComponent(int distance); //Get the Y component of moving in a set direction
  int getX();
  void setX(int x);
  int getY();
  void setY(int y);
  int getDirection();
  void setDirection(double direction);
  void draw_square(SDL_Renderer* &renderer, int x, int y, int line);
  void grid(SDL_Renderer* &renderer, int x, int y, int line);
  void draw_equal_triangle_down(SDL_Renderer* &renderer, int x, int y, int line);
  void draw_equal_triangle_up(SDL_Renderer* &renderer, int x, int y, int line);
  void sierpinsky_triangle(SDL_Renderer* &renderer, int x, int y, int line);

private:
  int X, Y;
  double Direction;
  int count;
};

#endif 