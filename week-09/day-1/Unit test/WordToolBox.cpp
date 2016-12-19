#include <algorithm>
#include <iterator>
#include <iostream>
#include "WordToolBox.h"

WordToolBox::WordToolBox(std::string text) : stringHeld(text) {
}

std::string WordToolBox::getStringHeld() {
  return stringHeld;
}

void WordToolBox::setStringHeld(std::string newstring) {
  stringHeld = newstring;
}

bool WordToolBox::isAnnagram(std::string stringToCheck) {
  std::string to_reverse = stringHeld;
  std::sort(to_reverse.begin(), to_reverse.end());
  std::sort(stringToCheck.begin(), stringToCheck.end());
  return to_reverse == stringToCheck;
}

int WordToolBox::countHowMany(char charToFind) {
  int count = 0;
  for (std::string::iterator it = stringHeld.begin(); it < stringHeld.end(); it++) {
    if (tolower(*it) == tolower(charToFind)) {
      count++;
    }
  }
  return count;
}