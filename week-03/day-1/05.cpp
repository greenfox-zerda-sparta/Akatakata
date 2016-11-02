#include <iostream>

using namespace std;

/**
 * Create a function called "resize" that takes a pointer to an int array, it's size and it's new size,
 * then it should return a new pointer that points to the new resized array.
 * It should copy all the elements to the new array, if the array is bigger it should fill all the new slots with zeros.
 * It should delete the old array.
 */

int* create_array(int size, int filler) {
  int* arr = new int[size];
  for (int i = 0; i < size; ++i) {
    arr[i] = filler;
  }
  return arr;
}

int* resize(int* arr, int size, int new_size) {
  int* pointer = new int[new_size];
  pointer = create_array(new_size, 0);
  for (int i = 0; i < new_size; i++) {
    if (i < size) {
      pointer[i] = arr[i];
    }
  }
  return pointer;
}


int main() {
  int* array = create_array(10, 5);
  array = resize(array, 10, 15);
  for (int i = 0; i < 15; i++) {
    cout << array[i] << " ";
  }
  delete[] array;
  return 0;
}
