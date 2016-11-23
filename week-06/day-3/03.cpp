#include <iostream>
#include <string>

using namespace std;

template<class T>
void Print_array(T arr, int length) {
  for (int i = 0; i < length; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  // create a function template which takes in an array, and the size of it
  // print all the elements of the array
  int array[] = {5, 6, 7};
  string array2[] = {"egy", "ketto", "harom", "negy"};
  Print_array(array, 3);
  Print_array(array2, 4);
  return 0;
}