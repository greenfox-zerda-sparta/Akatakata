#include <iostream>
#include "car.h"

using namespace std;

// The km and the type property should be a parmeter in the constructor
Car::Car(std::string type, unsigned int km) {
  this->type = type;
  this->km = km;
}

// It should have a method called "run" that takes a number and increments
// the "km" property by it
void Car::run(int number) {
  km = number + km;
}

unsigned int Car::getKm() {
  return km;
}


