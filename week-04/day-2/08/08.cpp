#include <iostream>
#include <string>
#include "pirate.h"

using namespace std;

int main() {
  Pirate captain = Pirate("Blackbeard", 0);
  captain.drink_rum();
  captain.drink_rum();
  cout << captain.hows_goin_mate();
  captain.drink_rum();
  captain.drink_rum();
  captain.drink_rum();
  cout << captain.hows_goin_mate();
  return 0;
}

