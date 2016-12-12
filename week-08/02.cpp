// Create a constatn using a prepocesor directive.
// Print it out to the console.
// Undefine it. And then redefine it with a new value.
// Print it out again.


#define APPLE 5
#if APPLE<7
#undef APPLE
#endif
#define APPLE 7

#include <iostream>

int main() {
  std::cout << APPLE << std::endl;
  return 0;
}




