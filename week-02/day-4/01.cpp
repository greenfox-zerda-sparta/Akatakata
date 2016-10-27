#include <iostream>
#include <string>

using namespace std;

void toSquare(int *array, int length);

int main() {
  // Write a function that takes an array and squares all the elements in the array
  int array[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(array)/sizeof(int);

  toSquare(array, size);

  return 0;
}

void toSquare(int *array, int length) {
  for (int i = 0; i < length; i++) {
    array[i] = array[i] * array[i];
  }
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
}
