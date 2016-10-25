#include <iostream>
#include <string>

using namespace std;

int summarize(int array[], int length) {
  int sum = 0;
  for (int i = 0; i <= length - 1; i++) {
    sum = sum + array[i];
  }
  return sum;
}

int main() {
  int numbers[] = {4, 5, 6, 7, 8, 9, 10};
  // write your own sum function
  // it should take an array and it's length
	int size = sizeof(numbers) / sizeof(int);
	cout << "The sum is: " << summarize(numbers, size) << endl;
  return 0;
}
