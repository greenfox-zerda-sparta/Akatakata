// Take the function like macro from the previous exercise.
// Make it so, that it's defined like the way You wrote it
// when __DEBUG is defined.
// It's defined to be nothing otherwise.

#include <iostream>
//#define __DEBUG
//or g++ main.cpp -D __DEBUG
#ifdef __DEBUG
#define false_prints_location(a) if(!(a)){std::cout << "False. The expression is: " << (#a) << ". It is in " << __FILE__ << " at line " << __LINE__ << std::endl; for(;;);}
#else
#define false_prints_location(a)
#endif

int main() {
  int x = 7;
  int y = 8;
  false_prints_location(x == y);
}