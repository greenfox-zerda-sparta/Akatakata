#pragma once
#ifndef INTARRAYLIST_H
#define INTARRAYLIST_H
#include "IntList.h"
class IntArrayList : public IntList {
private:
  int array_length;
  int* array;
public:
  IntArrayList();
  ~IntArrayList();
  void setArray(int* arr, int _size);
  void setArrayLength(int arr_size);
  int getArrayLength();
  void printArray();
  void append(int _a);
  void insert(int _idx, int _a);
  int getFirst();
  int getLast();
  bool isEmpty();
};
#endif
