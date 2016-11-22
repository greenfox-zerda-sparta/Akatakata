#include "Stack.h"

using namespace std;

Stack::Stack(double input[], int size) {
  this->size = size;
  this->array = new double[size];
  for (int i = 0; i < size; i++) {
    this->array[i] = input[i];
  }
}

Stack::~Stack() {
  delete[] array;
}

void Stack::stack_push(double value) {
  if (size == 5) {
    throw 1;
  }
  double* new_array = new double[++size];
  for (int i = 0; i < size; i++) {
    new_array[i] = i < size - 1 ? array[i] : value;
  }
  delete[] array;
  array = new_array;
}

double Stack::stack_pop() {
  if (size == 0) {
    throw 2;
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

string Stack::interpretException(int exception) {
  if (exception == 1) {
    return "Sorry, the stack is already full.";
  }
  else {
    return "Sorry, the stack is already empty.";
  }
}