#include <iostream>
#include <string>

using namespace std;

#ifndef STACK_H_
#define STACK_H_

// Create a `Stack` class that stores elements
class Stack {
  private:
    int number_of_elements;
    double* array;
    int array_size;

  public:
    Stack(double input[], int size, int length);

    void print_elements();

    int size();

    void push(double number);

    double pop();
};
    // It should have a `size` method that returns number of elements it has
    // It should have a `push` method that adds an element to the stack
    // It should have a `pop` method that returns the last element form the stack and also deletes it from it
#endif /* STACK_H_ */
