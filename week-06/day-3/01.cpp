#include <iostream>
#include <string>

using namespace std;

template<class T>
void Print_array_1st(T arr[]) {
  cout << arr[0] << endl;
}
int main() {
  // create a function template the takes in a fix long array and prints the 1st element of it
  int array[] = { 5, 6, 7 };
  string array2[] = { "egy", "ketto", "harom" };
  Print_array_1st(array);
  Print_array_1st(array2);
  return 0;
}