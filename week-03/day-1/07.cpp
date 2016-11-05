#include <iostream>

using namespace std;

/**
 * Create a function called "union" that takes two pointers to int arrays, and their sizes.
 * It should also take an output pointer and size as reference.
 * The output pointer should point to a new array that only consists the union of the two arrays.
 * The size should be the size of the new array.
 */
int* union_maker(int* arr1, int* arr2, int size1, int size2, int* arr_union, int union_size) {
  int index = 0;
  for (int i = 0; i < size1; i++) {
    for (int j = 0; j < size2; j++) {
      if (arr1[i] == arr2[j]) {
        arr_union[index] = arr1[i];
        index++;
      }
    }
  }
  return arr_union;
}

int main() {
  int array1[6] = {1, 2, 3, 4, 5, 6};
  int array2[6] = {4, 5, 6, 7, 8, 9};
  int* array_union = new int[3];
  int length3 = 3;

  array_union = union_maker(array1, array2, 6, 6, array_union, length3);
  for (int i = 0; i < length3; i++) {
    cout << array_union[i] << " ";
  }
  delete[] array_union;
  array_union = nullptr;
  return 0;
}
