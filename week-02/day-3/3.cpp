#include <iostream>

using namespace std;

int main() {
  int number = 1234;
  int* number_pointer = &number;
  // update the value of number variable to 42 using the "number_pointer"
  *number_pointer = 42;
  // cout << *number_pointer;
  return 0;
}
