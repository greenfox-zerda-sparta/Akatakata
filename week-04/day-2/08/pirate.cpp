#include <iostream>
#include <string>
#include "pirate.h"

using namespace std;

// pirate class constructor
Pirate::Pirate(string name, int number) {
  this->name = name;
  this->rum_number = number;
}

void Pirate::drink_rum() {
  cout << "A cup o' spicey rum fo ya matey!" << endl;
  rum_number++;
}

// if the drink_rum was called at least 5 times:
// hows_goin_mate should return "Arrrr!"
// "Nothin'" otherwise

string Pirate::hows_goin_mate() {
  if (rum_number == 5) {
    return "Arrrr!";
  }
  return "Nothin'\n";
}
