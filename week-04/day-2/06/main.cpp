#include <iostream>
#include <string>
#include <math.h>
#include "circle.h"

using namespace std;

int main() {
    // Create a `Circle` class that takes it's radius as cinstructor parameter
    // It should have a `get_circumference` method that returns it's circumference
    // It should have a `get_area` method that returns it's area

  Circle circle = Circle(10);
  cout << "Circumference: " << circle.get_circumference() << endl;
  cout << "Area: " << circle.get_area() << endl;
  return 0;
}
