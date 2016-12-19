#include <algorithm>
#include <iterator>
#include "WordToolBox.h"

WordToolBox::WordToolBox(std::string text) : stringHeld(text) {
}

std::string WordToolBox::getStringHeld() {
  return stringHeld;
}

void WordToolBox::setStringHeld(std::string newstring) {
  stringHeld = newstring;
}

bool WordToolBox::isAnAnagram(std::string stringToCheck) {
  return std::string(stringToCheck.rbegin(), stringToCheck.rend()) == stringToCheck;
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