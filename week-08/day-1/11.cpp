// Create a function like macro that takes one argument.
// If the argument is false, it should print out the following:
// The expression in the argument. And the file name and the line in the file.

#include <iostream>
#define false_prints_location(a) if(!(a)){std::cout << "False. The expression is: " << (#a) << ". It is in " << __FILE__ << " at line " << __LINE__ << std::endl; for(;;);}

int main() {
  int x = 7;
  int y = 8;
  false_prints_location(x == y);
}