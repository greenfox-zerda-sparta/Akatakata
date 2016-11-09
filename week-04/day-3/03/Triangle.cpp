#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
using namespace std;

Triangle::Triangle(double w, double h) : Shape(w, h) {
  this->height = h;
  this->width = w;
  this->mArea = calc_mArea();
}
string* Triangle::getName()   {
  return new string("It's a Triangle");
}
double Triangle::calc_mArea() {
  return (this->getHeight() * this->getWidth() / 2);
}
Triangle::~Triangle() {}
