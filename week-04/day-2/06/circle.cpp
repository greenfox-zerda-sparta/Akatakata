#include <iostream>
#include <string>
#include <math.h>
#include "circle.h"

using namespace std;

Circle::Circle(double r) {
  radius = r;
}

double Circle::get_circumference() {
  return 2 * this->radius * M_PI;
}

double Circle::get_area() {
  return radius * radius * M_PI;
}
