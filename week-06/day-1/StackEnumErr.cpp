#include "StackEnumErr.h"

using namespace std;

StackEnumErr::StackEnumErr(double input[], int size) {
  this->size = size;
  this->array = new double[size];
  for (int i = 0; i < size; i++) {
    this->array[i] = input[i];
  }
}

StackEnumErr::~StackEnumErr() {
  delete[] array;
}

void StackEnumErr::stack_push(double value) {
  if (size == 5) {
    throw Errors::FULL;
  }
  double* new_array = new double[++size];
  for (int i = 0; i < size; i++) {
    new_array[i] = i < size - 1 ? array[i] : value;
  }
  delete[] array;
  array = new_array;
}

double StackEnumErr::stack_pop() {
  if (size == 0) {
    throw Errors::EMPTY;
  }
  double to_pop = array[size - 1];
  double* remaining_array = new double[--size];
  for (int i = 0; i < size; i++) {
    remaining_array[i] = array[i];
  }
  delete[] array;
  array = remaining_array;
  return to_pop;
}

string StackEnumErr::interpretException(Errors exception) {
  if (exception == Errors::FULL) {
    return "Sorry, the stack is already full.";
  }
  else {
    return "Sorry, the stack is already empty.";
  }
}