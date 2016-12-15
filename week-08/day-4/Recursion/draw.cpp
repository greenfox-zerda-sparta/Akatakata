#include "draw.h"

draw::~draw() {

}

void draw::TurnTo(double direction) {
  setDirection(direction);
}

void draw::TurnBy(double direction) {
  setDirection(Direction + direction);
}


void draw::MoveTo(int x, int y) {
  setX(x);
  setY(y);
}

void draw::MoveBy(int distance) {
  setX(getX() + getXComponent(distance));
  setY(getY() + getYComponent(distance));
}

void draw::DrawTo(SDL_Renderer* &renderer, int x, int y) {
  SDL_RenderDrawLine(renderer, getX(), getY(), x, y);
  setX(x);
  setY(y);
  SDL_RenderPresent(renderer);
}

void draw::DrawBy(SDL_Renderer* &renderer, int distance) {
  SDL_RenderDrawLine(renderer, getX(), getY(), X + getXComponent(distance), Y + getYComponent(distance));
  setX(X + getXComponent(distance));
  setY(Y + getYComponent(distance));
  SDL_RenderPresent(renderer);
}

int draw::getX() {
  return X;
}

void draw::setX(int x) {
  this->X = x;
}

int draw::getY() {
  return Y;
}

void draw::setY(int y) {
  this->Y = y;
}

int draw::getXComponent(int distance) {
  return distance * cos(getDirection() * PI / 180.0);
}

int draw::getYComponent(int distance) {
  return distance * sin(getDirection() * PI / 180.0);
}

int draw::getDirection() {
  return Direction;
}

void draw::setDirection(double direction) {
 // this->Direction += fmod(direction, 360);
  Direction = direction;
}

void draw::draw_square(SDL_Renderer* &renderer, int line) {
  int x_start = X;
  int y_start = Y;
  DrawTo(renderer, x_start + line, y_start);
  DrawTo(renderer, x_start + line, y_start + line);
  DrawTo(renderer, x_start, y_start + line);
  DrawTo(renderer, x_start, y_start);
}

void draw::four_squares(SDL_Renderer* &renderer, int line) {
  draw_square(renderer, line);
  setX(X - line);
  setY(Y + line);
  draw_square(renderer, line);
  setX(X + line);
  setY(Y + line);
  draw_square(renderer, line);
  setX(X + line);
  setY(Y - line);
  draw_square(renderer, line);
  setX(X - line - line);
  setY(Y - line);
}

