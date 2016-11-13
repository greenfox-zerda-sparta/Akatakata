#pragma once
#ifndef INTLIST_H
#define INTLIST_H
class IntList {
private:
  int mLength;
  //We dont' want others to set the lenght of this list
public:
  IntList();
  // We want the descendant classes to implement (defin)
  // How these methods will actually work. 
  virtual ~IntList();
  int getLength();
  void setLength(int _length);
  virtual void append(int _a) = 0;
  virtual void insert(int _idx, int _a) = 0;
  virtual int getFirst() = 0;
  virtual int getLast() = 0;
  virtual bool isEmpty() = 0;
};
#endif
