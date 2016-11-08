#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

Stack::Stack(double input[], int size, int length) {
  this->number_of_elements = size;
  this->array = input;
  this->array_size = length;
}

void Stack::print_elements() {
  for (int i = 0; i < number_of_elements; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int Stack::size() {
  return number_of_elements;
}

void Stack::push(double number) {
  number_of_elements++;
  array[number_of_elements - 1] = number;
  if (number_of_elements >= array_size * 0.8) {
    array_size *= 2;
    double* new_array = new double[array_size];
    for (int i = 0; i < number_of_elements; i++) {
      new_array[i] = array[i];
    }
  delete array;
  array = new_array;
  }
}

double Stack::pop() {
  double to_pop = array[number_of_elements - 1];
  number_of_elements--;
  return to_pop;
}


