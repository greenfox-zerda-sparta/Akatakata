#include "MainMessage.h"

MainMessage::MainMessage() {
  welcome_text = "Hello! Let's play Bulls and Cows!\n\n";
  rules_text = "The rules: \nThere is a 4 digit long secret number. "
    "Enter your guess and I will tell you how many bulls and cows you have got.\n"
    "Cows = number of matching digits.\n"
    "Bulls = number of  matching digits in the right position.\n"
    "You have 10 guesses to find the secret number!\n\n";
}

MainMessage::~MainMessage() {
}

std::string MainMessage::get_welcome_text() {
  return welcome_text;
}

std::string MainMessage::get_rules_text() {
  return rules_text;
}