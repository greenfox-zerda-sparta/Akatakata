#include <iostream>
#include "IntList.h"
#include "IntArrayList.h"

IntArrayList::IntArrayList() : IntList() {
  array_length = 0;
  array = 0;
}

IntArrayList::~IntArrayList() {
  delete[] array;
}

void IntArrayList::setArray(int* arr, int _size) {
  array = new int[getLength()];
  for (int i = 0; i < _size; i++) {
    array[i] = arr[i];
  }
  setArrayLength(_size);
}

void IntArrayList::setArrayLength(int arr_size) {
  array_length = arr_size;
}

int IntArrayList::getArrayLength() {
  return array_length;
}

void IntArrayList::printArray() {
  for (int i = 0; i < getArrayLength(); i++) {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
}

void IntArrayList::append(int _a) {
  if (array_length + 1 >= getLength() * 0.8) {
    int* new_array = new int[getLength() * 2];
    setLength(getLength() * 2);
    for (int i = 0; i < getArrayLength(); i++) {
      new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
  }
  array[array_length] = _a;
  setArrayLength(++array_length);
}

bool IntArrayList::isEmpty() {
  if (getArrayLength() == 0) {
    return true;
  }
  return false;
}

int IntArrayList::getFirst() {
  if (isEmpty() == true) {
    std::cout << "This list is empty. ";
    return -1; // For now this will do...
  }
  else {
    return array[0];
  }
}

int IntArrayList::getLast() {
  if (isEmpty() == true) {
    std::cout << "This list is empty. ";
    return -1; // For now this will do...
  }
  else {
    return array[getArrayLength() - 1];
  }
}

void IntArrayList::insert(int _idx, int _a) {
  if (0 <= _idx && _idx <= getArrayLength()) {
    if (array_length + 1 >= getLength() * 0.8) {
      setLength(getLength() * 2);
    }
    int* new_array = new int[getLength()];
    for (int i = 0; i < _idx; i++) {
      new_array[i] = array[i];
    }
    new_array[_idx] = _a;
    for (int i = _idx + 1; i < getArrayLength() + 1; i++) {
      new_array[i] = array[i - 1];
    }
    delete[] array;
    array = new_array;
  } else {
    std::cout << "There is no index " << _idx << " element in the list." << '\n';
  }
}