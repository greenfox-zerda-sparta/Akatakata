// #pragma once
#ifndef STACK_H
#define STACK_H
#include <string>

class Stack {
private:
  int size;
  double* array;
public:
  Stack(double input[], int size);
  ~Stack();
  void stack_push(double value);
  double stack_pop();
  std::string interpretException(int exception);
};

#endif
