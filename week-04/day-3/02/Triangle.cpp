#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
using namespace std;

string* Triangle::getName()   {
  return new string("It's a Triangle");
}
