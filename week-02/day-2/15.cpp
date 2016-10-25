#include <iostream>
#include <string>

using namespace std;

int search(int array[], int length, int n) {
	for (int i = 0; i < length; i++) {
		if (array[i] == n) {
			if (i < length) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
  int numbers[] = {7, 5, 8, -1, 2};
  // Write a function that takes ana array, its length and a number
  // and it returns the index of the given number in the array.
  // It should return -1 if did not find it. (linear search)
  int size = sizeof(numbers) / sizeof(int);

  cout << "Location of -1: " << search(numbers, size, -1) << endl;
  cout << "Location of 7: " <<search(numbers, size, 7) << endl;
  cout << "Location of 2: " <<search(numbers, size, 2) << endl;
  cout << "Location of 12: " <<search(numbers, size, 12) << endl;
  return 0;
}
