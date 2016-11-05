#include <iostream>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it shoud print the average of the nubmers.
 * It should delete any dynamically allocated resource before the program exits.
 */

int main() {
  int count = 0;
  cout << "For how many numbers would you calculate average?" << endl;
  cin >> count;
  float *numbers = new float[count];
  float average = 0;
  for (int i = 0; i < count; i++) {
    cout << "Give me a number!" << endl;
    cin >> numbers[i];
    average += numbers[i];
  }
  cout << "The average is: " << average / count;
  delete[] numbers;
  numbers = nullptr;
  return 0;
}

