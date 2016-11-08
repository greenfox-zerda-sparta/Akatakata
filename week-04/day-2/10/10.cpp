#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main() {
    // Create a `Stack` class that stores elements
    // It should have a `size` method that returns number of elements it has
    // It should have a `push` method that adds an element to the stack
    // It should have a `pop` method that returns the last element form the stack and also deletes it from it
  double numbers[] = {1, 2, 3, 4};
  int length = sizeof(numbers) / sizeof(double);
  int array_length = 20;
  Stack mystack = Stack(numbers, length, array_length);
  mystack.print_elements();
  cout << "size: " << mystack.size() << endl;
  mystack.push(1010);
  mystack.print_elements();
  cout << "size: " << mystack.size() << endl;
  cout << "Pop: " << mystack.pop() << endl;
  mystack.print_elements();
  cout << "size: " << mystack.size() << endl;
  return 0;
}



