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

void draw::draw_square(SDL_Renderer* &renderer, int x, int y, int line) {
  setX(x);
  setY(y);
  DrawTo(renderer, x + line, y);
  DrawTo(renderer, x + line, y + line);
  DrawTo(renderer, x, y + line);
  DrawTo(renderer, x, y);
}

void draw::grid(SDL_Renderer* &renderer, int x, int y, int line) {
  if (line > 8) {
    draw_square(renderer, x, y, line);
    MoveTo(x + line / 3, y);
    DrawTo(renderer, x + line / 3, y + line);
    MoveTo(x + 2 * line / 3, y);
    DrawTo(renderer, x + 2 * line / 3, y + line);
    MoveTo(x, y + line / 3);
    DrawTo(renderer, x + line, y + line / 3);
    MoveTo(x, y + 2 * line / 3);
    DrawTo(renderer, x + line, y + 2 * line / 3);

    grid(renderer, x, y + line / 3, line / 3);
    grid(renderer, x + line / 3, y, line / 3);
    grid(renderer, x + 2 * line / 3, y + line / 3, line / 3);
    grid(renderer, x + line / 3, y + 2 * line / 3, line / 3);
  } else {
    
  }
}

