#include <iostream>
#include <string>

using namespace std;

int min(int array[], int length) {
  int min = array[0];
  for (int i = 1; i < length; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

int main() {
  int numbers[] = {7, 5, 8, -1, 2};
  // Write a function that takes ana array and its length returns the minimal element
  // in the array (your own min function)
  //int size = size(numbers);

  int size = sizeof(numbers) / sizeof(int);

  cout << "The smallest element is " << min(numbers, size) << endl;

  return 0;
}
