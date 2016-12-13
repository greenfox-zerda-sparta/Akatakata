// Define a function like macro that prints out the parameter it gets,
// and adds this string before it "DEBUG: " if __DEBUG is defined.
// Otherwise adds "RELEASE: " before the string.
// Use try it out. Illustrate that it works.

// #define __DEBUG 
// or: g++ main.cpp -D __DEBUG
#ifdef __DEBUG
#define test(a) std::cout << "DEBUG: " << a;
#else
#define test(a) std::cout<< "RELEASE: " << a;
#endif

#include <iostream>

int main() {
  int a = 7;
  test(a);
  return 0;
}