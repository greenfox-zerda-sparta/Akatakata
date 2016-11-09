#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
using namespace std;

Shape::Shape(double height, double width) {
  this->height = height;
  this->width = width;
  this->mArea = calc_mArea();
}

string* Shape::getName() {
  return new string("Generic Shape");
}

double Shape::calc_mArea() {
  return this->width * this->height;
}

double Shape::getWidth() {
  return this->width;
}

double Shape::getHeight(){
  return this->height;
}

void Shape::setWidth(double new_width) {
  this->width = new_width;
  this->mArea = calc_mArea(); // in order to change calculated area when width is changed
}

void Shape::setHeight(double new_height) {
  this->height = new_height;
  this->mArea = calc_mArea(); // in order to change calculated area when height is changed
}

double Shape::get_mArea() {
  return this->mArea;
}

Shape::~Shape() {
  // Nothing to do.
}
