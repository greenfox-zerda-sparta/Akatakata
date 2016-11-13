#include "IntList.h"
#include "IntArrayList.h"

IntList::IntList() {
  mLength = 0;
}

void IntList::setLength(int _length) {
  mLength = _length;
}

int IntList::getLength() {
  return mLength;
}

IntList::~IntList() {}
