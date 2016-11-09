#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
using namespace std;

Square::Square(double w, double h) : Shape(w, h) {
  this->height = h;
  this->width = w;
  this->mArea = calc_mArea();
}
string* Square::getName()   {
  return new string("It's a Square");
}
double Square::calc_mArea() {
  return height * width;
}
Square::~Square() {}

