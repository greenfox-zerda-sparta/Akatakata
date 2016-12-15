#include <iostream>
#include <string>

using namespace std;

unsigned int to_power(unsigned int base, unsigned int power) {
  if (power == 0) {
    return 1;
  }
  return base * to_power(base, power - 1);
}

int main() {
  // Given base and n that are both 1 or more, compute recursively (no loops)
  // the value of base to the n power, so powerN(3, 2) is 9 (3 squared).
  cout << to_power(3, 4) << endl;
  return 0;
}