// #pragma once
#ifndef WORDTOOLBOX_H
#define WORDTOOLBOX_H

#include <string>

class WordToolBox {
private:
  std::string stringHeld;
public:
  WordToolBox(std::string text);
  std::string getStringHeld();
  void setStringHeld(std::string newstring);
  bool isAnnagram(std::string stringToCheck);
  int countHowMany(char charToFind);
};

#endif