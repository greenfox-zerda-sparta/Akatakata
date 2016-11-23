#include <iostream>
#include <string>

using namespace std;

template<class T>
double Sum(T arr[], int length) {
  double sum = 0;
  for (int i = 0; i < length; i++) {
    sum += arr[i];
  }
  return sum;
}

template<>
double Sum<char>(char arr[], int length) {
  double sum = 0;
  for (int i = 0; i < length; i++) {
    // cout << "loc in alphablet:" << arr[i] << " is at  " << int(arr[i]) - 96 << endl;
    sum += (int(arr[i]) - 96);
  }
  return sum;
}



int main() {
  // Create a function template that takes an array, and its length and return the sum of his elements
  // Create a template specialization for char types, that it returns the sum of the characters integer position in the alphabet
  // NOT NEEDED: Create a template specialization for string types, that it returns the sum of 
  // the string's first characters position in the alphabet
  int array[] = { 5, 6, 7 };
  char array2[] = { 'e', 'k', 'h', 'o' };

  cout << Sum(array, 3) << endl;
  cout << Sum(array2, 4) << endl;
  return 0;
}