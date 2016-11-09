#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
using namespace std;

string* Square::getName()   {
  return new string("It's a Square");
}

