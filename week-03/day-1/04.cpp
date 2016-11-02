#include <iostream>

using namespace std;

/**
 * Create a function called "range" that creates a new array and returns a pointer to it.
 * It should fill the array with numbers based on it's paramters.
 * It should take 3 paramters:
 * int from: the first number in the array
 * int to: it will fill the array till it would reach this number (so this number is not in the array)
 * int step: the step between the numbers
 *
 * Examples:
 * range(0, 10, 2) -> {0, 2, 3, 4, 5, 6, 8}
 * range(1, -8, -3) -> {1, -2, -5}
 *
 * It should delete any dynamically allocated resource before the program exits.
 */

int* range(int from, int to, int step) {
  int size = (to - from) / step;
  int *array = new int[size];
  int index = 0;
  for (int i = from; i < to; i += step) {
    array[index] = i;
    index++;
  }
  return array;
}


int main() {
  int* array = range(0, 10, 2);
  cout << array << endl;
  for (int i = 0; i < 5; i++) {
    cout << array[i] << " ";
  }
  delete[] array;
  return 0;
}
