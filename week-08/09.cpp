// Create a function like macro. The Macro should take one parameter and
// print out the parameter to the console after printing out in which file 
// and at which line it has been called at.

#include <iostream>
#define print_location(a) std::cout << "In " << __FILE__ << " at line " << __LINE__ << " lies our parameter: " << a << std::endl;

int main() {
  int find_me = 7;
  print_location(find_me);
  return 0;
}