#include <iostream>
#include <string>

using namespace std;

template<class T>
void Sort_descending(T arr[], int length) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = i + 1; j < length; j++) {
      if (arr[j] > arr[i]) {
        T temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

template<class T>
void Print_array(T arr, int length) {
  for (int i = 0; i < length; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  // create a function template that takes an array and sort it in a descending order
  int array[] = {5, 8, 6, 7, 9};
  Sort_descending(array, 5);
  Print_array(array, 5);
  return 0;
}