#pragma once
#ifndef STACKENUMERR_H
#define STACKENUMERR_H

#include <string>

enum Errors { FULL, EMPTY };

class StackEnumErr {
private:
  int size;
  double* array;
public:
  StackEnumErr(double input[], int size);
  ~StackEnumErr();
  void stack_push(double value);
  double stack_pop();
  std::string interpretException(Errors exception);
};

#endif
