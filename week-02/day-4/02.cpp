#include <iostream>

using namespace std;

void filler(int *array, int length);

int main() {
  int array[10];

  // write a function that takes an array and a length and it fills the array
  // with numbers from zero till the length

  filler(array, 10);
  return 0;
}

void filler(int *array, int length) {
  for (int i = 0; i < length + 1; i++) {
    array[i] = i;
    cout << array[i] << " ";
  }
}
