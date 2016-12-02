// #pragma once
#ifndef MAINMESSAGE_H
#define MAINMESSAGE_H

#include <string>

class MainMessage {
private:
  std::string welcome_text;
  std::string rules_text;
public:
  MainMessage();
  ~MainMessage();
  std::string get_welcome_text();
  std::string get_rules_text();
};
#endif // !MAINMESSAGE_H
