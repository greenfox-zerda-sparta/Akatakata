#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

// Duplicate the Stack class from the previous exercies.
// Rewrite it so, that the push and pop methods don't throw integers.
// Define an enum for te two types of exceptions.
// Adapt the interpretException method to except an argument from that enum type.
// Adapt the main function so that the try and catch blocks except an exception of that enum type.

int main() {
  double my_input[] = { 1, 2, 3, 4, 5 };
  int length = 5;
  Stack* mystack = new Stack(my_input, length);
  try {
    mystack->stack_push(9);
  }
  catch (int i) {
    cout << "Exception: " + mystack->interpretException(i) << endl;
  }

  double my_input2[] = { 1 };
  int length2 = 1;
  Stack* mystack2 = new Stack(my_input2, length2);
  try {
    mystack2->stack_pop();
    mystack2->stack_pop();
  }
  catch (int z) {
    cout << "Exception: " + mystack2->interpretException(z) << endl;
  }

  return 0;
}