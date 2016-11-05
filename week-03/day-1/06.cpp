#include <iostream>

using namespace std;

/**
 * Create a function called "fliter_greater_than_5" that takes a pointer to an int array, and it's size.
 * It should return a pointer to a new array that only consists the numbers that are bigger than 5.
 */

int* create_array(int size) {
  int* arr = new int[size];
  for (int i = 0; i < size; ++i) {
    arr[i] = i;
  }
  return arr;
}

int* resize(int* arr, int size, int new_size) {
  int* pointer = new int[size];
  for (int i = 0; i < size; i++) {
    if (i < new_size) {
      pointer[i] = arr[i];
    } else {
      pointer[i] = 0;
    }
  }
  return pointer;
}

int* filter_greater_than_5(int* arr, int size) {
  int newsize = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > 5) {
      newsize++;
    }
  }
  int* pointer = new int[newsize];
  int index = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > 5) {
      pointer[index] = arr[i];
      index++;
    }
  }
  pointer = resize(pointer, size, newsize);
  return pointer;
}

int main() {
  int length = 10;
  int* array = create_array(length); // numbers 0 - 10
  int* new_array = filter_greater_than_5(array, length);
  for (int i = 0; i < length; i++) {
    cout << new_array[i] << " ";
  }
  delete[] array;
  delete[] new_array;
  array = nullptr;
  new_array = nullptr;
  return 0;
}
