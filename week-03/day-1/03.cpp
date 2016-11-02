#include <iostream>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it shoud print the average of the nubmers.
 * It should delete any dynamically allocated resource before the program exits.
 */
int calc_average(int *arr, int length) {
  int average = 0;
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += arr[i];
  }
  average = sum / length;
  return average;
}

void averager() {
  int count = 0;
  cout << "For how many numbers would you calculate average?" << endl;
  cin >> count;
  int *numbers = new int[count];
  int *new_number = new int;
  for (int i = 1; i <= count; i++) {
    cout << "Give me a number!" << endl;
    cin >> *new_number;
    numbers[i - 1] = *new_number;
  }
  cout << "The average is: " << calc_average(numbers, count);
  delete new_number;
  delete[] numbers;
}


int main() {
  averager();
  return 0;
}
