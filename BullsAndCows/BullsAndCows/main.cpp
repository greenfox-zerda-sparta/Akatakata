#include <iostream>
#include "MainMessage.h"
#include "SecretCode.h"
#include "GuessCode.h"

void evaluate_guess_for_bulls(SecretCode hidden, GuessCode guess) {
  int bulls = 0;
  for (unsigned int i = 0; i < hidden.get_code_length(); i++) {
    if (guess.get_guess_code()[i] == hidden.get_hidden_code()[i]) {
      bulls++;
    } 
  }
  std::cout << "Bulls: " << bulls << std::endl;

}

void evaluate_guess_for_cows(SecretCode hidden, GuessCode guess) {
  int cows = 0;
  for (unsigned int i = 0; i < hidden.get_code_length(); i++) {
    if (hidden.get_hidden_code().find(guess.get_guess_code()[i]) < hidden.get_code_length() && guess.get_guess_code()[i] != hidden.get_hidden_code()[i]) {
      cows++;
    }
  }
  std::cout << "Cows: " << cows << std::endl;
}

void gameplay(SecretCode hidden) {
  int counter = 1;
  std::string user_input = "";
  while (user_input.compare(hidden.get_hidden_code()) != 0 && counter <= 10) {
    std::cout << std::endl << "Round " << counter << ". Enter your guess: ";
    std::cin >> user_input;
    GuessCode guess(user_input);
    evaluate_guess_for_cows(hidden, guess);
    evaluate_guess_for_bulls(hidden, guess);
    counter++;
  }
  if (user_input.compare(hidden.get_hidden_code()) == 0) {
    std::cout << "Congratulations! You have found the secret code: ";
    hidden.print_formatted_hidden_code();
  } else {
    std::cout << "\nGame Over!" << std::endl;
    std::cout << "The code was: " << std::endl;
    hidden.print_formatted_hidden_code();
  }
}
int main() {

  MainMessage start;
  std::cout << start.get_welcome_text();
  std::cout << start.get_rules_text();
  SecretCode code;
  gameplay(code);
  
  return 0;
}