#include <iostream>
#include <string>

using namespace std;

unsigned int weird_bunny_ear_counter(unsigned int bunny_number) {
  if (bunny_number == 1) {
    return 2;
  }
  if (bunny_number == 0) {
    return 0;
  }
  return 2 + 3 + weird_bunny_ear_counter(bunny_number - 2);
}

int main() {
  // We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies
  // (1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) we'll say
  // have 3 ears, because they each have a raised foot. Recursively return the
  // number of "ears" in the bunny line 1, 2, ... n (without loops or
  // multiplication).
  cout << weird_bunny_ear_counter(7) << endl;
  return 0;
}