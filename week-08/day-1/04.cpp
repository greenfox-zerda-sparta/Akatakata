// Create a function like macro.
// It's job is to turn something written in code into a string.
// It should be called str(a).
// Try out the code below. See what happens!

#define str(a) #a

#include <iostream>

int main() {
  int a = 26;
  int b = 24;
  if (a > b) {
    std::cout << str(a > b) << "  a: " << a;
    std::cout << "  b: " << b << std::endl;
  }
  return 0;
}