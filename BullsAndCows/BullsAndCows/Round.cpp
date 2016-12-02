#include <iostream>
#include "Round.h"

Round::Round(unsigned int round, SecretCode hidden_code) : 
  round_number(round), hidden(hidden_code), bulls(0), cows(0)  {
  play_one_round();
}

Round::~Round() {
}

void Round::reset_bulls() {
  bulls = 0;
}

unsigned int Round::get_bulls() {
  return bulls;
}

void Round::reset_cows() {
  cows = 0;
}

void Round::evaluate_guess_for_bulls(GuessCode guess) {
  reset_bulls();
  for (unsigned int i = 0; i < hidden.get_code_length(); i++) {
    if (guess.get_guess_code()[i] == hidden.get_hidden_code()[i]) {
      bulls++;
    }
  }
  std::cout << "Bulls: " << bulls << std::endl;
}

void Round::evaluate_guess_for_cows(GuessCode guess) {
  reset_cows();
  for (unsigned int i = 0; i < hidden.get_code_length(); i++) {
    if (hidden.get_hidden_code().find(guess.get_guess_code()[i]) < hidden.get_code_length()
      && guess.get_guess_code()[i] != hidden.get_hidden_code()[i]) {
      cows++;
    }
  }
  std::cout << "Cows: " << cows << std::endl;
}

void Round::play_one_round() {
  std::string user_input = "";
  std::cout << "\nRound " << round_number << ". Enter your guess: ";
  std::cin >> user_input;
  GuessCode guess(user_input);
  evaluate_guess_for_cows(guess);
  evaluate_guess_for_bulls(guess);
  round_number++;
}