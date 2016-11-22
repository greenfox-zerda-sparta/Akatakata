#include <iostream>
#include <string>
#include "StackEnumErr.h"
using namespace std;

// Duplicate the Stack class from the previous exercies.
// Rewrite it so, that the push and pop methods don't throw integers.
// Define an enum for te two types of exceptions.
// Adapt the interpretException method to except an argument from that enum type.
// Adapt the main function so that the try and catch blocks except an exception of that enum type.


int main() {
  double my_input[] = { 1, 2, 3, 4, 5 };
  int length = 5;
  StackEnumErr* mystack = new StackEnumErr(my_input, length);
  try {
    mystack->stack_push(9);
  }
  catch (Errors a) {
    cout << "Exception: " + mystack->interpretException(Errors::FULL) << endl;
  }

  double my_input2[] = { 1 };
  int length2 = 1;
  StackEnumErr* mystack2 = new StackEnumErr(my_input2, length2);
  try {
    mystack2->stack_pop();
    mystack2->stack_pop();
  }
  catch (Errors b) {
    cout << "Exception: " + mystack2->interpretException(Errors::EMPTY) << endl;
  }

  delete mystack;
  delete mystack2;
  return 0;
}