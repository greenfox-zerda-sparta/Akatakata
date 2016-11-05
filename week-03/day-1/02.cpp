#include <iostream>

using namespace std;

int main() {
  int* pointer = new int[10];

  // Please allocate a 10 long array and fill it with numbers from 0 to 4, then print the whole array
  // Please delete the array before the program exits

  for (int i = 0; i < 10; i++) {
    pointer[i] = i;
  }

  for (int i = 0; i < 10; i++) {
    cout << pointer[i] << " ";
  }
  delete[] pointer;
  pointer = nullptr;
  cout << endl << "and deleted the allocated memory and resetting the pointer: " << pointer;
  return 0;
}
