// Define 3 constants using a macro directive. 
// One integer, one float and one string of characters.
// Print them out to the console in Your main funciton.
//

#define MYINT 1
#define MYFLOAT 22.22
#define MYSTRING "it's a string"
#include <iostream>

int main() {
  std::cout << MYINT << std::endl;
  std::cout << MYFLOAT << std::endl;
  std::cout << MYSTRING << std::endl;
  return 0;
}