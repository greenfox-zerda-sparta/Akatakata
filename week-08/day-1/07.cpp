// Create a function like macro, that get's one parameter.
// This macro should print out that paramter using cout.
// Illustrate that it works in Your main function.
#include <iostream>
#define coutprinter(a) (std::cout << "This macro uses cout to print: " << a << std::endl)

int main() {
  int stuff = 234;
  coutprinter(stuff);
}