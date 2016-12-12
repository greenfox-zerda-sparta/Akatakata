// Create a constant using preprocessor directives.
// Make it so, that depending on the existence of a defined variable
// it's value is different.
// Write a main function that writes it to the console.
// Experiment in Your IDE compiling it with the directive defined or not.
// (This is waht we used -D __DEBUG for example. You can try this and see how it works
// when You compile a Debug version and a Release version.)

//#define P 21
#define P 1 
#if P > 2
#define A 7
#else
#define A 5
#endif

#include <iostream>

int main() {
  std::cout << "A is " << A;
  std::cout <<  " when P is " << P << std::endl;
  return 0;
}

