#include <iostream>
#include "MainMessage.h"
#include "SecretCode.h"

int main() {

  MainMessage start;
  std::cout << start.get_welcome_text();
  std::cout << start.get_rules_text();
  SecretCode code;

  int counter = 1;
  std::string user_input = "";
  while (user_input.compare(code.get_hidden_code()) != 0 && counter <= 10) {
    std::cout << "Round " << counter << ". Enter your guess: ";
    std::cin >> user_input;
    int bulls = 0;
    int cows = 0;
    for (unsigned int i = 0; i < code.get_code_length(); i++) {
      if (user_input[i] == code.get_hidden_code()[i]) {
        bulls++;
      }
      else if (code.get_hidden_code().find(user_input[i]) < code.get_code_length()) {
        cows++;
      }
    }
    std::cout << "Bulls: " << bulls << std::endl;
    std::cout << "Cows: " << cows << std::endl << std::endl;
    counter++;
  }
  if (counter == 10 && user_input.compare(code.get_hidden_code()) != 0) { // doesnt work
    std::cout << "Game Over! Maybe next time!" << std::endl;
    std::cout << "The code was: " << std::endl;
    code.print_formatted_hidden_code();
  }
  if (user_input.compare(code.get_hidden_code()) == 0) {
    std::cout << "Congratulations! You have found the secret code: ";
    code.print_formatted_hidden_code();
  }

  return 0;
}