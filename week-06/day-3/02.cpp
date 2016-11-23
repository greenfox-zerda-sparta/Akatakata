#include <iostream>
#include <string>

using namespace std;

template<class T>
T AddFirstToThird(T arr[]) {
  return arr[0] + arr[2];
}

int main() {
  // create a function template that takes 3 long array 
  // and add the 1st element of it to the third
  int array[] = { 5, 6, 7 };
  string array2[] = { "egy", "ketto", "harom" };
  cout << AddFirstToThird(array) << endl;
  cout << AddFirstToThird(array2) << endl;
  return 0;
}