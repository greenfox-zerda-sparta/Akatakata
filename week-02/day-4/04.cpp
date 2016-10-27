#include <iostream>

using namespace std;

void change(int *array, int length);
void printArray(int *array, int length);

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

  // Write a function that takes an array and its length than reverses the array
  int size = sizeof(array) / sizeof(int);
  change(array, size);
  printArray(array, size);
  return 0;
}

void change(int *array, int length) {
  int swap = 0;
  for (int i = 0; i < length / 2; i++) {
    swap = array[i];
    array[i] = array[length-1-i];
    array[length-1-i] = swap;
  }
}

void printArray(int *array, int length) {
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
