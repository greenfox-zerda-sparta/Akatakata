#include <iostream>

using namespace std;

int main() {
  int high_number = 6655;
  int low_number = 2;

  int* hight_number_pointer = &low_number;
  int* low_number_pointer = &high_number;
  // Please fix the problem and swap where the pointers point,
  // without using the "&" operator.

  int* temp = hight_number_pointer;
  hight_number_pointer = low_number_pointer;
  low_number_pointer = temp;

  cout << "From high pointer: " << *hight_number_pointer << " From low pointer: " << *low_number_pointer << endl;

  return 0;
}
