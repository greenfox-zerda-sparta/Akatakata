#include <iostream>
#include <string>

using namespace std;

unsigned int bunny_ears(unsigned int bunny_number) {
  if (bunny_number == 1) {
    return 2;
  }
  return 2 + bunny_ears(bunny_number - 1);
}

int main() {
  // We have a number of bunnies and each bunny has two big floppy ears.
  // We want to compute the total number of ears across all the bunnies
  // recursively (without loops or multiplication).
  cout << bunny_ears(8) << endl;
  return 0;
}